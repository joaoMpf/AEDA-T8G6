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

///Contains info about a Vehicle such as license plate, category, ViaVerde status and trips
///
///@param trips is a vector of pointers to Trip

class Vehicle {
private:
    string licensePlate;
    int category;
    bool viaVerde; //true se tiver via verde
    vector<Trip *> trips;

public:
    //FALTA COMENTAR!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    Vehicle();

    /// Creates Vehicle with license plate, category and ViaVerde status
    ///
    /// \param licensePlate
    /// \param category
    /// \param viaVerde
    Vehicle(const string &licensePlate, int category, bool viaVerde);

    /// Creates a Vehicle with license plate, category and sets ViaVerde status to false
    ///
    /// \param plate
    /// \param cat
    Vehicle(string plate, int cat) : licensePlate(plate), category(cat) {
        viaVerde = 0;
    }

    ///Initializes license plate
    ///
    /// \param licensePlate
    Vehicle(const string &licensePlate);

    ~Vehicle() {}

    ///Returns price
    ///
    /// \param price
    void addPayment(double price);

    ///Returns vector of pointers to Trip
    ///
    /// \return vector of pointers to Trip
    vector<Trip *> getTrips();

    ///Returns license plate
    ///
    /// \return license plate
    const string &getLicensePlate() const;

    ///Checks if a Vehicle has ViaVerde
    ///
    /// \return true if the Vehicle has ViaVerde, false otherwise
    bool isViaVerde () const;

    ///Changes ViaVerde status
    void changeViaVerde();

    //FALTA COMENTAR/APAGAR!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    void setLicensePlate(const string &licensePlate);

    void setCategory(int category);

    //FALTA COMENTAR
    bool operator==(const Vehicle &rhs) const;

    //FALTA COMENTAR/APAGAR!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    bool operator!=(const Vehicle &rhs) const;

    ///Returns Vehicle's category
    ///
    /// \return
    int getCategory() const;

    ///Starts trip
    ///
    /// \param toll points to begin Toll
    /// \param time points to begin Time
    void startTrip(Toll *toll, Time *time);

    ///Ends Trip
    ///
    /// \param toll points to end Toll
    /// \param time points to end Time
    /// \return price
    double endTrip(Toll *toll, Time *time);

    ///Returns pointer to last Trip
    ///
    /// \return pointer to last Trip
    ///@note the last trip will be in the last index of the vector trip
    Trip* getLastTrip();

    ///Prints all of the Vehicle's Trips
    void printTrips();

    ///Prints Vehicle's Info
    ///
    ///Prints license plate, category and ViaVerde status
    void printInfo();

    ///Returns ostream with Vehicle's info
    ///
    /// \param os ostream
    /// \param vehicle
    /// \return ostream with Vehicle's info
    friend ostream &operator<<(ostream &os, const Vehicle &vehicle);

    //FALTA COMENTAR!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    friend istream &operator>>(istream &is, Vehicle &vehicle);

    //FALTA COMENTAR!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    void setTrips(const vector<Trip *> &trips);
};

///Thrown when Vehicle creatin is cancelled
class CreatingVehicleException : exception {
public:
    static void showMessage() {
        cout << "CREATING VEHICLE CANCELED\n";
    }
};

#endif //AEDA_T8G6_VEHICLE_H
