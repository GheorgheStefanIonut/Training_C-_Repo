#include "VWAccessoriesFactory.h"
#include "AudiAccessoriesFactory.h"

// Clientul care utilizeaza fabrica de accesorii auto pentru a instala si utiliza accesorii specifice
int main() {
    // Cream o fabrica de accesorii auto concreta pentru VW
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

    // Cream o fabrica de accesorii auto concreta pentru Audi
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
