#pragma once
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
    Prajitura(const Prajitura& other);
    ~Prajitura();

    Blat* getBlat() const;
    Crema* getCrema() const;
    Fructe* getFructe() const;

    void afiseazaPrajitura() const;
};