#include "vehicle.h"

const string &Vehicle::getLicensePlate() const {
    return licensePlate;
}

int Vehicle::getCategory() const {
    return category;
}


bool Vehicle::operator==(const Vehicle &rhs) const {
    return licensePlate == rhs.licensePlate &&
           category == rhs.category;
}

bool Vehicle::operator!=(const Vehicle &rhs) const {
    return !(rhs == *this);
}

