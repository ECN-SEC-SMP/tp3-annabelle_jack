#ifndef _TRECTANGLE_HPP
#define _TRECTANGLE_HPP

#include "TForme.hpp"

template <typename T>
class TRectangle : public TForme
{

private:
    T lenght;
    T largeur;
};

#endif