#ifndef _TPCARRE_HPP
#define _TPCARRE_HPP

#include "TRectangle.hpp"

template <typename T>
class TCarre : public TRectangle
{
private:
    T lenght;
public:
     T surface() override {
        return lenght*lenght;
    }

    T perimetre () override {
        return lenght*4;
    }

};

#endif