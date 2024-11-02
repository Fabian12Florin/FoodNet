#include "Fructe.h"
#include <iostream>

Fructe::Fructe() {}

Fructe::~Fructe() {
    for (auto ingredient : ingrediente) {
        delete ingredient;
    }
    ingrediente.clear();
}

Fructe::Fructe(const Fructe& other) {
    for (const auto& ingredient : other.ingrediente) {
        ingrediente.push_back(new Ingredient(*ingredient));
    }
}

void Fructe::adaugaIngredient(const Ingredient& ingredient) {
    ingrediente.push_back(new Ingredient(ingredient));
}

void Fructe::afiseazaFructe() const {
    std::cout << "Ingrediente Fructe:" << std::endl;
    for (const auto& ingredient : ingrediente) {
        ingredient->afiseazaIngredient();
    }
}