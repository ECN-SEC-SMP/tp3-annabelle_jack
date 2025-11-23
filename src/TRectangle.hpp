#ifndef _TRECTANGLE_HPP
#define _TRECTANGLE_HPP

#include "TForme.hpp"
#include <iostream>

template <typename T>
class TRectangle : public TForme<T>
{
protected:
    T largeur;
    T hauteur;

public:
    // Constructeur
    TRectangle(const TPoint<T>& centre, T largeur, T hauteur)
        : TForme<T>(centre), largeur(largeur), hauteur(hauteur) {}

    // Accesseurs
    T getLargeur() const { return largeur; }
    T getHauteur() const { return hauteur; }

    // Implémentation des méthodes abstraites
    T perimetre() const override
    {
        return 2 * (largeur + hauteur);
    }

    T surface() const override
    {
        return largeur * hauteur;
    }

    // Affichage
    friend std::ostream& operator<<(std::ostream &s, const TRectangle<T>& r)
    {
        s << "Rectangle - Centre: " << r.centre
          << " | Largeur: " << r.largeur
          << " | Hauteur: " << r.hauteur;
        return s;
    }
};

#endif
