// VWPassat.h
#pragma once
#include "Automobil.h"

class VWPassat : public Automobil {
public:
    static VWPassat* getInstance(const std::string& combustibil, const std::string& tractiune,
        int putere, const std::string& echipare, const char* vin,
        int numarPortiere);

    // Constructorul de copiere
    VWPassat(const VWPassat& other);

    // Operatorul de atribuire
    VWPassat& operator=(const VWPassat& other);

    // Constructorul de mutare
    VWPassat(VWPassat&& other) noexcept;

    // Operatorul de atribuire de mutare
    VWPassat& operator=(VWPassat&& other) noexcept;

    // Destructor
    ~VWPassat();

    void printInfo() const override;

private:
    // Constructorul privat pentru a preveni crearea directa a obiectelor
    VWPassat(const std::string& combustibil, const std::string& tractiune,
        int putere, const std::string& echipare, const char* vin,
        int numarPortiere);

    // Membru specific pentru clasa VWPassat
    int numarPortiere;

    // Membru static pentru instanța unica
    static VWPassat* instantaUnica;
};
