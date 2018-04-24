#ifndef POINT_H
#define POINT_H

// déclaration de la classe point en 2 dimensions (abscisse et ordonnée)
class point
{
    public:
        point(); // constructeur par défaut
        point(float x , float y); // autre constructeur
        ~point(); // destructeur

        // accesseurs
        float get_x() const;
        float get_y() const;

        // mutateurs
        void set_x( float x );
        void set_y( float y );

        // autres méthodes
        void afficher() const;
        void afficher_avec_retour_ligne() const;
        float distance(const point & p) const;

    private:
        float m_x; // l'abscisse du point
        float m_y; // l'ordonnée du point
}; // fin classe point

#endif // POINT_H
