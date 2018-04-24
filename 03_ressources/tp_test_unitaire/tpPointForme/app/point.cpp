#include "point.h"

#include <iostream>
#include "math.h"

// constructeur par défaut
point::point()
{
    m_x = 0;
    m_y = 0;
}

// autre constructeur
// x : la nouvelle abscisse du point
// y : la nouvelle ordonnée du point
point::point(float x, float y)
{
    m_x = x;
    m_y = y;
}

// destructeur
point::~point()
{
    // rien à faire
}

// Accesseur de l'abscisse
float point::get_x() const
{
    return m_x;
}

// Accesseur de l'ordonnée
float point::get_y() const
{
    return m_y;
}

// Mutateur de l'abscisse
// x : la nouvelle abscisse
void point::set_x(float x)
{
    m_x = x;
}

// Mutateur de l'ordonnée
// y : la nouvelle ordonnée
void point::set_y(float y)
{
    m_y = y;
}

// Affichage du point
void point::afficher() const
{
    std::cout << "( " << m_x << " , " << m_y << " )";
}

// Affichage du point avec un retour à la ligne
void point::afficher_avec_retour_ligne() const
{
    afficher();
    std::cout << std::endl;
}

// Retourne la distance à un point donné
// p : Le point avec lequel on calcul la distance
float point::distance(const point &p) const
{
    return sqrt( ( p.get_x() - get_x() ) * ( p.get_x() - get_x() ) +
                 ( p.get_y() - get_y() ) * ( p.get_y() - get_y() ) );
}
