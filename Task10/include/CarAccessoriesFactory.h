#ifndef CAR_ACCESSORIES_FACTORY_H
#define CAR_ACCESSORIES_FACTORY_H

#include "PanoramicRoof.h"
#include "AdaptiveHeadlights.h"

// Interfata pentru fabrica de accesorii auto
class CarAccessoriesFactory {
public:
    virtual PanoramicRoof* createPanoramicRoof() = 0;
    virtual AdaptiveHeadlights* createAdaptiveHeadlights() = 0;
};

#endif // CAR_ACCESSORIES_FACTORY_H