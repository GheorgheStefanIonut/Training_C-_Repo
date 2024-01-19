#include <iostream>
#include "Automobil.h"
#include "VWPassat.h"
#include "VWArteon.h"
#include "Utility.h"

int main() {
    // Creare obiect VWPassat
    VWPassat* passat = VWPassat::getInstance("Benzina", "Spate", 150, "Standard", "1GNEK13ZX3R298980", 4);

    // Creare obiect VWArteon
    VWArteon arteon("Motorina", "Sport", 200, "Premium", "1GNEK13ZX3R298984", true);

    // Afisare informatii VWPassat
    passat->printInfo();
    std::cout << std::endl;

    // Afisare informatii VWArteon
    arteon.printInfo();
    std::cout << std::endl;

    // Eliberare memorie VWPassat
    delete passat;

    // Afisare mesaj
    std::cout << std::endl;
    Utility::printCustom("What do you want?");

    // Calcul medie
    double rezult = Utility::getAvr(10.5, 20.5);

    std::cout << "Media numerelor este: " << rezult << std::endl;

    return 0;
}