#include "client.h"

#include <utility>

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

Client::Client(string name, int nif) : name(std::move(name)), nif(nif) {}

Client::Client(int nif) : nif(nif) {}

const vector<Vehicle *> &Client::getVehicles() const {
    return vehicles;
}

void Client::addVehicle(Vehicle *vehicle) {
    vehicles.push_back(vehicle);
}

Vehicle *Client::getVehicle(string &licensePlate) {
    int pos = sequentialSearch(vehicles, new Vehicle(licensePlate));
    if (pos == -1)
        return nullptr;

    return vehicles[pos];
}

