#include "cercle.h"

#include <iostream>

// constructeur par défaut
cercle::cercle()
{
    m_rayon = 1;
}

// autre constructeur
// centre : le centre du cercle
// le rayon du cercle
cercle::cercle(const point & centre, float rayon)
{
    m_centre = centre;
    m_rayon = rayon;
}

// destructeur
cercle::~cercle()
{

}

// Teste si le rectangle contient un point donné en paramètre
// p : le point à tester
bool cercle::contient(const point & p) const
{
    return m_centre.distance(p) <= m_rayon;
}

// Affichage du cercle
void cercle::afficher() const
{
    std::cout << "cercle de centre";
    m_centre.afficher();
    std::cout << " et de rayon " << m_rayon << std::endl;
}
