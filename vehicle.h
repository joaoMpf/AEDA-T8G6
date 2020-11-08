#ifndef AEDA_T8G6_VEHICLE_H
#define AEDA_T8G6_VEHICLE_H

#include <string>

using namespace std;


class Vehicle {
private:
    string licensePlate;
    int category;
    bool viaVerde;


public:
    Vehicle(string plate, int cat,bool via): licensePlate(plate), category(cat),viaVerde(via){
    }

    ~Vehicle(){}


    const string &getLicensePlate() const;


    void setLicensePlate(const string &licensePlate);


    bool operator==(const Vehicle &rhs) const;

    bool operator!=(const Vehicle &rhs) const;

    int getCategory() const;

};


#endif //AEDA_T8G6_VEHICLE_H
