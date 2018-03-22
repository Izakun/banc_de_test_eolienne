#ifndef CEOLIENNE_H
#define CEOLIENNE_H
#include <iostream>
#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlResult>
#include <QSqlError>
#include <QtCore>
#include <iostream>

class Ceolienne
{
private:
    QString model;
    QString type;
    QString fabricant;
    QString chemin_doc;
    QSqlQuery query;
public:
    Ceolienne(QString model, QString type, QString fabricant, QString chemin_doc);

    void insertDB(QSqlDatabase &db);
};

#endif // CEOLIENNE_H
