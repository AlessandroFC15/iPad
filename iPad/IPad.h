#ifndef IPAD_H
#define IPAD_H

# include "TouchID.h"
# include "Tablet.h"

using namespace std;

class IPad : public Tablet
{
    friend ostream &operator<<(ostream &, const IPad &);
    friend float operator+(const IPad &, const IPad &);
public:
    IPad();
    IPad(int storage);
    IPad(const IPad &);
    ~IPad();
    
    bool unlockScreen();
    static void updateIOSVersion();
    static int getNumberOfiPads();
private:
    int typeOfLockScreen;
    TouchID touchID;

    // HELPER FUNCTIONS
    void installDefaultApps();
    void setInitialSecuritySystem();
    void setTouchID();
    bool unlockPassword();
    bool unlockTouchID();
    
     /* STATIC VARIABLES */
    static float latestIOSVersion;
    static int numberOfiPads;
    
    /* CONSTANTS */
    const static int TOUCH_ID = 1;
    const static int PASSWORD = 2;
};

#endif // IPAD_H
