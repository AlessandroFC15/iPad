#include "SamsungTablet.h"

SamsungTablet::SamsungTablet()
{
}

SamsungTablet::~SamsungTablet()
{
}

void SamsungTablet::setSpecsToDefault()
{
    // The following values were chosen arbitrarily.
    isTurnedOn = true;
    storageCapacity = 16;
    freeMemory = storageCapacity;
    screenLocked = false;
    wiFiOn = true;
    mobileDataOn = false;
    Data InitialDate(17, 2, 2016);
}
