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

    Blat* getBlat() const;       // Accesare Blat
    Crema* getCrema() const;     // Accesare Crema
    Fructe* getFructe() const;   // Accesare Fructe

    void afiseazaPrajitura() const;
};