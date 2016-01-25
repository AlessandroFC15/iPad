# include <string>
# include <iostream>
# include "IPad.h"

using namespace std;

void menu(IPad& iPad);
void chooseAppToInstall(IPad& iPad);
void chooseAppToUninstall(IPad& iPad);
void chooseAppToOpen(IPad& iPad);
void chooseAppToClose(IPad& iPad);

int main(int argc, char **argv)
{
    IPad myiPad(64);
    
    menu(myiPad);
    
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
        cout << "\t\t10 => Unlock Screen";
        cout << "\n\n11 => Lock Screen";
        cout << "\t\t12 => Turn On";
        cout << "\n\n13 => Turn Off";
        cout << "\t\t\t14 => Quit";
        cout << "\n\n>> Enter your option: ";
        cin >> op;
        
        // For the options between 1 and 9, the program will only proceed if the iPad is turned on 
        // and also if it is unlocked.
        
        if (op >= 1 && op <= 9)
        {
            if (iPad.isOn())
            {
                if (iPad.isScreenUnlocked())
                {
                    // With the iPad on and unlocked, we can proceed to perform the option choosen.
                    switch (op)
                    {
                        case 1:
                            iPad.showAppsOpened();
                            break;
                        case 2:
                            chooseAppToInstall(iPad);
                            break;
                        case 3:
                            chooseAppToUninstall(iPad);
                            break;
                        case 4:
                            iPad.showAppsInstalled();
                            break;
                        case 5:
                            iPad.getInformation();
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
                    }
                } else 
                {
                    cout << "\n# Unlock the iPad screen first #\n";
                }
            } else 
            {
                cout << "\n# Turn the iPad on first #\n";
            }
            
        } else if (op >= 10 && op <= 11)
        {
            // For the options 10 and 11, we will only check if the iPad is on.
            if (iPad.isOn())
            {
                switch (op)
                {
                    case 10:
                        iPad.unlockScreen();
                        break;
                    case 11:
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
                case 12:
                    iPad.turnOn();
                    break;
                case 13:
                    iPad.turnOff();
                    break;
                case 14:
                    cout << "\n# PROGRAM FINISHED #\n";
                    break;
                default:
                    cout <<"\n\n# Invalid option. Try again.";
                    break;
            }
        }
    } while (op != 14);
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
    
    // Show apps that are installed
    if(iPad.showAppsInstalled())
    {
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
    }
}

void chooseAppToOpen(IPad& iPad)
{
    cin.ignore();
    
    // Show apps that are installed
    if(iPad.showAppsInstalled())
    {
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
    }
}

void chooseAppToClose(IPad& iPad)
{
    cin.ignore();
    
    // Show apps that are open.
    if(iPad.showAppsOpened())
    {
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
    }
}