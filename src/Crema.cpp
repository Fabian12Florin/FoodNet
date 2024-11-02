#include "Crema.h"
#include <iostream>

Crema::Crema() {}

Crema::~Crema() {
    for (auto ingredient : ingrediente) {
        delete ingredient;
    }
    ingrediente.clear();
}

Crema::Crema(const Crema& other) {
    for (const auto& ingredient : other.ingrediente) {
        ingrediente.push_back(new Ingredient(*ingredient));
    }
}

void Crema::adaugaIngredient(const Ingredient& ingredient) {
    ingrediente.push_back(new Ingredient(ingredient));
}

void Crema::afiseazaCrema() const {
    std::cout << "Ingrediente Crema:" << std::endl;
    for (const auto& ingredient : ingrediente) {
        ingredient->afiseazaIngredient();
    }
}