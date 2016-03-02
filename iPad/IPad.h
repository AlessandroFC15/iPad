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
    // Overload of operators
    const IPad &operator=(const IPad &);
    bool operator==(const IPad &) const;
    bool operator!=(const IPad &iPad) const
    {
        return ! (*this == iPad);
    }
    bool operator>(const IPad &) const;
    bool operator<(const IPad &) const;
    bool operator>=(const IPad &) const;
    bool operator<=(const IPad &) const;
    
    // Constructors
    IPad();
    IPad(int storage);
    IPad(const IPad &);
    ~IPad();
    
    /**
        Uninstall all apps.
        
        @return boolean value, returning true if the iPad wasn't empty and all apps were uninstalled.
        The function will return false if the iPad was empty before the execution.
    */
    bool unlockScreen();
    
    static void updateIOSVersion();
    static int getNumberOfiPads();
    
private:
    int typeOfLockScreen;
    TouchID touchID;
    
    /* STATIC VARIABLES */
    static float latestIOSVersion;
    static int numberOfiPads;
    
    /* CONSTANTS */
    const static int TOUCH_ID = 1;
    const static int PASSWORD = 2;
    
    /** HELPER FUNCTIONS
     * 
     * The following functions were designed to help the main functions perfomr
     */
    
    void installDefaultApps();
    void setInitialSecuritySystem();
    void setTouchID();
    bool unlockPassword();
    bool unlockTouchID();
};

#endif // IPAD_H
