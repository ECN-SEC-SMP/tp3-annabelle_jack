#ifndef _TFORME_HPP
#define _TFORME_HPP

#include "TPoint.hpp"

template <typename T>
class TForme
{
private:
    TPoint<T> centre;

public:
    TForme(void)
    {
        this->centre = TPoint();
    }

    TForme(TPoint<T> point)
    {
        this->centre = point;
    }

    // Methods pure virtuals //
    virtual T perimetre(void)=0;

    virtual T surface(void)=0;

    // Affichage //
    friend std::ostream &operator<<(std::ostream &s, TForme const &centre)
    {
        s << "centre : " << this->centre << "\n";
        return s
    }
};

#endif