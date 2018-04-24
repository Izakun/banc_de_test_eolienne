#include "cphase.h"

Cphase::Cphase(int scenario, int temps, int puissance)
{
    this->scenario = scenario;
    this->nom = nom;
    this->temps = temps;
    this-> puissance = puissance;
}

bool Cphase::insertDB(QSqlDatabase &db)
{
    if(!db.isOpen()) return false;
    query.prepare("INSERT INTO phase (fk_scenario, temps, puissance) VALUES (?, ?, ?)");
    query.addBindValue(this->scenario);
    query.addBindValue(this->temps);
    query.addBindValue(this->puissance);
    query.exec();
    return true;
}

void Cphase::removeDB(QSqlDatabase &db, int id)
{
    query.prepare("DELETE FROM phase WHERE id=?");
    query.addBindValue(id);
    query.exec();
}
