#ifndef AEDA_T8G6_CLIENT_H
#define AEDA_T8G6_CLIENT_H


#include "vehicle.h"

class Client {
private:
    string name;
    int id;
    Vehicle vehicle;
public:
    const string &getName() const;

    int getId() const;

    const Vehicle &getVehicle() const;

};


#endif //AEDA_T8G6_CLIENT_H
