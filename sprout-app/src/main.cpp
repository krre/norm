#include <QtCore>
#include "defines.h"
#include "sproutc.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        auto version = Defines::version();
        qDebug() << qPrintable(QString("Sprout %1.%2.%3").arg(version["major"].toInt()).arg(version["minor"].toInt()).arg(version["patch"].toInt()));
        qDebug() << "Usage: sprout [sourcefile]";
    } else {
        QString filePath = argv[1];
        Compiler compiler(filePath);
        compiler.run();
    }
    return EXIT_SUCCESS;
}
