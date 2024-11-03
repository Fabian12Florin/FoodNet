#pragma once
#include "ComponentaCuIngrediente.h"

class Crema : public ComponentaCuIngrediente {
public:
    Crema() = default;
    Crema(const Crema& other) : ComponentaCuIngrediente(other) {}

    void afiseazaIngrediente() const override {
        std::cout << "Ingrediente Crema:" << std::endl;
        ComponentaCuIngrediente::afiseazaIngrediente();
    }
};