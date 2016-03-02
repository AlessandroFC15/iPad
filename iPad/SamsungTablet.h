#ifndef SAMSUNGTABLET_H
#define SAMSUNGTABLET_H

# include "Tablet.h"

class SamsungTablet : public Tablet
{
public:
    SamsungTablet();
    SamsungTablet(int);
    ~SamsungTablet();
private:
    bool penActive;
    bool activeNFC; // NFC = Near Field Communication
    
    /** HELPER FUNCTIONS
     * 
     * The following functions were designed to help the main functions perfomr
     */
    
    void setSpecsToDefault();
    void installDefaultApps();
};

#endif // SAMSUNGTABLET_H
