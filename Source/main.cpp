#include "Core/Defines.h"
#include <IrbisLib/Core/Utils.h>
#include <QCoreApplication>
#include <QCommandLineParser>

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);
    app.setApplicationName(APP_NAME);
    app.setApplicationVersion(APP_VERSION_STR);

    QCommandLineParser parser;
    parser.setApplicationDescription("Irbis command line compiler");
    parser.addHelpOption();
    parser.addVersionOption();
    parser.addPositionalArgument("source", QCoreApplication::translate("main", "Source file to compile"));

    parser.addOptions({
        {{"o", "output"}, QCoreApplication::translate("main", "Output directory")},
    });

    parser.process(app);

    if (argc == 1) {
        parser.showHelp();
    } else {
        const QStringList args = parser.positionalArguments();
        if (args.count() == 0) {
            IrbisLib::qStdOut() << "Unknown source file";
            parser.showHelp();
        } else {
            QString filePath = args.at(0);
            IrbisLib::qStdOut() << "Compile " << filePath;
        }
    }

    return EXIT_SUCCESS;
}
