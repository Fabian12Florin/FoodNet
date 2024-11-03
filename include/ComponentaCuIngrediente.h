#pragma once
#include <vector>
#include "Ingredient.h"
#include <iostream>

class ComponentaCuIngrediente {
protected:
    std::vector<Ingredient*> ingrediente;

public:
    ComponentaCuIngrediente() = default; // Constructor implicit
    ComponentaCuIngrediente(const ComponentaCuIngrediente& other);  // Copy constructor
    virtual ~ComponentaCuIngrediente(); // Eliberare memorie, metoda abstracta

    ComponentaCuIngrediente& operator=(const ComponentaCuIngrediente& other);  // Operator de atribuire =
    ComponentaCuIngrediente& operator+(const Ingredient& ingredient);          // Operatorul + pentru adăugare

    virtual void afiseazaIngrediente() const;  // Metodă de afișare a ingredientelor
};