#include "ceolienne.h"

Ceolienne::Ceolienne(QString model, QString type, QString fabricant, QString chemin_doc)
{
    this->model = model;
    this->type = type;
    this->fabricant = fabricant;
    this->chemin_doc = chemin_doc;
}

bool Ceolienne::insertDB(QSqlDatabase &db)
{
    if(!db.isOpen()) return false;
    query.prepare("INSERT INTO eolienne(model, type, fabricant, chemin) VALUES (?, ?, ?, ?)");
    query.addBindValue(this->model);
    query.addBindValue(this->type);
    query.addBindValue(this->fabricant);
    query.addBindValue(this->chemin_doc);
    query.exec();
    return true;
}
