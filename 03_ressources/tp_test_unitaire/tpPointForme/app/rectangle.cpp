#include "rectangle.h"

#include <iostream>

// constructeur par défaut
rectangle::rectangle()
{
    // rien à faire
}

// Autre constructeur
// p1 : un premier point (passage par référence constante)
// p2 : un second point (passage par référence constante)
// Le rectangle sera défini à partir des abscisses et ordonnées extrèmes
rectangle::rectangle(const point & p1, const point & p2)
{
    // on garde l'abscisse minimal pour m_bas_gauche
    // et l'abscisse maximal pour m_haut_droit
    if ( p1.get_x() < p2.get_x() )
    {
        m_bas_gauche.set_x( p1.get_x() );
        m_haut_droit.set_x( p2.get_x() );
    }
    else
    {
        m_bas_gauche.set_x( p2.get_x() );
        m_haut_droit.set_x( p1.get_x() );
    }

    // on garde l'ordonnée minimale pour m_bas_gauche
    // et l'ordonnée maximale pour m_haut_droit
    if ( p1.get_y() < p2.get_y() )
    {
        m_bas_gauche.set_y( p1.get_y() );
        m_haut_droit.set_y( p2.get_y() );
    }
   else
    {
        m_bas_gauche.set_y( p2.get_y() );
        m_haut_droit.set_y( p1.get_y() );
    }
}

// desctructeur
rectangle::~rectangle()
{
    // rien à faire
}

// Teste si le rectangle contient un point donné en paramètre
// p : le point à tester (passage par référence constante)
bool rectangle::contient(const point & p) const
{
    return  p.get_x() >= m_bas_gauche.get_x() &&
            p.get_x() <= m_haut_droit.get_x() &&
            p.get_y() >= m_bas_gauche.get_y() &&
            p.get_y() <= m_haut_droit.get_y();
}

// Teste si le rectangle est un carré
bool rectangle::est_carre() const
{
    return  ( m_haut_droit.get_x() - m_bas_gauche.get_x() ) ==
            ( m_haut_droit.get_y() - m_bas_gauche.get_y() );
}

// Affichage du rectangle
void rectangle::afficher() const
{
    std::cout << "rectangle de ";
    m_bas_gauche.afficher();
    std::cout << " a ";
    m_haut_droit.afficher();
    std::cout << std::endl;
}
