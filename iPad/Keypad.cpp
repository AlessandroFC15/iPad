#include "Keypad.h"

Keypad::Keypad()
{
    autoCorrectOn = false;
}

Keypad::~Keypad()
{
}

void Keypad::turnAutoCorrectOff()
{
    autoCorrectOn = false;
}

void Keypad::turnAutoCorrectOn()
{
    autoCorrectOn = true;
}

void Keypad::turnCapsLockOff()
{
    capsLockOn = false;
}

void Keypad::turnCapsLockOn()
{
    capsLockOn = true;
}

bool Keypad::isAutoCorrectOn() const 
{
    return autoCorrectOn;
}

bool Keypad::isCapsLockOn() const
{
    return capsLockOn;
}