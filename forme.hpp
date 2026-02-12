#ifndef FORME_HPP
#define FORME_HPP

#include "point.hpp"
#include <iostream>

class Forme {
protected:
    Point centre;

public:
    // Constructeur
    Forme(const Point& p);
    Forme(float x = 0.0f, float y = 0.0f);
    
    // Destructeur virtuel
    virtual ~Forme();
    
    // Surcharge de l'opérateur += pour la translation
    Forme& operator+=(const Point& p);
    
    Point getCentre() const;
    
    virtual float perimetre() const = 0;
    virtual float surface() const = 0;
    
    friend std::ostream& operator<<(std::ostream& os, const Forme& f);
};

std::ostream& operator<<(std::ostream& os, const Forme& f);

#endif