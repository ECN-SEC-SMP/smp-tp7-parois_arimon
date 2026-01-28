#include "ListeFormes.hpp"
#include "Cercle.hpp"
#include "Rectangle.hpp"
#include "Carre.hpp"
#include <iostream>

int main() {
    std::cout << "=== TEST DE LA CLASSE LISTEFORMES ===" << std::endl;
    
    // ===============================
    // Test 1 : Création et ajout
    // ===============================
    std::cout << "\n--- Test 1 : Création et ajout de formes ---" << std::endl;
    
    ListeFormes liste;
    
    std::cout << "Liste vide? " << (liste.estVide() ? "Oui" : "Non") << std::endl;
    std::cout << "Taille: " << liste.taille() << std::endl;
    
    // Ajout de formes
    liste.ajouter(new Cercle(0, 0, 5.0f));
    liste.ajouter(new Rectangle(10, 10, 8.0f, 4.0f));
    liste.ajouter(new Carre(20, 20, 6.0f));
    liste.ajouter(new Cercle(Point(-5, 5), 3.0f));
    
    std::cout << "\nAprès ajout de 4 formes:" << std::endl;
    std::cout << "Liste vide? " << (liste.estVide() ? "Oui" : "Non") << std::endl;
    std::cout << "Taille: " << liste.taille() << std::endl;
    
    // ===============================
    // Test 2 : Affichage de la liste
    // ===============================
    std::cout << "\n--- Test 2 : Affichage de la liste ---" << std::endl;
    liste.afficher();
    
    // ===============================
    // Test 3 : Consultation
    // ===============================
    std::cout << "\n--- Test 3 : Consultation des formes ---" << std::endl;
    
    for (int i = 0; i < liste.taille(); i++) {
        Forme* f = liste.get(i);
        if (f != nullptr) {
            std::cout << "Forme " << i << ": " << *f << std::endl;
            std::cout << "  Périmètre: " << f->perimetre() << std::endl;
            std::cout << "  Surface: " << f->surface() << std::endl;
        }
    }
    
    // ===============================
    // Test 4 : Surface totale
    // ===============================
    std::cout << "\n--- Test 4 : Surface totale ---" << std::endl;
    
    float surfaceTot = liste.surfaceTotale();
    std::cout << "Surface totale de toutes les formes: " << surfaceTot << std::endl;
    
    // Vérification manuelle
    std::cout << "\nVérification:" << std::endl;
    std::cout << "  Cercle 1 (r=5): " << liste.get(0)->surface() << std::endl;
    std::cout << "  Rectangle (8x4): " << liste.get(1)->surface() << std::endl;
    std::cout << "  Carré (6x6): " << liste.get(2)->surface() << std::endl;
    std::cout << "  Cercle 2 (r=3): " << liste.get(3)->surface() << std::endl;
    float somme = liste.get(0)->surface() + liste.get(1)->surface() + 
                  liste.get(2)->surface() + liste.get(3)->surface();
    std::cout << "  Somme manuelle: " << somme << std::endl;
    
    // ===============================
    // Test 5 : Boîte englobante
    // ===============================
    std::cout << "\n--- Test 5 : Boîte englobante ---" << std::endl;
    
    BoiteEnglobante boite = liste.boiteEnglobante();
    std::cout << boite << std::endl;
    
    std::cout << "\nDétails des formes:" << std::endl;
    std::cout << "  Cercle (0,0) rayon 5: occupe de (-5,-5) à (5,5)" << std::endl;
    std::cout << "  Rectangle (10,10) 8x4: occupe de (6,8) à (14,12)" << std::endl;
    std::cout << "  Carré (20,20) côté 6: occupe de (17,17) à (23,23)" << std::endl;
    std::cout << "  Cercle (-5,5) rayon 3: occupe de (-8,2) à (-2,8)" << std::endl;
    std::cout << "\nBoîte englobante attendue: de (-8,-5) à (23,23)" << std::endl;
    
    // ===============================
    // Test 6 : Périmètre total
    // ===============================
    std::cout << "\n--- Test 6 : Périmètre total ---" << std::endl;
    
    float perimetreTot = liste.perimetreTotal();
    std::cout << "Périmètre total: " << perimetreTot << std::endl;
    
    // ===============================
    // Test 7 : Suppression
    // ===============================
    std::cout << "\n--- Test 7 : Suppression ---" << std::endl;
    
    std::cout << "Avant suppression:" << std::endl;
    liste.afficher();
    
    std::cout << "\nSuppression de la forme à l'index 1 (Rectangle)..." << std::endl;
    liste.supprimer(1);
    
    std::cout << "Après suppression:" << std::endl;
    liste.afficher();
    std::cout << "Nouvelle taille: " << liste.taille() << std::endl;
    std::cout << "Nouvelle surface totale: " << liste.surfaceTotale() << std::endl;
    
    // ===============================
    // Test 8 : Opérateur 
    // ===============================
    std::cout << "\n--- Test 8 : Opérateur << ---" << std::endl;
    
    std::cout << liste << std::endl;
    
    // ===============================
    // Test 9 : Nouvelle liste avec formes alignées
    // ===============================
    std::cout << "\n--- Test 9 : Liste avec formes alignées ---" << std::endl;
    
    ListeFormes liste2;
    liste2.ajouter(new Rectangle(0, 0, 10.0f, 10.0f));
    liste2.ajouter(new Rectangle(15, 0, 10.0f, 10.0f));
    liste2.ajouter(new Rectangle(30, 0, 10.0f, 10.0f));
    
    std::cout << "Liste de 3 rectangles alignés horizontalement:" << std::endl;
    liste2.afficher();
    
    BoiteEnglobante boite2 = liste2.boiteEnglobante();
    std::cout << "\nBoîte englobante:" << std::endl;
    std::cout << boite2 << std::endl;
    
    // ===============================
    // Test 10 : Liste vide
    // ===============================
    std::cout << "\n--- Test 10 : Liste vide ---" << std::endl;
    
    ListeFormes listeVide;
    std::cout << "Surface totale d'une liste vide: " << listeVide.surfaceTotale() << std::endl;
    BoiteEnglobante boiteVide = listeVide.boiteEnglobante();
    std::cout << "Boîte englobante d'une liste vide: " << boiteVide << std::endl;
    
    // ===============================
    // Test 11 : Vider la liste
    // ===============================
    std::cout << "\n--- Test 11 : Vider la liste ---" << std::endl;
    
    std::cout << "Avant vidage: " << liste << std::endl;
    liste.vider();
    std::cout << "Après vidage: " << liste << std::endl;
    std::cout << "Liste vide? " << (liste.estVide() ? "Oui" : "Non") << std::endl;
    
    std::cout << "\n=== FIN DES TESTS ===" << std::endl;
    
    return 0;
}