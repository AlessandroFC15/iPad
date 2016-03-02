#ifndef DEVICE_H
#define DEVICE_H

# include "Data.h"

class Device
{
    friend ostream &operator<<(ostream &, const Device &);
    
public:
    Device();
    Device(bool);
    Device(const Device &);
    ~Device();

    void turnOn();
    void turnOff();
    bool isOn() const;
protected:
    bool isTurnedOn;
    Data InitialDate;
};

#endif // DEVICE_H
