#include "Compiler.h"
#include "global.h"
#include <QFileInfo>
#include <QtSql>
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/IRBuilder.h"

Compiler::Compiler(const QString &filePath): filePath(filePath)
{

}

void Compiler::run()
{
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
        }
    } else {
        console("File not exists: " << filePath.toStdString())
    }

    llvm::LLVMContext& context = llvm::getGlobalContext();
    llvm::Module* module = new llvm::Module("top", context);
    llvm::IRBuilder<> builder(context);

    module->dump();
}

bool Compiler::isFileExists(const QString &filePath) {
    QFileInfo checkFile(filePath);
    // check if file exists and if yes: Is it really a file and no directory?
    if (checkFile.exists() && checkFile.isFile()) {
        return true;
    } else {
        return false;
    }
}
