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
    
    storageCapacity = 32;
    
    freeMemory = storageCapacity;
    
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



void IPad::showAppsInstalled() const
{
    // Check to see if the iPad isn't empty.
    if (not appsInstalled.empty())
    {
        cout << "\n\n.: APPS INSTALLED :.\n";
        
        // Iterate through appsInstalled.
        // app holds the pair <name, sizeOfApp>
        for (auto app : appsInstalled)
        {
            cout << "\nName: " << app.first << " | " << app.second << "MB" << endl;
        }
    } else 
    {
        cout << "\n>> There are no apps installed <<\n";
    }
}

void IPad::showActiveApps() const
{
    // Check to see if there is any active app.
    if (not activeApps.empty())
    {
        cout << "\n\n.: ACTIVE APPS :.\n";
        for (string nameOfApp : activeApps)
        {
            cout << "\n>> " << nameOfApp;
        }
    } else
    {
        cout << "\n>> There are no apps open <<\n";
    }
}

bool IPad::closeAllApps()
{
    // Check to see if there is any app open.
    if (not activeApps.empty())
    {
        // Clear the vector that holds the name of the active apps.
        activeApps.clear();
        cout << "\n|| All apps were closed. ||\n";
        return true;
    } else
    {
        cout << "\n|| All apps were already closed. ||\n";
        return false;
    }
}

bool IPad::uninstallAllApps()
{
    // Check to see if there is any app in the device
    if (not appsInstalled.empty())
    {
        // Close all apps
        activeApps.clear();
        
        // Uninstall all apps
        appsInstalled.clear();
        
        // Reset memory to its initial state.
        freeMemory = storageCapacity;
        
        cout << "\n\n|| All apps were uninstalled ||\n\n";
        return true;
    } else
    {
        cout << "\n\n|| There are no apps in the iPad. ||\n\n";
        return false;
    }
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

void IPad::turnWiFiOn()
{
    if (wiFiOn)
    {
        cout << "\n# WiFi is already turned on.\n";
    } else
    {
        wiFiOn = true;
        cout << "\n# WiFi is now turned on.\n";
    }
}

void IPad::turnWiFiOff()
{
    if (not wiFiOn)
    {
        cout << "\n# WiFi is already turned off.\n";
    } else
    {
        wiFiOn = false;
        cout << "\n# WiFi is now turned off.\n";
    }
}

void IPad::turnMobileDataOn()
{
    if (mobileDataOn)
    {
        cout << "\n# Mobile data network is already turned on.\n";
    } else
    {
        mobileDataOn = true;
        cout << "\n# Mobile data network is now turned on.\n";
    }
}
    
void IPad::turnMobileDataOff()
{
    if (not mobileDataOn)
    {
        cout << "\n# Mobile data network is already turned off.\n";
    } else
    {
        mobileDataOn = false;
        cout << "\n# Mobile data network is now turned off.\n";
    }
}


/* HELPERS */



bool IPad::isIPadEmpty() const
{
    return appsInstalled.empty();
}

bool IPad::isAnyAppOpen() const
{
    return not activeApps.empty();
}

void IPad::setSpecsToDefault()
{
    // The following values were chosen arbitrarily.
    isTurnedOn = true;
    storageCapacity = 32;
    freeMemory = storageCapacity;
    screenLocked = false;
    wiFiOn = true;
    mobileDataOn = false;
    Data InitialDate(17, 2, 2016);
}

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



bool IPad::isInternetAvailable() const
{
    return wiFiOn || mobileDataOn;
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

void IPad::setLockScreenPassword()
{
    string password;
    while (true)
    {
        cout << "\n>> Set initial password to lock screen (4-32 chars): ";
        getline(cin, password);
        
        if ((password.length() >= 4) && (password.length() <= 32))
        {
            lockScreenPassword = password;
            cout << "\n|| Lock screen password set successfully ||\n";
            break;
        }
        
        cout << "\n# Password must be 4 to 32 chars. Try again. #\n";
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