#include "cphase.h"

Cphase::Cphase(int scenario, /*QString nom,*/ int temps, int puissance)
{
    this->scenario = scenario;
    this->nom = nom;
    this->temps = temps;
    this-> puissance = puissance;
}

void Cphase::insertDB(QSqlDatabase &db)
{
    query.prepare("INSERT INTO phase (fk_scenario, temps, puissance) VALUES (?, ?, ?)");
    query.addBindValue(this->scenario);
    query.addBindValue(this->temps);
    query.addBindValue(this->puissance);
    query.exec();
}

void Cphase::removeDB(QSqlDatabase &db, int id)
{
    query.prepare("DELETE FROM phase WHERE id=?");
    query.addBindValue(id);
    query.exec();
}
