#include "forme.hpp"


Forme::Forme(const Point& p){
    centre = p;
}

Forme::Forme(float x, float y){
    centre.modifx(x);
    centre.modify(y);
}

Forme::~Forme() {}


Forme& Forme::operator+=(const Point& p) {
    centre += p;  // Utilise l'opérateur += de Point
    return *this;
}

Point Forme::getCentre() const {
    return centre;
}

std::ostream& operator<<(std::ostream& os, const Forme& f) {
    os << "Forme centrée en " << f.centre;
    os << " [Périmètre: " << f.perimetre() 
       << ", Surface: " << f.surface() << "]";
    return os;
}