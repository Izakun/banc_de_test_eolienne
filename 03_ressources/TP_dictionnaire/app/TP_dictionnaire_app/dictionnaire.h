#ifndef DICTIONNAIRE_H
#define DICTIONNAIRE_H

#include<string>

class dictionnaire
{
    public:
        dictionnaire();

        bool mot_existe(const std::string& s) const;

    private:
        void charger();
        void ajouter_mot(const std::string &s);
};

#endif // DICTIONNAIRE_H
