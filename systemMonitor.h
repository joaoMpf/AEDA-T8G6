#ifndef AEDA_T8G6_SYSTEMMONITOR_H
#define AEDA_T8G6_SYSTEMMONITOR_H

#include "toll.h"

using namespace std;

//Main class com Menu
class SystemMonitor {
private:
    vector<Toll *> tolls;

public:
    const vector<Toll *> &getTolls() const;

    void setTolls(const vector<Toll *> &tolls);
};


#endif //AEDA_T8G6_SYSTEMMONITOR_H
