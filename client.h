#ifndef AEDA_T8G6_CLIENT_H
#define AEDA_T8G6_CLIENT_H


#include <ostream>
#include "vehicle.h"

class Client {
private:
    string name;
    int nif;
    vector<Vehicle *> vehicles;

public:
    Client(string name, int nif);

    Client(int nif);

    const string &getName() const;



    int getNif() const;

    vector<Vehicle *> &getVehicles() ;

    Vehicle *getVehicle(string &licensePlate);

    void removeVehicle(Vehicle *vehicle);

    bool operator==(const Client &rhs) const;

    bool operator!=(const Client &rhs) const;

    void addVehicle(Vehicle *vehicle);

    void printVehicles();

    void changeName(string name);

    void changeNIF(int nif);

    void printInfo();

    friend ostream &operator<<(ostream &os, const Client &client);
};


#endif //AEDA_T8G6_CLIENT_H
