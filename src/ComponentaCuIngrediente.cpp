#include "ComponentaCuIngrediente.h"

ComponentaCuIngrediente& ComponentaCuIngrediente::operator+(const std::shared_ptr<Ingredient>& ingredient) {
    std::lock_guard<std::mutex> lock(mtx);
    ingrediente.push_back(ingredient);
    std::cout << "Ingredient adăugat: " << ingredient->getNume() << std::endl;
    return *this;
}

void ComponentaCuIngrediente::afiseazaIngrediente() const {
    std::lock_guard<std::mutex> lock(mtx);
    if (ingrediente.empty()) {
        std::cout << "Nu există ingrediente." << std::endl;
        return;
    }

    for (const auto& ingredient : ingrediente) {
        ingredient->afiseazaIngredient();
    }
}
