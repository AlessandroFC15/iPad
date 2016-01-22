# include <stdio.h>
# include <string>
# include <iostream>
# include "IPad.h"

using namespace std;

int main(int argc, char **argv)
{
    IPad myiPad(1.4, 9, 7, 64, 5, 1.4, "white");
    
    myiPad.getInformation();
    
    myiPad.openApp("Youtube");
    myiPad.openApp("Safari");
    myiPad.openApp("Google");
    
    cout << "\n\n" << myiPad.isAppOpened("Youtube") << endl;
    cout << "\n\n" << myiPad.isAppOpened("Safari") << endl;
    cout << "\n\n" << myiPad.isAppOpened("Google") << endl;
    
    myiPad.closeAllApps();

    cout << "\n\n" << myiPad.isAppOpened("Youtube") << endl;
    cout << "\n\n" << myiPad.isAppOpened("Safari") << endl;
    cout << "\n\n" << myiPad.isAppOpened("Google") << endl;
     
	return 0;
}
