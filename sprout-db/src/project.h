#pragma once
#include <QtCore>
#include <QtSql>

class Project : public QObject
{
    Q_OBJECT
public:
    Project();
    static bool create(const QString& path, const QString& projectName);

private:
    static void initTables(const QSqlDatabase& db);
    static void initRecords(const QSqlDatabase& db, const QString& projectName);
};
