#include "SamsungTablet.h"

SamsungTablet::SamsungTablet()
{
    cout << ".:. Samsung Tablet Creation .:.\n";
    
    externalSDCard = false;
    sizeSDCard = 0;

    installDefaultApps();
    
    setLockScreenPassword();
}

SamsungTablet::SamsungTablet(int storage)
:Tablet(storage)
{
    cout << ".:. Samsung Tablet Creation .:.\n";

    externalSDCard = false;
    sizeSDCard = 0;

    installDefaultApps();
    
    setLockScreenPassword();
}

SamsungTablet::SamsungTablet(const SamsungTablet &oldTablet)
:Tablet(static_cast< Tablet > (oldTablet))
{
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
        cin >> storage;
        
        sizeSDCard = validateValue(storage, 2, 128, "SD card size");
        
        externalSDCard = true;
        
        storageCapacity += sizeSDCard;
        freeMemory += sizeSDCard;
        
        cout << "\n|| SD Card successfully inserted ||\n";
        
        return true;
    } else
    {
        cout << "\n# There is already a SD card inserted in the tablet. #\n";
        cout << "\n# Remove it first and try again! #\n";
        
        return false;
    }
}

bool SamsungTablet::removeSDCard()
{
    if (externalSDCard)
    {       
        string choice;
         
        cout << "\n>> Are you sure you want to remove your SD Card (" << sizeSDCard << "GB) (Y or N): ";
        cin >> choice;
        
        if (choice == "Y" || choice == "y")
        {
            externalSDCard = false;
            storageCapacity -= sizeSDCard;
            
            // If there isn't enough space in the tablet without the SD card,
            // then all the apps will be uninstalled.
            if (freeMemory - sizeSDCard < 0)
            {
                appsInstalled.clear();
                activeApps.clear();
                freeMemory = storageCapacity;
            } else 
            {
                freeMemory -= sizeSDCard;
            }
            
            sizeSDCard = 0;
            
            cout << "\n|| SD Card successfully removed ||\n";
            
            return true;
        } else
        {
            cout << "\n# SD Card wasn't removed #\n";
            return false;
        }
    } else
    {
        cout << "\n# No SD card to remove in the tablet. #\n";
        return false;
    }
}

bool SamsungTablet::changeSDCard()
{
    if (externalSDCard)
    {
        float storage;
        cout << "\n>> Enter the size of the new SD Card (in GB): ";
        cin >> storage;
        
        if (not removeSDCard())
        {
            return false;
        }
        
        sizeSDCard = validateValue(storage, 2, 128, "SD card size");
        
        externalSDCard = true;
        
        storageCapacity += sizeSDCard;
        freeMemory += sizeSDCard;
        
        cout << "\n|| SD Card successfully changed. ||\n";
        
        return true;
    } else 
    {
        string choice;
        cout << "\n# No SD card to perfom change in the tablet. #";
        cout << "\n>> Would you like to insert a SD Card? (Y or N): ";
        cin >> choice;
        
        if (choice == "Y" || choice == "y")
        {
            return insertSDCard();
        }
        
        return false;
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

// OVERLOAD OF OPERATORS

ostream &operator<<(ostream &output, const SamsungTablet &tablet)
{
    output << static_cast< Tablet > (tablet);
    output << "\n\n.: SamsungTablet Specs :.\n"
    << "\n>> SD CARD INSERTED = " << (tablet.externalSDCard? "YES":"NO");
    if (tablet.externalSDCard) output << "\n>> SIZE OF SD CARD: " << tablet.sizeSDCard << "GB";
    
    tablet.showAppsInstalled();
    
    return output;
}

const SamsungTablet & SamsungTablet::operator=(const SamsungTablet &tablet)
{
    static_cast <Tablet&> (*this) = static_cast <Tablet> (tablet);

    externalSDCard = tablet.externalSDCard;
    sizeSDCard = tablet.sizeSDCard;
    
    return *this;
}