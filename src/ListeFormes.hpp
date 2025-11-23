#ifndef _LISTEFORMES_HPP
#define _LISTEFORMES_HPP

#include <vector>
#include <memory>
#include "TRectangle.hpp"
#include "TCarre.hpp"

template <typename T>
class ListeFormes
{
private:
    std::vector<TForme<T> *> formes;

public:
    // Ajouter une forme
    void ajouter(TForme<T> *f)
    {
        formes.push_back(f);
    }

    // Surface totale
    T surfaceTotale() const
    {
        T surface = 0;
        for (auto f : formes)
            surface += f->surface();
        return surface;
    }

    // Boîte englobante : retourne un TRectangle<T>
    TRectangle<T> boiteEnglobante() const
    {
        if (formes.empty())
            return TRectangle<T>(TPoint<T>(0, 0), 0, 0);

        // On initialise avec des valeurs extrêmes
        T minX = 1e9, minY = 1e9;
        T maxX = -1e9, maxY = -1e9;

        for (auto f : formes)
        {
            const TRectangle<T> *r = dynamic_cast<const TRectangle<T> *>(f);
            if (!r)
            {
                continue;
            }
            T cx = r->getCentre().getAbscisse();
            T cy = r->getCentre().getOrdonnee();

            T demiL = r->getLargeur() / 2;
            T demiH = r->getHauteur() / 2;

            minX = std::min(minX, cx - demiL);
            maxX = std::max(maxX, cx + demiL);

            minY = std::min(minY, cy - demiH);
            maxY = std::max(maxY, cy + demiH);
        }

        T largeur = maxX - minX;
        T hauteur = maxY - minY;

        TPoint<T> centre((minX + maxX) / 2, (minY + maxY) / 2);

        return TRectangle<T>(centre, largeur, hauteur);
    }
};

#endif
