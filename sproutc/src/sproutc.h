#pragma once

#include <QtCore>

class Compiler: public QObject
{
    Q_OBJECT

public:
    Compiler(const QString& filePath);
    void run();
private:
    QString filePath;
    bool isFileExists(const QString& filePath);
};
