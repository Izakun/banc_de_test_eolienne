#include <QCoreApplication>

#include "point.h"
#include "rectangle.h"
#include "cercle.h"
#include <iostream>

int main()
{
    point p1(3,4);
    p1.afficher_avec_retour_ligne();

    point p2(1,6);
    p2.afficher_avec_retour_ligne();

    rectangle r1(p1,p2);
    r1.afficher();

    if ( r1.est_carre() )
        std::cout << "Le rectangle est un carre"<< std::endl;
    else
        std::cout << "Le rectangle n'est pas un carre"<< std::endl;

    cercle c1(p1,3);
    c1.afficher();

    std::cout << "Il y a " << forme::nb_formes() << " forme(s)" << std::endl;

    return 0;
}
