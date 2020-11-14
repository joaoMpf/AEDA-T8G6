#ifndef AEDA_T8G6_SYSTEMMONITOR_H
#define AEDA_T8G6_SYSTEMMONITOR_H

#include "highway.h"
#include "toll.h"
#include "client.h"
#include "sequentialSearch.h"
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

//Main class
class SystemMonitor {
private:
    vector<Highway* > highways;
    vector<Employee *> employees;
    vector<Client *> clients;
    vector<Vehicle *> vehicles;

public:
    int findVehicle(const string& licensePlate);

    //void load();

    void save();

    SystemMonitor(){
        //load();
    };

    ~SystemMonitor(){

    };


    const vector<Employee *> &getEmployees() const;

    bool addEmployee(const Employee* &employee);

    bool removeEmployee(const Employee* &employee); //Definir operator == em Employee

    int findEmployee(const Employee* &employee);

    void sortEmployees();

    const vector<Client *> &getClients() const;

    bool addClient(const Client* &client);

    bool removeClient(const Client* &client);

    int findClient(const Client *client);

    void sortClients();

    void startTrip(Vehicle* vehicle, Toll* toll, Time* time);

    void endTrip(Vehicle* vehicle, Toll* toll, Time* time);

    void printHighwaysNumbered();

    Highway* getHighwayAt(int i);

    Vehicle* getVehicle(string licensePlate);

    void addVehicle(Vehicle* vehicle);

    void addHighway(Highway* highway);

    string licensePlateInput();

    Vehicle * firstTimeClient(string licensePlate);

    Client *login();

    void addVehicleClient(Client *client);

    string getNewLicensePlate();

    int categoryInput() const;

    bool viaVerdeInput();
};



#endif //AEDA_T8G6_SYSTEMMONITOR_H
