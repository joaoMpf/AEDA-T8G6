#ifndef AEDA_T8G6_EMPLOYEE_H
#define AEDA_T8G6_EMPLOYEE_H

#include <string>

using namespace std;

class Employee {
private:
    string name;
    int ss_number;
public:
    const string &getName() const;

    void setName(const string &name);

    int getSsNumber() const;

    void setSsNumber(int ssNumber);

    bool operator==(const Employee &rhs) const;

    bool operator!=(const Employee &rhs) const;
};


#endif //AEDA_T8G6_EMPLOYEE_H
