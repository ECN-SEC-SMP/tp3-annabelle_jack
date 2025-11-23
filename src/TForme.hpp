#ifndef _TFORME_HPP
#define _TFORME_HPP

#include "TPoint.hpp"
#include <iostream>

template <typename T>
class TForme
{
protected:
    TPoint<T> centre;

public:
    // Constructeur par défaut
    TForme() : centre(TPoint<T>(0, 0)) {}

    // Constructeur avec un point
    TForme(const TPoint<T>& c) : centre(c) {}

    // Accesseur centre
    TPoint<T> getCentre() const { return centre; }

    // Méthodes abstraites
    virtual T perimetre() const = 0;
    virtual T surface() const = 0;

    // Affichage
    friend std::ostream &operator<<(std::ostream &s, const TForme &f)
    {
        s << "Centre : " << f.centre;
        return s;
    }

    // Destructeur virtuel
    virtual ~TForme() {}
};

#endif
