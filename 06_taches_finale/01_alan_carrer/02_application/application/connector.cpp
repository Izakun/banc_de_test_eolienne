#include "connector.h"

connector::connector(int port, string host, string database, string user, string pass)
{
    db.setPort(port);
    db.setHostName(host);
    db.setDatabaseName(database);
    db.setUserName(user);
    db.setPassword(pass);
}

void connector::update(string table, vector valeurs)
{
    QSqlQuery query(db);
    //QSqlResult result;
    //query.exec("SHOW COLUMNS FROM " + table);

    query.exec("UPDATE " + table + " ");
}

void connector::insert(string table, vector valeurs)
{

}

void connector::select(string table)
{
    QSqlQuery query(db);
    query.exec("SELECT * FROM " + table);
}

void connector::close()
{
    db.close();
}
