#ifndef IPAD_H
#define IPAD_H

# include <string>
# include <tr1/unordered_map>
# include <vector>
# include "Data.h"
# include "TouchID.h"

using namespace std::tr1;
using namespace std;

class IPad
{
public:
    IPad();
    IPad(int storage);
    IPad(const IPad &);
    ~IPad();
    
    void turnOn();
    void turnOff();
    
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
        Prints to the screen information about the iPad, including:
         * storageCapacity
         * freeMemory
         * color
         * num of apps installed
         * num of apps open
    */
    void getInformation() const;

    /**
        Closes all active apps.
        
        @return boolean value, returning true if there was n (n > 0) apps open and
        now there are 0 apps open. The function will return false if there were no 
        apps open before its execution.
    */
    bool closeAllApps();
    
    /**
        Uninstall all apps.
        
        @return boolean value, returning true if the iPad wasn't empty and all apps were uninstalled.
        The function will return false if the iPad was empty before the execution.
    */
    bool uninstallAllApps();
    
    bool unlockScreen();
    
    bool lockScreen();
    
    void turnWiFiOn();
    
    void turnWiFiOff();
    
    void turnMobileDataOn();
    
    void turnMobileDataOff();
    
    /** HELPER FUNCTIONS
     * 
     * The following functions were designed to help the main functions perfomr
     */
     
    bool isOn() const;
    bool isScreenUnlocked() const;
    bool isInternetAvailable() const;
    bool isIPadEmpty() const;
    bool isAnyAppOpen() const;
    
    static void updateIOSVersion();
    static int getNumberOfiPads();
    
private:
    bool isTurnedOn;
    float storageCapacity; // Measured in GB
    float freeMemory; // Measured in GB
    bool screenLocked;
    bool wiFiOn;
    bool mobileDataOn;
    unordered_map<string, float> appsInstalled;
    vector<string> activeApps;
    static float latestIOSVersion;
    static int numberOfiPads;
    const Data InitialDate;
    int typeOfLockScreen;
    string lockScreenPassword;
    TouchID touchID;
    
    /* CONSTANTS */
    const static int TOUCH_ID = 1;
    const static int PASSWORD = 2;
    
    /** HELPER FUNCTIONS
     * 
     * The following functions were designed to help the main functions perfomr
     */
    bool isAppInstalled(const string &) const;
    bool isAppOpen(const string &) const;
    void setSpecsToDefault();
    void installDefaultApps();
    
    /**
        Helper function designed to validate the values passed as parameters to the constructor.
        
        @param value: value to be validated.
               min: The value to be analyzed can't be lower than the mininum.
               max: The value to be analyzed can't be higher than the maximum.
               name: String to help identify which attribute is being validated.
        @return float value already validated acording to the max and min limits provided in the arguments.
    */
    float validateValue(float, float, float, const string &) const;

    /*
     * Make a choice if your system of lock screen will be through Touch ID or regular password
     * */
    void setInitialSecuritySystem();
    void setLockScreenPassword();
    void setTouchID();
    bool unlockPassword();
    bool unlockTouchID();
};

#endif // IPAD_H
