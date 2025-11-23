#ifndef _TPOINT_HPP
#define _TPOINT_HPP

#include <utility>
#include <iostream>

template <typename T>
class TPoint
{
private:
    /**
     * @brief Abscisse du point
     *
     */
    T abscisse;

    /**
     * @brief Ordonnee du point
     *
     */
    T ordonnee;

public:
    /**
     * @brief Construct a new TPoint object
     *
     */
    TPoint() : abscisse(0), ordonnee(0) {}

    /**
     * @brief Construct a new TPoint object
     *
     * @param x Abscisse du point
     * @param y Ordonnee du point
     */
    TPoint(T x, T y) : abscisse(x), ordonnee(y) {}

    /**
     * @brief Construct a new TPoint object
     *
     * @param p Point à recopier
     */
    TPoint(const TPoint &p) : abscisse(p.abscisse), ordonnee(p.ordonnee) {}

    /**
     * @brief Translate un point
     *
     * @param cordonnees Coordonnées de translation
     */
    void translate(std::pair<T, T> cordonnees)
    {
        abscisse += cordonnees.first;
        ordonnee += cordonnees.second;
    }

    /**
     * @brief Get the Abscisse object
     *
     * @return T
     */
    T getAbscisse() const
    {
        return abscisse;
    }

    /**
     * @brief Get the Ordonnee object
     *
     * @return T
     */
    T getOrdonnee() const
    {
        return ordonnee;
    }

    /**
     * @brief Set the Abscisse object
     *
     * @param x Nouvel abscisse
     */
    void setAbscisse(T x)
    {
        abscisse = x;
    }

    /**
     * @brief Set the Ordonnee object
     *
     * @param y Nouvelle ordonnée
     */
    void setOrdonnee(T y)
    {
        ordonnee = y;
    }

    /**
     * @brief Destroy the TPoint object
     *
     */
    ~TPoint() {}

    /**
     * @brief Surchage de l'opérateur d'affichage
     *
     * @param s outputstream
     * @param point Point à afficher
     * @return std::ostream&
     */
    friend std::ostream &operator<<(std::ostream &s, const TPoint &point)
    {
        s << "(" << point.abscisse << ", " << point.ordonnee << ")";
        return s;
    }
};

#endif
