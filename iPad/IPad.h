#ifndef IPAD_H
#define IPAD_H

# include <string>
# include <vector>

using namespace std;

class IPad
{
public:
    IPad();
    ~IPad();
    
    void turnOn();
    void turnOff();
    bool isOn();
    bool installApp(string);
    bool uninstallApp();
    bool uninstallApp(string);
    void checkAppsInstalled();
    void getInformation();
    bool openApp();
    bool openApp(string);
    bool closeApp();
    bool closeApp(string);
    
private:
    bool isTurnedOn;
    float processorSpeed;
    string operatingSystem;
    float displaySize;
    float storageCapacity; // Em GB
    float rearCamera;
    float frontCamera;
    string color;
    vector<string> appsInstalled;
    vector<string> activeApps;
};

#endif // IPAD_H
