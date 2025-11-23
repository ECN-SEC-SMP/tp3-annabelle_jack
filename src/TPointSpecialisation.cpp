#include "TPoint.hpp"

/**
 * @brief Translate un point
 * Surcharge la méthode Transate<T> pour prendre en charge les std::string
 *
 * @tparam
 * @param cord Coordonées en std::string
 */
template <>
void TPoint<std::string>::translate(std::pair<std::string, std::string> cord)
{
    std::swap(this->abscisse, cord.first);
    std::swap(this->ordonnee, cord.second);
}

// Obligatoire : instanciation explicite du template
template class TPoint<std::string>;
