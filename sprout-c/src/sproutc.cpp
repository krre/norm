#include "sproutc.h"
#include "sproutdb.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/IRBuilder.h"
#include "macro.h"

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
