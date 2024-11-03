#pragma once
#include "ComponentaCuIngrediente.h"

class Blat : public ComponentaCuIngrediente {
public:
    Blat() = default;
    Blat(const Blat& other) : ComponentaCuIngrediente(other) {}

    void afiseazaIngrediente() const override {
        std::cout << "Ingrediente Blat:" << std::endl;
        ComponentaCuIngrediente::afiseazaIngrediente();
    }
};