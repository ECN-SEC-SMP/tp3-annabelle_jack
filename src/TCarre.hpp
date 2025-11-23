#ifndef _TCARRE_HPP
#define _TCARRE_HPP

#include "TRectangle.hpp"

template <typename T>
class TCarre : public TRectangle<T>
{
public:
    /**
     * @brief Construct a new TCarre object
     *
     * @param centre Centre du point
     * @param cote Coté du carré
     */
    TCarre(const TPoint<T> &centre, T cote)
        : TRectangle<T>(centre, cote, cote) {}

    /**
     * @brief Surcharge de l'opérateur d'affichage
     *
     * @param s output stream
     * @param c Carré à afficher
     * @return std::ostream&
     */
    friend std::ostream &operator<<(std::ostream &s, const TCarre<T> &c)
    {
        s << "Carré - Centre: " << c.centre
          << " | Côté: " << c.largeur;
        return s;
    }
};

#endif
