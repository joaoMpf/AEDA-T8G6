#ifndef AEDA_T8G6_VEHICLE_H
#define AEDA_T8G6_VEHICLE_H

#include <string>
#include <vector>
#include <ostream>
#include "trip.h"
#include "toll.h"

using namespace std;

enum vehicleClass {
    classe1 = 1, classe2 = 2, classe3 = 3, classe4 = 4, classe5 = 5
};

class Vehicle {
private:
    string licensePlate;
    int category;
    bool viaVerde; //true se tiver via verde
    vector<Trip *> trips;

public:
    Vehicle(const string &licensePlate, int category, bool viaVerde);

    Vehicle(string plate, int cat) : licensePlate(plate), category(cat) {
        viaVerde = 0;
    }

    Vehicle(const string &licensePlate);

    ~Vehicle() {}

    void addPayment(double price);

    vector<Trip *> getTrips();

    const string &getLicensePlate() const;

    bool isViaVerde () const;

    void changeViaVerde();

    void setLicensePlate(const string &licensePlate);

    bool operator==(const Vehicle &rhs) const;

    bool operator!=(const Vehicle &rhs) const;

    int getCategory() const;

    void startTrip(Toll *toll, Time *time);

    double endTrip(Toll *toll, Time *time);

    Trip* getLastTrip();

    void printTrips();

    void printInfo();

    friend ostream &operator<<(ostream &os, const Vehicle &vehicle);
};

class CreatingVehicleException : exception {
public:
    static void showMessage() {
        cout << "CREATING VEHICLE CANCELED\n";
    }
};


#endif //AEDA_T8G6_VEHICLE_H
