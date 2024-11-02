#include "Prajitura.h"
#include <iostream>

Prajitura::Prajitura(const std::string& nume, const Blat& blat, const Crema& crema, const Fructe& fructe)
    : nume(nume), blat(new Blat(blat)), crema(new Crema(crema)), fructe(new Fructe(fructe)) {}

Prajitura::Prajitura(const Prajitura& other) : nume(other.nume) {
    blat = new Blat(*other.blat);
    crema = new Crema(*other.crema);
    fructe = new Fructe(*other.fructe);
}

Prajitura::~Prajitura() {
    delete blat;
    delete crema;
    delete fructe;
}

Blat* Prajitura::getBlat() const { return blat; }
Crema* Prajitura::getCrema() const { return crema; }
Fructe* Prajitura::getFructe() const { return fructe; }

void Prajitura::afiseazaPrajitura() const {
    std::cout << "Prajitura: " << nume << std::endl;
    blat->afiseazaBlat();
    crema->afiseazaCrema();
    fructe->afiseazaFructe();
}