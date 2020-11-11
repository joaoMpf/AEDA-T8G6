//
// Created by Pedro Figueiredo on 11/11/2020.
//

#include "highway.h"

const string &Highway::getName() const {
    return name;
}

Toll * Highway::getTollAt(int i) {
    return tolls[i];
}

void Highway::printTollsNumbered() {
    vector<Toll*>::const_iterator it; int i = 1;
    for(it = tolls.begin(); it!= tolls.end(); it++) {
        cout << i << ": " << (*it)->getName()<< endl;
        i++;
    }
}

void Highway::addToll(Toll * toll) {
    tolls.push_back(toll);
}
