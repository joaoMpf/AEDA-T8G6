#include "lane.h"

int Lane::getNumCrossings() const {
    return numCrossings;
}

void Lane::addCrossing() {
    this->numCrossings++;
}

void Lane::addVehicle(string licensePlate, double price) {
    vehicleQueue.push(pair<string, double>(licensePlate, price));
}

Lane::Lane(int numCrossings, const queue<pair<string, double>> vehicleQueue) : numCrossings(numCrossings),
                                                                               vehicleQueue(vehicleQueue) {}

bool Lane::operator<(const Lane &rhs) const {
    return numCrossings < rhs.numCrossings;
}

bool Lane::operator>(const Lane &rhs) const {
    return rhs < *this;
}

bool Lane::operator<=(const Lane &rhs) const {
    return !(rhs < *this);
}

bool Lane::operator>=(const Lane &rhs) const {
    return !(*this < rhs);
}

bool Lane::passVehicle() {
    if (!vehicleQueue.empty()) {
        vehicleQueue.pop();
        return true;
    }
    return false;
}

ostream &operator<<(ostream &os, const Lane &lane) {
    return lane.saveToFile(os);
}

istream &operator>>(istream &is, Lane &lane) {
    int numCross, vehicleQueueSize;
    pair<string, double> pair;
    if (is >> numCross >> vehicleQueueSize) {
        lane.numCrossings = numCross;
        if (vehicleQueueSize > 0) {
            for (int i = 0; i < vehicleQueueSize; i++) {
                is >> pair.first >> pair.second;
                lane.vehicleQueue.push(pair);
            }
        }
    }

    return is;
}

ostream &Lane::saveToFile(ostream &os) const {
    os << isViaVerde() << " " << numCrossings;
    return os;
}

Lane::Lane(int numCrossings) : numCrossings(numCrossings) {}


void NormalExitLane::setEmployee(Employee *employee1) {
    this->employee = employee1;
}

Employee *NormalExitLane::getEmployee() {
    return employee;
}

const vector<Employee *> &NormalExitLane::getLastEmployees() const {
    return lastEmployees;
}

NormalExitLane::NormalExitLane(int numCrossings, const queue<pair<string, double>> vehicleQueue, Employee *employee,
                               const vector<Employee *> &lastEmployees) : NormalLane(numCrossings, vehicleQueue),
                                                                          employee(employee),
                                                                          lastEmployees(lastEmployees) {}

ostream &NormalExitLane::saveToFile(ostream &os) const {
    Lane::saveToFile(os);
    os << " " << vehicleQueue.size();
    if (!vehicleQueue.empty()) {
        queue<pair<string, double>> copy(vehicleQueue);
        while (!copy.empty()) {
            os << " " << copy.front().first << " " << copy.front().second;
            copy.pop();
        }
    }
    bool hasCurrentEmployee = (employee == nullptr);
    os << " " << hasCurrentEmployee << " ";
    if (hasCurrentEmployee)
        os << employee->getSsNumber() << " ";
    os << lastEmployees.size() << " ";
    if (!lastEmployees.empty()) {
        for (auto lastEmployee : lastEmployees) {
            os << lastEmployee->getSsNumber() << " ";
        }
    }
    return os;
}

void ViaVerdeLane::addVehicle(string licensePlate, double price) {
    Lane::addVehicle(licensePlate, price);
    addCrossing();
}

ViaVerdeLane::ViaVerdeLane() {}

ViaVerdeLane::ViaVerdeLane(int numCrossings) : Lane(numCrossings) {}
