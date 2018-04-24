#ifndef CERCLE_H
#define CERCLE_H

#include "forme.h"

// Déclaration de la classe cercle
class cercle : public forme
{
    public:
        cercle(); // constructeur par défaut
        cercle(const point & centre, float rayon); // autre constructeur
        ~cercle(); // destructeur

        // autres méthodes
        bool contient( const point & p ) const;
        void afficher() const;

    private:
        float m_rayon;
        point m_centre;
};

#endif // CERCLE_H
