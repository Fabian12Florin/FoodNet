#pragma once
#include <vector>
#include "Ingredient.h"
#include <iostream>

class ComponentaCuIngrediente {
protected:
    std::vector<Ingredient*> ingrediente;

public:
    ComponentaCuIngrediente() = default; // Constructor implicit
    // Folosim const ca sa nu modificam obiectul other pe care il primim ca referinta
    ComponentaCuIngrediente(const ComponentaCuIngrediente& other);  // Copy constructor
    virtual ~ComponentaCuIngrediente(); // Eliberare memorie, metoda abstracta
    ComponentaCuIngrediente(ComponentaCuIngrediente&& other) noexcept; // Move constructor


    ComponentaCuIngrediente& operator=(const ComponentaCuIngrediente& other);  // Operator de atribuire =
    ComponentaCuIngrediente& operator+(const Ingredient& ingredient);          // Operatorul + pentru adăugare

    virtual void afiseazaIngrediente() const;  // Metodă de afișare a ingredientelor
};