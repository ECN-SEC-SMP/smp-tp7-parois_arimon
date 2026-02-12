#include "Cercle.hpp"

Cercle::Cercle(const Point& centre, float r) : Forme(centre) 
{
    rayon = r;
}

Cercle::Cercle(float x, float y, float r) : Forme(x, y) 
{
    rayon = r;
}

float Cercle::perimetre() const {
    return 2 * M_PI * this->rayon;
}

float Cercle::surface() const {
    return M_PI * this->rayon * this->rayon;
}

float Cercle::getRayon() const {
    return this->rayon;
}

std::ostream& operator<<(std::ostream& os, const Cercle& c) {
    os << "Cercle [Centre: " << c.centre 
       << ", Rayon: " << c.rayon << "]";
    return os;
}