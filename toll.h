#ifndef AEDA_T8G6_TOLL_H
#define AEDA_T8G6_TOLL_H

#include "lane.h"

using namespace std;

class Toll {
protected:
    string name, location;
    vector<Lane> lanes;
    bool type; //SE FOR TRUE É SAIDA SENAO entrada


public:
    Toll(string n, string loc,bool type1, vector<Lane> l):
        name(n), location(loc),type(type1), lanes(l){

    }

    ~Toll(){};

    const string &getName() const;

    const string &getLocation() const;

    const vector<Lane> &getLanes() const;

    const bool &getType() const;

    void exitToll(string basicString);

    void enterToll(string basicString);
};


class In : public Toll {

};

class Out : public Toll {

};


#endif //AEDA_T8G6_TOLL_H
