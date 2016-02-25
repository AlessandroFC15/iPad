#include "TouchID.h"
# include <iostream>

TouchID::TouchID()
{
}

TouchID::~TouchID()
{
}



bool TouchID::addFingerPrint()
{
    cin.ignore();
    string nameOfUser;
    int fingerUsed;

    cout << "\n.: ADD NEW FINGERPRINT :.\n";
    
    // 1st Step = Get the name of the user
    while (true)
    {
        cout << "\n>> Enter your name (Max 25 chars): ";

        getline(cin, nameOfUser);
        
        if (nameOfUser.length() > 0)
        {
            // Check to see if the user isn't already registered
            if (not checkForFingerPrint(nameOfUser))
            {
                break;
            } else
            {
                cout << "\n# The user " << nameOfUser << " is already registered #\n";
            }
        } else
        {
            cout << "\n# Enter a valid name #\n";
        }
    }
    
    // 2nd Step = Get the finger used by the user
    cout << "\n|| FINGERPRINT ||\n";
    cout << "\n| 1 - Left Thumb" << "\t| 6 - Right Thumb"
         << "\n| 2 - Left Index" << "\t| 7 - Right Index"
         << "\n| 3 - Left Middle" << "\t| 8 - Right Middle"
         << "\n| 4 - Left Ring" << "\t\t| 9 - Right Ring"
         << "\n| 5 - Left Pinky" << "\t| 10 - Right Pinky";
    
    while (true)
    {
        cout << "\n\n>> Choose finger to be your TouchID: ";
        cin >> fingerUsed;
        if (fingerUsed >= 1 && fingerUsed <= 10)
        {
            break;
        }
        
        cout << "\n# Enter a valid number (1 to 10). #\n";
    }
    
    cout << "\n|| Fingerprint successfully registered ||\n";
    // 3st Step = Add data to the data structure
    registeredFingerprints[nameOfUser] = fingerUsed;
    
    return true;
}

bool TouchID::checkForFingerPrint(const string &name) const
{
    // Find the user in the unordered map registeredFingerPrints;
    auto lookup = registeredFingerprints.find(name);

    /* If the function "find" above returns something other than an 
     * iterator to the end of the map, that means the element was 
     * found and therefore, is installed.*/
    if (lookup != registeredFingerprints.end())
    {
        return true;
    }
    
    return false;
}

bool TouchID::unlockScreen()
{
    cin.ignore();
    string nameOfUser;
    int fingerUsed;
    
    cout << "\n>> To unlock the screen, please enter your name: ";
    getline(cin, nameOfUser);
    
    // Check to see if there is a user with this name in the database
    if (checkForFingerPrint(nameOfUser))
    {
        while (true)
        {
            cout << "\n>> Enter the finger you registered: ";
            cin >> fingerUsed;
            
            if (fingerUsed >= 1 && fingerUsed <= 10)
            {
                break;
            }
            
            cout << "\n# Enter a valid number (1 to 10). #\n";
        }
        
        if (fingerUsed == registeredFingerprints[nameOfUser])
        {
            cout << "\n|| THE SCREEN IS NOW UNLOCKED ||\n";
            return true;
        } else 
        {
            cout << "\n# Sorry! We couldn't match your fingerprint! #";
            return false;
        }
    } else
    {
        cout << "\n# There are no fingerprints registered in your name #\n";
        return false;
    }
}

// OVERLOAD OF OPERATORS

const TouchID & TouchID::operator=(const TouchID &touchID)
{
    registeredFingerprints = touchID.registeredFingerprints;
    
    return *this;
}

bool TouchID::operator==(const TouchID &touchID) const
{
    return registeredFingerprints == touchID.registeredFingerprints;
}


bool TouchID::removeFingerPrint()
{
    cin.ignore();
    
    if (isAnyFingerPrintRegistered())
    {
        showFingerPrintsRegistered();
    
        string nameOfUser;
        
        cout << "\n>> Enter the name to be removed: ";
        getline(cin, nameOfUser);
        
        if (checkForFingerPrint(nameOfUser))
        {
            registeredFingerprints.erase(nameOfUser);
            cout << "\n|| The user " << nameOfUser << " was successfully erased ||";
            return true;
        } 
        
        cout << "\n# This name isn't registered #";
        return false;
    } else 
    {
        cout << "\n>> There are no fingerprints to be removed <<\n";
        return false;
    }
}

void TouchID::showFingerPrintsRegistered() const
{
    // Check to see if the iPad isn't empty.
    if (isAnyFingerPrintRegistered())
    {
        cout << "\n\n.: FINGERPRINTS :.\n";
        
        // Iterate through the unordered map
        // app holds the pair <nameOfUser, chosenFinger>
        for (auto fingerprint : registeredFingerprints)
        {
            cout << "\nName: " << fingerprint.first << endl;
        }
    } else 
    {
        cout << "\n>> There are no fingerprints registered <<\n";
    }
}

bool TouchID::isAnyFingerPrintRegistered() const
{
    return not registeredFingerprints.empty();
}