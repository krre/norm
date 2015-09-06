#include <QtCore>
#include "defines.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        auto version = Defines::version();
        qDebug() << QString("Sprout %1.%2.%3").arg(version["major"]).arg(version["minor"]).arg(version["patch"]);
        qDebug() << "Usage: sprout [sourcefile]";
    } else {
        qDebug() << argv[1];
    }
    return EXIT_SUCCESS;
}
