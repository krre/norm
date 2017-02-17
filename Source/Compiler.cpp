#include "Compiler.h"
#include "Macro.h"
#include <QtCore>

Compiler::Compiler(const QString& filePath): filePath(filePath) {

}

void Compiler::run(bool isDump, bool isExecute) {
    if (!isFileExists(filePath)) {
        console("File not exists: " << filePath.toStdString());
        return;
    }
}

bool Compiler::isFileExists(const QString& filePath) {
    QFileInfo checkFile(filePath);
    return checkFile.exists() && checkFile.isFile();
}
