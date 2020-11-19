#include "employee.h"

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
    os << employee.name << " " << employee.ss_number;
    return os;
}



