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

const bool &Toll::getType() const {
    return type;
}

void Toll::enterToll(string basicString) {
    //falta sugerir para que lane vai

}

void Toll::exitToll(string basicString) {
    //falta sugerir para que lane vai

}
