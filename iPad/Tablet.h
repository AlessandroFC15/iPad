#ifndef TABLET_H
#define TABLET_H

# include <unordered_map>
# include <vector>
# include "Device.h"
# include <string>

class Tablet : public Device
{
public:
    Tablet();
    Tablet(int);
    ~Tablet();
    
    bool unlockScreen();
    bool lockScreen();
    bool isScreenUnlocked() const;
    
    /**
        Installs an app in the iPad.

        @param name of the app.
        @param size of the app in MB.
        @return boolean value, indicating if the app was successfully installed.
    */
    bool installApp(const string &, float);
    
    /**
        Uninstalls an app in the iPad.
        
        @param name of the app.
        @return boolean value, indicating if the app was successfully uninstalled.
    */
    bool uninstallApp(const string &);
    
     /**
        Opens an specific app in the iPad.
        
        @param name of the app.
        @return boolean value, indicating if the app was successfully opened.
    */
    bool openApp(const string &);
 
    /**
        Closes an app in the iPad, given its name.
        
        @return boolean value, returning true only if the app was open and after the
        function is closed. Any other case will return false.
    */
    bool closeApp(const string &);
    
    /**
        Prints a list of the apps installed in the iPad.
    */
    void showAppsInstalled() const;
    
    /**
        Prints a list of the apps open in the iPad.
    */
    void showActiveApps() const;
    
    /**
        Closes all active apps.
        
        @return boolean value, returning true if there was n (n > 0) apps open and
        now there are 0 apps open. The function will return false if there were no 
        apps open before its execution.
    */
    bool closeAllApps(); 
    
    bool uninstallAllApps();
    
    void turnWiFiOn();
    
    void turnWiFiOff();
    
    void turnMobileDataOn();
    
    void turnMobileDataOff();
    
    bool isInternetAvailable() const;
    bool isDeviceEmpty() const;
    bool isAnyAppOpen() const;
    
    void setLockScreenPassword();
    
protected:
    bool screenLocked;
    string lockScreenPassword;
    bool wiFiOn;
    bool mobileDataOn;
    float storageCapacity; // Measured in GB
    float freeMemory; // Measured in GB
    unordered_map<string, float> appsInstalled;
    vector<string> activeApps;
    
private:
    void setSpecsToDefault();
    bool isAppInstalled(const string &) const;
    bool isAppOpen(const string &) const;
    
};

#endif // TABLET_H
