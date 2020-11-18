#ifndef AEDA_T8G6_EMPLOYEE_H
#define AEDA_T8G6_EMPLOYEE_H

#include <string>

using namespace std;

class Employee {
private:
    string name;
    int ss_number;

public:
    Employee(string n, int ss): name(n), ss_number(ss){};

    ~Employee(){};

    const string &getName() const;

    int getSsNumber() const;

    bool operator==(const Employee &rhs) const;
};


#endif //AEDA_T8G6_EMPLOYEE_H
