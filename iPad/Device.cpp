#include "Device.h"

// CONSTRUTORES

Device::Device()
{
    isTurnedOn = true;
    Data InitialDate(02, 3, 2016);  
}

Device::Device(bool state)
{
    isTurnedOn = state;
    Data InitialDate(02, 3, 2016);
}

Device::Device(const Device &oldDevice)
{
    isTurnedOn = oldDevice.isTurnedOn;
    InitialDate = oldDevice.InitialDate;
}

Device::~Device()
{
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

// Overload of operator

ostream &operator<<(ostream &output, const Device &device)
{
    output << "\n\n.: Device Specs :.\n"
    << "\n>> STATUS = " << (device.isTurnedOn? "ON":"OFF")
    << device.InitialDate;
    
    return output;
}

const Device & Device::operator=(const Device &device)
{
    isTurnedOn = device.isTurnedOn;
    InitialDate = device.InitialDate;
    
    return *this;
}

bool Device::operator==(const Device &device) const
{
    return (isTurnedOn == device.isTurnedOn) && (InitialDate == device.InitialDate);
}