#include "employee.h"

const string &Employee::getName() const {
    return name;
}

void Employee::setName(const string &name) {
    Employee::name = name;
}

int Employee::getSsNumber() const {
    return ss_number;
}

void Employee::setSsNumber(int ssNumber) {
    ss_number = ssNumber;
}

bool Employee::operator==(const Employee &rhs) const {
    return ss_number == rhs.ss_number;
}

bool Employee::operator!=(const Employee &rhs) const {
    return !(rhs == *this);
}
