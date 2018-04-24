#include "forme.h"

int forme::m_nb_formes = 0; // initialisation de l'attribut statique

// constructeur par défaut
forme::forme()
{
    m_nb_formes++;
}

// destructeur
forme::~forme()
{
    m_nb_formes--;
}

// Retourne le nombre de formes actuelles
int forme::nb_formes()
{
    return m_nb_formes;
}
