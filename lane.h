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

    virtual bool isViaVerde() const { return false; }

    virtual bool isNormalExitLane() const {return false;}

    virtual Employee *getEmployee() const {return nullptr;}

    int numberVehiclesWaiting(){ return vehicleQueue.size();}

    virtual void setEmployee(Employee *employee){};

    bool operator<(const Lane &rhs) const;

    bool operator>(const Lane &rhs) const;

    bool operator<=(const Lane &rhs) const;

    bool operator>=(const Lane &rhs) const;
};

///Child of Lane
class NormalLane : public Lane {
public:
    NormalLane(int numCrossings, const queue<pair<string, double>> &vehicleQueue) : Lane(numCrossings, vehicleQueue) {}
    bool isViaVerde() const override { return false; }
};

///Child of NormalLane
class NormalExitLane : public NormalLane {
private:
    Employee *employee;
    vector<Employee *> lastEmployees;

    void setEmployee(Employee *employee);

public:
    NormalExitLane(int numCrossings, const queue<pair<string, double>> &vehicleQueue, Employee *employee,
                   const vector<Employee *> &lastEmployees);
    bool isNormalExitLane() const override {return true;}
    Employee *getEmployee() const;

    void ChangeEmployee(Employee *employee);

    const vector<Employee *> &getLastEmployees() const;
};

///Child of Lane
class ViaVerdeLane : public Lane {
public:
    void addVehicle(string licensePlate, double price);

    bool isViaVerde() const override { return true; }
};

#endif //AEDA_T8G6_LANE_H
