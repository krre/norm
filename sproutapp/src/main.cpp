#include <QtCore>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        qDebug() << "Sprout";
        qDebug() << "Usage: sprout [sourcefile]";
    } else {
        qDebug() << argv[1];
    }
    return EXIT_SUCCESS;
}
