# include <string>
# include <iostream>
# include <vector>
# include <typeinfo>
# include "Tablet.h"
# include "IPad.h"
# include "SamsungTablet.h"

using namespace std;

void newMenu(Tablet *tablet);
void chooseAppToInstall(Tablet& iPad);
void chooseAppToUninstall(Tablet& iPad);
void chooseAppToOpen(Tablet& iPad);
void chooseAppToClose(Tablet& iPad);
bool isInstanceOfIPad(Tablet *tablet);
bool isInstanceOfSamsung(Tablet *tablet);

const static int IPAD = 0;
const static int SAMSUNG = 1;

int main(int argc, char **argv)
{
    newMenu(new IPad());
    
    /*
    vector<Tablet*> tablet;
    
    tablet.push_back(new IPad());
    tablet.push_back(new SamsungTablet());
    tablet.push_back(new IPad(128));
    tablet.push_back(new SamsungTablet(64));
    
    for (Tablet *tabletPt : tablet)
    {
        cout << *tabletPt;
    }

    for (size_t i = 0; i < tablet.size(); i++)
    {
        // downcast pointer
        IPad *iPadPtr = dynamic_cast < IPad * > ( tablet[ i ] );
        
        if (iPadPtr != 0)
        {
            // We will print only the iPad objects
            cout << *iPadPtr;
            
            // We procceed then to try to unlock the iPad's screens.
            iPadPtr->unlockScreen();
        }
    }
    
    // Show the type of all tablet objects
    for (size_t j = 0; j < tablet.size(); j++)
    {
        cout << "\nObject of class: " << typeid(*tablet[j]).name();
    }
    
    tablet.clear();*/
    
}

void newMenu(Tablet *tablet)
{
    // Downcast pointer that will be used if the tablet is a Samsung.
    SamsungTablet *samsungPtr = dynamic_cast < SamsungTablet * > (tablet);
    
    int typeOfObject;
    
    if (isInstanceOfIPad(tablet))
    {
        typeOfObject = IPAD;
    } else if (isInstanceOfSamsung(tablet))
    {
        typeOfObject = SAMSUNG;
    } else
    {
        return;
    }
    
    int op;
    
    do 
    {
        // The options will change accordingly to the type of object.
        
        cout << "\n\t\t|| " << (typeOfObject == IPAD? "iPad" : "Samsung") << " Control Center ||\n"
        << "\n1 => Show Open Apps"
        << "\t\t2 => Install App"
        << "\n\n3 => Uninstall App"
        << "\t\t4 => Show Apps Installed"
        << "\n\n5 => Get " << (typeOfObject == IPAD? "iPad" : "Samsung") << " Specs"
        << "\t\t6 => Open App"
        << "\n\n7 => Close App"
        << "\t\t\t8 => Close All Apps"
        << "\n\n9 => Uninstall All Apps"
        << "\t\t10 => Turn Wi-Fi On"
        << "\n\n11 => Turn Wi-Fi Off"
        << "\t\t12 => Turn Mobile Data On"
        << "\n\n13 => Turn Mobile Data Off"
        << "\t14 => Unlock Screen"
        << "\n\n15 => Lock Screen"
        << "\t\t16 => Turn On"
        << "\n\n17 => Turn Off"
        << "\t\t\t18 => " << (typeOfObject == IPAD? "Get Number of iPads Created" : "Insert SD Card")
        << "\n\n19 => " << (typeOfObject == IPAD? "Update iOS Version" : "Remove SD Card")
        << (typeOfObject == SAMSUNG? "\t\t20 => Change SD Card\n\n" : "\t")
        << "-1 => Quit"
        << "\n\n>> Enter your option: ";
        cin >> op;
        
        // For the options between 1 and 13, the program will only proceed if the tablet turned on 
        // and also if it is unlocked.
        
        if (op >= 1 && op <= 13)
        {
            if (tablet->isOn())
            {
                if (tablet->isScreenUnlocked())
                {
                    // With the tablet on and unlocked, we can proceed to perform the option choosen.
                    switch (op)
                    {
                        case 1:
                            tablet->showActiveApps();
                            break;
                        case 2:
                            // To download any app, internet must be available
                            if (tablet->isInternetAvailable())
                            {
                                chooseAppToInstall(*tablet);
                            } else
                            {
                                cout << "\n# There is no internet connection to download apps. \n# Turn WiFi or mobile data on. \n";
                            }
                            break;
                        case 3:
                            chooseAppToUninstall(*tablet);
                            break;
                        case 4:
                            tablet->showAppsInstalled();
                            break;
                        case 5:
                            cout << *tablet;
                            break;
                        case 6:
                            chooseAppToOpen(*tablet);
                            break;
                        case 7:
                            chooseAppToClose(*tablet);
                            break;
                        case 8:
                            tablet->closeAllApps();
                            break;
                        case 9:
                            tablet->uninstallAllApps();
                            break;
                        case 10:
                            tablet->turnWiFiOn();
                            break;
                        case 11:
                            tablet->turnWiFiOff();
                            break;
                        case 12:
                            tablet->turnMobileDataOn();
                            break;
                        case 13:
                            tablet->turnMobileDataOff();
                            break;
                    }
                } else 
                {
                    cout << "\n# Unlock the tablet sreen first #\n";
                }
            } else 
            {
                cout << "\n# Turn the tablet on first #\n";
            }
            
        } else if (op >= 14 && op <= 15)
        {
            // For the options 14 and 15, we will only check if the tablet is on.
            if (tablet->isOn())
            {
                switch (op)
                {
                    case 14:
                        tablet->unlockScreen();
                        break;
                    case 15:
                        tablet->lockScreen();
                        break;
                }
            } else 
            {
                 cout << "\n# Turn the tablet on first #\n";
            }
        } else 
        {
            // For the other options, there are no pre-conditions that the iPad must be in.
            switch (op)
            {
                case 16:
                    tablet->turnOn();
                    break;
                case 17:
                    tablet->closeAllApps();
                    tablet->turnOff();
                    break;
                case 18:
                    if (typeOfObject == IPAD)
                    {
                        cout << ">> NUMBER OF IPADS = " << IPad::getNumberOfiPads();
                    } else
                    {
                        samsungPtr->insertSDCard();
                    }
                    
                    break;
                case 19:
                    if (typeOfObject == IPAD)
                    {
                        IPad::updateIOSVersion();
                        cout << ">> IOS Version update for all iPads. ";
                    } else
                    {
                        samsungPtr->removeSDCard();
                    }
                    
                    break;
                case 20:
                    if (typeOfObject == IPAD)
                    {
                        cout <<"\n\n# Invalid option. Try again.";
                    } else
                    {
                        samsungPtr->changeSDCard();
                    }
                    
                    break;
                case -1:
                    cout << "\n# PROGRAM FINISHED #\n";
                    break;
                default:
                    cout <<"\n\n# Invalid option. Try again.";
                    break;
            }
        }
    } while (op != -1); 
}

// FUNCTIONS

void chooseAppToInstall(Tablet& iPad)
{
    // Array of pairs to hold the apps to be presented in App Store
    pair<string, float> appsToInstall[10] = {{"Instagram", 23}, {"Facebook", 108},
                                             {"Snapchat", 73}, {"Messenger", 89},
                                             {"Uber", 63}, {"Spotify", 84},
                                             {"Netflix", 33}, {"Twitter", 69},
                                             {"Google Maps", 47}, {"Periscope", 17}};
    int op;
    
    do 
    {
        cout << "\n\t\t.: App Store :.\n";
        int i;
        
        // Present every app of the array declared above
        for (i = 0; i < 10; i++)
        {
            cout << "\n" << i + 1 << " => " << appsToInstall[i].first << " (" << appsToInstall[i].second << "MB)"; 
        }
        cout << "\n" << 11 << " => Install Another App";
        cout << "\n" << 12 << " => Quit App Store";
        
        cout << "\n\n>> Enter your choice: ";
        cin >> op;
        
        if (op >= 1 && op <= 10)
        {
            iPad.installApp(appsToInstall[op - 1].first, appsToInstall[op - 1].second);
        } else if (op == 11)
        {
            string nameOfApp;
            float sizeOfApp;
            
            // Validate the name of the app.
            while (true)
            {
                cout << "\n\n>> Enter name of app (Max 25 chars): ";
                cin.ignore();
                getline(cin, nameOfApp);
                
                if (nameOfApp.length() > 0)
                {
                    nameOfApp = nameOfApp.substr(0, 25);
                    break;
                }
                
                cout << "\n# Invalid name. Try again.";
            }
            
            // Validate the size of the app.
            while (true)
            {
                cout << "\n\n>> Enter size of app in MB: ";
                cin >> sizeOfApp;
                
                if (sizeOfApp > 0)
                {
                    break;
                }
                
                cout << "\n# Invalid size. Try again.";
            }
                
            iPad.installApp(nameOfApp, sizeOfApp);
            
        } else if (op == 12)
        {
            cout << "\n# App Store closed #\n";
        } else
        {
            cout << "\n# Invalid option. Try again #\n";
        }
    } while (op != 12);
}

void chooseAppToUninstall(Tablet& iPad)
{
    cin.ignore();
    
    // Check to see if the iPad is not empty
    if (not iPad.isDeviceEmpty())
    {
        // Show a list of installed apps
        iPad.showAppsInstalled();
        
        // Ask the user to select an app
        while (true)
        {
            string nameOfApp;
            
            cout << "\n>> Enter name of the app to be uninstalled (X to quit): "; 
            getline(cin, nameOfApp);
            
            if (nameOfApp == "X" || nameOfApp == "x")
            {
                break;
            }
            
            iPad.uninstallApp(nameOfApp);
        }
        
    } else 
    {
        cout << "\n|| There are no apps installed ||\n";
    }
}

void chooseAppToOpen(Tablet& iPad)
{
    cin.ignore();
    
    // Check to see there are apps installed to open
    if (not iPad.isDeviceEmpty())
    {
        // Show a list of installed apps
        iPad.showAppsInstalled();
        
        // Ask the user to select an app to open
        while (true)
        {
            string nameOfApp;
            
            cout << "\n>> Enter name of the app to open (X to quit): "; 
            getline(cin, nameOfApp);
            
            if (nameOfApp == "X" || nameOfApp == "x")
            {
                break;
            }
            
            iPad.openApp(nameOfApp);
        }
    } else 
    {
        cout << "\n|| There are no apps installed ||\n";
    }
}

void chooseAppToClose(Tablet& iPad)
{
    cin.ignore();
    
    // Check to see if there are any apps active
    if (iPad.isAnyAppOpen())
    {
        // Show apps that are open.
        iPad.showActiveApps();
        
        while (true)
        {
            string nameOfApp;
            
            cout << "\n>> Enter name of the app to close (X to quit): "; 
            getline(cin, nameOfApp);
            
            if (nameOfApp == "X" || nameOfApp == "x")
            {
                break;
            }
            
            iPad.closeApp(nameOfApp);
        }
    } else 
    {
        cout << "\n|| There are no apps open ||\n";
    }
}

bool isInstanceOfIPad(Tablet *tablet)
{
    return typeid(*tablet).name() == typeid(IPad).name();
}

bool isInstanceOfSamsung(Tablet *tablet)
{
    return typeid(*tablet).name() == typeid(SamsungTablet).name();
}
