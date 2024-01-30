#include "Automobil.h"
#include <iostream>

// Implementarea constructorului
Automobil::Automobil(const std::string& combustibil, const std::string& caroserie,
    const std::string& tractiune, int putere, const std::string& echipare, const char* vin)
    : combustibil(combustibil), caroserie(caroserie), tractiune(tractiune),
    putere(putere), echipare(echipare), vin(vin) {
    std::cout << "Se apeleaza constructorul Automobil" << std::endl;
}

// Implementarea destructorului
Automobil::~Automobil() {
    std::cout << "Se apeleaza destructorului Automobil" << std::endl;
}