#include "ceolienne.h"

ceolienne::ceolienne(QString model, QString type, QString fabricant, QString chemin_doc)
{
    //valeurs.emplace_back(value{model, type, fabricant, chemin_doc});
    valeurs.model = model;
    valeurs.type = type;
    valeurs.fabricant = fabricant;
    valeurs.chemin_doc = chemin_doc;
    db.insert(valeurs);
    db.close();
}
