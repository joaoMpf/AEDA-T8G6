#ifndef AEDA_T8G6_VEHICLE_H
#define AEDA_T8G6_VEHICLE_H

#include <string>

using namespace std;

class Vehicle {
private:
    string licensePlate;
    int category;

public:
    Vehicle(string plate, int cat): licensePlate(plate), category(cat){}

    ~Vehicle();

    const string &getLicensePlate() const;

    int getCategory() const;
};


#endif //AEDA_T8G6_VEHICLE_H
