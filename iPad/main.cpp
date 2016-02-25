# include <string>
# include <iostream>
# include "IPad.h"
# include "TouchID.h"

using namespace std;

void menu(IPad& iPad);
void chooseAppToInstall(IPad& iPad);
void chooseAppToUninstall(IPad& iPad);
void chooseAppToOpen(IPad& iPad);
void chooseAppToClose(IPad& iPad);

int main(int argc, char **argv)
{
    IPad iPad1(64), iPad2(64);
    
    // Uso do cout
    cout << iPad1;
    
    // Teste da igualdade
    cout << (iPad1 == iPad2? "\nEQUAL":"\nDIFFERENT");
    
    // Atribuição
    iPad2 = iPad1;
    
    // Teste de igualdade, novamente
    cout << (iPad1 == iPad2? "\nEQUAL":"\nDIFFERENT");
    
    cout << (iPad1 <= iPad2? "\n1ST LOWER":"\n2ND LOWER");

    return 0;
}

void menu(IPad& iPad)
{
    int op;
    
    do 
    {
        cout << "\n\t\t|| iPad Control Center ||\n";
        cout << "\n1 => Show Open Apps";
        cout << "\t\t2 => Install App";
        cout << "\n\n3 => Uninstall App";
        cout << "\t\t4 => Show Apps Installed";
        cout << "\n\n5 => Get iPad Specs";
        cout << "\t\t6 => Open App";
        cout << "\n\n7 => Close App";
        cout << "\t\t\t8 => Close All Apps";
        cout << "\n\n9 => Uninstall All Apps";
        cout << "\t\t10 => Turn Wi-Fi On";
        cout << "\n\n11 => Turn Wi-Fi Off";
        cout << "\t\t12 => Turn Mobile Data On";
        cout << "\n\n13 => Turn Mobile Data Off";
        cout << "\t14 => Unlock Screen";
        cout << "\n\n15 => Lock Screen";
        cout << "\t\t16 => Turn On";
        cout << "\n\n17 => Turn Off";
        cout << "\t\t\t18 => Get Number of iPads Created";
        cout << "\n\n19 => Update iOS Version";
        cout << "\t20 => Quit";
        cout << "\n\n>> Enter your option: ";
        cin >> op;
        
        // For the options between 1 and 13, the program will only proceed if the iPad is turned on 
        // and also if it is unlocked.
        
        if (op >= 1 && op <= 13)
        {
            if (iPad.isOn())
            {
                if (iPad.isScreenUnlocked())
                {
                    // With the iPad on and unlocked, we can proceed to perform the option choosen.
                    switch (op)
                    {
                        case 1:
                            iPad.showActiveApps();
                            break;
                        case 2:
                            // To download any app, internet must be available
                            if (iPad.isInternetAvailable())
                            {
                                chooseAppToInstall(iPad);
                            } else
                            {
                                cout << "\n# There is no internet connection to download apps. \n# Turn WiFi or mobile data on. \n";
                            }
                            break;
                        case 3:
                            chooseAppToUninstall(iPad);
                            break;
                        case 4:
                            iPad.showAppsInstalled();
                            break;
                        case 5:
                            cout << iPad;
                            break;
                        case 6:
                            chooseAppToOpen(iPad);
                            break;
                        case 7:
                            chooseAppToClose(iPad);
                            break;
                        case 8:
                            iPad.closeAllApps();
                            break;
                        case 9:
                            iPad.uninstallAllApps();
                            break;
                        case 10:
                            iPad.turnWiFiOn();
                            break;
                        case 11:
                            iPad.turnWiFiOff();
                            break;
                        case 12:
                            iPad.turnMobileDataOn();
                            break;
                        case 13:
                            iPad.turnMobileDataOff();
                            break;
                    }
                } else 
                {
                    cout << "\n# Unlock the iPad screen first #\n";
                }
            } else 
            {
                cout << "\n# Turn the iPad on first #\n";
            }
            
        } else if (op >= 14 && op <= 15)
        {
            // For the options 14 and 15, we will only check if the iPad is on.
            if (iPad.isOn())
            {
                switch (op)
                {
                    case 14:
                        iPad.unlockScreen();
                        break;
                    case 15:
                        iPad.lockScreen();
                        break;
                }
            } else 
            {
                 cout << "\n# Turn the iPad on first #\n";
            }
        } else 
        {
            // For the other options, there are no pre-conditions that the iPad must be in.
            switch (op)
            {
                case 16:
                    iPad.turnOn();
                    break;
                case 17:
                    iPad.turnOff();
                    break;
                case 18:
                    cout << ">> NUMBER OF IPADS = " << IPad::getNumberOfiPads();
                    break;
                case 19:
                    IPad::updateIOSVersion();
                    cout << ">> IOS Version update for all iPads. ";
                    break;
                case 20:
                    cout << "\n# PROGRAM FINISHED #\n";
                    break;
                default:
                    cout <<"\n\n# Invalid option. Try again.";
                    break;
            }
        }
    } while (op != 20);
}

// FUNCTIONS

void chooseAppToInstall(IPad& iPad)
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

void chooseAppToUninstall(IPad& iPad)
{
    cin.ignore();
    
    // Check to see if the iPad is not empty
    if (not iPad.isIPadEmpty())
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

void chooseAppToOpen(IPad& iPad)
{
    cin.ignore();
    
    // Check to see there are apps installed to open
    if (not iPad.isIPadEmpty())
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

void chooseAppToClose(IPad& iPad)
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