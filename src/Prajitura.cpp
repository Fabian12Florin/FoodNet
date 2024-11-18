#include "Prajitura.h"
#include <iostream>

// Constructor cu parametrii cu referinte constate pentru a evita copierea și a proteja obiectele primite
// : reprezinta o lista de initializare unde nu se mai aloca memorie pentru membrii const
// : mai este folosit deoarece se evita operatia de asignare(extra step) in constructorii parametrizati
Prajitura::Prajitura(const std::string& nume, const Blat& blat, const Crema& crema, const Fructe& fructe)
    : nume(nume), blat(new Blat(blat)), crema(new Crema(crema)), fructe(new Fructe(fructe)) {}

Prajitura::Prajitura(const Prajitura& other) : nume(other.nume) {
    blat = other.blat ? new Blat(*other.blat) : nullptr;
    crema = other.crema ? new Crema(*other.crema) : nullptr;
    fructe = other.fructe ? new Fructe(*other.fructe) : nullptr;
    std::cout << "Copy constructor apelat pentru Prajitura: " << nume << std::endl;
}

Prajitura& Prajitura::operator=(const Prajitura& other) {
    // nu vrem ca un obiect sa faca copie dupa el insusi
    if (this != &other) {
        // Reconstruim fiecare membru utilizând placement new
        blat->~Blat();
        new (blat) Blat(*other.blat);

        crema->~Crema();
        new (crema) Crema(*other.crema);

        fructe->~Fructe();
        new (fructe) Fructe(*other.fructe);

        // Copiem numele direct, deoarece este gestionat automat
        nume = other.nume;
    }
    std::cout << "sadasd "<< std::endl;
    return *this;
}

Prajitura::~Prajitura() {
    delete blat;
    delete crema;
    delete fructe;
    std::cout << "Destructor apelat pentru Prajitura: " << nume << std::endl;
}

Prajitura::Prajitura(Prajitura&& other) noexcept
    : nume(std::move(other.nume)), blat(other.blat), crema(other.crema), fructe(other.fructe) {
    other.blat = nullptr;
    other.crema = nullptr;
    other.fructe = nullptr;

    std::cout << "Move constructor apelat pentru Prajitura: " << nume << std::endl;
}

Blat* Prajitura::getBlat() const { return blat; }
Crema* Prajitura::getCrema() const { return crema; }
Fructe* Prajitura::getFructe() const { return fructe; }

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
