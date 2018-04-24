#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "forme.h"
#include "point.h"

// déclaration de la classe rectangle
// Un rectangle est une forme (héritage)
class rectangle : public forme
{
    public:
        rectangle(); // constructeur par défaut
        rectangle(const point & p1, const point & p2); // autre constructeur
        ~rectangle(); // destructeur

        // autres méthodes
        bool contient( const point & p ) const;
        bool est_carre() const;
        void afficher() const;

    private:
        point m_bas_gauche; // Le point bas gauche du rectangle
        point m_haut_droit; // Le point haut droit du rectangle
}; // fin classe rectangle

#endif // RECTANGLE_H
