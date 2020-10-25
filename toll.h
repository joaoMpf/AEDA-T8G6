#ifndef AEDA_T8G6_TOLL_H
#define AEDA_T8G6_TOLL_H

#include "lane.h"

using namespace std;

class Toll {
protected:
    string name, location;
    vector<Lane> lanes;

public:
    Toll(string n, string loc, vector<Lane> l):
        name(n), location(loc), lanes(l){}

    ~Toll(){};

    const string &getName() const;

    const string &getLocation() const;

    const vector<Lane> &getLanes() const;

};

class In : public Toll {

};

class Out : public Toll {

};


#endif //AEDA_T8G6_TOLL_H
