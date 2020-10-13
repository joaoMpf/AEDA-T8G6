#ifndef AEDA_T8G6_TOLL_H
#define AEDA_T8G6_TOLL_H

#include "lane.h"

using namespace std;

class Toll {
protected:
    string name, location;
    vector<Lane> lanes;

public:
    const string &getName() const;

    void setName(const string &name);

    const string &getLocation() const;

    void setLocation(const string &location);

    const vector<Lane> &getLanes() const;

    void setLanes(const vector<Lane> &lanes);
};

class In : public Toll {

};

class Out : public Toll {

};


#endif //AEDA_T8G6_TOLL_H
