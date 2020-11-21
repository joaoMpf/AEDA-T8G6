#include "highway.h"

const string &Highway::getName() const {
    return name;
}

Toll *Highway::getTollAt(int i, bool exit) {
    int cnt = 0;
    vector<Toll *>::iterator it;
    if (!tolls.empty() && exit) {
        for (it = tolls.begin(); it != tolls.end(); it++) {
            if ((*it)->isExitToll()) {
                cnt++;
            }
            if (cnt == i) {
                return *it;
            }
        }
    } else if (!tolls.empty() && !exit) {
        for (it = tolls.begin(); it != tolls.end(); it++) {
            if (!(*it)->isExitToll()) {
                cnt++;
            }
            if (cnt == i) {
                return *it;
            }
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
    if (!tolls.empty())
        for (int i = 0; i < tolls.size(); ++i) {
            tolls[i]->printTollNumbered(i + 1);
        }
}

ostream &operator<<(ostream &os, const Highway &highway) {
    os << highway.name << " " << highway.tolls.size() << endl;
    if (!highway.tolls.empty())
        for (int i = 0; i < highway.tolls.size(); ++i) {
            os << *highway.tolls[i];
            if (i != highway.tolls.size() - 1)
                os << endl;
        }
    return os;
}

int Highway::getTollsSize(bool exit) {
    int cnt = 0;
    for (auto x:tolls) {
        if (x->isExitToll() && exit) {
            cnt++;
        } else if (!(x->isExitToll()) && exit) {
            cnt++;
        }
    }
    return cnt;
}
