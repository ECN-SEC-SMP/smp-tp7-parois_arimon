#include "point.hpp"
#include <iostream>

int main() {
    std::cout << "=== TEST DE L'OPÉRATEUR << ===" << std::endl;
    
    // Test 1 : Affichage simple
    Point p1(3.5f, 7.2f);
    std::cout << "p1 = " << p1 << std::endl;
    
    Point p2;
    std::cout << "p2 (défaut) = " << p2 << std::endl;
    
    // Test 2 : Chaînage de l'opérateur 
    Point p3(1.0f, 2.0f);
    Point p4(4.0f, 5.0f);
    std::cout << "p3 = " << p3 << " et p4 = " << p4 << std::endl;
    
    std::cout << "\n=== TEST DE L'OPÉRATEUR += ===" << std::endl;
    
    // Test 3 : Addition simple
    Point p5(10.0f, 20.0f);
    Point p6(5.0f, 3.0f);
    
    std::cout << "Avant: p5 = " << p5 << std::endl;
    std::cout << "       p6 = " << p6 << std::endl;
    
    p5 += p6;
    
    std::cout << "Après p5 += p6:" << std::endl;
    std::cout << "       p5 = " << p5 << std::endl;
    std::cout << "       p6 = " << p6 << " (inchangé)" << std::endl;
    
    // Test 4 : Chaînage de l'opérateur +=
    Point p7(1.0f, 1.0f);
    Point p8(2.0f, 2.0f);
    Point p9(3.0f, 3.0f);
    
    std::cout << "\nAvant: p7 = " << p7 << std::endl;
    std::cout << "       p8 = " << p8 << std::endl;
    std::cout << "       p9 = " << p9 << std::endl;
    
    p7 += p8 += p9;  // Chaînage possible car += retourne une référence
    
    std::cout << "Après p7 += p8 += p9:" << std::endl;
    std::cout << "       p7 = " << p7 << std::endl;
    std::cout << "       p8 = " << p8 << std::endl;
    std::cout << "       p9 = " << p9 << " (inchangé)" << std::endl;
    
    // Test 5 : Addition avec lui-même
    Point p10(5.0f, 5.0f);
    std::cout << "\nAvant: p10 = " << p10 << std::endl;
    p10 += p10;
    std::cout << "Après p10 += p10: p10 = " << p10 << std::endl;
    
    // Test 6 : Combinaison des deux opérateurs
    Point p11(100.0f, 200.0f);
    Point p12(50.0f, 25.0f);
    
    std::cout << "\n=== COMBINAISON DES OPÉRATEURS ===" << std::endl;
    std::cout << "p11 = " << p11 << std::endl;
    std::cout << "p12 = " << p12 << std::endl;
    std::cout << "Résultat de (p11 += p12) = " << (p11 += p12) << std::endl;
    std::cout << "p11 maintenant = " << p11 << std::endl;
    
    return 0;
}