#include <QtCore>
#include "global.h"
#include "Compiler.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        console("Sprout")
        console("Usage: sprout [sourcefile]")
    } else {
        QString filePath = argv[1];
        Compiler compiler(filePath);
        compiler.run();
    }
}
