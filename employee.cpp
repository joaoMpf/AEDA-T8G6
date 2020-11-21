#include "employee.h"
#include <iostream>

const string &Employee::getName() const {
    return name;
}

int Employee::getSsNumber() const {
    return ss_number;
}

bool Employee::operator==(const Employee &rhs) const {
    return ss_number == rhs.ss_number;
}

bool Employee::isWorking() {
    return working;
}

ostream &operator<<(ostream &os, const Employee &employee) {
    os << employee.name << " " << employee.ss_number << " " << employee.working;
    return os;
}

void Employee::changeWorkStatus() {
    working = !working;
}

istream &operator>>(istream &is, Employee &employee) {
    string name;
    int ss_number;
    bool working; //IF EMPLOYEE IS WORKING IN A LANE, VALUE TRUE

    if (is >> name >> ss_number >> working) {
        employee.setName(name);
        employee.setSsNumber(ss_number);
        if (working) employee.changeWorkStatus();
    }
    return is;
}

void Employee::setName(const string &name) {
    Employee::name = name;
}

void Employee::setSsNumber(int ssNumber) {
    ss_number = ssNumber;
}

Employee::Employee() {working = false;
}
