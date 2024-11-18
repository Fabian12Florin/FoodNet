#pragma once
#include "ComponentaCuIngrediente.h"

class Crema : public ComponentaCuIngrediente {
public:
    Crema() = default;

    void afiseazaIngrediente() const override {
        std::cout << "Ingrediente Crema:" << std::endl;
        ComponentaCuIngrediente::afiseazaIngrediente();
    }
};