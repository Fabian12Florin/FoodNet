#pragma once
#include <string>
#include <memory>
#include "Blat.h"
#include "Crema.h"
#include "Fructe.h"

class Prajitura {
private:
    std::string nume;
    std::unique_ptr<Blat> blat;
    std::unique_ptr<Crema> crema;
    std::unique_ptr<Fructe> fructe;

public:
    Prajitura(const std::string& nume, std::unique_ptr<Blat> blat, std::unique_ptr<Crema> crema, std::unique_ptr<Fructe> fructe);
    Prajitura(const Prajitura&) = delete;             // Copy constructor dezactivat
    Prajitura& operator=(const Prajitura&) = delete;  // Operator de atribuire dezactivat
    ~Prajitura() = default;                          // Destructor implicit
    Prajitura(Prajitura&& other) noexcept = default; // Move constructor implicit

    /*
    Blat* getBlat() const;       // Pointer brut din `unique_ptr`
    Crema* getCrema() const;
    Fructe* getFructe() const;
    */
    std::string getNume() const;

    void afiseazaPrajitura() const;
};
