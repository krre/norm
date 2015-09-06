#include "sproutc.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/IRBuilder.h"

Compiler::Compiler(const QString& filePath): filePath(filePath)
{

}

void Compiler::run()
{
    /*
    if (isFileExists(filePath)) {
        console(filePath.toStdString())
        auto db = QSqlDatabase::addDatabase("QSQLITE", filePath);
        db.setDatabaseName(filePath);
        if (!db.open()) {
             console("Error occurred opening the database");
             console(db.lastError().text().toStdString())
             return;
        }

        QSqlQuery query(db);
        query.prepare("SELECT * FROM Functions");
        if (!query.exec()) {
            console("Error occurred querying");
            console(db.lastError().text().toStdString())
            return;
        }
        while (query.next()) {
            console(query.value("name").toString().toStdString() << " "
                    << query.value("command").toString().toStdString() << " "
                    << query.value("argument").toString().toStdString())

            if (query.value("command").toString() == "print") {

                llvm::LLVMContext& context = llvm::getGlobalContext();
                llvm::Module* module = new llvm::Module("top", context);
                llvm::IRBuilder<> builder(context);

                llvm::FunctionType* funcType = llvm::FunctionType::get(builder.getInt32Ty(), false);
                llvm::Function* mainFunc = llvm::Function::Create(funcType, llvm::Function::ExternalLinkage, "main", module);

                llvm::BasicBlock* entry = llvm::BasicBlock::Create(context, "entrypoint", mainFunc);
                builder.SetInsertPoint(entry);

                llvm::Value* printArg = builder.CreateGlobalStringPtr(query.value("argument").toString().toStdString() + "\n");

                std::vector<llvm::Type*> putsArgs;
                putsArgs.push_back(builder.getInt8Ty()->getPointerTo());
                llvm::ArrayRef<llvm::Type*> argsRef(putsArgs);

                llvm::FunctionType* putsType = llvm::FunctionType::get(builder.getInt32Ty(), argsRef, false);
                llvm::Constant* putsFunc = module->getOrInsertFunction("puts", putsType);

                builder.CreateCall(putsFunc, printArg);
                builder.CreateRetVoid();

                module->dump();
            }
        }
    } else {
        console("File not exists: " << filePath.toStdString())
    }
    */
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
