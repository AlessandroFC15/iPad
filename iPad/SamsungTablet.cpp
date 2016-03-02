#include "SamsungTablet.h"

SamsungTablet::SamsungTablet()
{
    cout << ".:. Samsung Tablet Creation .:.\n";

    penActive = false;
    activeNFC = false;

    installDefaultApps();
    
    setLockScreenPassword();
}

SamsungTablet::SamsungTablet(int storage)
:Tablet(storage)
{
    cout << ".:. Samsung Tablet Creation .:.\n";

    penActive = false;
    activeNFC = false;

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
}

SamsungTablet::~SamsungTablet()
{
}

ostream &operator<<(ostream &output, const SamsungTablet &tablet)
{
    output << static_cast< Tablet > (tablet);
    output << "\n\n.: SamsungTablet Specs :.\n"
    << "\n>> PEN ACTIVE = " << (tablet.penActive? "YES":"NO")
    << "\n>> NFC ACTIVE = " << (tablet.activeNFC? "YES":"NO");
    
    tablet.showAppsInstalled();
    
    return output;
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