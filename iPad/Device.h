#ifndef DEVICE_H
#define DEVICE_H

# include "Data.h"

class Device
{
public:
    Device();
    Device(bool);
    ~Device();

    void turnOn();
    void turnOff();
    bool isOn() const;
protected:
    bool isTurnedOn;
    const Data InitialDate;
};

#endif // DEVICE_H
