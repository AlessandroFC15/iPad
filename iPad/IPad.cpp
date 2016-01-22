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
    
    validateStorageValue(storage);
    
    installDefaultApps();
}

void IPad::validateStorageValue(int storage)
{
    while (true)
    {
        if (storage >= 16 && storage <= 128)
        {
            break;
        }
        
        cout << "\n>> Invalid value for storage capacity. Must be between 16GB and 128GB.";
        cout << "\n>> Enter a new value: ";
        cin >> (storage);
    }
    
    storageCapacity = storage;
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

void IPad::turnOn()
{
    isTurnedOn = true;
}

void IPad::turnOff()
{
    isTurnedOn = false;
}

bool IPad::isOn()
{
    return isTurnedOn;
}

bool IPad::installApp(string name, float sizeOfApp)
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
}

bool IPad::uninstallApp(string name)
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
}

void IPad::checkAppsInstalled()
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
}

void IPad::getInformation()
{
    
    
}

bool IPad::isAppInstalled(string name)
{
    auto lookup = appsInstalled.find(name);
    
    if (lookup != appsInstalled.end())
    {
        return true;
    }
    
    return false;
}

IPad::~IPad()
{
}

