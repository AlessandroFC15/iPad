#ifndef IPAD_H
#define IPAD_H

# include <string>
# include <tr1/unordered_map>
# include <vector>

using namespace std::tr1;
using namespace std;

class IPad
{
public:
    IPad();
    IPad(int storage, float cpuSpeed = 1, float versionOS = 9.2, float display = 7.9, string iPadColor = "WHITE");
    ~IPad();
    
    void turnOn();
    void turnOff();
    
    /**
        Installs an app in the iPad.

        @param name of the app.
        @param size of the app in MB.
        @return boolean value, indicating if the app was successfully installed.
    */
    bool installApp(string, float);

    /**
        Uninstalls an app in the iPad.
        
        @param name of the app.
        @return boolean value, indicating if the app was successfully uninstalled.
    */
    bool uninstallApp(string);
    
    /**
        Prints a list of the apps installed in the iPad.
    */
    void showAppsInstalled();
    
    /**
        Prints a list of the apps open in the iPad.
    */
    void showActiveApps();
    
    /**
        Prints to the screen information about the iPad, including:
         * processorSpeed
         * operatingSystem
         * displaySize
         * storageCapacity
         * freeMemory
         * rearCamera, frontCamera
    */
    void getInformation();

    /**
        Opens an specific app in the iPad.
        
        @param name of the app.
        @return boolean value, indicating if the app was successfully opened.
    */
    bool openApp(string);
 
    /**
        Closes an app in the iPad, given its name.
        
        @return boolean value, returning true only if the app was open and after the
        function is closed. Any other case will return false.
    */
    bool closeApp(string);
    
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
    
    
    /** HELPER FUNCTIONS
     * 
     * The following functions were designed to help the main functions perfomr
     */
     
    bool isOn();
    bool isAppInstalled(string);
    bool isAppOpened(string);
    bool isIPadEmpty();
    
    // At the construction of the object, the attributes get set to default values, if no parameters were given.
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
    float validateValue(float value, float min , float max, string name);
    
    void setLockScreenPassword();

    bool isScreenUnlocked();
    
    bool isAnyAppOpen();
    
private:
    bool isTurnedOn;
    float processorSpeed; // Measured in GHz
    float operatingSystem; // Indicate the version of the iOS.
    float displaySize; // Measured in inches
    float storageCapacity; // Measured in GB
    float freeMemory; // Measured in GB
    string color;
    unordered_map<string, float> appsInstalled;
    vector<string> activeApps;
    int lockScreenPassword;
    bool screenLocked;
};

#endif // IPAD_H
