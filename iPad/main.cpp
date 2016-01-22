# include <stdio.h>
# include <string>
# include <iostream>
# include "IPad.h"

using namespace std;

int main(int argc, char **argv)
{
    IPad myiPad;
    
    myiPad.installApp("iTunes", 30);
    
    myiPad.installApp("Instagram", 30);
    
    myiPad.uninstallApp("iTunes");

	return 0;
}
