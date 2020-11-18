#ifndef AEDA_T8G6_TOLL_H
#define AEDA_T8G6_TOLL_H

#include <utility>
#include <vector>
#include <iostream>
#include "lane.h"
#include "algorithm"

using namespace std;

class Toll {
protected:
    string name, location;
//    int code;
    vector<Lane *> lanes;
    int position; // this is the position within the highway ex: position = 0km, or 15km, etc
    float price; //price corresponds to the distance between this toll and the previous one

public:
    Toll(string n, string loc, vector<Lane *> l, int pos, float pri) :
            name(std::move(n)), location(std::move(loc)), lanes(std::move(l)),
            position(std::move(pos)), price(pri){};


    ~Toll(){};

    const string &getName() const;

    const string &getLocation() const;

    const vector<Lane *> &getLanes() const;

    virtual bool isExitToll() const { return false; }

    Lane *getRecommendedLane(bool isViaVerde);

    vector<Lane *> getTypeLanes(bool isViaVerde);

    vector<Lane *> getViaVerdeLanes();

    vector<Lane *> getNormalLanes();

    int getPosition() const;

    float getPrice() const;
};


class InToll : public Toll {
public:
    InToll(const string &n, const string &loc, const vector<Lane *> &l, const int &pos, const float &price);

public:
    bool isExitToll() const override;
};

class OutToll : public Toll {
public:
    OutToll(const string &n, const string &loc, const vector<Lane *> &l, const int &pos, const float &price);

private:
    bool isExitToll() const override;
};


#endif //AEDA_T8G6_TOLL_H
