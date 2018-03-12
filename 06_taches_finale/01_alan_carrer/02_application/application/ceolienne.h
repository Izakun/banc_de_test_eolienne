#ifndef CEOLIENNE_H
#define CEOLIENNE_H
#include <iostream>
#include "connector.h"

using namespace std;

class ceolienne
{
private:
    struct value
    {
        string model;
        string type;
        string fabricant;
        string chemin_doc;
    };
    std::vector<value> valeurs;

public:
    ceolienne(string model, string type, string fabricant, string chemin_doc);
};

#endif // CEOLIENNE_H
