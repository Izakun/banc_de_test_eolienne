#include "ceolienne.h"

Ceolienne::Ceolienne(QString model, QString type, QString fabricant, QString chemin_doc)
{
    this->model = model;
    this->type = type;
    this->fabricant = fabricant;
    this->chemin_doc = chemin_doc;
}

void Ceolienne::insertDB(QSqlDatabase &db)
{
    if(!db.isOpen()) qDebug()<< db.lastError();
    else qDebug() << "success";
    query.prepare("INSERT INTO eolienne VALUES (?, ?, ?, ?)");
    query.addBindValue(this->model);
    query.addBindValue(this->type);
    query.addBindValue(this->fabricant);
    query.addBindValue(this->chemin_doc);
    query.exec();
}
