#include "Tablet.h"

Tablet::Tablet()
{
    setSpecsToDefault();
}

Tablet::Tablet(int storage)
{
    setSpecsToDefault();
    
    storageCapacity = validateValue(storage, 1, 128, "storage capacity");
    
    freeMemory = storageCapacity;
}

// Construtor de cópia
Tablet::Tablet(const Tablet &oldTablet)
:Device(static_cast< Device > (oldTablet))
{
    storageCapacity = oldTablet.storageCapacity;
    freeMemory = oldTablet.freeMemory;
    screenLocked = oldTablet.screenLocked;
    lockScreenPassword = oldTablet.lockScreenPassword;
    wiFiOn = oldTablet.wiFiOn;
    mobileDataOn = oldTablet.mobileDataOn;
    appsInstalled = oldTablet.appsInstalled;
    activeApps = oldTablet.activeApps;
}

Tablet::~Tablet()
{
}

bool Tablet::installApp(const string &name, float sizeOfApp)
{
    // Check to see if the app isn't already installed
    if (not isAppInstalled(name))
    {
        // Proceed to check if there is enough space to install the app
        if (sizeOfApp/1000 <= freeMemory)
        {
            appsInstalled[name] = sizeOfApp;
            freeMemory -= sizeOfApp/1000;
            cout << "\n|| The app " << name << " was successfully installed. ||\n";
            return true;
        } else
        {
            cout << "\nThere isn't enough space to install the " << name << " app. Consider uninstalling some other apps.";
            return false;
        }
    } else 
    {
        cout << "\n# App " << name << " is already installed. #\n";
        return false;
    }
}

bool Tablet::uninstallApp(const string &name)
{
    // Check to see if the app is indeed installed
    if (isAppInstalled(name))
    {
        cout << "\n|| Uninstalling " << name << "... ||\n";
        // Close the app, in case it is open
        //closeApp(name);
        
        // The memory the app held is set free. Needs to convert to GB.
        freeMemory += appsInstalled[name]/1000;
        
        // Proceed to erase the app.
        appsInstalled.erase(name);
        
        cout << "\n|| The app " << name << " was successfully uninstalled. ||\n";
        return true;
    } else 
    {
        cout << "\n# The app " << name <<" isn't installed. #\n";
        return false;
    }
}

bool Tablet::openApp(const string &name)
{
    // Check to see if the app is installed
    if (isAppInstalled(name))
    {
        // Check to see if the app isn't already open
        if (not isAppOpen(name))
        {
            activeApps.push_back(name);
            
            cout << "\n|| App " << name << " was successfully opened. ||\n";
            return true;
        } else
        {
            cout << "\n# App " << name <<" is already opened. #\n";
            return false;
        }
    } else
    {
        cout << "\n# Couldn't open app " << name <<", because it isn't installed. #\n";
        return false;
    }
}

bool Tablet::closeApp(const string &name)
{
    // Check to see if the app is installed.
    if (isAppInstalled(name))
    {
        // Check to see if the app is open.
        if (isAppOpen(name))
        {
            for (int i = 0, n = activeApps.size(); i < n; i++)
            {
                if (name == activeApps[i])
                {
                    activeApps.erase(activeApps.begin() + i);
                    cout << "\n|| App " << name << " was successfully closed. ||\n";
                    return true;
                }    
            }
        } else
        {
            cout << "\n# App " << name <<" wasn't open. #\n";
            return false;
        }
    } 
    
    cout << "\n# App " << name <<" isn't even installed. #\n";
    return false;
}

void Tablet::showAppsInstalled() const
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

void Tablet::showActiveApps() const
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

bool Tablet::closeAllApps()
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

bool Tablet::uninstallAllApps()
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

bool Tablet::unlockScreen()
{
    cin.ignore();
    // Check to see if the screen is indeed locked
    if (not isScreenUnlocked())
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
    
    cout << "\n| Screen was already unlocked. |\n";
    return false;
}

bool Tablet::lockScreen()
{
    // Check to see if the screen is indeed unlocked.
    if (isScreenUnlocked())
    {
        screenLocked = true;
        cout << "\n|| Screen is now locked ||\n";
        return true;
    } else 
    {
        cout << "\n| Screen was already locked. |\n";
        return false;
    }
}

void Tablet::setLockScreenPassword()
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

bool Tablet::isScreenUnlocked() const
{
    return not screenLocked;
}

void Tablet::turnWiFiOn()
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

void Tablet::turnWiFiOff()
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

void Tablet::turnMobileDataOn()
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
    
void Tablet::turnMobileDataOff()
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

bool Tablet::isInternetAvailable() const
{
    return wiFiOn || mobileDataOn;
}

bool Tablet::isDeviceEmpty() const
{
    return appsInstalled.empty();
}

bool Tablet::isAnyAppOpen() const
{
    return not activeApps.empty();
}

float Tablet::validateValue(float value, float min, float max, const string &name) const
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

/* HELPER FUNCTIONS | PRIVATE FUNCTION */

bool Tablet::isAppOpen(const string &name) const
{
    for (string nameOfApp : activeApps)
    {
        if (nameOfApp == name)
        {
            return true;
        }
    }
    
    return false;
}

bool Tablet::isAppInstalled(const string &name) const
{
    // Find the app in the unordered map appsInstalled.
    auto lookup = appsInstalled.find(name);

    // If the function "find" above returns something other than an iterator to the end of the map,
    // that means the element was found and therefore, is installed.
    if (lookup != appsInstalled.end())
    {
        return true;
    }
    
    return false;
}

void Tablet::setSpecsToDefault()
{
    storageCapacity = 32;
    freeMemory = storageCapacity;
    screenLocked = true;
    wiFiOn = true;
    mobileDataOn = false;
    lockScreenPassword = "";
}

// Overload of operators
ostream &operator<<(ostream &output, const Tablet &tablet)
{
    output << static_cast< Device > (tablet)
    << "\n>> STORAGE CAPACITY = " << tablet.storageCapacity << "GB"
    << "\n>> FREE MEMORY = " << tablet.freeMemory << "GB"
    << "\n>> NUM OF APPS INSTALLED = " << tablet.appsInstalled.size()
    << "\n>> NUM OF ACTIVE APPS = " << tablet.activeApps.size()
    << "\n>> SCREEN LOCKED = " << (tablet.screenLocked? "YES":"NO");
    
    return output;
}

const Tablet & Tablet::operator=(const Tablet &oldTablet)
{
    static_cast <Device&> (*this) = static_cast <Device> (oldTablet);
    
    storageCapacity = oldTablet.storageCapacity;
    freeMemory = oldTablet.freeMemory;
    screenLocked = oldTablet.screenLocked;
    lockScreenPassword = oldTablet.lockScreenPassword;
    wiFiOn = oldTablet.wiFiOn;
    mobileDataOn = oldTablet.mobileDataOn;
    appsInstalled = oldTablet.appsInstalled;
    activeApps = oldTablet.activeApps;
    
    return *this;
}

bool Tablet::operator==(const Tablet &tablet) const
{
    if (static_cast <Device> (*this) != static_cast <Device> (tablet))
        return false;
    
    // Must have the same storage capacity and free memory
    if ((storageCapacity != tablet.storageCapacity) || (freeMemory != tablet.freeMemory))
        return false;
        
    // Must have the same security system
    if ((lockScreenPassword != tablet.lockScreenPassword) || (screenLocked != tablet.screenLocked))
        return false;

    // Must have the same configurations
    if ((wiFiOn != tablet.wiFiOn) || (mobileDataOn != mobileDataOn))
        return false;

    // Comparison of unordered maps and active apps
    if ((appsInstalled != tablet.appsInstalled) || (activeApps != tablet.activeApps))
        return false;

    return true;
}