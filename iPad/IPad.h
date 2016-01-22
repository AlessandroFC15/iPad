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
    ~IPad();
    
    void turnOn();
    void turnOff();
    bool isOn();
    bool installApp(string, float);
    bool uninstallApp();
    bool uninstallApp(string);
    void checkAppsInstalled();
    void getInformation();
    bool openApp();
    bool openApp(string);
    bool closeApp();
    bool closeApp(string);
    bool isAppInstalled(string);
    
private:
    bool isTurnedOn;
    float processorSpeed;
    string operatingSystem;
    float displaySize;
    float storageCapacity; // Em GB
    float freeMemory;
    float rearCamera;
    float frontCamera;
    string color;
    unordered_map<string, float> appsInstalled;
    vector<string> activeApps;
};

#endif // IPAD_H
