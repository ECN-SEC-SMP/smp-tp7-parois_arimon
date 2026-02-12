#ifndef POINT_HPP
#define POINT_HPP
#include <iostream>
using namespace std;
class Point{
    private:
        float x;
        float y; 

    public:
        bool translater(float xx, float yy);
        bool translater(Point p);
        Point();
        Point(float xx, float yy);
        Point(const Point& p);
        float getx();
        float gety();
        void modifx(float xx);
        void modify(float yy);
        // Surcharge de l'opérateur += (MEMBRE de la classe)
        Point& operator+=(const Point& p);
    
        // Déclaration de l'opérateur << comme ami (EXTERNE à la classe)
        friend ostream& operator<<(ostream& os, const Point& p);
};
ostream& operator<<(ostream& os, const Point& p);
#endif