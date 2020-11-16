//
// Created by Pedro Figueiredo on 11/11/2020.
//

#include "highway.h"

const string &Highway::getName() const {
    return name;
}

Toll * Highway::getTollAt(int i, bool exit) {
    int cnt=0;
    vector<Toll*>::iterator it;
    if(exit) {
        for (it = tolls.begin(); it != tolls.end(); it++) {
            if ((*it)->isExitToll()) {
                cnt++;
            }
            if (cnt==i){
                return *it;
            }
        }
    }
    else if(!exit) {
        for (it = tolls.begin(); it != tolls.end(); it++) {
            if (!((*it)->isExitToll())) {
                cnt++;
            }
            if (cnt == i) {
                return *it;
            }
        }
    }
    return nullptr;
}

void Highway::printTollsNumbered(bool exit) {
    vector<Toll*>::const_iterator it; int i = 1;
    for(it = tolls.begin(); it!= tolls.end(); it++) {
        if((*it)->isExitToll()&&exit) {
            cout << i << ": " << (*it)->getName() << endl;
            i++;
        }
        else if(!((*it)->isExitToll())&&!exit){
            cout << i << ": " << (*it)->getName() << endl;
            i++;
        }
    }
}

void Highway::addToll(Toll * toll) {
    tolls.push_back(toll);
}
