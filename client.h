#ifndef AEDA_T8G6_CLIENT_H
#define AEDA_T8G6_CLIENT_H


#include "vehicle.h"

class Client {
private:
    string name;
    int nif;
    vector<Vehicle *> vehicles;
public:
    Client(const string &name, int nif);

    Client(int nif);

    const string &getName() const;

    int getNif() const;

    const vector<Vehicle *> &getVehicles() const;

    bool operator==(const Client &rhs) const;

    bool operator!=(const Client &rhs) const;

    void addVehicle(Vehicle *vehicle);
};


#endif //AEDA_T8G6_CLIENT_H
