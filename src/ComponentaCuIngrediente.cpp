#include "ComponentaCuIngrediente.h"

ComponentaCuIngrediente::ComponentaCuIngrediente(const ComponentaCuIngrediente& other) {
    for (const auto& ingredient : other.ingrediente) {
        ingrediente.push_back(new Ingredient(*ingredient));
        // prin new Ingredient(*ingredient) se apeleaza un copy constructor implicit generat automat,
        // clasa Ingredient nu are definit unul explicit
    }
}

ComponentaCuIngrediente::~ComponentaCuIngrediente() {
    std::cout << "Stergem ingredientele: ";
    for (auto ingredient : ingrediente) {
        std::cout << ingredient->getNume() << " ";
        delete ingredient;
    }
    std::cout << std::endl;
    ingrediente.clear();
}

ComponentaCuIngrediente& ComponentaCuIngrediente::operator=(const ComponentaCuIngrediente& other) {
    if (this != &other) {
        // Eliberam resursele curente prin apelarea destructorului
        this->~ComponentaCuIngrediente();

        // Reconstruim obiectul curent folosind copy constructorul
        new (this) ComponentaCuIngrediente(other); // Placement new; obiect nou alocat in spatiul vechi

    }
    // Standard in c++ cand suprascriem operatorul; Astfel putem face apeluri in lant
    return *this;
}

ComponentaCuIngrediente& ComponentaCuIngrediente::operator+(const Ingredient& ingredient) {
    ingrediente.push_back(new Ingredient(ingredient));
    return *this;
}

void ComponentaCuIngrediente::afiseazaIngrediente() const {
    for (const auto& ingredient : ingrediente) {
        ingredient->afiseazaIngredient();
    }
}