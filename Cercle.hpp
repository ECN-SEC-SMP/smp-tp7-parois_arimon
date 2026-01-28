#ifndef CERCLE_HPP
#define CERCLE_HPP

#include "forme.hpp"
#include <cmath>

class Cercle : public Forme {
private:
    float rayon;

public:

    Cercle(const Point& centre, float r);
    Cercle(float x, float y, float r);
    
    // Implémentation des méthodes abstraites
    float perimetre() const override;
    float surface() const override;
    
    float getRayon() const;
    
    // Surcharge de l'opérateur 
    friend std::ostream& operator<<(std::ostream& os, const Cercle& c);
};

#endif