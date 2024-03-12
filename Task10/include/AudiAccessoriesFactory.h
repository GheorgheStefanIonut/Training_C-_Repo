#include "CarAccessoriesFactory.h"
#include "AudiAdaptiveHeadlights.h"

// Implementare concreta a fabricii de accesorii auto pentru Audi
class AudiAccessoriesFactory : public CarAccessoriesFactory {
public:
    PanoramicRoof* createPanoramicRoof() override;
    AdaptiveHeadlights* createAdaptiveHeadlights() override;
};