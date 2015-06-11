#include "../def.h"

QTextStream& qStdOut() {
    static QTextStream ts(stdout);
    return ts;
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        QString ver = "Sprout " + VERSION;
        qStdOut() << ver << endl;
    } else {
        QString sproutPath = argv[1];
        qStdOut() << sproutPath << endl;
    }
}
