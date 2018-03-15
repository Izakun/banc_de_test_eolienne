#include "connector.h"

connector::connector()
{

}

void connector::test()
{
    connector(3306, "127.0.0.1", "test", "root", "");
    QSqlQuery query(db);
            query.exec("INSERT INTO test VALUES (2, test1)");
}

connector::connector(int port, QString host, QString database, QString user, QString pass)
{
    db.setPort(port);
    db.setHostName(host);
    db.setDatabaseName(database);
    db.setUserName(user);
    db.setPassword(pass);
}

void connector::insert(const donnees& valeurs)
{
    connector(3306, "localhost", "soufflerie", "root", "");
    QSqlQuery query(db);
    if(valeurs.nom_phase.isEmpty())
    {
        if(valeurs.nom_scenario.isEmpty())
            query.exec("INSERT INTO eolienne VALUES ("+ valeurs.model + "," + valeurs.type + "," + valeurs.fabricant + "," + valeurs.chemin_doc +")");
        if(valeurs.model.isEmpty())
            query.exec("INSERT INTO scenario VALUES ("+ valeurs.nom_scenario +")");
    }
    query.exec("INSERT INTO phase VALUES ("+ valeurs.nom_phase + "," + valeurs.duree + "," + valeurs.puissance +")");
}

void connector::select(QString table)
{
    QSqlQuery query(db);
    query.exec("SELECT * FROM " + table);
}

void connector::close()
{
    db.close();
}

/*void connector::update(std::string table, std::vector valeurs)
{
    QSqlQuery query(db);
    //QSqlResult result;
    //query.exec("SHOW COLUMNS FROM " + table);

    query.exec("UPDATE " + table + " ");
}*/
