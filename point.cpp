#include "point.hpp"


// Constructeur par défaut
Point::Point(){
    this->x = 0.;
    this->y = 0.;
}

// Constructeur avec paramètres
Point::Point(float xx, float yy){
    this->x = xx;
    this->y = yy;
}

// Constructeur de recopie
Point::Point(const Point& p){
    this->x = p.x;
    this->y = p.y;
}


bool Point::translater(float xx, float yy){
    if(xx == 0 && yy == 0){
        return false;
    }else{
        this->x += xx;
        this->y += yy;
        return true;
    }
}

bool  Point::translater(Point p){
    if(p.getx() == 0 && p.gety() == 0){
        return false;
    }else{
        this->x += p.getx();
        this->y += p.gety();
        return true;
    }
}

float Point::getx(){
    return this->x;
}

float Point::gety(){
    return this->y;
}

void Point::modifx(float xx){
   this->x = xx;
}

void Point::modify(float yy){
    this->y = yy;
}

// Surcharge de l'opérateur += (MEMBRE de la classe)
Point& Point::operator+=(const Point& p) {
    this->translater(p);
    return *this;  // Retourne une référence à l'objet courant
}

// Surcharge de l'opérateur << (EXTERNE à la classe)
std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << "Point(" << p.x << ", " << p.y << ")";
    return os;  // Retourne le flux pour permettre le chaînage
}