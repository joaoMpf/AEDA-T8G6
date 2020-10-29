#include "Client.h"

const string &Client::getName() const {
    return name;
}

int Client::getId() const {
    return id;
}

const Vehicle &Client::getVehicle() const {
    return vehicle;
}
