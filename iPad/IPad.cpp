# include "IPad.h"
# include <iostream>

float IPad::latestIOSVersion = 9;
int IPad::numberOfiPads = 0;

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
    
    setSpecsToDefault();
    
    storageCapacity = validateValue(storage, 16, 128, "storage capacity");

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
    lockScreenPassword = oldIPad.lockScreenPassword;
    screenLocked = oldIPad.screenLocked;
    wiFiOn = oldIPad.wiFiOn;
    mobileDataOn = oldIPad.mobileDataOn;
    appsInstalled = oldIPad.appsInstalled;
    activeApps = oldIPad.activeApps;

    numberOfiPads++;
}

IPad::~IPad()
{
}

void IPad::turnOn()
{
    if (isTurnedOn)
    {
        cout << "\n# iPad is already turned on.\n";
    } else
    {
        isTurnedOn = true;
        cout << "\n# iPad is now turned on.\n";
    }
}

void IPad::turnOff()
{
    // Check to see if the iPad isn't already turned off.
    if (not isTurnedOn)
    {
        cout << "\n\n# iPad is already turned off.\n\n";
    } else
    {
        // Close all apps
        activeApps.clear();
        
        isTurnedOn = false;
        
        cout << "\n# iPad is now turned off.\n";
    }
}

bool IPad::installApp(const string &name, float sizeOfApp)
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

bool IPad::uninstallApp(const string &name)
{
    // Check to see if the app is indeed installed
    if (isAppInstalled(name))
    {
        cout << "\n|| Uninstalling " << name << "... ||\n";
        // Close the app, in case it is open
        closeApp(name);
        
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

bool IPad::openApp(const string &name)
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

bool IPad::closeApp(const string &name)
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

void IPad::getInformation() const
{
    cout << "\n\n.: iPad Specs :.\n";
    cout << "\n>> STORAGE CAPACITY = " << storageCapacity << "GB";
    cout << "\n>> FREE MEMORY = " << freeMemory << "GB";
    cout << "\n>> iOS VERSION = " << latestIOSVersion;
    InitialDate.print();
    cout << "\n>> NUM OF APPS INSTALLED = " << appsInstalled.size();
    cout << "\n>> NUM OF ACTIVE APPS = " << activeApps.size();
    cout << "\n\n";
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
    } else
    {
        cout << "\n| Screen was already unlocked. |\n";
        return false;
    }
}

bool IPad::lockScreen()
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

bool IPad::isOn() const
{
    return isTurnedOn;
}

bool IPad::isAppInstalled(const string &name) const
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

bool IPad::isAppOpen(const string &name) const
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

bool IPad::isScreenUnlocked() const
{
    return not screenLocked;
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