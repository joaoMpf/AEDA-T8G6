#include "toll.h"

const string &Toll::getName() const {
    return name;
}

const string &Toll::getLocation() const {
    return location;
}

const vector<Lane> &Toll::getLanes() const {
    return lanes;
}
