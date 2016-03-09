#ifndef SAMSUNGTABLET_H
#define SAMSUNGTABLET_H

# include "Tablet.h"

class SamsungTablet : public Tablet
{
    friend ostream &operator<<(ostream &, const SamsungTablet &);
public:
    const SamsungTablet &operator=(const SamsungTablet &);

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
    
    // HELPER FUNCTION
    void installDefaultApps();
};

#endif // SAMSUNGTABLET_H
