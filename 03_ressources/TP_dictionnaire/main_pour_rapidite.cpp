#include <QCoreApplication>

#include "dictionnaire.h"
#include <iostream>
#include <time.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    dictionnaire dico;

    std::vector< std::string > tab_mots;
    for ( unsigned int i = 0; i != 100; ++i )
    {
        tab_mots.push_back("bonjour");
        tab_mots.push_back("zkjlhz");
        tab_mots.push_back("sksks");
        tab_mots.push_back("akljdkljxxx");
        tab_mots.push_back("arbre");
        tab_mots.push_back("abeille");
        tab_mots.push_back("porteur");
        tab_mots.push_back("ajuie");
        tab_mots.push_back("herbe");
        tab_mots.push_back("vacances");
        tab_mots.push_back("noel");
        tab_mots.push_back("anticonstitutionnellement");
        tab_mots.push_back("libelle");
        tab_mots.push_back("surprise");
        tab_mots.push_back("programme");
        tab_mots.push_back("langage");
        tab_mots.push_back("pour");
        tab_mots.push_back("klssll");
    }

    bool resultat;
    float temps;
    clock_t t1, t2;
    t1 = clock();

    for ( unsigned int i = 0; i < tab_mots.size(); ++i )
        resultat = dico.mot_existe( tab_mots[i] );

    t2 = clock();
    temps = (float)(t2-t1)/CLOCKS_PER_SEC;
    printf("temps = %f\n", temps);

    std::cout << "Fin" << std::endl;

    return a.exec();
}
