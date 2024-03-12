#include "VWAccessoriesFactory.h"

PanoramicRoof* VWAccessoriesFactory::createPanoramicRoof() {
    return new VWPanoramicRoof();
}

AdaptiveHeadlights* VWAccessoriesFactory::createAdaptiveHeadlights() {
    // Pentru VW, nu avem faruri adaptive, deci returnam nullptr
    return nullptr;
}
