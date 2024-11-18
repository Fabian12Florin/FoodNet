#pragma once // Fișierul va fi procesat o singură dată de către compilator
#include <string>
#include "Blat.h"
#include "Crema.h"
#include "Fructe.h"

class Prajitura {
private:
    std::string nume;
    Blat* blat;
    Crema* crema;
    Fructe* fructe;

public:
    Prajitura(const std::string& nume, const Blat& blat, const Crema& crema, const Fructe& fructe);
    Prajitura(const Prajitura& other);             // Copy constructor
    Prajitura& operator=(const Prajitura& other);  // Operator de atribuire
    ~Prajitura();                                  // Destructor
    // noexcept spune compilatorului ca move constructorul nu va arunca exceptii;
    // daca el nu este folosit atunci, pentru siguranta, o sa se foloseasca copy constructor
    Prajitura(Prajitura&& other) noexcept;         // Move constructor

    Blat* getBlat() const;       // Accesare Blat
    Crema* getCrema() const;     // Accesare Crema
    Fructe* getFructe() const;   // Accesare Fructe

    void afiseazaPrajitura() const;
};