#ifndef SAMSUNGTABLET_H
#define SAMSUNGTABLET_H

# include "Tablet.h"

class SamsungTablet : public Tablet
{
    friend ostream &operator<<(ostream &, const SamsungTablet &);
public:
    SamsungTablet();
    SamsungTablet(int);
    SamsungTablet(const SamsungTablet &);
    ~SamsungTablet();
private:
    bool penActive;
    bool activeNFC; // NFC = Near Field Communication
    
    /** HELPER FUNCTIONS
     * 
     * The following functions were designed to help the main functions perfomr
     */
    
    void installDefaultApps();
};

#endif // SAMSUNGTABLET_H
