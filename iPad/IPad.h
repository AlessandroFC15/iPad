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
    IPad(int storage);
    IPad(float cpuSpeed, float versionOS, float display, int storage, float backCam, float frontCam, string iPadColor);
    ~IPad();
    
    void turnOn();
    void turnOff();
    bool isOn();
    
    /**
        Installs an app in the iPad.

        @param name of the app.
        @param size of the app in GB.
        @return boolean value, indicating if the app was successfully installed.
    */
    bool installApp(string, float);
    
    /**
        Uninstalls an app in the iPad, given a list of apps installed.
        
        @return boolean value, indicating if the app was successfully uninstalled.
    */
    bool uninstallApp();
    
    /**
        Uninstalls an specific app in the iPad.
        
        @param name of the app.
        @return boolean value, indicating if the app was successfully uninstalled.
    */
    bool uninstallApp(string);
    
    /**
        Prints a list of the apps installed in the iPad.
    */
    void checkAppsInstalled();
    
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
        Opens an app, given a list of apps installed.
        
        @return boolean value, indicating if the app was successfully opened.
    */
    bool openApp();
    
    /**
        Opens an specific app in the iPad.
        
        @param name of the app.
        @return boolean value, indicating if the app was successfully opened.
    */
    bool openApp(string);
    
    /**
        Closes an app, given a list of active apps.
        
        @return boolean value, indicating if the app was successfully closed.
    */
    bool closeApp();
    
    /**
        Closes an specific app in the iPad.
        
        @return boolean value, indicating if the app was successfully closed.
    */
    bool closeApp(string);
    
    /**
        Check to see if an app is installed in the iPad.

        @param name of the app.
        @return boolean value, indicating if the apps in indeed installed or not.
    */
    bool isAppInstalled(string);
    
    void setSpecsToDefault();
    
    void installDefaultApps();
    
    void validateStorageValue(int);
    
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
