# TP7 - Gestion de Formes Géométriques

Projet de programmation orientée objet en C++ pour la gestion et la manipulation de formes géométriques.

## 📋 Description

Ce projet implémente un système de gestion de formes géométriques 2D en utilisant les concepts de la programmation orientée objet : héritage, polymorphisme et encapsulation. Il permet de créer, manipuler et analyser différentes formes géométriques (cercles, rectangles, carrés).

## 🎯 Fonctionnalités

- **Gestion de formes variées** : Support des cercles, rectangles et carrés
- **Calculs géométriques** : Calcul automatique des périmètres et surfaces
- **Liste dynamique** : Gestion d'une collection de formes avec ajout, suppression et consultation
- **Analyses avancées** :
  - Calcul de la surface totale
  - Calcul du périmètre total
  - Détermination de la boîte englobante (bounding box)
- **Manipulation des formes** : Translation des formes dans le plan 2D

## 🏗️ Structure du Projet

```
smp-tp7-parois_arimon-main/
│
├── point.hpp / point.cpp          # Classe Point : représentation d'un point 2D
├── forme.hpp / forme.cpp          # Classe abstraite Forme
├── Cercle.hpp / Cercle.cpp        # Classe Cercle
├── Rectangle.hpp / Rectangle.cpp  # Classe Rectangle
├── Carre.hpp / Carre.cpp          # Classe Carré
├── ListeFormes.hpp / ListeFormes.cpp  # Gestionnaire de collection de formes
├── main.cpp                       # Programme de test et démonstration
├── MAKEFILE                       # Fichier de compilation
└── tp-template.pdf                # Énoncé du TP
```

## 📐 Architecture des Classes

### Hiérarchie d'Héritage

```
Point
  └── Forme (classe abstraite)
       ├── Cercle
       └── Rectangle
            └── Carre
```

### Classes Principales

#### `Point`
Représente un point dans un plan 2D avec coordonnées (x, y).

#### `Forme` (abstraite)
Classe de base pour toutes les formes géométriques.
- **Attributs** : Point centre
- **Méthodes virtuelles pures** :
  - `float perimetre() const`
  - `float surface() const`
- **Opérateurs** : `+=` pour la translation

#### `Cercle`
Hérite de `Forme`.
- **Attributs** : rayon
- **Formules** :
  - Périmètre : 2π × rayon
  - Surface : π × rayon²

#### `Rectangle`
Hérite de `Forme`.
- **Attributs** : largeur, hauteur
- **Formules** :
  - Périmètre : 2 × (largeur + hauteur)
  - Surface : largeur × hauteur

#### `Carre`
Hérite de `Rectangle`.
- **Attributs** : côté (largeur = hauteur)
- Utilise les formules du rectangle

#### `ListeFormes`
Gestionnaire de collection utilisant `std::vector<Forme*>`.
- **Méthodes** :
  - `ajouter(Forme* f)` : Ajoute une forme
  - `supprimer(int index)` : Supprime une forme
  - `vider()` : Vide la liste
  - `get(int index)` : Accède à une forme
  - `taille()` : Retourne le nombre de formes
  - `surfaceTotale()` : Calcule la somme des surfaces
  - `perimetreTotal()` : Calcule la somme des périmètres
  - `boiteEnglobante()` : Calcule le rectangle englobant toutes les formes

#### `BoiteEnglobante`
Structure représentant un rectangle englobant.
- **Attributs** : xMin, xMax, yMin, yMax
- **Méthodes** : largeur(), hauteur(), centre()

## 🚀 Compilation et Exécution

### Prérequis
- Compilateur C++ supportant C++11 ou supérieur (g++, clang++)
- Make (optionnel)

### Compilation

#### Avec Make
```bash
make
```

#### Compilation manuelle
```bash
g++ -std=c++11 -Wall -Wextra -o main \
    point.cpp forme.cpp Cercle.cpp Rectangle.cpp \
    Carre.cpp ListeFormes.cpp main.cpp
```

### Exécution
```bash
./main
```

## 📊 Exemple d'Utilisation

```cpp
#include "ListeFormes.hpp"
#include "Cercle.hpp"
#include "Rectangle.hpp"
#include "Carre.hpp"

int main() {
    // Création d'une liste de formes
    ListeFormes liste;
    
    // Ajout de formes
    liste.ajouter(new Cercle(0, 0, 5.0f));
    liste.ajouter(new Rectangle(10, 10, 8.0f, 4.0f));
    liste.ajouter(new Carre(20, 20, 6.0f));
    
    // Affichage des formes
    liste.afficher();
    
    // Calculs
    std::cout << "Surface totale: " << liste.surfaceTotale() << std::endl;
    std::cout << "Périmètre total: " << liste.perimetreTotal() << std::endl;
    
    // Boîte englobante
    BoiteEnglobante boite = liste.boiteEnglobante();
    std::cout << "Boîte englobante: " << boite << std::endl;
    
    return 0;
}
```

## 🧪 Tests Inclus

Le fichier `main.cpp` contient une suite complète de tests :

1. **Test 1** : Création et ajout de formes
2. **Test 2** : Affichage de la liste
3. **Test 3** : Consultation des formes
4. **Test 4** : Calcul de surface totale
5. **Test 5** : Calcul de boîte englobante
6. **Test 6** : Calcul de périmètre total
7. **Test 7** : Suppression de formes
8. **Test 8** : Utilisation de l'opérateur <<
9. **Test 9** : Liste avec formes alignées
10. **Test 10** : Gestion de liste vide
11. **Test 11** : Vidage de la liste

## 🔍 Concepts C++ Utilisés

- **Programmation Orientée Objet** : Classes, héritage, polymorphisme
- **Méthodes virtuelles** : Fonctions virtuelles pures et destructeur virtuel
- **Conteneurs STL** : std::vector pour la gestion dynamique
- **Surcharge d'opérateurs** : `<<`, `+=`
- **Gestion mémoire** : Pointeurs et allocation dynamique
- **Const correctness** : Méthodes const, références const
- **Friend functions** : Pour les opérateurs de flux

## ⚠️ Notes Importantes

### Gestion de la Mémoire
La classe `ListeFormes` prend possession des pointeurs qui lui sont passés et gère leur destruction :
- Le destructeur libère automatiquement toutes les formes
- La méthode `supprimer()` libère la forme avant de la retirer
- La méthode `vider()` libère toutes les formes
