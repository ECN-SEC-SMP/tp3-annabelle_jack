# Compte Rendu TP3 - Templates
**Jack et Annabelle**

## Objectif
Manipulation de classes templates avec héritage et surcharge d'opérateurs.

## Diagramme de classes
![Diagramme de classes](image.png)


### Classe TPoint<T>
Classe template permet de faire un objet point 2D (abscisse, ordonnée) avec un template.

### Classe TForme<T>
Classe abstraite template contenant un centre (`TPoint<T>`). Définit deux méthodes virtuelles pures : `surface()` et `perimetre()`.

### Classes TRectangle<T> et TCarre<T>
Classes filles de `TForme<T>` qui implémentent `surface()` et `perimetre()` :
- **TRectangle** : longueur × largeur
- **TCarre** : côté²

### Spécialisation

### Liste de formes 