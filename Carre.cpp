#include "Carre.hpp"

Carre::Carre(const Point& centre, float cote) : Rectangle(centre, cote, cote) 
{
}

// Constructeur avec coordonnées
Carre::Carre(float x, float y, float cote) : Rectangle(x, y, cote, cote) 
{
}

float Carre::getCote() const {
    return this->largeur;
}

std::ostream& operator<<(std::ostream& os, const Carre& c) {
    os << "Carré [Centre: " << c.centre 
       << ", Côté: " << c.largeur << "]";
    return os;
}