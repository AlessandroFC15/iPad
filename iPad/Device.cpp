#include "Device.h"

Device::Device()
{
    isTurnedOn = true;
    Data InitialDate(17, 2, 2016);
}

Device::Device(bool state)
{
    isTurnedOn = state;
    Data InitialDate(17, 2, 2016);
}

Device::~Device()
{
}

void Device::turnOn()
{
    if (isTurnedOn)
    {
        cout << "\n# Device is already turned on.\n";
    } else
    {
        isTurnedOn = true;
        cout << "\n# Device is now turned on.\n";
    }
}

void Device::turnOff()
{
    // Check to see if the iPad isn't already turned off.
    if (not isTurnedOn)
    {
        cout << "\n\n# Device is already turned off.\n\n";
    } else
    {
        isTurnedOn = false;
        
        cout << "\n# Device is now turned off.\n";
    }
}

/* HELPERS */

bool Device::isOn() const
{
    return isTurnedOn;
}
