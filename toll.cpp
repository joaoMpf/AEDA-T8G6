#include "toll.h"

const string &Toll::getName() const {
    return name;
}

const string &Toll::getLocation() const {
    return location;
}

const vector<Lane*> &Toll::getLanes() const {
    return lanes;
}

const string &Toll::getType() const {
    return type1;
}

int Toll::getCode() const {
    return code;
}

