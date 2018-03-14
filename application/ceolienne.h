#ifndef CEOLIENNE_H
#define CEOLIENNE_H
#include <iostream>
#include "connector.h"

class ceolienne : public connector
{
private:
    connector db;

    /*struct value
    {
        QString model;
        QString type;
        QString fabricant;
        QString chemin_doc;
    };
    std::vector<value> valeurs;*/
    connector::donnees valeurs;

public:
    ceolienne(QString model, QString type, QString fabricant, QString chemin_doc);
};

#endif // CEOLIENNE_H
