#include "highway.h"

const string &Highway::getName() const {
    return name;
}

Toll *Highway::getTollAt(int i, bool exit) {
    int cnt = 0;
    vector<Toll *>::iterator it;
    if (!tolls.empty())
        for (it = tolls.begin(); it != tolls.end(); it++) {
            if (exit ? (*it)->isExitToll() : !((*it)->isExitToll())) {
                cnt++;
            }
            if (cnt == i) {
                return *it;
            }
        }
    return nullptr;
}

void Highway::printTollsNumbered(bool isExit) {
    vector<Toll *>::const_iterator it;
    int i = 1;
    for (it = tolls.begin(); it != tolls.end(); it++) {
        if ((*it)->isExitToll() == isExit) {
            cout << i << ": " << (*it)->getName() << endl;
            i++;
        }
    }
}

void Highway::addToll(Toll *toll) {
    tolls.push_back(toll);
}

vector<Toll *> &Highway::getTolls() {
    return tolls;
}

void Highway::printTollsNumbered() {
    vector<Toll *>::const_iterator it;
    int i = 1;
    for (it = tolls.begin(); it != tolls.end(); it++) {
        cout << i << ": " << (*it)->getName() << endl;
        i++;

    }

}

ostream &operator<<(ostream &os, const Highway &highway) {
    os << highway.name << " " << highway.tolls.size() << endl;
    for (auto toll : highway.tolls) {
        os << *toll << endl;
    }
    return os;
}
