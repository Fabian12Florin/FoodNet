// pragma once previne includerea multipla a unui fisier header in timpul compilarii
#pragma once
#include <string>

class Ingredient {
private:
    std::string nume;
    double cantitate;
    std::string unitate;

public:
    Ingredient(const std::string& nume, double cantitate, const std::string& unitate);

    std::string getNume() const;
    double getCantitate() const;
    std::string getUnitate() const;

    void afiseazaIngredient() const;
};