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
    return numCrossings < numCrossings;
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


void NormalExitLane::setEmployee(Employee *employee1) {
    this->employee = employee1;
}

Employee *NormalExitLane::getEmployee() const {
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
