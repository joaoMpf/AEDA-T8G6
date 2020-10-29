#include "vehicle.h"

const string &Vehicle::getLicensePlate() const {
    return LicensePlate;
}

void Vehicle::setLicensePlate(const string &licensePlate) {
    LicensePlate = licensePlate;
}

vehicleClass Vehicle::getVClass() const {
    return vClass;
}

void Vehicle::setVClass(vehicleClass vClass) {
    Vehicle::vClass = vClass;
}

bool Vehicle::operator==(const Vehicle &rhs) const {
    return LicensePlate == rhs.LicensePlate &&
           vClass == rhs.vClass;
}

bool Vehicle::operator!=(const Vehicle &rhs) const {
    return !(rhs == *this);
}
