#include "VWPassat.h"
#include <iostream>

// Initializare cu nullptr
VWPassat* VWPassat::instantaUnica = nullptr;

// Implementarea functiei
VWPassat* VWPassat::getInstance(const std::string& combustibil, const std::string& tractiune,
    int putere, const std::string& echipare, const char* vin,
    int numarPortiere) {
    if (!instantaUnica) {
        instantaUnica = new VWPassat(combustibil, tractiune, putere, echipare, vin, numarPortiere);
    }
    return instantaUnica;
}

// Constructorul de copiere
VWPassat::VWPassat(const VWPassat& other)
    : Automobil(other), numarPortiere(other.numarPortiere) {}

// Operatorul de atribuire
VWPassat& VWPassat::operator=(const VWPassat& other) {
    if (this != &other) {
        Automobil::operator=(other); // Apelează operatorul de atribuire al clasei de bază
        numarPortiere = other.numarPortiere;
    }
    return *this;
}

// Constructorul de mutare
VWPassat::VWPassat(VWPassat&& other) noexcept
    : Automobil(std::move(other)), numarPortiere(std::exchange(other.numarPortiere, 0)) {}

// Operatorul de atribuire de mutare
VWPassat& VWPassat::operator=(VWPassat&& other) noexcept {
    if (this != &other) {
        Automobil::operator=(std::move(other)); // Apelează operatorul de atribuire al clasei de bază
        numarPortiere = std::exchange(other.numarPortiere, 0);
    }
    return *this;
}

// Implementarea destructorului
VWPassat::~VWPassat() {}

// Implementarea constructorului privat
VWPassat::VWPassat(const std::string& combustibil, const std::string& tractiune,
    int putere, const std::string& echipare, const char* vin,
    int numarPortiere)
    : Automobil(combustibil, "Sedan", tractiune, putere, echipare, vin),
    numarPortiere(numarPortiere) {
    std::cout << "Se apeleaza constructorul Passat" << std::endl;
    }

// Suprascrierea functiei
void VWPassat::printInfo() const {
    std::cout << "Marca: VW Passat" << std::endl;
    std::cout << "Combustibil: " << combustibil << std::endl;
    std::cout << "Caroserie: " << caroserie << std::endl;
    std::cout << "Tractiune: " << tractiune << std::endl;
    std::cout << "Putere: " << putere << " CP" << std::endl;
    std::cout << "Echipare: " << echipare << std::endl;
    std::cout << "VIN: " << vin << std::endl;
    std::cout << "Numar de portiere: " << numarPortiere << std::endl;
}
