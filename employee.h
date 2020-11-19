#ifndef AEDA_T8G6_EMPLOYEE_H
#define AEDA_T8G6_EMPLOYEE_H

#include <string>
#include <ostream>

using namespace std;

///Contains info about an employee, such as name, ss_number and working status
///
///The private member "working" will be 1 if the employee is working, or 0 otherwize

class Employee {
private:
    string name;
    int ss_number;
    bool working; //IF EMPLOYEE IS WORKING IN A LANE, VALUE TRUE

public:
    ///Creates an Employee with name and ss_number
    Employee(string n, int ss): name(n), ss_number(ss){
        working = false;
    };

    ~Employee(){};

    ///Returns Employee's name
    ///
    /// \return Employee's name
    const string &getName() const;

    ///Returns Employee's ss number
    ///
    /// \return Employee's ss number
    int getSsNumber() const;

    ///Returns true, if ss_numbers are equal, false otherwise
    ///
    /// \param rhs is another Employee
    /// \return true, if ss_numbers are equal, false otherwise
    bool operator==(const Employee &rhs) const;

    ///Returns true, if the Employee is working, false otherwise
    ///
    /// \return true, if the Employee is working, false otherwise
    bool isWorking();

    ///Changes the boolean member working
    ///
    ///If working is true it becomes false and vice-versa
    void changeWorkStatus(){working=!working;};

    ///Returns ostream with name and ss_number
    ///
    /// \param os
    /// \param employee
    /// \return ostream with Employee's name and ss number
    friend ostream &operator<<(ostream &os, const Employee &employee);
};


#endif //AEDA_T8G6_EMPLOYEE_H
