#include "lane.h"

int Lane::getNumCrossings() const {
    return numCrossings;
}

/*void Lane::setNumCrossings(int numCrossings) {
    this->numCrossings = numCrossings;
}*/

void Lane::addCrossing() {
    this->numCrossings++;
}


void NormalExit::setEmployee(Employee *employee) {
    NormalExit::employee = employee;
}

Employee *NormalExit::getEmployee() const {
    return employee;
}

void NormalExit::ChangeEmployee(Employee *employee) {
    setEmployee(employee);
    lastEmployees.push_back(employee);
}

const vector<Employee *> &NormalExit::getLastEmployees() const {
    return lastEmployees;
}
