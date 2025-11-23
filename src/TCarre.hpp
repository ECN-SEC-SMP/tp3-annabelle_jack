#ifndef _TCARRE_HPP
#define _TCARRE_HPP

#include "TRectangle.hpp"

template <typename T>
class TCarre : public TRectangle<T>
{
public:
    // Constructeur : un carré est un rectangle avec largeur = hauteur
    TCarre(const TPoint<T>& centre, T cote)
        : TRectangle<T>(centre, cote, cote) {}

    // Affichage
    friend std::ostream& operator<<(std::ostream &s, const TCarre<T>& c)
    {
        s << "Carré - Centre: " << c.centre
          << " | Côté: " << c.largeur;
        return s;
    }
};

#endif
