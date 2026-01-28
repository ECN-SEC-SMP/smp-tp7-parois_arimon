#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "forme.hpp"

class Rectangle : public Forme {
protected:
    float largeur;
    float hauteur;

public:
    // Constructeurs
    Rectangle(const Point& centre, float l, float h);
    Rectangle(float x, float y, float l, float h);
    
    // Implémentation des méthodes abstraites
    float perimetre() const override;
    float surface() const override;
    
    // Getters
    float getLargeur() const;
    float getHauteur() const;
    
    // Surcharge de l'opérateur 
    friend std::ostream& operator<<(std::ostream& os, const Rectangle& r);
};

#endif