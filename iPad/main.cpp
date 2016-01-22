# include <string>
# include <iostream>
# include "IPad.h"

using namespace std;

void menu(IPad& iPad);

int main(int argc, char **argv)
{
    IPad myiPad(1.4, 9, 7, 64, 5, 1.4, "white");
    
    menu(myiPad);
    
    return 0;
}

void menu(IPad& iPad)
{
    int op;
    
    do 
    {
        cout << "\n|| iPad Control Center ||";
        cout << "\n\n1 => ";
        cout << "\n\n2 => Install App";
        cout << "\n\n3 => Uninstall App";
        cout << "\n\n4 => Show Apps Installed";
        cout << "\n\n5 => Get iPad Specs";
        cout << "\n\n6 => Open App";
        cout << "\n\n7 => Close App";
        cout << "\n\n8 => Close All Apps";
        cout << "\n\n9 => Turn On";
        cout << "\n\n10 => Turn Off";
        cout << "\n\n11  => Quit";
        cout << "\n\n>> Enter your option: ";
        cin >> op;
        
        switch (op)
        {
            case 1:
                break;
            case 2:
                // Present list of apps to install or choose to install own app
                break;
            case 3:
                // Present list of apps that can be unistalled.
                break;
            case 4:
                iPad.showAppsInstalled();
                break;
            case 5:
                iPad.getInformation();
                break;
            case 6:
                // Present list of apps that can be opened.
                break;
            case 7:
                // Present list of active apps that can be closed.
                break;
            case 8:
                iPad.closeAllApps();
                break;
            case 9:
                if (iPad.isOn())
                {
                    cout << "\n\n# iPad is already turned on.";
                } else
                {
                    iPad.turnOn();
                    cout << "\n\n# iPad is now turned on.";
                }
                
                break;
            case 10:
                if (not iPad.isOn())
                {
                    cout << "\n\n# iPad is already turned off.\n\n";
                } else
                {
                    iPad.turnOff();
                    cout << "\n\n# iPad is now turned off.\n\n";
                }
            
                break;
            case 11:
                cout << "\n\n# PROGRAM FINISHED #";
                break;
                
            default:
                cout <<"\n\n# Invalid option. Try again.";
                break;
        }
        
    } while (op != 11);
}