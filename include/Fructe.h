#pragma once
#include <vector>
#include "Ingredient.h"

class Fructe {
private:
    std::vector<Ingredient*> ingrediente;

public:
    Fructe();
    ~Fructe();
    Fructe(const Fructe& other);

    void adaugaIngredient(const Ingredient& ingredient);
    void afiseazaFructe() const;
};