#include "toll.h"

const string &Toll::getName() const {
    return name;
}

void Toll::setName(const string &name) {
    this->name = name;
}

const string &Toll::getLocation() const {
    return location;
}

void Toll::setLocation(const string &location) {
    this->location = location;
}

const vector<Lane> &Toll::getLanes() const {
    return lanes;
}

void Toll::setLanes(const vector<Lane> &lanes) {
    Toll::lanes = lanes;
}
