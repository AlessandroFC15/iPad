#include "SamsungTablet.h"

using namespace std;

ostream &operator<<(ostream &output, const SamsungTablet &tablet)
{
    output << static_cast< Tablet > (tablet);
    output << "\n\n.: SamsungTablet Specs :.\n"
    << "\n>> PEN ACTIVE = " << (tablet.penActive? "YES":"NO")
    << "\n>> NFC ACTIVE = " << (tablet.activeNFC? "YES":"NO");
    
    tablet.showAppsInstalled();
    
    return output;
}

SamsungTablet::SamsungTablet()
{
    cout << ".:. Samsung Tablet Creation .:.\n";

    penActive = false;
    activeNFC = false;
    externalSDCard = false;
    sizeSDCard = 0;

    installDefaultApps();
    
    setLockScreenPassword();
}

SamsungTablet::SamsungTablet(int storage)
:Tablet(storage)
{
    cout << ".:. Samsung Tablet Creation .:.\n";

    penActive = false;
    activeNFC = false;
    externalSDCard = false;
    sizeSDCard = 0;

    installDefaultApps();
    
    setLockScreenPassword();
}

SamsungTablet::SamsungTablet(const SamsungTablet &oldTablet)
{
    isTurnedOn = oldTablet.isTurnedOn;
    InitialDate = oldTablet.InitialDate;
    storageCapacity = oldTablet.storageCapacity;
    freeMemory = oldTablet.freeMemory;
    screenLocked = oldTablet.screenLocked;
    lockScreenPassword = oldTablet.lockScreenPassword;
    wiFiOn = oldTablet.wiFiOn;
    mobileDataOn = oldTablet.mobileDataOn;
    appsInstalled = oldTablet.appsInstalled;
    activeApps = oldTablet.activeApps;
    penActive = oldTablet.penActive;
    activeNFC = oldTablet.activeNFC;
    externalSDCard = oldTablet.externalSDCard;
    sizeSDCard = oldTablet.sizeSDCard;
}

SamsungTablet::~SamsungTablet()
{
}

bool SamsungTablet::insertSDCard()
{
    // Check to see if there isn't already a SD Card on the tablet
    if (not externalSDCard)
    {
        int storage;
        cout << "\n>> Enter the size of the SD Card in GB: ";
        //cin(storage);
        
        
        
    } else
    {
        cout << "\n# There is already a SD card inserted in the tablet. #\n";
        cout << "\n# Remove it first and try again! #\n";
    }
    
}


void SamsungTablet::installDefaultApps()
{
    // Installing Google
    appsInstalled["Google"] = 200;
    freeMemory -= 200/1000.0;
    
    // Installing Safari
    appsInstalled["Google Chrome"] = 122;
    freeMemory -= 122/1000.0;
    
    // Installing Youtube
    appsInstalled["YouTube"] = 50;
    freeMemory -= 50/1000.0;
    
    // Installing iTunes
    appsInstalled["Google Play Store"] = 98;
    freeMemory -= 98/1000.0;
}