#ifndef AEDA_T8G6_VEHICLE_H
#define AEDA_T8G6_VEHICLE_H

#include <string>

using namespace std;

enum vehicleClass {
    classe1 = 1, classe2 = 2, classe3 = 3, classe4 = 4, classe5 = 5
};

class Vehicle {
private:
    string LicensePlate;
    vehicleClass vClass;
public:
    const string &getLicensePlate() const;

    void setLicensePlate(const string &licensePlate);

    vehicleClass getVClass() const;

    void setVClass(vehicleClass vClass);

    bool operator==(const Vehicle &rhs) const;

    bool operator!=(const Vehicle &rhs) const;
};


#endif //AEDA_T8G6_VEHICLE_H
