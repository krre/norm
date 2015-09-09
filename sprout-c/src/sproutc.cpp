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
#include "llvm/PassManager.h"

Compiler::Compiler(const QString& filePath): filePath(filePath)
{

}

void Compiler::run()
{
    if (isFileExists(filePath)) {
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

        llvm::FunctionType* funcType = llvm::FunctionType::get(builder.getInt32Ty(), false);
        llvm::Function* mainFunc = llvm::Function::Create(funcType, llvm::Function::ExternalLinkage, "main", module);

        llvm::BasicBlock* entry = llvm::BasicBlock::Create(context, "entrypoint", mainFunc);
        builder.SetInsertPoint(entry);

        if (instruction == "print") {

            llvm::Value* printArg = builder.CreateGlobalStringPtr(argument.toStdString() + "\n");

            std::vector<llvm::Type*> putsArgs;
            putsArgs.push_back(builder.getInt8Ty()->getPointerTo());
            llvm::ArrayRef<llvm::Type*> argsRef(putsArgs);

            llvm::FunctionType* putsType = llvm::FunctionType::get(builder.getInt32Ty(), argsRef, false);
            llvm::Constant* putsFunc = module->getOrInsertFunction("puts", putsType);

            builder.CreateCall(putsFunc, printArg);
        }

        builder.CreateRetVoid();

        module->dump();

        // generate output file

        llvm::InitializeAllTargets();
        llvm::InitializeAllTargetMCs();
        llvm::InitializeAllAsmPrinters();
        llvm::InitializeAllAsmParsers();

        llvm::PassManager PM;

        llvm::TargetOptions Options;

        std::string Err;

        llvm::Triple TheTriple(module->getTargetTriple());
        if (TheTriple.getTriple().empty())
            TheTriple.setTriple(llvm::sys::getDefaultTargetTriple());

        const llvm::Target* TheTarget = llvm::TargetRegistry::lookupTarget(TheTriple.getTriple(), Err);

        std::string MCPU,FeaturesStr;

        llvm::TargetMachine * machineTarget =
            TheTarget->createTargetMachine(TheTriple.getTriple(), MCPU, FeaturesStr, Options);

        // Figure out where we are going to send the output...
        QString outobjname = "/home/krre/work/sprout/proj.o";

//        QSharedPointer<llvm::tool_output_file> Out(new llvm::tool_output_file(outobjname.toStdString(), Err, llvm::sys::fs::OpenFlags::F_RW));
        auto Out = new llvm::tool_output_file(outobjname.toStdString(), 1);

        llvm::formatted_raw_ostream FOS(Out->os());

        if (machineTarget->addPassesToEmitFile(PM, FOS, llvm::TargetMachine::CGFT_ObjectFile,true)) {
            std::cerr << " target does not support generation of this file type!\n";
            return;
        }

        PM.run(*module);

    } else {
        console("File not exists: " << filePath.toStdString());
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
