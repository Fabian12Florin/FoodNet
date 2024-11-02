#pragma once
#include <vector>
#include "Ingredient.h"

class Crema {
private:
    std::vector<Ingredient*> ingrediente;

public:
    Crema();
    ~Crema();
    Crema(const Crema& other);

    void adaugaIngredient(const Ingredient& ingredient);
    void afiseazaCrema() const;
};