#include "highway.h"

const string &Highway::getName() const {
    return name;
}

Toll *Highway::getTollAt(int i, bool exit) {
    int cnt = 0;
    vector<Toll *>::iterator it;
    if (!tolls.empty())
        if (exit) {
            for (it = tolls.begin(); it != tolls.end(); it++) {
                if ((*it)->isExitToll()) {
                    cnt++;
                }
                if (cnt == i) {
                    return *it;
                }
            }
        } else if (!exit) {
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

vector<Toll *> &Highway::getTolls() {
    return tolls;
}

void Highway::printTollsNumbered() {
    vector<Toll*>::const_iterator it; int i = 1;
    for(it = tolls.begin(); it!= tolls.end(); it++) {
        cout << i << ": " << (*it)->getName() << endl;
        i++;

    }

}

ostream &operator<<(ostream &os, const Highway &highway) {
    os << highway.name << " " << highway.tolls.size() << endl;
    for (auto toll : highway.tolls) {
        os << toll << endl;
    }
    return os;
}
