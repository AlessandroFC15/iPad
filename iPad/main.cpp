#include <stdio.h>
# include <string>
# include <iostream>
# include "IPad.h"

using namespace std;

int main(int argc, char **argv)
{
	printf("hello world\n\n");
    
    IPad myiPad;
    
    myiPad.turnOn();
    myiPad.turnOff();
    
    cout << myiPad.isOn() << endl;
    
	return 0;
}
