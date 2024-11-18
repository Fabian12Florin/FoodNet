#include "Prajitura.h"
#include "Blat.h"
#include "Crema.h"
#include "Fructe.h"
#include "Ingredient.h"
#include <iostream>
#include <utility> // pentru std::move

int main() {
    // Creăm un obiect Blat și adăugăm ingrediente folosind operatorul +
    Blat blat;
    blat + Ingredient("Faina", 500, "g") + Ingredient("Zahar", 200, "g");
    blat.afiseazaIngrediente();
    std::cout << "--1--" << std::endl;

    // Utilizare copy constructor pentru Blat
    Blat blatCopy(blat);
    blatCopy.afiseazaIngrediente();
    blatCopy + Ingredient("Cacao", 50, "g");
    blatCopy.afiseazaIngrediente();
    std::cout << "--2--" << std::endl;

    // Atribuirea cu operatorul `=`
    Blat blatAtribuire;
    blatAtribuire = blat;
    blatAtribuire.afiseazaIngrediente();
    std::cout << "--3--" << std::endl;

    // Demonstrăm utilizarea move constructorului pentru Blat ***
    Blat blatMutat = std::move(blat); // Mutăm resursele din blat în blatMutat
    blatMutat.afiseazaIngrediente();
    std::cout << "După mutare, blat: " << std::endl;
    blat.afiseazaIngrediente(); // blat ar trebui să fie gol după mutare
    blatMutat.afiseazaIngrediente();
    std::cout << "--4--" << std::endl;

    // Creăm crema și fructele
    Crema crema;
    crema + Ingredient("Lapte", 300, "ml") + Ingredient("Frisca", 200, "ml");
    crema.afiseazaIngrediente();
    std::cout << "--5--" << std::endl;

    Fructe fructe;
    fructe + Ingredient("Afine", 50, "g");
    fructe.afiseazaIngrediente();
    std::cout << "--6--" << std::endl;

    // Creăm o prăjitură folosind Blat, Crema și Fructe
    Prajitura tort("Tort de Ciocolată", blatMutat, crema, fructe);
    tort.afiseazaPrajitura();
    std::cout << "--7--" << std::endl;

    // Cream o copie a prajiturii folosind copy constructor
    Prajitura tortCopie = tort;
    tortCopie.afiseazaPrajitura();
    std::cout << "--8--" << std::endl;

    // Demonstrăm utilizarea move constructorului pentru Prajitura
    Prajitura tortMutat = std::move(tort); // Mutăm resursele din tort în tortMutat
    tortMutat.afiseazaPrajitura();
    std::cout << "După mutare, tort: ";
    tort.afiseazaPrajitura(); // tort ar trebui să fie gol după mutare
    std::cout << "--9--" << std::endl;

    // Incercam sa utilizam operatorul + blocat
    //Prajitura tortFuratDeCiolacu = tortMutat + tortMutat; // Aceasta va genera o eroare de compilare


    return 0;
}
