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
    
    bool insertSDCard();
    bool removeSDCard();
    bool changeSDCard();
    
private:
    bool externalSDCard;
    int sizeSDCard;
    
    /** HELPER FUNCTIONS
     * 
     * The following functions were designed to help the main functions perfomr
     */
    
    void installDefaultApps();
};

#endif // SAMSUNGTABLET_H
