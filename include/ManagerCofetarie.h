#pragma once
#include <vector>
#include <memory>
#include <mutex>
#include "Prajitura.h"

class ManagerCofetarie {
private:
    std::vector<std::shared_ptr<Prajitura>> prajituri;
    std::mutex mtx;

public:
    void adaugaPrajitura(std::shared_ptr<Prajitura> prajitura) {
        std::lock_guard<std::mutex> lock(mtx);
        prajituri.push_back(prajitura);
        std::cout << "Prăjitura adăugată: " << prajitura->getNume() << "\n";
    }

    void afiseazaPrajituri() {
        std::lock_guard<std::mutex> lock(mtx);
        for (const auto& prajitura : prajituri) {
            prajitura->afiseazaPrajitura();
        }
    }
};
