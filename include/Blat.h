#pragma once
#include "ComponentaCuIngrediente.h"

class Blat : public ComponentaCuIngrediente {
public:
    Blat() = default;

    void afiseazaIngrediente() const override {
        std::cout << "Ingrediente Blat:" << std::endl;
        ComponentaCuIngrediente::afiseazaIngrediente();
    }
};