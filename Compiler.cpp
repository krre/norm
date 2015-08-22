#include "Compiler.h"
#include "global.h"
#include <QFileInfo>
#include <QtSql>

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
             qDebug("Error occurred opening the database.");
             qDebug("%s.", qPrintable(db.lastError().text()));
             return;
        }

        QSqlQuery query(db);
        query.prepare("SELECT * FROM Functions");
        if (!query.exec()) {
            qDebug("Error occurred querying.");
            qDebug("%s.", qPrintable(db.lastError().text()));
            return;
        }
        while (query.next()) {
            qDebug() << query.value("name").toString() << query.value("body").toString();
        }
    } else {
        console("File not exists: " << filePath.toStdString())
    }
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
