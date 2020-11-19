#ifndef AEDA_T8G6_EMPLOYEE_H
#define AEDA_T8G6_EMPLOYEE_H

#include <string>
#include <ostream>

using namespace std;

class Employee {
private:
    string name;
    int ss_number;
    bool working; //IF EMPLOYEE IS WORKING IN A LANE, VALUE TRUE

public:
    Employee(string n, int ss): name(n), ss_number(ss){
        working = false;
    };

    ~Employee(){};

    const string &getName() const;

    int getSsNumber() const;

    bool operator==(const Employee &rhs) const;

    bool isWorking();

    void changeWorkStatus(){working=!working;};

    friend ostream &operator<<(ostream &os, const Employee &employee);
};


#endif //AEDA_T8G6_EMPLOYEE_H
