#include "CarAccessoriesFactory.h"
#include "VWPanoramicRoof.h"

// Implementare concreta a fabricii de accesorii auto pentru VW
class VWAccessoriesFactory : public CarAccessoriesFactory {
public:
    PanoramicRoof* createPanoramicRoof() override;
    AdaptiveHeadlights* createAdaptiveHeadlights() override;
};