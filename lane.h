#ifndef AEDA_T8G6_LANE_H
#define AEDA_T8G6_LANE_H

#include "employee.h"
#include "sequentialSearch.h"
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

///Contains info about a Lane, such as numCrossings and vehicleQueue
///
///@param vehicleQueue contains pairs of licensePlate and prices
///Example: XX-XX-XX, 1.60
///This indicates the Vehicle with the licensePlate XX-XX-XX will pay 1.60€ at this Lane

class Lane {
protected:
    int numCrossings;
    queue<pair<string, double>> vehicleQueue; //pair<licensePlate, price>

public:
    ///Creates a Lane with 0 crossings
    Lane() { this->numCrossings = 0; }

    ///Creates a Lane with numCrossings crossings and a queue with <licensePlate, price> pairs
    ///
    /// \param numCrossings
    /// \param vehicleQueue
    Lane(int numCrossings, const queue<pair<string, double>> &vehicleQueue);

    ///Returns Number of Crossings
    ///
    /// \return Number of Crossings
    int getNumCrossings() const;

    ///Pops the front vehicle from queue
    ///
    /// \return true if successful, false otherwise
    ///@note This function will return false when vehicleQueue is empty
    bool passVehicle();

    ///Adds Crossing
    ///increments numCrossings\n
    ///pops price paid from queue
    /// \return poped price pair
    pair<string, double> addCrossing(); //Chamar função para tirar próximo veiculo da queue

    virtual void addVehicle(string licensePlate, double price);

    bool isViaVerde() const { return false; }

    bool isNormalExitLane() {return false;}

    virtual Employee *getEmployee() {}

    int numberVehiclesWaiting(){ return vehicleQueue.size()/2;}

    virtual void setEmployee(Employee *employee){};

    virtual vector<Employee*> getLastEmployees(){ return vector<Employee *>(); };

    bool operator<(const Lane &rhs) const;

    void addToEmployeeList(Employee* employee1){};

    bool operator>(const Lane &rhs) const;

    bool operator<=(const Lane &rhs) const;

    bool operator>=(const Lane &rhs) const;

    friend ostream &operator<<(ostream &os, const Lane &lane);
};

///Child of Lane
class NormalLane : public Lane {
public:
    NormalLane(int numCrossings, const queue<pair<string, double>> &vehicleQueue) : Lane(numCrossings, vehicleQueue) {}

};

///Child of NormalLane
class NormalExitLane : public NormalLane {
private:
    Employee *employee;
    vector<Employee *> lastEmployees;

public:
    NormalExitLane(int numCrossings, const queue<pair<string, double>> &vehicleQueue, Employee *employee,
                   const vector<Employee *> &lastEmployees);
    bool isNormalExitLane()  {return true;}

    Employee *getEmployee() ;

    void setEmployee(Employee *employee);

    vector<Employee*> getLastEmployees(){return lastEmployees;}

    void addToEmployeeList(Employee* employee1){lastEmployees.push_back(employee);};

    void ChangeEmployee(Employee *employee);

    const vector<Employee *> &getLastEmployees() const;
};

///Child of Lane
class ViaVerdeLane : public Lane {

public:
    void addVehicle(string licensePlate, double price);
    bool isViaVerde() const { return true; }
};

#endif //AEDA_T8G6_LANE_H
