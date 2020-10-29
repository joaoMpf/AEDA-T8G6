#ifndef AEDA_T8G6_SYSTEMMONITOR_H
#define AEDA_T8G6_SYSTEMMONITOR_H

#include "toll.h"

using namespace std;

//Main class
class SystemMonitor {
private:
    vector<Toll *> tolls;

    vector<Vehicle *> vehicles;



    const vector<Toll *> &getTolls() const;

    void setTolls(const vector<Toll *> &tolls);
public:

    void save();

    void showTollsNumbered();

    void showToll(int toll);
};


#endif //AEDA_T8G6_SYSTEMMONITOR_H
