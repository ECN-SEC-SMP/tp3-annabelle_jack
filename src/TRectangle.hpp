#ifndef _TRECTANGLE_HPP
#define _TRECTANGLE_HPP

#include "TForme.hpp"
#include <iostream>

template <typename T>
class TRectangle : public TForme<T>
{
protected:
    /**
     * @brief Largeur du rectangle
     *
     */
    T largeur;
    /**
     * @brief Hauteur du rectangle
     *
     */
    T hauteur;

public:
    /**
     * @brief Construct a new TRectangle object
     *
     * @param centre Centre du rectangle
     * @param largeur Largeur du rectangle
     * @param hauteur Hauteur du rectangle
     */
    TRectangle(const TPoint<T> &centre, T largeur, T hauteur)
        : TForme<T>(centre), largeur(largeur), hauteur(hauteur) {}

    /**
     * @brief Get the Largeur object
     *
     * @return T
     */
    T getLargeur() const
    {
        return largeur;
    }

    /**
     * @brief Get the Hauteur object
     *
     * @return T
     */
    T getHauteur() const
    {
        return hauteur;
    }

    /**
     * @brief Calcule le périmètre du rectangkle
     *
     * @return T
     */
    T perimetre() const override
    {
        return 2 * (largeur + hauteur);
    }

    /**
     * @brief Calcule la surface du rectangle
     *
     * @return T
     */
    T surface() const override
    {
        return largeur * hauteur;
    }

    /**
     * @brief Surchage de l'opérateur d'affichage
     *
     * @param s outputstream
     * @param r Retangle à afficher
     * @return std::ostream&
     */
    friend std::ostream &operator<<(std::ostream &s, const TRectangle<T> &r)
    {
        s << "Rectangle - Centre: " << r.centre
          << " | Largeur: " << r.largeur
          << " | Hauteur: " << r.hauteur;
        return s;
    }
};

#endif
