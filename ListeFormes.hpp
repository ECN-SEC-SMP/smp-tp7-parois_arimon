#ifndef LISTEFORMES_HPP
#define LISTEFORMES_HPP

#include "forme.hpp"
#include "Rectangle.hpp"
#include <vector>

// Structure pour représenter une boîte englobante
struct BoiteEnglobante {
    float xMin;
    float xMax;
    float yMin;
    float yMax;
    
    // Constructeur
    BoiteEnglobante(float xmin = 0, float xmax = 0, float ymin = 0, float ymax = 0)
        : xMin(xmin), xMax(xmax), yMin(ymin), yMax(ymax) {}
    
    // Largeur et hauteur
    float largeur() const { return xMax - xMin; }
    float hauteur() const { return yMax - yMin; }
    
    // Centre
    Point centre() const {
        return Point((xMin + xMax) / 2.0f, (yMin + yMax) / 2.0f);
    }
};

class ListeFormes {
private:
    std::vector<Forme*> formes;

public:
    ListeFormes();
    ~ListeFormes();
    
    void ajouter(Forme* f);
    
    Forme* get(int index) const;
    int taille() const;
    bool estVide() const;
    
    void supprimer(int index);
    void vider();

    float surfaceTotale() const;
    BoiteEnglobante boiteEnglobante() const;
    float perimetreTotal() const;
    
    void afficher() const;
    
    friend std::ostream& operator<<(std::ostream& os, const ListeFormes& liste);
};

std::ostream& operator<<(std::ostream& os, const BoiteEnglobante& boite);

#endif