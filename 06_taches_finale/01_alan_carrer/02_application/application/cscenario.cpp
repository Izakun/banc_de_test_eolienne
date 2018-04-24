#include "cscenario.h"

CScenario::CScenario(QString nom)
{
    this->nom = nom;
}

bool CScenario::insertDB(QSqlDatabase &db)
{
    if (!db.isOpen()) return false;
    query.prepare("INSERT INTO scenario VALUES (NULL, ?)");
    query.addBindValue(this->nom);
    query.exec();
    return true;
}

void CScenario::removeDB(QSqlDatabase &db, int id)
{
    query.prepare("DELETE FROM scenario WHERE id=?");
    query.addBindValue(id);
    query.exec();
}

void CScenario::selectDB(QSqlDatabase &db)
{
    query.prepare("SELECT * FROM scenario");
    query.exec();
}
