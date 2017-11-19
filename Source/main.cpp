#include <QCoreApplication>
#include "Core/Defines.h"

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);
    app.setApplicationName(APP_NAME);
    app.setApplicationVersion(APP_VERSION_STR);

    return EXIT_SUCCESS;
}
