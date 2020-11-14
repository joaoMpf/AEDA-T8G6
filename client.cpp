#include "client.h"

const string &Client::getName() const {
    return name;
}

int Client::getNif() const {
    return nif;
}

bool Client::operator==(const Client &rhs) const {
    return nif == rhs.nif;
}

bool Client::operator!=(const Client &rhs) const {
    return !(rhs == *this);
}

Client::Client(const string &name, int nif) : name(name), nif(nif) {}

Client::Client(int nif) : nif(nif) {}

const vector<Vehicle *> &Client::getVehicles() const {
    return vehicles;
}

void Client::addVehicle(Vehicle *vehicle) {
    vehicles.push_back(vehicle);
}

