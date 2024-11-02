#include "Blat.h"
#include <iostream>

Blat::Blat() {}

Blat::~Blat() {
    for (auto ingredient : ingrediente) {
        delete ingredient;
    }
    ingrediente.clear();
}

Blat::Blat(const Blat& other) {
    for (const auto& ingredient : other.ingrediente) {
        ingrediente.push_back(new Ingredient(*ingredient));
    }
}

void Blat::adaugaIngredient(const Ingredient& ingredient) {
    ingrediente.push_back(new Ingredient(ingredient));
}

void Blat::afiseazaBlat() const {
    std::cout << "Ingrediente Blat:" << std::endl;
    for (const auto& ingredient : ingrediente) {
        ingredient->afiseazaIngredient();
    }
}