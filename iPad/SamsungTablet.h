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
    
    virtual void installDefaultApps();
    
    const SamsungTablet &operator=(const SamsungTablet &);
    bool operator==(const SamsungTablet &) const;
private:
    bool externalSDCard;
    int sizeSDCard;
    
    // HELPER FUNCTION
    
};

#endif // SAMSUNGTABLET_H
