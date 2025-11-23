#ifndef _TFORME_HPP
#define _TFORME_HPP

#include "TPoint.hpp"
#include <iostream>

template <typename T>
class TForme
{
protected:
    /**
     * @brief Centre de la forme
     *
     */
    TPoint<T> centre;

public:
    /**
     * @brief Construct a new TForme object
     *
     */
    TForme() : centre(TPoint<T>(0, 0)) {}

    /**
     * @brief Construct a new TForme object
     *
     * @param c Centre de la forme
     */
    TForme(const TPoint<T> &c) : centre(c) {}

    /**
     * @brief Get the Centre object
     *
     * @return TPoint<T>
     */
    TPoint<T> getCentre() const { return centre; }

    /**
     * @brief Méthode abstraite pure du périmètre d'une forme
     *
     * @return T Le périmètre de la forme
     */
    virtual T perimetre() const = 0;

    /**
     * @brief Méthode abstraite pure de la surface d'une forme
     *
     * @return T La surface de la forme
     */
    virtual T surface() const = 0;

    /**
     * @brief Surchage de l'opérateur d'affichage
     *
     * @param s output stream
     * @param f La forme à afficher
     * @return std::ostream&
     */
    friend std::ostream &operator<<(std::ostream &s, const TForme &f)
    {
        s << "Centre : " << f.centre;
        return s;
    }

    /**
     * @brief Destroy the TForme object
     *
     */
    virtual ~TForme() {}
};

#endif
