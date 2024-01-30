#pragma once
#include <string>

class Automobil {
public:
    // Constructor
    Automobil(const std::string& combustibil, const std::string& caroserie,
        const std::string& tractiune, int putere, const std::string& echipare, const char* vin);

    // Destructor 
    virtual ~Automobil();

    virtual void printInfo() const = 0;

protected:
    std::string combustibil;
    std::string caroserie;
    std::string tractiune;
    int putere;
    std::string echipare;
    const char* vin;
};