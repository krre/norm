#pragma once
#include <QDebug>

namespace Irbis {

QTextStream& qStdOut() {
    static QTextStream ts(stdout);
    return ts;
}

} // Irbis
