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

    ///Adds the pair licensePlate, price to the queue
    ///
    /// \param licensePlate
    /// \param price
    ///@see ViaVerdeLane::addVehicle(string licensePlate, double price)
    virtual void addVehicle(string licensePlate, double price);

    bool isViaVerde() const { return false; }

    bool isNormalExitLane() {return false;}


    ///Returns pointer to Employee
    ///
    /// \return pointer to Employee
    virtual Employee *getEmployee(){return nullptr;}

    ///Returns number of Vehicles in queue
    ///
    /// \return number of Vehicles in queue
    int numberVehiclesWaiting(){ return vehicleQueue.size()/2;}
>>>>>>> 4e0845448bf8e1ba0c335b4122bd5b9567a25266

    ///Set Employee
    ///
    /// \param employee
    virtual void setEmployee(Employee *employee){};

    virtual vector<Employee*> getLastEmployees(){ return vector<Employee *>(); };

    bool operator<(const Lane &rhs) const;

    void addToEmployeeList(Employee* employee1){};

    bool operator>(const Lane &rhs) const;

    bool operator<=(const Lane &rhs) const;

    bool operator>=(const Lane &rhs) const;

    ///Returns ostream with the pairs <licensePlate, price> in queue
    ///
    /// \param os ostream
    /// \param lane
    /// \return ostream with the pairs <licensePlate, price> in queue
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

    ///Return pointer to Employee working in NormalExitLane
    ///
    /// \return pointer to Employee working in NormalExitLane
    Employee *getEmployee() ;

    void setEmployee(Employee *employee);

    vector<Employee*> getLastEmployees(){return lastEmployees;}

    void addToEmployeeList(Employee* employee1){lastEmployees.push_back(employee);};

    ///Changes Employee working in NormalExitLane
    ///
    /// \param employee pointer to Employee
    void ChangeEmployee(Employee *employee);


    ///Returns vector of pointers to Employee
    ///
    /// \return
    const vector<Employee *> &getLastEmployees() const;
};

///Child of Lane
class ViaVerdeLane : public Lane {

public:
    /// Passes Vehicle through ViaVerdeLane
    ///
    /// \param licensePlate
    /// \param price
    ///@note Adds the pair <licensePlate, price> to queue vehicleQueue and pops it, incrementing numCrossings
    ///@see Lane::addVehicle()
    ///@see addCrossing()
    void addVehicle(string licensePlate, double price);
    bool isViaVerde() const { return true; }
};

#endif //AEDA_T8G6_LANE_H
