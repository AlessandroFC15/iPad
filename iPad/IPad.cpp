# include "IPad.h"
# include <iostream>

float IPad::latestIOSVersion = 9;
int IPad::numberOfiPads = 0;

IPad::IPad()
{
    cout << ".:. iPad Creation .:.\n";

    installDefaultApps();
    
    setInitialSecuritySystem();
    
    numberOfiPads++;
}

IPad::IPad(int storage)
:Tablet(storage)
{
    cout << ".:. iPad Creation .:.\n";
    
    installDefaultApps();
    
    setInitialSecuritySystem();
    
    numberOfiPads++;
}

// Construtor de cópia
IPad::IPad(const IPad &oldIPad)
:Tablet(static_cast< Tablet > (oldIPad))
{
    typeOfLockScreen = oldIPad.typeOfLockScreen;
    touchID = oldIPad.touchID;

    numberOfiPads++;
}

IPad::~IPad()
{
}

bool IPad::unlockiPadScreen()
{
    // Check to see if the screen is indeed locked
    if (not isScreenUnlocked())
    {
        // Depending of the type of lock screen selected, 
        // the procedures are different.
        if (typeOfLockScreen == PASSWORD)
        {
            return unlockPassword();
        } else if (typeOfLockScreen == TOUCH_ID)
        {
            return unlockTouchID();
        }
    } 
    
    cout << "\n| Screen was already unlocked. |\n";
    return false;
}

/* HELPERS */

void IPad::installDefaultApps()
{
    // Installing Google
    appsInstalled["Google"] = 200;
    freeMemory -= 200/1000.0;
    
    // Installing Safari
    appsInstalled["Safari"] = 100;
    freeMemory -= 100/1000.0;
    
    // Installing Youtube
    appsInstalled["YouTube"] = 50;
    freeMemory -= 50/1000.0;
    
    // Installing iTunes
    appsInstalled["iTunes"] = 100;
    freeMemory -= 100/1000.0;
}


int IPad::getNumberOfiPads()
{
    return numberOfiPads;
}

void IPad::updateIOSVersion()
{
    latestIOSVersion += 0.1;
}

void IPad::setInitialSecuritySystem()
{
    int choice;
    cout << "\n|| CHOICE OF SECURITY SYSTEM ||\n";
    cout << "\n| 1 - TouchID";
    cout << "\n| 2 - Regular Password\n";
    
    while (true)
    {
        cout << "\n>> Enter your choice: ";
        cin >> choice;
        
        if (choice == 1)
        {
            typeOfLockScreen = TOUCH_ID;
            setTouchID();
            break;
        } else if (choice == 2)
        {
            typeOfLockScreen = PASSWORD;
            setLockScreenPassword();
            break;
        } else
        {
            cout << "\n# Invalid choice. Try again! #";
        }
    }
}

void IPad::setTouchID()
{
    touchID.addFingerPrint();
}

bool IPad::unlockPassword()
{
    // The process of unlocking the screen by password of the iPad
    // is the same of a generic Tablet. For that reason, we simply
    // use the method to unlock the screen of the class Tablet
    return Tablet::unlockScreen();
}

bool IPad::unlockTouchID()
{
    if (touchID.unlockScreen())
    {
        screenLocked = false;
        return true;
    }
    
    return false;
}

// OVERLOAD OF OPERATORS

ostream &operator<<(ostream &output, const IPad &iPad)
{
    output << static_cast< Tablet > (iPad)
    << "\n>> iOS VERSION = " << iPad.latestIOSVersion
    << "\n>> TYPE OF LOCK SCREEN = " << (iPad.typeOfLockScreen == iPad.TOUCH_ID? "TOUCH ID":"PASSWORD");
    
    iPad.showAppsInstalled();
    
    return output;
}

// The + operator will sum the storage capacities of iPads

float operator+(const IPad &iPad1, const IPad &iPad)
{
    return iPad1.storageCapacity + iPad.storageCapacity;
}

const IPad & IPad::operator=(const IPad &iPad)
{
    static_cast <Tablet&> (*this) = static_cast <Tablet> (iPad);
    
    typeOfLockScreen = iPad.typeOfLockScreen;
    touchID = iPad.touchID;
    
    return *this;
}

/* For the equality operator, every single attribute must be equal to each other. Any difference will result in returning false. */

bool IPad::operator==(const IPad &iPad) const
{
    // Must have the same storage capacity and free memory
    if ((storageCapacity != iPad.storageCapacity) || (freeMemory != iPad.freeMemory))
        return false;
        
    // Must have the same security system
    if ((typeOfLockScreen != iPad.typeOfLockScreen) || (lockScreenPassword != iPad.lockScreenPassword) || (screenLocked != iPad.screenLocked))
        return false;

    // Must have the same configurations
    if ((isTurnedOn != iPad.isTurnedOn) || (wiFiOn != iPad.wiFiOn) || (mobileDataOn != mobileDataOn))
        return false;

    // Comparison of unordered maps and active apps
    if ((appsInstalled != iPad.appsInstalled) || (activeApps != iPad.activeApps))
        return false;

    if (touchID != iPad.touchID)
        return false;
        
    if (InitialDate != iPad.InitialDate)
        return false;

    return true;
}

/* The operators > and <  will compare the storage capacity of 2 givens iPads. */
bool IPad::operator>(const IPad &iPad) const
{
    return storageCapacity > iPad.storageCapacity;
}

bool IPad::operator<(const IPad &iPad) const
{
    return storageCapacity < iPad.storageCapacity;
}

bool IPad::operator>=(const IPad &iPad) const
{
    return ((*this > iPad) || (storageCapacity == iPad.storageCapacity));
}

bool IPad::operator<=(const IPad &iPad) const
{
    return ((*this < iPad) || (storageCapacity == iPad.storageCapacity));
}

// END OF OVERLOADING OPERATORS