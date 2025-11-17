#ifndef _TRECTANGLE_HPP
#define _TRECTANGLE_HPP

#include "TForme.hpp"

template <typename T>
class TRectangle : public TForme
{

private :
    T lenght;
    T largeur;

public : 
    T surface() override {
        return lenght*largeur;
    }

    T perimetre () override {
        return lenght*2 + largeur*2
    }
};

#endif