#include "vehicle.h"

const string &Vehicle::getLicensePlate() const {
    return LicensePlate;
}

void Vehicle::setLicensePlate(const string &licensePlate) {
    LicensePlate = licensePlate;
}
