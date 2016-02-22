#ifndef TOUCHID_H
#define TOUCHID_H

# include <tr1/unordered_map>
# include <string>

using namespace std::tr1;
using namespace std;

class TouchID
{
public:
    TouchID();
    ~TouchID();
    bool addFingerPrint();
    bool removeFingerPrint();
    bool removeAllFingerPrints();
    bool checkForFingerPrint(const string &);
    bool unlockScreen();
private:
    // unordered_map<string, pair <int, float >> registeredFingerprints;
    // string nameOfUser => pair <int fingerUsed, float timeToHold>
    unordered_map<string, int> registeredFingerprints;
    void showFingerPrintsRegistered();
    bool isAnyFingerPrintRegistered();
};

#endif // TOUCHID_H
