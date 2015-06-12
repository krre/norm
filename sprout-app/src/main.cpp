#include <QTextStream>
#include "../sprout-lib/src/def.h"

QTextStream& qStdOut() {
    static QTextStream ts(stdout);
    return ts;
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        auto ver = "Sprout " + QString(VERSION);
        qStdOut() << ver << endl;
    } else {
        auto sproutPath = argv[1];
        qStdOut() << sproutPath << endl;
    }
}
