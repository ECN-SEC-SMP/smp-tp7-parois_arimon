#include "Rectangle.hpp"

Rectangle::Rectangle(const Point& centre, float l, float h): Forme(centre){
    this->largeur = l;
    this->hauteur = h;
}

Rectangle::Rectangle(float x, float y, float l, float h): Forme(x, y){
    this->largeur = l;
    this->hauteur = h;
}

float Rectangle::perimetre() const {
    return 2 * (this->largeur + this->hauteur);
}

float Rectangle::surface() const {
    return this->largeur * this->hauteur;
}

float Rectangle::getLargeur() const {
    return this->largeur;
}

float Rectangle::getHauteur() const {
    return this->hauteur;
}

std::ostream& operator<<(std::ostream& os, const Rectangle& r) {
    os << "Rectangle [Centre: " << r.centre 
       << ", Largeur: " << r.largeur 
       << ", Hauteur: " << r.hauteur << "]";
    return os;
}