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
    
    freeMemory = storageCapacity;
    
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
            if (sizeOfApp/1000 <= freeMemory)
            {
                appsInstalled[name] = sizeOfApp;
                freeMemory -= sizeOfApp/1000;
                cout << "\n\n || The app " << name << " was successfully installed. ||\n";
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
    } else
    {
        cout << "\n# Turn the iPad on first #";
        return false;
    }
}

bool IPad::showAppsInstalled()
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
                cout << "\nName: " << app.first << " | " << app.second << "MB" << endl;
            }
            
            return true;
        } else 
        {
            cout << "\n>> There are no apps installed <<\n";
            return false;
        }
    } else
    {
        cout << "\n# Turn the iPad on first #";
        return false;
    }
}

bool IPad::showAppsOpened()
{
    // Check to see if there is any app active.
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
    } else
    {
        cout << "\n# Turn the iPad on first #\n";
        return false;
    }
}

bool IPad::closeApp(string name)
{
    // Check to see if the iPad is on
    if (isOn())
    {
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
                cout << "\n# App " << name <<" was already closed. #\n";
                return true;
            }
        } else
        {
            cout << "\n# App " << name <<" isn't even installed. #\n";
            return true;
        }
    } 
    
    cout << "\n# Turn the iPad on first #";
    return false;
}

bool IPad::closeAllApps()
{
    if (isOn())
    {
        // Check to see if there is any app open.
        if (not activeApps.empty())
        {
            activeApps.clear();
            cout << "\n\n|| All apps were closed. ||\n\n";
            return true;
        } else
        {
            cout << "\n\n|| All apps were already closed. ||\n\n";
            return true;
        }
    } else
    {
        cout << "\n# Turn the iPad on first #";
        return false;
    }
}

bool IPad::uninstallAllApps()
{
    if (isOn())
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
        
    } else
    {
        cout << "\n# Turn the iPad on first #";
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
    // Installing Google
    appsInstalled["Google"] = 200;
    freeMemory -= 0.2;
    
    // Installing Safari
    appsInstalled["Safari"] = 100;
    freeMemory -= 0.1;
    
    // Installing Youtube
    appsInstalled["YouTube"] = 50;
    freeMemory -= 0.05;
    
    // Installing iTunes
    appsInstalled["iTunes"] = 100;
    freeMemory -= 0.01;
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
