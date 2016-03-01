#include "Tablet.h"

Tablet::Tablet()
{
}

Tablet::~Tablet()
{
}

bool Tablet::unlockScreen()
{
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

bool Tablet::isScreenUnlocked() const
{
    return not screenLocked;
}

void Tablet::setSpecsToDefault()
{
    screenLocked = false;
    wiFiOn = true;
    mobileDataOn = false;
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