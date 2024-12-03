#pragma once
#include <vector>
#include <memory>
#include <mutex>
#include <iostream>
#include "Ingredient.h"

class ComponentaCuIngrediente {
protected:
    std::vector<std::shared_ptr<Ingredient>> ingrediente; // Vector de shared_ptr pentru ingrediente
    mutable std::mutex mtx;

public:
    ComponentaCuIngrediente() = default; // Constructor implicit
    ComponentaCuIngrediente(const ComponentaCuIngrediente&) = delete;            // Copy constructor dezactivat
    ComponentaCuIngrediente& operator=(const ComponentaCuIngrediente&) = delete; // Operator de atribuire dezactivat
    ComponentaCuIngrediente(ComponentaCuIngrediente&&) noexcept = default;       // Move constructor implicit
    ComponentaCuIngrediente& operator=(ComponentaCuIngrediente&&) noexcept = default; // Move assignment operator
    virtual ~ComponentaCuIngrediente() = default;                                // Destructor implicit

    ComponentaCuIngrediente& operator+(const std::shared_ptr<Ingredient>& ingredient); // Adaugare ingredient
    virtual void afiseazaIngrediente() const;  // Metodă de afișare a ingredientelor
};
