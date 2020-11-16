#include "vehicle.h"

const string &Vehicle::getLicensePlate() const {
    return licensePlate;
}

int Vehicle::getCategory() const {
    return category;
}

vehicleClass Vehicle::getVClass() const {
    return vClass;
}

void Vehicle::setVClass(vehicleClass vClass) {
    Vehicle::vClass = vClass;
}

bool Vehicle::operator==(const Vehicle &rhs) const {
    return licensePlate == rhs.licensePlate;
}

bool Vehicle::operator!=(const Vehicle &rhs) const {
    return !(rhs == *this);
}

void Vehicle::startTrip(Toll *toll, Time *time) {
    if (!trips.empty() && !trips[trips.size() - 1]->isFinished()) {
        cout << "VEHICLE IS ALREADY IN A TRIP. "
             << "VEHICLE MUST PASS THROUGH AN EXIT TOLL "
             << "BEFORE ENTERING AGAIN\n";
        return;
    }
    trips.push_back(new Trip(toll, time));
}

double Vehicle::endTrip(Toll *toll, Time *time) {
    if ((!trips.empty() && trips[trips.size() - 1]->isFinished())) {
        cout << "VEHICLE NEVER ENTERED OR ALREADY EXITED.\n";
        return -1;
    }
    trips[trips.size() - 1]->setEnd(toll);
    trips[trips.size() - 1]->setEndTime(time);

    double price = 5.0;
    return price;
}

void Vehicle::printTrips() {
    vector<Trip *>::const_iterator it;
    for (it = trips.begin(); it != trips.end(); it++) {
        cout << "Trip Info:\n"
             << "Started at: " <<
             (*it)->getBeginTime()->getHour() << ":" <<
             (*it)->getBeginTime()->getMinute() << ":"
             << (*it)->getBeginTime()->getSecond() << endl
             << "Ended at: " <<
             (*it)->getEndTime()->getHour() << ":" <<
             (*it)->getEndTime()->getMinute() << ":"
             << (*it)->getEndTime()->getSecond() << endl;
    }
}

Vehicle::Vehicle(const string &licensePlate) : licensePlate(licensePlate) {}

Vehicle::Vehicle(const string &licensePlate, int category, bool viaVerde) : licensePlate(licensePlate),
                                                                            category(category), viaVerde(viaVerde) {}

bool Vehicle::isViaVerde() const {
    return viaVerde;
}
