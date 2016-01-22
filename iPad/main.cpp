# include <stdio.h>
# include <string>
# include <iostream>
# include "IPad.h"

using namespace std;

int main(int argc, char **argv)
{
    IPad myiPad(10);
    
    myiPad.checkAppsInstalled();

	return 0;
}
