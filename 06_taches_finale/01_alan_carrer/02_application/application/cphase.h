#ifndef CPHASE_H
#define CPHASE_H
#include <iostream>
#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlResult>
#include <QtCore>
#include <iostream>

class Cphase
{
private:
    int scenario;
    QString nom;
    int temps;
    int puissance;
    QSqlQuery query;
public:
    Cphase(int scenario, /*QString nom,*/ int temps, int puissance);
    void insertDB(QSqlDatabase &db);
    void removeDB(QSqlDatabase &db, int id);
};

#endif // CPHASE_H
