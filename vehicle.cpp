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

