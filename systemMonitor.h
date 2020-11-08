#ifndef AEDA_T8G6_SYSTEMMONITOR_H
#define AEDA_T8G6_SYSTEMMONITOR_H

#include "toll.h"
#include "client.h"
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

//Main class
class SystemMonitor {
private:
    vector<Toll *> tolls;
    vector<Employee *> employees;
    vector<Client *> clients;
    vector<Vehicle *> vehiclesCirculating;

public:
    friend void Toll::enterToll(string basicString);

    friend void Toll::exitToll(string basicString);

    void addVehicle(string licensePlate);

    void removeVehicle(string licensePlate);

    void setTolls(const vector<Toll *> &tolls);

    int findVehicle(string licensePlate);

    void load();

    void save();

    void showTollsNumbered();

    void showToll(int toll);

    SystemMonitor(){
        load();
    };


    ~SystemMonitor(){

    };

    const vector<Toll *> &getTolls() const;

    bool addToll(const Toll* &toll);

    bool removeToll(const Toll* &toll); //Definir operator == em Toll

    int findToll(const Toll* &toll);

    void sortTolls();

    const vector<Employee *> &getEmployees() const;

    bool addEmployee(const Employee* &employee);

    bool removeEmployee(const Employee* &employee); //Definir operator == em Employee

    int findEmployee(const Employee* &employee);

    void sortEmployees();

    const vector<Client *> &getClients() const;

    bool addClient(const Client* &client);

    bool removeClient(const Client* &client);

    int findClient(const Client* &client);

    void sortClients();

    void TollMonitor(int TollNumber);

};



#endif //AEDA_T8G6_SYSTEMMONITOR_H
