#include "sproutc.h"
#include "sproutdb.h"
#include "macro.h"

#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Verifier.h"

#include "llvm/InitializePasses.h"
#include "llvm/LinkAllPasses.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Support/TargetRegistry.h"
#include "llvm/Support/ToolOutputFile.h"
#include "llvm/Support/FormattedStream.h"
#include "llvm/Support/Host.h"
#include "llvm/Support/FileSystem.h"
#include "llvm/IR/LegacyPassManager.h"

#include <llvm/ExecutionEngine/ExecutionEngine.h>
#include <llvm/ExecutionEngine/GenericValue.h>
#include <llvm/ExecutionEngine/MCJIT.h>

Compiler::Compiler(const QString& filePath): filePath(filePath)
{

}

void Compiler::run(bool isDump, bool isExecute)
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
    std::unique_ptr<llvm::Module> modulePtr = llvm::make_unique<llvm::Module>("top", context);
    llvm::Module* module = modulePtr.get();
    llvm::IRBuilder<> builder(context);

    // 'main' function prototype
    llvm::FunctionType* mainType = llvm::FunctionType::get(builder.getVoidTy(), false);
    llvm::Function* mainFunc = llvm::Function::Create(mainType, llvm::Function::ExternalLinkage, "main", module);
    llvm::BasicBlock* entry = llvm::BasicBlock::Create(context, "entrypoint", mainFunc);
    builder.SetInsertPoint(entry);

    // 'print-line' function prototype
    if (instruction == "print-line") {
        auto printArg = builder.CreateGlobalStringPtr(QString(argument).toStdString());

        std::vector<llvm::Type*> putsArgs;
        putsArgs.push_back(builder.getInt8Ty()->getPointerTo());
        llvm::ArrayRef<llvm::Type*>  argsRef(putsArgs);

        llvm::FunctionType* putsType = llvm::FunctionType::get(builder.getInt32Ty(), argsRef, false);
        llvm::Constant* putsFunc = module->getOrInsertFunction("puts", putsType);

        builder.CreateCall(putsFunc, printArg);

    // 'read-line' function prototype
    } else if (instruction == "read-line") {
         qDebug() << "readline " << argument;
    }

    builder.CreateRetVoid();

    if (isDump) {
        module->dump();
    }

    if (isExecute) {
        llvm::InitializeNativeTarget();
        llvm::InitializeNativeTargetAsmPrinter();
        llvm::InitializeNativeTargetAsmParser();

        llvm::ExecutionEngine* engine = llvm::EngineBuilder(std::move(modulePtr)).create();
        engine->finalizeObject(); // memory for generated code marked executable:
                                  // http://lists.cs.uiuc.edu/pipermail/llvmdev/2013-June/062677.html
        engine->runFunction(mainFunc, std::vector<llvm::GenericValue>());
    } else {
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
    //    qDebug() << objPath;

        std::error_code ec;
        llvm::raw_fd_ostream os(objPath.toStdString(), ec, llvm::sys::fs::F_None);
        llvm::formatted_raw_ostream fos(os);

        if (machineTarget->addPassesToEmitFile(pm, fos, llvm::TargetMachine::CGFT_ObjectFile, false)) {
            std::cerr << " target does not support generation of this file type!\n";
            return;
        }

        bool result = pm.run(*module);
        if (result) {
            QProcess* process = new QProcess();
            QString binPath = objPath;
            binPath.replace(".o", "");
            process->start(QString("gcc %1 -o %2").arg(objPath).arg(binPath));
        }
    }
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
