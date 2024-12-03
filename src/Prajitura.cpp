#include "Prajitura.h"
#include <iostream>

Prajitura::Prajitura(const std::string& nume, std::unique_ptr<Blat> blat, std::unique_ptr<Crema> crema, std::unique_ptr<Fructe> fructe)
    : nume(nume), blat(std::move(blat)), crema(std::move(crema)), fructe(std::move(fructe)) {
    std::cout << "Prajitura creată: " << nume << std::endl;
}

// Getters
/*
Blat* Prajitura::getBlat() const { return blat.get(); }
Crema* Prajitura::getCrema() const { return crema.get(); }
Fructe* Prajitura::getFructe() const { return fructe.get(); }
*/
std::string Prajitura::getNume() const {return nume;}

void Prajitura::afiseazaPrajitura() const {
    std::cout << "Prajitura: " << nume << std::endl;

    if (blat) {
        blat->afiseazaIngrediente();
    } else {
        std::cout << "Blatul este gol." << std::endl;
    }

    if (crema) {
        crema->afiseazaIngrediente();
    } else {
        std::cout << "Crema este goala." << std::endl;
    }

    if (fructe) {
        fructe->afiseazaIngrediente();
    } else {
        std::cout << "Fructele sunt goale." << std::endl;
    }
}
