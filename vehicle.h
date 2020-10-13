#ifndef AEDA_T8G6_VEHICLE_H
#define AEDA_T8G6_VEHICLE_H

#include <string>

using namespace std;

class Vehicle {
private:
    string LicensePlate;

public:
    const string &getLicensePlate() const;

    void setLicensePlate(const string &licensePlate);
};


#endif //AEDA_T8G6_VEHICLE_H
