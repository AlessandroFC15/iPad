#ifndef IPAD_H
#define IPAD_H

# include "TouchID.h"
# include "Tablet.h"

using namespace std;

class IPad : public Tablet
{
    friend ostream &operator<<(ostream &, const IPad &);
    friend float operator+(const IPad &, const IPad &);
public:
    // Overload of operators
    const IPad &operator=(const IPad &);
    bool operator==(const IPad &) const;
    bool operator!=(const IPad &iPad) const
    {
        return ! (*this == iPad);
    }
    bool operator>(const IPad &) const;
    bool operator<(const IPad &) const;
    bool operator>=(const IPad &) const;
    bool operator<=(const IPad &) const;
    
    // Constructors
    IPad();
    IPad(int storage);
    IPad(const IPad &);
    ~IPad();
    
    

    
    
    
    
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
    
    /**
        Uninstall all apps.
        
        @return boolean value, returning true if the iPad wasn't empty and all apps were uninstalled.
        The function will return false if the iPad was empty before the execution.
    */
    bool unlockScreen();
    
    bool uninstallAllApps();
    
    void turnWiFiOn();
    
    void turnWiFiOff();
    
    void turnMobileDataOn();
    
    void turnMobileDataOff();
    
    bool isInternetAvailable() const;
    bool isIPadEmpty() const;
    bool isAnyAppOpen() const;
    
    static void updateIOSVersion();
    static int getNumberOfiPads();
    
private:
    int typeOfLockScreen;
    TouchID touchID;
    
    /* STATIC VARIABLES */
    static float latestIOSVersion;
    static int numberOfiPads;
    
    /* CONSTANTS */
    const static int TOUCH_ID = 1;
    const static int PASSWORD = 2;
    
    /** HELPER FUNCTIONS
     * 
     * The following functions were designed to help the main functions perfomr
     */
    
    
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
