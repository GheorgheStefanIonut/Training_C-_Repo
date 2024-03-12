#include "AudiAccessoriesFactory.h"

PanoramicRoof* AudiAccessoriesFactory::createPanoramicRoof() {
    // Pentru Audi, nu avem trapa panoramica, deci returnam nullptr
    return nullptr;
}

AdaptiveHeadlights* AudiAccessoriesFactory::createAdaptiveHeadlights() {
    return new AudiAdaptiveHeadlights();
}
