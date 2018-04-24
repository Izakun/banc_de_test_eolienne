#ifndef FORME_H
#define FORME_H

#include "point.h"

// Déclaration de la classe forme
class forme
{
    public:
        forme(); // constructeur par défaut
        virtual ~forme(); // destructeur

        // autres méthodes
        virtual bool contient( const point & p ) const = 0; // méthode virtuelle pure
        static int nb_formes(); // méthode statique (partagée entre toutes les instances de forme)

    private:
        static int m_nb_formes; // attribut statique (partagé entre toutes les instances de forme)
}; // fin classe forme

#endif // FORME_H
