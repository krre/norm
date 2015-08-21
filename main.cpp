#include <QtCore>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        qDebug() << "Sprout";
        qDebug() << "Usage: sprout [sourcefile]";
    } else {
        QString filePath = argv[1];
    }
}
