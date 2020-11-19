#ifndef AEDA_T8G6_LANE_H
#define AEDA_T8G6_LANE_H

#include "employee.h"
#include "sequentialSearch.h"
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

class Lane {
protected:
    int numCrossings;
    queue<pair<string, double>> vehicleQueue; //pair<licensePlate, price>

public:
    Lane() { this->numCrossings = 0; }

    Lane(int numCrossings, const queue<pair<string, double>> &vehicleQueue);

    int getNumCrossings() const;

    bool passVehicle();

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

class NormalLane : public Lane {
public:
    NormalLane(int numCrossings, const queue<pair<string, double>> &vehicleQueue) : Lane(numCrossings, vehicleQueue) {}
    bool isViaVerde() const override { return false; }
};

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


class ViaVerdeLane : public Lane {
public:
    void addVehicle(string licensePlate, double price);

    bool isViaVerde() const override { return true; }
};

#endif //AEDA_T8G6_LANE_H
