#include <QCoreApplication>

#include "dictionnaire.h"
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    dictionnaire dico;

    std::cout << "Quel mot voulez-vous tester ?" << std::endl;
    std::string s;
    std::cin >> s;

    if ( dico.mot_existe(s))
        std::cout << "le mot " << s << " existe." << std::endl;
    else
        std::cout << "le mot " << s << " n'existe pas." << std::endl;

    return a.exec();
}
