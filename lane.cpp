#include "lane.h"

int Lane::getNumCrossings() const {
    return numCrossings;
}

pair<string, double> Lane::addCrossing() {
    this->numCrossings++;
    pair<string, double> pricePair = vehicleQueue.front();
    vehicleQueue.pop();
    return pricePair;
}

void Lane::addVehicle(string licensePlate, double price) {
    vehicleQueue.push(pair<string, double>(licensePlate, price));
}

Lane::Lane(int numCrossings, const queue<pair<string, double>> &vehicleQueue) : numCrossings(numCrossings),
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
    os << lane.numCrossings << " " << lane.vehicleQueue.size();
    if(lane.vehicleQueue.empty()) {
        queue<pair<string, double>> printQueue = lane.vehicleQueue;
        while (!printQueue.empty()) {
            os << printQueue.front().first << " " << printQueue.front().second;
            if (printQueue.size() > 1)
                os << " ";
            printQueue.pop();
        }
    }
    return os;
}


void NormalExitLane::setEmployee(Employee *employee1) {
    this->employee = employee1;
}

Employee *NormalExitLane::getEmployee() {
    return employee;
}

void NormalExitLane::ChangeEmployee(Employee *employee1) {
    setEmployee(employee1);
    lastEmployees.push_back(employee);
}

const vector<Employee *> &NormalExitLane::getLastEmployees() const {
    return lastEmployees;
}

NormalExitLane::NormalExitLane(int numCrossings, const queue<pair<string, double>> &vehicleQueue, Employee *employee,
                               const vector<Employee *> &lastEmployees) : NormalLane(numCrossings, vehicleQueue),
                                                                          employee(employee),
                                                                          lastEmployees(lastEmployees) {}

void ViaVerdeLane::addVehicle(string licensePlate, double price) {
    Lane::addVehicle(licensePlate, price);
    addCrossing();
}
