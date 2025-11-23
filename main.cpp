#include <cassert>
#include <iostream>

#include "TPoint.hpp"
#include "TForme.hpp"
#include "TRectangle.hpp"
#include "TCarre.hpp"
#include "ListeFormes.hpp"
#include <climits>

//     TEST TPOINT<T>
void test_TPoint_constructor()
{
    TPoint<int> p(3, 5);
    assert(p.getAbscisse() == 3);
    assert(p.getOrdonnee() == 5);

    TPoint<int> q(p);
    assert(q.getAbscisse() == 3);
    assert(q.getOrdonnee() == 5);

    TPoint<double> d(2.5, -1.5);
    assert(d.getAbscisse() == 2.5);
    assert(d.getOrdonnee() == -1.5);

    // Valeurs limites
    TPoint<int> lim(INT_MAX, INT_MIN);
    assert(lim.getAbscisse() == INT_MAX);
    assert(lim.getOrdonnee() == INT_MIN);
}

void test_TPoint_translate()
{
    TPoint<int> p(10, 20);
    p.translate({-5, 5});
    assert(p.getAbscisse() == 5);
    assert(p.getOrdonnee() == 25);

    // Cas limite : translation nulle
    TPoint<int> q(1, 1);
    q.translate({0, 0});
    assert(q.getAbscisse() == 1);
    assert(q.getOrdonnee() == 1);

    // Translation très grande
    TPoint<long long> b(0, 0);
    b.translate({LLONG_MAX, LLONG_MIN});
    assert(b.getAbscisse() == LLONG_MAX);
    assert(b.getOrdonnee() == LLONG_MIN);
}

void test_TPoint_string_specialization()
{
    TPoint<std::string> p("A", "B");
    p.translate({"X", "Y"}); // swap implémenté
    assert(p.getAbscisse() == "X");
    assert(p.getOrdonnee() == "Y");
}

//     TEST TRECTANGLE<T>
void test_TRectangleNormal()
{
    TRectangle<double> r(TPoint<double>(0, 0), 10.0, 4.0);

    assert(r.getLargeur() == 10.0);
    assert(r.getHauteur() == 4.0);

    assert(r.surface() == 40.0);
    assert(r.perimetre() == 28.0);
}

void test_TRectangleLimite()
{
    // Largeur zéro
    TRectangle<double> r1(TPoint<double>(0, 0), 0, 5);
    assert(r1.surface() == 0);
    assert(r1.perimetre() == 10);

    // Hauteur négative (si accepté)
    TRectangle<double> r2(TPoint<double>(0, 0), -3, 6);
    assert(r2.getLargeur() == -3);
    assert(r2.surface() == -18); // comportement mathématique brut
}

//     TEST TCarre<T>
void test_TCarreNormal()
{
    TCarre<double> c(TPoint<double>(1, 1), 4.0);

    assert(c.getLargeur() == 4.0);
    assert(c.getHauteur() == 4.0);
    assert(c.surface() == 16.0);
    assert(c.perimetre() == 16.0);
}

void test_TCarreLimite()
{
    TCarre<int> c(TPoint<int>(0, 0), 0);
    assert(c.surface() == 0);
    assert(c.perimetre() == 0);
}

//     TEST ListeFormes<T>
void test_ListeFormesSurface()
{
    ListeFormes<double> liste;

    TRectangle<double> r1(TPoint<double>(0, 0), 10, 2);
    TCarre<double> c1(TPoint<double>(2, 1), 4);

    liste.ajouter(&r1);
    liste.ajouter(&c1);

    assert(liste.surfaceTotale() == r1.surface() + c1.surface());
}

void test_ListeFormesEnglobante()
{
    ListeFormes<double> liste;

    TRectangle<double> r1(TPoint<double>(0, 0), 4, 4);
    // étendu de -2 à +2
    TCarre<double> c1(TPoint<double>(5, 0), 4);
    // étendu de 3 à 7

    liste.ajouter(&r1);
    liste.ajouter(&c1);

    TRectangle<double> box = liste.boiteEnglobante();

    // La boîte doit aller de x=-2 à x=7 = largeur = 9
    // et de y=-2 à +2 = hauteur = 4

    assert(box.getLargeur() == 9);
    assert(box.getHauteur() == 4);

    assert(box.getCentre().getAbscisse() == 2.5); // milieu entre -2 et +7
    assert(box.getCentre().getOrdonnee() == 0);
}

//     MAIN = lance tous les tests
int main()
{
    std::cout << "Lancement des tests" << std::endl;

    test_TPoint_constructor();
    test_TPoint_translate();
    test_TPoint_string_specialization();

    test_TRectangleNormal();
    test_TRectangleLimite();

    test_TCarreNormal();
    test_TCarreLimite();

    test_ListeFormesSurface();
    test_ListeFormesEnglobante();

    std::cout << "TEST: OK" << std::endl;

    return 0;
}
