#include "TPoint.hpp"

template <>
void TPoint<std::string>::translate(std::pair<std::string, std::string> cord)
{
    std::swap(this->abscisse, cord.first);
    std::swap(this->ordonnee, cord.second);
}

// Obligatoire : instanciation explicite du template
template class TPoint<std::string>;
