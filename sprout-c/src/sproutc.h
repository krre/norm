#pragma once

#include <QtCore>

class Compiler: public QObject
{
    Q_OBJECT

public:
    Compiler(const QString& filePath);
    void run(bool isDump = false, bool isExecute = false, bool isEmitFile = true);
private:
    QString filePath;
    bool isFileExists(const QString& filePath);
};
