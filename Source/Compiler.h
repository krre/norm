#pragma once
#include <QObject>
#include <QString>

class Compiler: public QObject {
    Q_OBJECT

public:
    Compiler(const QString& filePath);
    void build();
private:
    QString filePath;
    bool isFileExists(const QString& filePath);
};
