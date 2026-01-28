#ifndef CARRE_HPP
#define CARRE_HPP

#include "Rectangle.hpp"
#include "forme.hpp"

class Carre : public Rectangle {
public:
    Carre(const Point& centre, float cote);
    Carre(float x, float y, float cote);
    
    float getCote() const;

    friend std::ostream& operator<<(std::ostream& os, const Carre& c);
};

#endif