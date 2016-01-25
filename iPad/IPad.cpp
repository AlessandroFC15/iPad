# include "IPad.h"
# include <iostream>

IPad::IPad()
{
    cout << ".:. iPad Creation .:.\n";
    // Como não foi fornecido nenhum parametro, os dados serão inicializados com valores padrões.
    setSpecsToDefault();
    
    installDefaultApps();
    
    setLockScreenPassword();
}

IPad::IPad(int storage, float cpuSpeed, float versionOS, float display, float backCam, float frontCam, string iPadColor)
{
    cout << ".:. iPad Creation .:.\n";
    
    isTurnedOn = true;
    
    processorSpeed = validateValue(cpuSpeed, 0, 5, "processor speed");
    
    operatingSystem = validateValue(versionOS, 1, 10, "operating system");
    
    displaySize = validateValue(display, 5, 13, "display size");
    
    storageCapacity = validateValue(storage, 16, 128, "storage capacity");
    
    freeMemory = storageCapacity;
    
    rearCamera = validateValue(backCam, 5, 8, "rear camera quality");
    
    frontCamera = validateValue(frontCam, 1, 2, "front camera quality");
    
    color = iPadColor.substr(0, 25);
    
    screenLocked = false;
    
    installDefaultApps();
    
    setLockScreenPassword();
}

void IPad::turnOn()
{
    if (isOn())
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
    if (not isOn())
    {
        cout << "\n\n# iPad is already turned off.\n\n";
    } else
    {
        cout << "\n>> Turning iPad off..."; 
        cout << "\n\t>> Closing all apps..."; 
        closeAllApps();
        isTurnedOn = false;
        cout << "\n# iPad is now turned off.\n";
    }
}


bool IPad::installApp(string name, float sizeOfApp)
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

bool IPad::uninstallApp(string name)
{
    // Check to see if the app is indeed installed
    if (isAppInstalled(name))
    {
        // Close the app, in case it is open
        closeApp(name);
        
        // Find the app in the appsInstalled unordered map.
        auto app = appsInstalled.find(name);
        
        // The memory the app held is set free.
        freeMemory += (app->second)/1000;
        
        // Proceed to erase the app.
        appsInstalled.erase(app);
        
        cout << "\n|| The app " << name << " was successfully uninstalled. ||\n";
        return true;
    } else 
    {
        cout << "\n# The app " << name <<" isn't installed. #\n";
        return false;
    }
}

bool IPad::showAppsInstalled()
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
        
        return true;
    } else 
    {
        cout << "\n>> There are no apps installed <<\n";
        return false;
    }
}

bool IPad::showAppsOpened()
{
    // Check to see if there is any active app.
    if (not activeApps.empty())
    {
        cout << "\n\n.: ACTIVE APPS :.\n";
        for (string nameOfApp : activeApps)
        {
            cout << "\n>> " << nameOfApp;
        }
        
        return true;
    } else
    {
        cout << "\n>> There are no apps open <<\n";
        return false;
    }
}

void IPad::getInformation()
{
    cout << "\n\n.: iPad Specs :.\n";
    cout << "\n>> CPU SPEED = " << processorSpeed << "GHz";
    cout << "\n>> OPERATING SYSTEM = iOS " << operatingSystem;
    cout << "\n>> DISPLAY SIZE = " << displaySize << "\"";
    cout << "\n>> STORAGE CAPACITY = " << storageCapacity << "GB";
    cout << "\n>> FREE MEMORY = " << freeMemory << "GB";
    cout << "\n>> REAR CAMERA = " << rearCamera << "MP";
    cout << "\n>> FRONT CAMERA = " << frontCamera << "MP";
    cout << "\n>> COLOR = " << color;
    cout << "\n>> NUM OF APPS INSTALLED = " << appsInstalled.size();
    cout << "\n\n";
}

bool IPad::openApp(string name)
{
    // Check to see if the app is installed
    if (isAppInstalled(name))
    {
        // Check to see if the app isn't already open
        if (not isAppOpened(name))
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

bool IPad::closeApp(string name)
{
    // Check to see if the app is installed.
    if (isAppInstalled(name))
    {
        // Check to see if the app is open.
        if (isAppOpened(name))
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
    } else
    {
        cout << "\n# App " << name <<" isn't even installed. #\n";
        return false;
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

/* HELPERS */

bool IPad::isOn()
{
    return isTurnedOn;
}

bool IPad::isAppInstalled(string name)
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

bool IPad::isAppOpened(string name)
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

void IPad::setSpecsToDefault()
{
    // The following values were chosen arbitrarily.
    isTurnedOn = true;
    processorSpeed = 1;
    operatingSystem = 9.2;
    displaySize = 7.9;
    storageCapacity = 32;
    freeMemory = storageCapacity;
    rearCamera = 5;
    frontCamera = 1.2;
    color =  "WHITE";
    screenLocked = false;
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

float IPad::validateValue(float value, float min, float max, string name)
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

void IPad::setLockScreenPassword()
{
    int password;
    while (true)
    {
        cout << "\n>> Set initial password to lock screen (4 digits): ";
        cin >> password;
        if ((password >= 1000) & (password <= 9999))
        {
            lockScreenPassword = password;
            cout << "\n|| Lock screen password set successfully ||\n";
            break;
        }
        
        cout << "\n# Password must be 4 digits. Try again. #\n";
    }
}

bool IPad::isScreenUnlocked()
{
    return not screenLocked;
}

bool IPad::unlockScreen()
{
    // Check to see if the screen is indeed locked
    if (not isScreenUnlocked())
    {
        int password;
        while (true)
        {
            cout << "\n>> Enter password to unlock screen (0 to Quit): ";
            cin >> password;
            
            if (password == 0)
            {
                cout << "\n|| Unlock process was cancelled. iPad remains locked. ||\n";
                return false;
            } else if ((password >= 1000) & (password <= 9999))
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
                cout << "\n# Password must be 4 digits. Try again #\n";
            }
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

IPad::~IPad()
{
}
