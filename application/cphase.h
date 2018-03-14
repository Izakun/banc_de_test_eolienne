#ifndef CPHASE_H
#define CPHASE_H


class cphase
{
private:
    int temps;
    int puissance;
public:
    cphase(int temps, int puissance);
    void BDD_ajouter();
    void BDD_supprimer(int id);
};

#endif // CPHASE_H
