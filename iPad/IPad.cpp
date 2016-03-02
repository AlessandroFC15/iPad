# include "IPad.h"
# include <iostream>

float IPad::latestIOSVersion = 9;
int IPad::numberOfiPads = 0;

ostream &operator<<(ostream &output, const IPad &iPad)
{
    output << "\n\n.: iPad Specs :.\n"
    << "\n>> STORAGE CAPACITY = " << iPad.storageCapacity << "GB"
    << "\n>> FREE MEMORY = " << iPad.freeMemory << "GB"
    << "\n>> iOS VERSION = " << iPad.latestIOSVersion
    << "\n>> NUM OF APPS INSTALLED = " << iPad.appsInstalled.size()
    << "\n>> NUM OF ACTIVE APPS = " << iPad.activeApps.size()
    << "\n>> TYPE OF LOCK SCREEN = " << (iPad.typeOfLockScreen == iPad.TOUCH_ID? "TOUCH ID":"PASSWORD")
    << "\n>> SCREEN LOCKED = " << (iPad.screenLocked? "YES":"NO")
    << "\n>> STATUS = " << (iPad.isTurnedOn? "ON":"OFF")
    << iPad.InitialDate;
    
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
    isTurnedOn = iPad.isTurnedOn;
    storageCapacity = iPad.storageCapacity;
    freeMemory = iPad.freeMemory;
    screenLocked = iPad.screenLocked;
    wiFiOn = iPad.wiFiOn;
    mobileDataOn = iPad.mobileDataOn;
    appsInstalled = iPad.appsInstalled;
    Data InitialDate(iPad.InitialDate);
    activeApps = iPad.activeApps;
    typeOfLockScreen = iPad.typeOfLockScreen;
    lockScreenPassword = iPad.lockScreenPassword;
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

IPad::IPad()
{
    cout << ".:. iPad Creation .:.\n";
    
    setSpecsToDefault();
    
    installDefaultApps();
    
    setInitialSecuritySystem();
    
    numberOfiPads++;
}

IPad::IPad(int storage)
{
    cout << ".:. iPad Creation .:.\n";
    
    storageCapacity = validateValue(storage, 16, 128, "storage capacity");
    
    freeMemory = storageCapacity;

    installDefaultApps();
    
    setInitialSecuritySystem();
    
    numberOfiPads++;
}

// Construtor de cópia
IPad::IPad(const IPad &oldIPad)
{
    isTurnedOn = oldIPad.isTurnedOn;
    storageCapacity = oldIPad.storageCapacity;
    freeMemory = oldIPad.freeMemory;
    screenLocked = oldIPad.screenLocked;
    wiFiOn = oldIPad.wiFiOn;
    mobileDataOn = oldIPad.mobileDataOn;
    appsInstalled = oldIPad.appsInstalled;
    activeApps = oldIPad.activeApps;
    typeOfLockScreen = oldIPad.typeOfLockScreen;
    lockScreenPassword = oldIPad.lockScreenPassword;
    touchID = oldIPad.touchID;

    numberOfiPads++;
}

IPad::~IPad()
{
}

bool IPad::unlockScreen()
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

float IPad::validateValue(float value, float min, float max, const string &name) const
{
    while (true)
    {
        if (value >= min && value <= max)
        {
            break;
        }
        
        cout << "\n>> Invalid value for " << name << ". Must be between " << min << " and " << max << ".";
        cout << "\n>> Enter a new value: ";
        cin >> (value);
    }
    
    return value;
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
    string password;
    while (true)
    {
        cout << "\n>> Enter password to unlock screen (0 to Quit): ";
        
        getline(cin, password);
        
        if (password == "0")
        {
            cout << "\n|| Unlock process was cancelled. iPad remains locked. ||\n";
            return false;
        } else if ((password.length() >= 4) & (password.length() <= 32))
        {
            if (password == lockScreenPassword)
            {
                screenLocked = false;
                cout << "\n|| Screen is now unlocked ||\n";
                return true;
            } else 
            {
                cout << "\n# Wrong password. Try again #\n";
            }
        } else 
        {
            cout << "\n# Password must be 4 to 32 chars. Try again #\n";
        }
    }
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