#ifndef AEDA_T8G6_LANE_H
#define AEDA_T8G6_LANE_H

#include "employee.h"
#include "vehicle.h"
#include <vector>

using namespace std;

class Lane {
protected:
    int numCrossings;
    void setNumCrossings(int numCrossings);

public:
    Lane(){}

    int getNumCrossings() const;

    void addCrossing();
};
class Exit: public Lane{

};
class ViaVerde : public Lane {

};

class Normal : public Lane {

};

class NormalExit : public Normal {
private:
    Employee *employee;
    vector<Employee *> lastEmployees;

    void setEmployee(Employee *employee);

public:
    Employee *getEmployee() const;

    void ChangeEmployee(Employee *employee);

    const vector<Employee *> &getLastEmployees() const;
};


#endif //AEDA_T8G6_LANE_H
