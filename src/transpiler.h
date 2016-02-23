#pragma once
#include <QObject>

class Transpiler : public QObject
{
    Q_OBJECT
public:
    explicit Transpiler(QObject *parent = 0);

signals:

public slots:
};
