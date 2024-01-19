#pragma once
#include "Automobil.h"

class VWArteon : public Automobil {
public:
    // Constructor
    VWArteon(const std::string& combustibil, const std::string& tractiune,
        int putere, const std::string& echipare, const char* vin,
        bool aerConditionat);

    // Constructorul de copiere
    VWArteon(const VWArteon& other);

    // Operatorul de atribuire
    VWArteon& operator=(const VWArteon& other);

    // Constructorul de mutare
    VWArteon(VWArteon&& other) noexcept;

    // Operatorul de atribuire de mutare
    VWArteon& operator=(VWArteon&& other) noexcept;

    // Destructorul
    ~VWArteon();

    // Suprascrierea 
    void printInfo() const override;

private:
    bool aerConditionat;
};

