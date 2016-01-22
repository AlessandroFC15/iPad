# include "IPad.h"
# include <iostream>

IPad::IPad()
{
    // Por padrão, quando o objeto é inicializado, o iPad será considerado como ligado.
    isTurnedOn = true;
    
    // Como não foi fornecido nenhum parâmetro, os dados serão inicializados com 0.
    processorSpeed = 0.0;
    operatingSystem = "";
    displaySize = 0.0;
    
    // Para a capacidade de armazenamento, será fornecido um valor arbitrário de 32GB.
    storageCapacity = 32;
    freeMemory = storageCapacity;
    
    rearCamera = 0;
    frontCamera = 0;
    color =  "white";
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

bool IPad::installApp(string name, float size)
{
    // Check to see if the app isn't already installed
    if (not isAppInstalled(name))
    {
        // Proceed to check if there is enough space to install the app
        if (size <= freeMemory)
        {
            appsInstalled[name] = size;
            freeMemory -= size;
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
    // 1st Step = Check to see if the app is indeed installed
    if (isAppInstalled(name))
    {
        auto position = appsInstalled.find(name);
        appsInstalled.erase(position);
        cout << "\nThe app " << name << " was successfully uninstalled.";
        return true;
    } else 
    {
        cout << "\nThe app isn't installed.";
        return false;
    }
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

