#ifndef _TPOINT_HPP
#define _TPOINT_HPP

#include <utility>

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
     * @brief Construct a new Point object
     *
     */
    Point(void);

    /**
     * @brief Construct a new Point object
     *
     * @param abscisse Valeur de l'abscisse
     * @param ordonnee Valeur de l'ordonnee
     */
    Point(T abscisse, T ordonnee);

    /**
     * @brief Construct a new Point object
     * 
     * @param p Point à recopier
     */
    Point(const TPoint& p);

    /**
     * @brief Translate le point
     *
     * @param cordonnees Les nouvelles coordonnées
     */
    void translate(std::pair<T, T> cordonnees);

    /**
     * @brief Get the Abscisse object
     *
     * @return T
     */
    T getAbscisse(void);

    /**
     * @brief Get the Ordonnee object
     *
     * @return T
     */
    T getOrdonnee(void);

    /**
     * @brief Set the Abscisse object
     * @param abscisse Valeur de l'abscisse
     */
    void setAbscisse(T abscisse);

    /**
     * @brief Set the Ordonnee object
     * @param ordonnee Valeur de l'ordonnee
     */
    void setOrdonnee(T ordonnee);

    /**
     * @brief Destroy the Point object
     *
     */
    ~Point(void);
};

#endif