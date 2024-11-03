#include "ComponentaCuIngrediente.h"

ComponentaCuIngrediente::ComponentaCuIngrediente(const ComponentaCuIngrediente& other) {
    for (const auto& ingredient : other.ingrediente) {
        ingrediente.push_back(new Ingredient(*ingredient));
    }
}

ComponentaCuIngrediente::~ComponentaCuIngrediente() {
    for (auto ingredient : ingrediente) {
        delete ingredient;
    }
    ingrediente.clear();
}

ComponentaCuIngrediente& ComponentaCuIngrediente::operator=(const ComponentaCuIngrediente& other) {
    if (this != &other) {
        for (auto ingredient : ingrediente) {
            delete ingredient;
        }
        ingrediente.clear();

        for (const auto& ingredient : other.ingrediente) {
            ingrediente.push_back(new Ingredient(*ingredient));
        }
    }
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