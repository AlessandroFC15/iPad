#ifndef KEYPAD_H
#define KEYPAD_H

class Keypad
{
public:
    Keypad();
    ~Keypad();
    
    void changeKeyPadPattern();
    void changeKeyPadLanguage();
    void turnAutoCorrectOn();
    void turnAutoCorrectOff();
    void turnCapsLockOn();
    void turnCapsLockOff();
    bool isAutoCorrectOn() const;
    bool isCapsLockOn() const;
    
private:
    int keypadPattern;
    int keypadLanguage;
    bool autoCorrectOn;
    bool capsLockOn;
};

#endif // KEYPAD_H
