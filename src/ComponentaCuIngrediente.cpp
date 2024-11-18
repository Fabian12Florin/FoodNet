#include "ComponentaCuIngrediente.h"

ComponentaCuIngrediente::ComponentaCuIngrediente(const ComponentaCuIngrediente& other) {
    for (const auto& ingredient : other.ingrediente) {
        ingrediente.push_back(new Ingredient(*ingredient));
        // prin new Ingredient(*ingredient) se apeleaza un copy constructor implicit generat automat,
        // clasa Ingredient nu are definit unul explicit
    }
    std::cout << "Copy constructor ComponentaCuIngrediente. Nr ingrediente : "  << other.ingrediente.size() << std::endl;
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

// Move constructor
ComponentaCuIngrediente::ComponentaCuIngrediente(ComponentaCuIngrediente&& other) noexcept {
    // Mutam resursele (ingredientele) din obiectul sursa
    ingrediente = std::move(other.ingrediente);

    // Resetam obiectul sursa pentru a nu elibera memoria duplicat
    other.ingrediente.clear();

    std::cout << "Move constructor apelat pentru ComponentaCuIngrediente." << std::endl;
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
    std::cout << "Ingredient adăugat folosind operatorul +: " 
              << ingredient.getNume() << " (" << ingredient.getCantitate() 
              << " " << ingredient.getUnitate() << ")" << std::endl;
    return *this;
}

void ComponentaCuIngrediente::afiseazaIngrediente() const {
    if (ingrediente.empty()) { // Verificam daca vectorul este gol
        std::cout << "Nu există ingrediente." << std::endl;
        return;
    }

    // Afisam fiecare ingredient
    for (const auto& ingredient : ingrediente) {
        ingredient->afiseazaIngredient();
    }
}
