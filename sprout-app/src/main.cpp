#include <QtCore>
#include "defines.h"
#include "sproutc.h"

int main(int argc, char* argv[]) {
    QCoreApplication app(argc, argv);
    QCoreApplication::setApplicationName("Sprout");
    auto versionMap = Defines::version();
    QString versionStr = QString("%1.%2.%3").arg(versionMap["major"].toInt()).arg(versionMap["minor"].toInt()).arg(versionMap["patch"].toInt());
    QCoreApplication::setApplicationVersion(versionStr);

    QCommandLineParser parser;
    parser.setApplicationDescription("Sprout command line compiler");
    parser.addHelpOption();
    parser.addVersionOption();
    parser.addPositionalArgument("source", QCoreApplication::translate("main", "Source file to compile"));

    parser.addOptions({
        {{"d", "dump"}, QCoreApplication::translate("main", "Dump IR code")},
        {{"e", "execute"}, QCoreApplication::translate("main", "Execute in memory")}
    });

    parser.process(app);

    if (argc == 1) {
        parser.showHelp();
    } else {
        const QStringList args = parser.positionalArguments();
        if (args.count() == 0) {
            qDebug() << "Sprout: unknown source file";
            parser.showHelp();
        } else {
            QString filePath = args.at(0);
            bool isDump = parser.isSet("dump");
            bool isExecute = parser.isSet("execute");
            Compiler compiler(filePath);
            compiler.run(isDump, isExecute);
        }
    }

    return EXIT_SUCCESS;
}
