#include "Utility.h"

void Utility::printCustom(const std::string& mesaj) {
    std::cout << mesaj << std::endl;
}

double Utility::getAvr(double numar1, double numar2) {
    return (numar1 + numar2) / 2.0;
}