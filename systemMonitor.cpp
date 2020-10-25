#include "systemMonitor.h"


const vector<Toll *> &SystemMonitor::getTolls() const {
    return tolls;
}

bool SystemMonitor::addToll(const Toll *&toll) {
    return false;
}

bool SystemMonitor::removeToll(const Toll *&toll) {
    return false;
}

int SystemMonitor::findToll(const Toll *&toll) {
    return 0;
}

void SystemMonitor::sortTolls() {

}

const vector<Employee *> &SystemMonitor::getEmployees() const {
    return employees;
}

bool SystemMonitor::addEmployee(const Employee *&employee) {
    return false;
}

bool SystemMonitor::removeEmployee(const Employee *&employee) {
    return false;
}

int SystemMonitor::findEmployee(const Employee *&employee) {
    return 0;
}

void SystemMonitor::sortEmployees() {

}

const vector<Client *> &SystemMonitor::getClients() const {
    return clients;
}

bool SystemMonitor::addClient(const Client *&client) {
    return false;
}

bool SystemMonitor::removeClient(const Client *&client) {
    return false;
}

int SystemMonitor::findClient(const Client *&client) {
    return 0;
}

void SystemMonitor::sortClients() {

}
