#include "Prajitura.h"
#include "ManagerCofetarie.h"
#include "Ingredient.h"
#include <iostream>
#include <memory>
#include <thread>

int main() {
    auto blat = std::make_unique<Blat>();
    *blat + std::make_shared<Ingredient>("Faina", 500, "g") + std::make_shared<Ingredient>("Zahar", 200, "g");

    auto crema = std::make_unique<Crema>();
    *crema + std::make_shared<Ingredient>("Lapte", 300, "ml") + std::make_shared<Ingredient>("Frisca", 200, "ml");

    auto fructe = std::make_unique<Fructe>();
    *fructe + std::make_shared<Ingredient>("Capsuni", 100, "g");

    auto tort = std::make_shared<Prajitura>("Tort de Ciocolată", std::move(blat), std::move(crema), std::move(fructe));

    ManagerCofetarie manager;
    manager.adaugaPrajitura(tort);

    std::thread t1([&manager]() { manager.afiseazaPrajituri(); });
    std::thread t2([&manager]() { manager.afiseazaPrajituri(); });

    t1.join();
    t2.join();

    return 0;
}
