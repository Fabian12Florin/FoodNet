#include "Prajitura.h"
#include "Blat.h"
#include "Crema.h"
#include "Fructe.h"
#include "Ingredient.h"
#include <iostream>

int main() {
    // Creăm un obiect Blat și adăugăm ingrediente folosind operatorul +
    Blat blat;
    blat + Ingredient("Faina", 500, "g") + Ingredient("Zahar", 200, "g");
    blat.afiseazaIngrediente();
    std::cout << std::endl;

    // Utilizare copy constructor pentru Blat
    Blat blatCopy(blat);
    blatCopy.afiseazaIngrediente();
    blatCopy + Ingredient("Cacao", 50, "g");
    blatCopy.afiseazaIngrediente();
    std::cout << std::endl;

    // Atribuirea cu operatorul `=`
    Blat blatAtribuire;
    blatAtribuire = blat;
    blatAtribuire.afiseazaIngrediente();
    std::cout << std::endl;

    Crema crema;
    crema + Ingredient("Lapte", 300, "ml") + Ingredient("Frisca", 200, "ml");
    crema.afiseazaIngrediente();

    Fructe fructe;
    fructe + Ingredient("Capsuni", 100, "g") + Ingredient("Afine", 50, "g");
    fructe.afiseazaIngrediente();
    std::cout << std::endl;

    // Creăm o prăjitură folosind Blat, Crema și Fructe
    Prajitura tort("Tort de Ciocolată", blat, crema, fructe);
    tort.afiseazaPrajitura();

    std::cout << std::endl;

    // Creăm o copie a prăjiturii folosind copy constructor
    Prajitura tortCopie = tort;
    tortCopie.afiseazaPrajitura();

    return 0;
}