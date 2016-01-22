# include "IPad.h"
# include <iostream>

IPad::IPad()
{
    // Como não foi fornecido nenhum parametro, os dados serão inicializados com valores padrões.
    setSpecsToDefault();
 
    installDefaultApps();
}

IPad::IPad(int storage)
{
    setSpecsToDefault();
    
    storageCapacity = validateValue(storage, 16, 128, "storage capacity");
    
    installDefaultApps();
}

IPad::IPad(float cpuSpeed, float versionOS, float display, int storage, float backCam, float frontCam, string iPadColor)
{
    isTurnedOn = true;
    
    processorSpeed = validateValue(cpuSpeed, 0, 5, "processor speed");
    
    operatingSystem = validateValue(versionOS, 1, 10, "operating system");
    
    displaySize = validateValue(display, 5, 13, "display size");
    
    storageCapacity = validateValue(storage, 16, 128, "storage capacity");
    
    freeMemory = storage;
    
    rearCamera = validateValue(backCam, 5, 8, "rear camera quality");
    
    frontCamera = validateValue(frontCam, 1, 2, "front camera quality");
    
    color = iPadColor.substr(0, 25);
    
    installDefaultApps();
}

void IPad::turnOn()
{
    isTurnedOn = true;
}

void IPad::turnOff()
{
    closeAllApps();
    isTurnedOn = false;
}


bool IPad::installApp(string name, float sizeOfApp)
{
    // Check to see if the iPad is on
    if (isOn())
    {
        // Check to see if the app isn't already installed
        if (not isAppInstalled(name))
        {
            // Proceed to check if there is enough space to install the app
            if (sizeOfApp <= freeMemory)
            {
                appsInstalled[name] = sizeOfApp;
                freeMemory -= sizeOfApp;
                cout << "\nThe app " << name << " was successfully installed.";
                return true;
            } else
            {
                cout << "\nThere isn't enough space to install the " << name << " app. Consider uninstalling some other apps.";
                return false;
            }
        } else 
        {
            cout << "\nApp already installed.";
            return false;
        }
    } else
    {
        cout << "\n# Turn the iPad on first #";
        return false;
    }
    
    
}

bool IPad::uninstallApp(string name)
{
     // Check to see if the iPad is on
    if (isOn())
    {
        // Check to see if the app is indeed installed
        if (isAppInstalled(name))
        {
            // Find the app in the appsInstalled unordered map.
            auto position = appsInstalled.find(name);
            
            // Proceed to erase the app.
            appsInstalled.erase(position);
            
            cout << "\nThe app " << name << " was successfully uninstalled.";
            return true;
        } else 
        {
            cout << "\nThe app isn't installed.";
            return false;
        }
    } else
    {
        cout << "\n# Turn the iPad on first #";
        return false;
    }
}

void IPad::showAppsInstalled()
{
    // Check to see if the iPad is on
    if (isOn())
    {
        // Check to see if the iPad isn't empty.
        if (not appsInstalled.empty())
        {
            cout << "\n\n.: APPS INSTALLED :.\n";
            
            // Iterate through the appsInstalled
            // app holds the pair <name, sizeOfApp>
            for (auto app : appsInstalled)
            {
                cout << "\nName: " << app.first << "\t\t Size: " << app.second << "GB" << endl;
            }
            
        } else 
        {
            cout << "\n>> There are no apps installed <<";
        }
    } else
    {
        cout << "\n# Turn the iPad on first #";
    }
}

void IPad::getInformation()
{
    // Check to see if the iPad is on
    if (isOn())
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
    } else
    {
        cout << "\n# Turn the iPad on first #";
    }
}

bool IPad::openApp(string name)
{
    // Check to see if the iPad is on
    if (isOn())
    {
        // Check to see if the app is installed
        if (isAppInstalled(name))
        {
            // Check to see if the app isn't already open
            if (not isAppOpened(name))
            {
                activeApps.push_back(name);
                
                cout << "\nApp " << name << " was successfully opened.";
                return true;
            } else
            {
                cout << "\n# App " << name <<" is already opened.";
                return false;
            }
        } else
        {
            cout << "\n# Couldn't open app " << name <<", because it isn't installed.";
            return false;
        }
    } else
    {
        cout << "\n# Turn the iPad on first #";
        return false;
    }
}

bool IPad::closeApp(string name)
{
    // Check to see if the iPad is on
    if (isOn())
    {
        // Check to see if the app is open.
        if (isAppOpened(name))
        {
            for (int i = 0, n = activeApps.size(); i < n; i++)
            {
                if (name == activeApps[i])
                {
                    activeApps.erase(activeApps.begin() + i);
                    cout << "\nApp " << name << " was successfully closed.";
                    return true;
                }    
            }
        } else
        {
            cout << "\nApp " << name <<" isn't open.";
            return false;
        }
        
    } 
    
    cout << "\n# Turn the iPad on first #";
    return false;
}

bool IPad::closeAllApps()
{
    activeApps.clear();
    cout << "\nAll apps were closed.";
    return true;
}


/* HELPERS */

bool IPad::isOn()
{
    return isTurnedOn;
}

bool IPad::isAppInstalled(string name)
{
    // Check to see if the iPad is on
    if (isOn())
    {
        auto lookup = appsInstalled.find(name);
    
        if (lookup != appsInstalled.end())
        {
            return true;
        }
        
        return false;
    } else
    {
        cout << "\n# Turn the iPad on first #";
        return false;
    }
}

bool IPad::isAppOpened(string name)
{
    for (auto app : activeApps)
    {
        if (app == name)
        {
            return true;
        }
    }
    
    return false;
}

void IPad::setSpecsToDefault()
{
    // Por padrão, quando o objeto é inicializado, o iPad será considerado como ligado.
    isTurnedOn = true;
    processorSpeed = 1;
    operatingSystem = 9.2;
    displaySize = 7.9;
    storageCapacity = 32;
    freeMemory = storageCapacity;
    rearCamera = 5;
    frontCamera = 1.2;
    color =  "white";
}

void IPad::installDefaultApps()
{
    installApp("Google", 0.2);
    installApp("Safari", 0.1);
    installApp("Youtube", 0.05);
    installApp("Clock", 0.01);
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

IPad::~IPad()
{
}
