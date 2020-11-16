#ifndef AEDA_T8G6_TOLL_H
#define AEDA_T8G6_TOLL_H

#include <utility>
#include <vector>
#include <iostream>
#include "lane.h"

using namespace std;

class Toll {
protected:
    string name, location;
//    int code;
    vector<Lane *> lanes;

public:
    Toll(string n, string loc, vector<Lane *> l) :
            name(std::move(n)), location(std::move(loc)), lanes(std::move(l)) {}

    ~Toll() {};

    const string &getName() const;

    const string &getLocation() const;

    const vector<Lane *> &getLanes() const;

    virtual bool isExitToll() const { return false; }

    Lane *getRecommendedLane(bool isViaVerde);

    vector<Lane *> getTypeLanes(bool isViaVerde);

    vector<Lane *> getViaVerdeLanes();

    vector<Lane *> getNormalLanes();
};


class InToll : public Toll {
public:
    InToll(const string &n, const string &loc, const vector<Lane *> &l);

public:
    bool isExitToll() const override;
};

class OutToll : public Toll {
public:
    OutToll(const string &n, const string &loc, const vector<Lane *> &l);

private:
    bool isExitToll() const override;
};


#endif //AEDA_T8G6_TOLL_H
