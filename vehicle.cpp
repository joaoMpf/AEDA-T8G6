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
    return licensePlate == rhs.licensePlate &&
           vClass == rhs.vClass;
}

bool Vehicle::operator!=(const Vehicle &rhs) const {
    return !(rhs == *this);
}

void Vehicle::startTrip(Toll* toll, Time *time) {
    trips.push_back(new Trip(toll, time));
}

void Vehicle::endTrip(Toll *toll, Time *time) {
    trips[trips.size()]->setEnd(toll);
    trips[trips.size()]->setEndTime(time);
}

void Vehicle::printTrips() {
    vector<Trip*>::const_iterator it;
    for(it=trips.begin(); it!=trips.end(); it++){
        cout << "Trip Info:\n" << "Started at:" << (*it)->getBegin()->getName();
    }
}