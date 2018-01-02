#pragma once
#include <QDebug>

QTextStream& qStdOut() {
    static QTextStream ts(stdout);
    return ts;
}
