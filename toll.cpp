#include "toll.h"
#include <algorithm>

const string &Toll::getName() const {
    return name;
}

const string &Toll::getLocation() const {
    return location;
}

const vector<Lane *> &Toll::getLanes() const {
    return lanes;
}

Lane *Toll::getRecommendedLane(bool isViaVerde) {
    if (lanes.empty())
        return nullptr;

    vector<Lane *> recommendedLanes;

    if (isViaVerde)
        recommendedLanes = getViaVerdeLanes();
    else
        recommendedLanes = getNormalLanes();

    if (recommendedLanes.empty())
        return nullptr;

    return recommendedLanes[0];
}

vector<Lane *> Toll::getTypeLanes(bool isViaVerde) {
    vector<Lane *> typeLanes;

    if (!lanes.empty())
        for (auto lane : lanes)
            if (lane->isViaVerde() == isViaVerde)
                typeLanes.push_back(lane);

    sort(typeLanes.begin(), typeLanes.end()); //sort so lane with less cars appears first
    return typeLanes;
}

vector<Lane *> Toll::getViaVerdeLanes() {
    return getTypeLanes(true);
}

vector<Lane *> Toll::getNormalLanes() {
    return getTypeLanes(false);
}

int Toll::getPosition() const {
    return position;
}

double Toll::getPrice() const {
    return price;
}

void Toll::addLane(Lane *lane) {
    lanes.push_back(lane);
}

void Toll::addLane(ViaVerdeLane *lane) {
    lanes.push_back(lane);
}

void Toll::removeLaneAt(int i) {
    lanes.erase(lanes.begin() + i);
}

ostream &operator<<(ostream &os, const Toll &toll) {
    os << toll.isExitToll() << " " << toll.name << " " << toll.location << " " << toll.lanes.size() << " "
       << toll.position << " " << toll.price;
    if (!toll.lanes.empty()) {
        os << endl;
        for (auto lane : toll.lanes) {
            os << *lane;
            if (toll.lanes.size() > 1)
                os << endl;
        }
    }
    return os;
}

bool InToll::isExitToll() const {
    return false;
}

bool OutToll::isExitToll() const {
    return true;
}

InToll::InToll(const string &n, const string &loc, const vector<Lane *> &l, const int &pos, const double &price) :
        Toll(n, loc, l, pos, price) {}

OutToll::OutToll(const string &n, const string &loc, const vector<Lane *> &l, const int &pos, const double &price) :
        Toll(n, loc, l, pos, price) {}
