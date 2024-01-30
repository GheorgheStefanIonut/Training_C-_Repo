#include "VWArteon.h"
#include <iostream>

// Implementarea constructorului pentru clasa derivata VWArteon
VWArteon::VWArteon(const std::string& combustibil, const std::string& tractiune,
    int putere, const std::string& echipare, const char* vin,
    bool aerConditionat)
    : Automobil(combustibil, "Fastback", tractiune, putere, echipare, vin),
    aerConditionat(aerConditionat) {
    std::cout << "Se apeleaza constructorul Arteon" << std::endl;
    }

// Constructorul de copiere
VWArteon::VWArteon(const VWArteon& other)
    : Automobil(other) {}

// Operatorul de atribuire
VWArteon& VWArteon::operator=(const VWArteon& other) {
    if (this != &other) {
        Automobil::operator=(other); 
    }
    return *this;
}

// Constructorul de mutare
VWArteon::VWArteon(VWArteon&& other) noexcept
    : Automobil(std::move(other)) {}

// Operatorul de atribuire de mutare
VWArteon& VWArteon::operator=(VWArteon&& other) noexcept {
    if (this != &other) {
        Automobil::operator=(std::move(other)); 
    }
    return *this;
}

// Destructorul
VWArteon::~VWArteon() {}

// Suprascrierea 
void VWArteon::printInfo() const {
    std::cout << "Marca: VW Arteon" << std::endl;
    std::cout << "Combustibil: " << combustibil << std::endl;
    std::cout << "Caroserie: " << caroserie << std::endl;
    std::cout << "Tractiune: " << tractiune << std::endl;
    std::cout << "Putere: " << putere << " CP" << std::endl;
    std::cout << "Echipare: " << echipare << std::endl;
    std::cout << "VIN: " << vin << std::endl;
    std::cout << "Aer conditionat: " << (aerConditionat ? "Da" : "Nu") << std::endl;
}
