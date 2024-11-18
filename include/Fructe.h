#pragma once
#include "ComponentaCuIngrediente.h"

class Fructe : public ComponentaCuIngrediente {
public:
    Fructe() = default;

    void afiseazaIngrediente() const override {
        std::cout << "Ingrediente Fructe:" << std::endl;
        ComponentaCuIngrediente::afiseazaIngrediente();
    }
};