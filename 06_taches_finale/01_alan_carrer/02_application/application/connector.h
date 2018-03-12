#ifndef CONNECTOR_H
#define CONNECTOR_H
#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlResult>
#include <QtCore>
#include <iostream>
#include <vector>

using namespace std;

class connector
{
private:
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");

    int port;
    string host;
    string database;
    string user;
    string pass;



public:
    connector(string host, string database, string user, string pass);
    void update(string table, vector<type> valeurs);
    void insert(string table, vector valeurs);
    void select(string table);
    void close();
};

#endif // CONNECTOR_H
