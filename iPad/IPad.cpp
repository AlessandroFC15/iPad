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
    
    // Para a capacidade de armazenamento, será fornecido um valor arbitrário
    storageCapacity = 0.0;
    
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

bool IPad::installApp(string name)
{
    // Check to see if the app isn't already installed
    if (not isAppInstalled(name))
    {
        cout << "Will be." << endl;
        return true;
    } else {
        cout << "App already installed." << endl;
        return false;
    }
    
}

bool IPad::isAppInstalled(string name)
{
    for (int i = 0, n = appsInstalled.size(); i < n; i++)
    {
        if (name == appsInstalled[i])
        {
            return true;
        }
    }
    
    return false;
    
}

IPad::~IPad()
{
}

