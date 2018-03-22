#ifndef CSCENARIO_H
#define CSCENARIO_H
#include <iostream>
#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlResult>
#include <QtCore>
#include <iostream>

class CScenario
{
private:
    QString nom;
    QSqlQuery query;
public:
    CScenario(QString nom);
    void insertDB(QSqlDatabase &db);
    void removeDB(QSqlDatabase &db, int id);
};

#endif // CSCENARIO_H
