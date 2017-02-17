#include <QCoreApplication>
#include <QCommandLineParser>
#include <QDebug>
#include "Compiler.h"

int main(int argc, char* argv[]) {
    QCoreApplication app(argc, argv);
    QCoreApplication::setApplicationName("Sprout Compiler");
    QCoreApplication::setApplicationVersion("0.1.0");

    QCommandLineParser parser;
    parser.setApplicationDescription("Sprout command line compiler");
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
            qDebug() << "Unknown source file";
            parser.showHelp();
        } else {
            QString filePath = args.at(0);
            Compiler compiler(filePath);
            compiler.run();
        }
    }

    return EXIT_SUCCESS;
}
