#ifndef _TPOINT_HPP
#define _TPOINT_HPP

#include <utility>
#include <iostream>

template <typename T>
class TPoint
{
private:
    T abscisse;
    T ordonnee;

public:
    // Constructeur par défaut
    TPoint() : abscisse(0), ordonnee(0) {}

    // Constructeur avec paramètres
    TPoint(T x, T y) : abscisse(x), ordonnee(y) {}

    // Constructeur de copie
    TPoint(const TPoint& p) : abscisse(p.abscisse), ordonnee(p.ordonnee) {}

    // Translate le point
    void translate(std::pair<T, T> cordonnees)
    {
        abscisse += cordonnees.first;
        ordonnee += cordonnees.second;
    }

    // Accesseurs
    T getAbscisse() const { return abscisse; }
    T getOrdonnee() const { return ordonnee; }

    // Mutateurs
    void setAbscisse(T x) { abscisse = x; }
    void setOrdonnee(T y) { ordonnee = y; }

    // Destructeur
    ~TPoint() {}

    // Affichage
    friend std::ostream &operator<<(std::ostream &s, const TPoint &point)
    {
        s << "(" << point.abscisse << ", " << point.ordonnee << ")";
        return s;
    }
};

#endif
