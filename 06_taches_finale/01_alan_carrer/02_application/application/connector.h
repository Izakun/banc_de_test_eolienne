#ifndef CONNECTOR_H
#define CONNECTOR_H
#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlResult>
#include <QtCore>
#include <iostream>
#include <vector>

class connector
{
protected:
    struct donnees
    {
        //eolienne
        QString model;
        QString type;
        QString fabricant;
        QString chemin_doc;
        //scenario
        QString nom_scenario;
        //phase
        QString nom_phase;
        int puissance;
        int duree;
    };

private:
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    QSqlQuery query();

    int port;
    QString host;
    QString database;
    QString user;
    QString pass;
    donnees valeurs;

public:
    connector();
    connector(int port, QString host, QString database, QString user, QString pass);
    void insert(const donnees &valeurs);
    void select(QString table);
    void test();
    void close();
    //void update(std::string table, std::vector<type> valeurs);
    //  show columns pour avoir les collones d'une table
};

#endif // CONNECTOR_H
