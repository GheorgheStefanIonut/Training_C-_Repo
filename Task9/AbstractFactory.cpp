#include <iostream>

// Interfata PanoramicRoof
class PanoramicRoof {
public:
    virtual void installPanoramicRoof() = 0;
};

// Interfata AdaptiveHeadlights
class AdaptiveHeadlights {
public:
    virtual void installAdaptiveHeadlights() = 0;
};

// Implementare PanoramicRoof pentru VW
class VWPanoramicRoof : public PanoramicRoof {
public:
    void installPanoramicRoof() override {
        std::cout << "Panoramic Roof installed for VW.\n";
    }
};

// Implementare AdaptiveHeadlights pentru Audi
class AudiAdaptiveHeadlights : public AdaptiveHeadlights {
public:
    void installAdaptiveHeadlights() override {
        std::cout << "Adaptive Headlights installed for Audi.\n";
    }
};

// Interfata CarAccessoriesFactory
class CarAccessoriesFactory {
public:
    virtual PanoramicRoof* createPanoramicRoof() = 0;
    virtual AdaptiveHeadlights* createAdaptiveHeadlights() = 0;
};

// Implementare CarAccessoriesFactory pentru VW
class VWAccessoriesFactory : public CarAccessoriesFactory {
public:
    PanoramicRoof* createPanoramicRoof() override {
        return new VWPanoramicRoof();
    }

    AdaptiveHeadlights* createAdaptiveHeadlights() override {
        // Pentru VW, nu avem faruri adaptive, deci returnam nullptr
        return nullptr;
    }
};

// Implementare CarAccessoriesFactory pentru Audi
class AudiAccessoriesFactory : public CarAccessoriesFactory {
public:
    PanoramicRoof* createPanoramicRoof() override {
        // Pentru Audi, nu avem trapa panoramica, deci returnam nullptr
        return nullptr;
    }

    AdaptiveHeadlights* createAdaptiveHeadlights() override {
        return new AudiAdaptiveHeadlights();
    }
};

// Clientul care utilizeaza fabrica de accesorii auto pentru a instala si utiliza accesorii specifice
int main() {
    // Cream CarAccessoriesFactory pentru VW
    CarAccessoriesFactory* vwAccessoriesFactory = new VWAccessoriesFactory();

    // Utilizam fabrica pentru a crea accesorii concrete
    PanoramicRoof* vwPanoramicRoof = vwAccessoriesFactory->createPanoramicRoof();
    AdaptiveHeadlights* vwAdaptiveHeadlights = vwAccessoriesFactory->createAdaptiveHeadlights();

    // Utilizam accesorii create
    if (vwPanoramicRoof)
        vwPanoramicRoof->installPanoramicRoof();
    else
        std::cout << "VW does not have Panoramic Roof.\n";

    if (vwAdaptiveHeadlights)
        vwAdaptiveHeadlights->installAdaptiveHeadlights();
    else
        std::cout << "VW does not have Adaptive Headlights.\n";

    delete vwPanoramicRoof;
    delete vwAdaptiveHeadlights;
    delete vwAccessoriesFactory;

    // Cream CarAccessoriesFactory pentru Audi
    CarAccessoriesFactory* audiAccessoriesFactory = new AudiAccessoriesFactory();

    // Utilizam fabrica pentru a crea accesorii concrete
    PanoramicRoof* audiPanoramicRoof = audiAccessoriesFactory->createPanoramicRoof();
    AdaptiveHeadlights* audiAdaptiveHeadlights = audiAccessoriesFactory->createAdaptiveHeadlights();

    // Utilizam accesorii create
    if (audiPanoramicRoof)
        audiPanoramicRoof->installPanoramicRoof();
    else
        std::cout << "Audi does not have Panoramic Roof.\n";

    if (audiAdaptiveHeadlights)
        audiAdaptiveHeadlights->installAdaptiveHeadlights();
    else
        std::cout << "Audi does not have Adaptive Headlights.\n";

    delete audiPanoramicRoof;
    delete audiAdaptiveHeadlights;
    delete audiAccessoriesFactory;

    return 0;
}
