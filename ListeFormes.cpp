#include "ListeFormes.hpp"
#include "Cercle.hpp"
#include <iostream>
#include <limits>
#include <cmath>

// Constructeur
ListeFormes::ListeFormes() {
}

// Destructeur
ListeFormes::~ListeFormes() {
    // Libère toutes les formes allouées dynamiquement
    for (size_t i = 0; i < formes.size(); i++) {
        delete formes[i];
    }
    formes.clear();
}

// Ajouter une forme
void ListeFormes::ajouter(Forme* f) {
    if (f != nullptr) {
        formes.push_back(f);
    }
}

// Obtenir une forme par index
Forme* ListeFormes::get(int index) const {
    if (index >= 0 && index < static_cast<int>(formes.size())) {
        return formes[index];
    }
    return nullptr;
}

// Taille de la liste
int ListeFormes::taille() const {
    return formes.size();
}

// Vérifier si vide
bool ListeFormes::estVide() const {
    return formes.empty();
}

// Supprimer une forme par index
void ListeFormes::supprimer(int index) {
    if (index >= 0 && index < static_cast<int>(formes.size())) {
        delete formes[index];
        formes.erase(formes.begin() + index);
    }
}

// Vider la liste
void ListeFormes::vider() {
    for (size_t i = 0; i < formes.size(); i++) {
        delete formes[i];
    }
    formes.clear();
}

// Calculer la surface totale
float ListeFormes::surfaceTotale() const {
    float total = 0.0f;
    for (size_t i = 0; i < formes.size(); i++) {
        total += formes[i]->surface();
    }
    return total;
}

// Calculer le périmètre total
float ListeFormes::perimetreTotal() const {
    float total = 0.0f;
    for (size_t i = 0; i < formes.size(); i++) {
        total += formes[i]->perimetre();
    }
    return total;
}

// Calculer la boîte englobante
BoiteEnglobante ListeFormes::boiteEnglobante() const {
    if (formes.empty()) {
        return BoiteEnglobante(0, 0, 0, 0);
    }
    
    float xMin = std::numeric_limits<float>::max();
    float xMax = std::numeric_limits<float>::lowest();
    float yMin = std::numeric_limits<float>::max();
    float yMax = std::numeric_limits<float>::lowest();
    
    for (size_t i = 0; i < formes.size(); i++) {
        Point centre = formes[i]->getCentre();
        float cx = centre.getx();
        float cy = centre.gety();
        
        // Déterminer les limites selon le type de forme
        // On utilise dynamic_cast pour identifier le type
        
        if (Cercle* cercle = dynamic_cast<Cercle*>(formes[i])) {
            // Pour un cercle
            float rayon = cercle->getRayon();
            xMin = std::min(xMin, cx - rayon);
            xMax = std::max(xMax, cx + rayon);
            yMin = std::min(yMin, cy - rayon);
            yMax = std::max(yMax, cy + rayon);
        }
        else if (Rectangle* rect = dynamic_cast<Rectangle*>(formes[i])) {
            // Pour un rectangle ou carré
            float demiLargeur = rect->getLargeur() / 2.0f;
            float demiHauteur = rect->getHauteur() / 2.0f;
            xMin = std::min(xMin, cx - demiLargeur);
            xMax = std::max(xMax, cx + demiLargeur);
            yMin = std::min(yMin, cy - demiHauteur);
            yMax = std::max(yMax, cy + demiHauteur);
        }
    }
    
    return BoiteEnglobante(xMin, xMax, yMin, yMax);
}

// Afficher toutes les formes
void ListeFormes::afficher() const {
    std::cout << "Liste de " << formes.size() << " forme(s):" << std::endl;
    for (size_t i = 0; i < formes.size(); i++) {
        std::cout << "  [" << i << "] " << *formes[i] << std::endl;
    }
}

// Surcharge de l'opérateur 
std::ostream& operator<<(std::ostream& os, const ListeFormes& liste) {
    os << "ListeFormes [" << liste.taille() << " forme(s), "
       << "Surface totale: " << liste.surfaceTotale() << "]";
    return os;
}

// Surcharge de l'opérateur << pour BoiteEnglobante
std::ostream& operator<<(std::ostream& os, const BoiteEnglobante& boite) {
    os << "BoiteEnglobante ["
       << "xMin: " << boite.xMin << ", "
       << "xMax: " << boite.xMax << ", "
       << "yMin: " << boite.yMin << ", "
       << "yMax: " << boite.yMax << ", "
       << "Largeur: " << boite.largeur() << ", "
       << "Hauteur: " << boite.hauteur() << ", "
       << "Centre: " << boite.centre() << "]";
    return os;
}