#pragma once

#include <QtCore>

class Defines: public QObject
{
    Q_OBJECT

public:
    Defines();
    Q_INVOKABLE static QVariantMap version();
};
