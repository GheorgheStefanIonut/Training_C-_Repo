#pragma once
#include <iostream>

class Utility {
public:
    // afisarea unui mesaj custom
    static void printCustom(const std::string& mesaj);

    // calcul media a 2 numere
    static double getAvr(double numar1, double numar2);
};
