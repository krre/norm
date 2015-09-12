#include "sproutc.h"
#include "sproutdb.h"
#include "macro.h"

#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/IRBuilder.h"

#include "llvm/InitializePasses.h"
#include "llvm/LinkAllPasses.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Support/TargetRegistry.h"
#include "llvm/Support/ToolOutputFile.h"
#include "llvm/Support/FormattedStream.h"
#include "llvm/Support/Host.h"
#include "llvm/Support/FileSystem.h"
#include "llvm/IR/LegacyPassManager.h"

Compiler::Compiler(const QString& filePath): filePath(filePath)
{

}

void Compiler::run()
{
    if (!isFileExists(filePath)) {
        console("File not exists: " << filePath.toStdString());
        return;
    }

    SproutDb sproutDb;
    sproutDb.open(filePath);
    QVariantList functionList = sproutDb.readRecords("SELECT * FROM Functions WHERE name='main'");
    QString functionId = functionList.at(0).toMap().value("id").toString();
//        qDebug() << functionId;
    QVariantList instructionList = sproutDb.readRecords(QString("SELECT * FROM Instructions WHERE functionId=%1").arg(functionId));
//        qDebug() << instructionList;
    QString instructionId = instructionList.at(0).toMap().value("id").toString();
    QString instruction = instructionList.at(0).toMap().value("name").toString();
//        qDebug() << instructionId << instruction;
    QVariantList argumentList = sproutDb.readRecords(QString("SELECT * FROM Arguments WHERE instructionId=%1").arg(instructionId));
//        qDebug() << argumentList;
    QString argument = argumentList.at(0).toMap().value("arg").toString();
//        qDebug() << argument;

    llvm::LLVMContext& context = llvm::getGlobalContext();
    llvm::Module* module = new llvm::Module("top", context);
    llvm::IRBuilder<> builder(context);

    // print function prototype

    llvm::Value* printArg = llvm::ConstantDataArray::getString(context, argument.toStdString());
    std::vector<llvm::Type*> printArgTypes;
    printArgTypes.push_back(printArg->getType());

    llvm::FunctionType* printType = llvm::FunctionType::get(llvm::Type::getInt32Ty(context), printArgTypes, true);
    llvm::Function *printFunc = llvm::Function::Create(printType, llvm::Function::ExternalLinkage, llvm::Twine("printf"), module);
    printFunc->setCallingConv(llvm::CallingConv::C);

    // main func prototype

    std::vector<llvm::Type*> mainArgTypes;

    llvm::FunctionType* mainType = llvm::FunctionType::get(llvm::Type::getInt32Ty(context), mainArgTypes, false);
    llvm::Function *mainFunc = llvm::Function::Create(mainType, llvm::Function::ExternalLinkage, llvm::Twine("main"), module);
    mainFunc->setCallingConv(llvm::CallingConv::C);

    llvm::BasicBlock *block = llvm::BasicBlock::Create(context, "entrypoint", mainFunc);
    builder.SetInsertPoint(block);

    builder.CreateCall(printFunc, printArg);

    builder.CreateRet(llvm::ConstantInt::get(context, llvm::APInt(32, 0)));

    module->dump();

    // generate output file

    llvm::InitializeAllTargets();
    llvm::InitializeAllTargetMCs();
    llvm::InitializeAllAsmPrinters();
    llvm::InitializeAllAsmParsers();

    llvm::legacy::PassManager pm;

    llvm::TargetOptions options;

    std::string err;

    llvm::Triple triple(module->getTargetTriple());

    if (triple.getTriple().empty()) {
        triple.setTriple(llvm::sys::getDefaultTargetTriple());
    }

    const llvm::Target* target = llvm::TargetRegistry::lookupTarget(triple.getTriple(), err);

    std::string mcpu, featuresStr;

    llvm::TargetMachine* machineTarget = target->createTargetMachine(triple.getTriple(), mcpu, featuresStr, options);

    QString objPath = filePath.replace(".sprout", ".o");
    qDebug() << objPath;

    std::error_code ec;
    llvm::raw_fd_ostream os(objPath.toStdString(), ec, llvm::sys::fs::F_None);

    if (machineTarget->addPassesToEmitFile(pm, os, llvm::TargetMachine::CGFT_ObjectFile, false)) {
        std::cerr << " target does not support generation of this file type!\n";
        return;
    }

    pm.run(*module);
}

bool Compiler::isFileExists(const QString& filePath) {
    QFileInfo checkFile(filePath);
    // check if file exists and if yes: Is it really a file and no directory?
    if (checkFile.exists() && checkFile.isFile()) {
        return true;
    } else {
        return false;
    }
}
