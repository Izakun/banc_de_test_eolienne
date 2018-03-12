#include "ceolienne.h"

ceolienne::ceolienne(string model, string type, string fabricant, string chemin_doc)
{
    valeurs.emplace_back(value{model, type, fabricant, chemin_doc});
    connector.insert(eolienne, valeurs);
    connector.close();
}
