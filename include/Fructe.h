#pragma once
#include "ComponentaCuIngrediente.h"

class Fructe : public ComponentaCuIngrediente {
public:
    Fructe() = default;
    Fructe(const Fructe& other) : ComponentaCuIngrediente(other) {}

    void afiseazaIngrediente() const override {
        std::cout << "Ingrediente Fructe:" << std::endl;
        ComponentaCuIngrediente::afiseazaIngrediente();
    }
};