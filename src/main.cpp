#include "Prajitura.h"
#include "Ingredient.h"

int main() {
    Blat blat;
    blat.adaugaIngredient(Ingredient("Făină", 500, "g"));
    blat.adaugaIngredient(Ingredient("Zahăr", 200, "g"));
    blat.adaugaIngredient(Ingredient("Cacao", 50, "g"));

    Crema crema;
    crema.adaugaIngredient(Ingredient("Lapte", 300, "ml"));
    crema.adaugaIngredient(Ingredient("Frișcă", 200, "ml"));
    crema.adaugaIngredient(Ingredient("Ciocolata", 100, "g"));

    Fructe fructe;
    fructe.adaugaIngredient(Ingredient("Capsuni", 100, "g"));
    fructe.adaugaIngredient(Ingredient("Afine", 50, "g"));

    Prajitura tort("Tort de Ciocolată", blat, crema, fructe);

    tort.afiseazaPrajitura();

    return 0;
}