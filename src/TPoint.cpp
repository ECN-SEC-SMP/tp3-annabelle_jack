#include "TPoint.hpp"

//Constructors//
template <typename T>
TPoint<T>::TPoint(void) : abscisse(T()), ordonnee(T()) {}

template <typename T>
TPoint<T>::TPoint(T abscisse, T ordonnee) {
    this->abscisse = abscisse;
    this->ordonnee = ordonnee;
}

template <typename T>
TPoint<T>::TPoint(const TPoint& p) {
    this->abscisse = p.abscisse;
    this->ordonnee = p.ordonnee;
}

//Setters and getters//
template <typename T>
void TPoint<T>::setAbscisse(T abscisse) {
    this->abscisse = abscisse;
}

template <typename T>
void TPoint<T>::setOrdonnee(T ordonne) {
    this->ordonnee = ordonne;
}

template <typename T>
T TPoint<T>::getAbscisse(void) {
    return this->abscisse;
}

template <typename T>
T TPoint<T>::getOrdonnee(void) {
    return this->ordonnee;
}

//Methods//

template <typename T> 
void TPoint<T>::translate(std::pair<T, T> cordonnees){
    setAbscisse(cordonnees.first + getAbscisse());
    setOrdonnee(cordonnees.second + getOrdonnee());
}


// Destructeur//

template<typename T>
TPoint<T>::~TPoint(void){}


// Affichage //
template<typename T>
std::ostream &operator<< (std::ostream &s, TPoint<T> const &point){
    s << "Abscisse : " << point.abscisse << "\n";
    s << "Ordonnee : " << point.ordonnee << "\n";
    return s
}