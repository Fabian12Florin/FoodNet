#pragma once
#include <vector>
#include "Ingredient.h"

class Blat {
private:
    std::vector<Ingredient*> ingrediente;

public:
    Blat();
    ~Blat();
    Blat(const Blat& other);

    void adaugaIngredient(const Ingredient& ingredient);
    void afiseazaBlat() const;
};
