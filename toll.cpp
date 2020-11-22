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

    int c = -1;
    while (c < 0 || c >= recommendedLanes.size()) {
        for (int i = 0; i < recommendedLanes.size(); ++i) {
            cout << "NUMBER OF CROSSINGS TODAY: " << recommendedLanes[i]->getNumCrossings() << endl;
            recommendedLanes[i]->printLaneNumbered(i);
        }
        cout << "WE RECOMMEND LANE 0 THAT HAS THE FEWEST CROSSINGS FOR TODAY\n";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin.clear();
        c = getchar_unlocked() - '0';
    }
    return recommendedLanes[c];
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

void Toll::printTollNumbered(int i) const {
    cout << i << ": " << getName() << endl;
    cout << "LOCATION: " << getLocation() << endl;
    if (isExitToll()) cout << "EXIT TOLL\n\n";
    else cout << "ENTRY TOLL\n\n";
}

void Toll::viewLanes() {

    for (int i = 0; i < getLanes().size(); ++i) {
        getLanes()[i]->printLaneNumbered(i + 1);
    }
    if(this->isExitToll()) {
        while (true) {
            int j;
            cout << "SELECT A LANE TO VIEW ITS PAST EMPLOYEES OR ENTER 0 TO GO BACK\n\n";
            cin >> j;
            if (j == 0) return;
            else if (getLanes()[j-1]->isNormalExitLane()&&j > 0 && j <= getLanes().size() ) {
                if (getLanes()[j-1]->getLastEmployees().size()==0){
                    cout<<"NO EMPLOYEE HISTORY TO SHOW\n";
                    return;
                }
                for (auto x:getLanes()[j - 1]->getLastEmployees()) {
                    cout << x->getName() << endl;
                    cout << x->getSsNumber() << endl << endl;
                }
            }
            else cout << "ONLY NORMAL EXIT LANES HAVE EMPLOYEES\n";
        }
    }

}

ostream &operator<<(ostream &os, const Toll &toll) {
    os << toll.isExitToll() << " " << toll.name << " " << toll.location << " " << toll.lanes.size() << " "
       << toll.position << " " << toll.price;
    if (!toll.lanes.empty()) {
        os << endl;
        for (int i = 0; i < toll.lanes.size(); ++i) {
            os << *toll.lanes[i];
            if (i < toll.lanes.size() - 1)
                os << endl;
        }
    }
    return os;
}

istream &operator>>(istream &is, Toll &toll) {
    return toll.loadFromFile(is);
}


istream &Toll::loadFromFile(istream &is) {
    string name, location;
    int numLanes, pos;
    double price;
    vector<Lane *> lanes;
    is >> name >> location >> numLanes >> pos >> price;
    lanes.reserve(numLanes);
    for (int i = 0; i < numLanes; i++) {
        lanes.push_back(loadLaneFromFile(is));
    }
    setName(name);
    setLocation(location);
    setLanes(lanes);
    setPosition(pos);
    setPrice(price);
    return is;
}

void Toll::setName(const string &name) {
    Toll::name = name;
}

void Toll::setLocation(const string &location) {
    Toll::location = location;
}

void Toll::setLanes(const vector<Lane *> &lanes) {
    Toll::lanes = lanes;
}

void Toll::setPosition(int position) {
    Toll::position = position;
}

void Toll::setPrice(double price) {
    Toll::price = price;
}

Toll::Toll() {}



bool InToll::isExitToll() const {
    return false;
}

bool OutToll::isExitToll() const {
    return true;
}

InToll::InToll(const string &n, const string &loc, const vector<Lane *> &l, const int &pos, const double &price) :
        Toll(n, loc, l, pos, price) {}

Lane *InToll::loadLaneFromFile(istream &is) {
    bool viaVerde;

    is >> viaVerde;
    if (viaVerde) {
        ViaVerdeLane *viaVerdeLane = new ViaVerdeLane();
        is >> *viaVerdeLane;
        return viaVerdeLane;
    } else {
        NormalLane *normalLane = new NormalLane();
        is >> *normalLane;
        return normalLane;
    }
}

InToll::InToll() = default;

OutToll::OutToll(const string &n, const string &loc, const vector<Lane *> &l, const int &pos, const double &price) :
        Toll(n, loc, l, pos, price) {}

OutToll::OutToll() = default;

Lane *OutToll::loadLaneFromFile(istream &is) {
    bool viaVerde;

    is >> viaVerde;
    if (viaVerde) {
        ViaVerdeLane *viaVerdeLane = new ViaVerdeLane();
        is >> *viaVerdeLane;
        return viaVerdeLane;
    } else {
        NormalExitLane *normalExitLane = new NormalExitLane();
        is >> *normalExitLane;
        return normalExitLane;
    }
}
