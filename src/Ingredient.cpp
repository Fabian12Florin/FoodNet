#include "Ingredient.h"
#include <iostream>

Ingredient::Ingredient(const std::string& nume, double cantitate, const std::string& unitate)
    : nume(nume), cantitate(cantitate), unitate(unitate) {}

std::string Ingredient::getNume() const { return nume; }
double Ingredient::getCantitate() const { return cantitate; }
std::string Ingredient::getUnitate() const { return unitate; }

void Ingredient::afiseazaIngredient() const {
    std::cout << nume << ": " << cantitate << " " << unitate << std::endl;
}