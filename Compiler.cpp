#include "Compiler.h"
#include "global.h"
#include <QFileInfo>

Compiler::Compiler(const QString &filePath): filePath(filePath)
{

}

void Compiler::run()
{
    if (isFileExists(filePath)) {
        console(filePath.toStdString())
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
