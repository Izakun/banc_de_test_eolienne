#include "dictionnaire.h"

#include <iostream>
#include <fstream>

/*----------------------------------------------------------------------------*/
dictionnaire::dictionnaire()
{
    charger();
}

/*----------------------------------------------------------------------------*/
bool dictionnaire::mot_existe(const std::string &s) const
{
    bool resultat = false;

    // A FAIRE : il faut mettre la bonne valeur à resultat
    // ...

    return resultat;
}

/*----------------------------------------------------------------------------*/
void dictionnaire::charger()
{
    std::ifstream f("dico.txt");

    unsigned int nb_mots;
    f >> nb_mots;

    std::cout << "-- Chargement du dictionnaire" << std::endl;
    for (unsigned int i=0; i!=nb_mots; ++i)
    {
        std::string s;
        f >> s;

        ajouter_mot(s);

        std::cout << s << std::endl;
    }
    std::cout << "-- Fin du chargement" << std::endl;
}

/*----------------------------------------------------------------------------*/
void dictionnaire::ajouter_mot(const std::string &s)
{
    // A FAIRE : il faut stocker le mot s au dictionnaire
    // ...
}
