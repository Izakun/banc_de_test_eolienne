#include "cphase.h"

Cphase::Cphase(int temps, int puissance)
{
    this->temps = temps;
    this-> puissance = puissance;
}

void Cphase::insertDB(QSqlDatabase &db)
{
    db.open();
    query.prepare("INSERT INTO phase VALUES (?, ?)");
    query.addBindValue(this->temps);
    query.addBindValue(this->puissance);
    query.exec();
    db.close();
}

void Cphase::removeDB(QSqlDatabase &db, int id)
{
    db.open();
    query.prepare("DELETE FROM phase WHERE id=?");
    query.addBindValue(id);
    query.exec();
    db.close();
}
