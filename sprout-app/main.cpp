#include  "QtCore"
#include "../def.h"

QTextStream& qStdOut() {
    static QTextStream ts( stdout );
    return ts;
}

int main() {
    QString ver = "Sprout " + VERSION;
    qStdOut() << ver << endl;
}
