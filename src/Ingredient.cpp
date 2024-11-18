#include "Ingredient.h"
#include <iostream>

// Folosim lista de initializare; Aceasta este utila in mai multe situatii. De exemplu:
// 1. Membrii const nu pot fi initializati prin atribuire, doar in lista de initializare
// 2. Daca o clasa derivata trebuie sa initializeze membrii clasei de baza
// 3. Membrii sunt initializati direct cu valorile furnizate în lista de initializare, altfel
//    se intializa un obiect gol iar apoi se facea atribuirea
Ingredient::Ingredient(const std::string& nume, double cantitate, const std::string& unitate)
    : nume(nume), cantitate(cantitate), unitate(unitate) {}

// const pentru a ne asigura ca nu modificam starea obiectului. Ne asiguram ca putem apela
// metodele si pe obiecte constante
std::string Ingredient::getNume() const { return nume; }
double Ingredient::getCantitate() const { return cantitate; }
std::string Ingredient::getUnitate() const { return unitate; }

void Ingredient::afiseazaIngredient() const {
    std::cout << nume << ": " << cantitate << " " << unitate << std::endl;
}