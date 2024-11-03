#include "Prajitura.h"
#include <iostream>

// Constructor cu parametrii cu referinte constate pentru a evita copierea și a proteja obiectele primite
// : reprezinta o lista de initializare unde nu se mai aloca memorie pentru membrii const
// : mai este folosit deoarece se evita operatia de asignare(extra step) in constructorii parametrizati
Prajitura::Prajitura(const std::string& nume, const Blat& blat, const Crema& crema, const Fructe& fructe)
    : nume(nume), blat(new Blat(blat)), crema(new Crema(crema)), fructe(new Fructe(fructe)) {}

Prajitura::Prajitura(const Prajitura& other) : nume(other.nume) {
    blat = new Blat(*other.blat);
    crema = new Crema(*other.crema);
    fructe = new Fructe(*other.fructe);
}

Prajitura& Prajitura::operator=(const Prajitura& other) {
    // nu vrem ca un obiect sa faca copie dupa el insusi
    if (this != &other) {
        delete blat;
        delete crema;
        delete fructe;
        nume = other.nume;
        blat = new Blat(*other.blat);
        crema = new Crema(*other.crema);
        fructe = new Fructe(*other.fructe);
    }
    return *this;
}

Prajitura::~Prajitura() {
    delete blat;
    delete crema;
    delete fructe;
    std::cout << "Destructor apelat pentru Prajitura: " << nume << std::endl;
}

Blat* Prajitura::getBlat() const { return blat; }
Crema* Prajitura::getCrema() const { return crema; }
Fructe* Prajitura::getFructe() const { return fructe; }

void Prajitura::afiseazaPrajitura() const {
    std::cout << "Prajitura: " << nume << std::endl;
    blat->afiseazaIngrediente();
    crema->afiseazaIngrediente();
    fructe->afiseazaIngrediente();
}