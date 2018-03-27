#include "cscenario.h"

CScenario::CScenario(QString nom)
{
    this->nom = nom;
}

void CScenario::insertDB(QSqlDatabase &db)
{
    db.open();
    query.prepare("INSERT INTO scenario (nom) VALUES (?)");
    query.addBindValue(this->nom);
    query.exec();
    db.close();
}

void CScenario::removeDB(QSqlDatabase &db, int id)
{
    db.open();
    query.prepare("DELETE FROM scenario WHERE id=?");
    query.addBindValue(id);
    query.exec();
    db.close();
}

void CScenario::selectDB(QSqlDatabase &db)
{
    db.open();
    query.prepare("SELECT * FROM scenario");
    query.exec();
    if(query.size()>0){
        while (query.next()) {
            query.value("name").toString().toUtf8().constData();
        }
    }
    db.close();
}
