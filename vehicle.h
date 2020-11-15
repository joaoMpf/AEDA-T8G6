#ifndef AEDA_T8G6_VEHICLE_H
#define AEDA_T8G6_VEHICLE_H

#include <string>

#include <vector>
#include "trip.h"
#include "toll.h"

using namespace std;

enum vehicleClass {
    classe1 = 1, classe2 = 2, classe3 = 3, classe4 = 4, classe5 = 5
};

class Vehicle {
private:
    vehicleClass vClass;
    string licensePlate;
    int category;
    bool viaVerde; //true se tiver via verde
    vector<Trip *> trips;

public:
    Vehicle(const string &licensePlate, int category, bool viaVerde);

    Vehicle(string plate, int cat) : licensePlate(plate), category(cat) {
    }

    Vehicle(const string &licensePlate);

    ~Vehicle() {}


    const string &getLicensePlate() const;

    bool isViaVerde() const;

    void setLicensePlate(const string &licensePlate);

    vehicleClass getVClass() const;

    void setVClass(vehicleClass vClass);

    bool operator==(const Vehicle &rhs) const;

    bool operator!=(const Vehicle &rhs) const;

    int getCategory() const;

    void startTrip(Toll *toll, Time *time);

    void endTrip(Toll *toll, Time *time);

    void printTrips();

};

class CreatingVehicleException : exception {
public:
    static void showMessage() {
        cout << "CREATING VEHICLE CANCELED\n";
    }
};


#endif //AEDA_T8G6_VEHICLE_H
