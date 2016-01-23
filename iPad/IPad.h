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
    IPad(int storage, float cpuSpeed = 1, float versionOS = 9.2, float display = 7.9, float backCam = 5, float frontCam = 1.2, string iPadColor = "WHITE");
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
        Uninstalls an specific app in the iPad.
        
        @param name of the app.
        @return boolean value, indicating if the app was successfully uninstalled.
    */
    bool uninstallApp(string);
    
    /**
        Prints a list of the apps installed in the iPad.
        
        @return boolean value. Returns true if there is any app installed, false otherwise.
    */
    bool showAppsInstalled();
    
    /**
        Prints a list of the apps opened in the iPad.
        
        @return boolean value. Returns true if there is any app open, false otherwise.
    */
    bool showAppsOpened();
    
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
        Closes an specific app in the iPad.
        
        @return boolean value, indicating if the app was successfully closed.
    */
    bool closeApp(string);
    
    /**
        Closes all active apps.
        
        @return boolean value, indicating if alls apps were successfully closed.
    */
    bool closeAllApps();
    
    /**
        Uninstall all apps.
        
        @return boolean value, indicating if alls apps were successfully uninstalled.
    */
    bool uninstallAllApps();
    
    /** HELPER FUNCTIONS
     * 
     * The following functions were designed to help the main functions perfomr
     */
     
    bool isOn();
    bool isAppInstalled(string);
    bool isAppOpened(string name);
    
    // At the construction of the object, the attributes get set to default values, if no parameters were given.
    void setSpecsToDefault();
    void installDefaultApps();
    float validateValue(float, float, float, string);
    
private:
    bool isTurnedOn;
    float processorSpeed; // Measured in GHz
    float operatingSystem; // Indicate the version of the iOS.
    float displaySize; // Measured in inches
    float storageCapacity; // Measured in GB
    float freeMemory; // Measured in GB
    float rearCamera; // Measured in MP
    float frontCamera; // Measured in MP
    string color;
    unordered_map<string, float> appsInstalled;
    vector<string> activeApps;
};

#endif // IPAD_H
