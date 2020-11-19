#ifndef AEDA_T8G6_SYSTEMMONITOR_H
#define AEDA_T8G6_SYSTEMMONITOR_H

#include "highway.h"
#include "client.h"
#include "toll.h"
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
    Vehicle *findVehicleClients(const string& licensePlate);

    void load();

    void save();

    SystemMonitor(){
        load();
    };

    ~SystemMonitor(){

    };

    vector<Highway* > getHighways();

    const vector<Employee *> &getEmployees() const;

    bool addEmployee(const Employee* &employee);

    bool removeEmployee(const Employee* &employee); //Definir operator == em Employee

    int findEmployee(const Employee* cemployee);

    void sortEmployees();

    const vector<Client *> &getClients() const;

    void addClient(Client* client);

    bool removeClient(const Client* client);

    int findClient(const Client *client);

    void sortClients();

    static void startTrip(Vehicle* vehicle, Toll* toll, Time* time);

    static void endTrip(Vehicle* vehicle, Toll* toll, Time* time);

    void printHighwaysNumbered();

    Highway* getHighwayAt(int i);

    Vehicle* getVehicle(const string& licensePlate);

    void addVehicle(Vehicle* vehicle);

    void removeVehicle(Client *client);

    void viewVehicles(Client *client);

    void showCosts(Client *client);

    void updateVehicles(Client *client);

    void addHighway(Highway* highway);

    static string licensePlateInput();

    Vehicle * firstTimeClient(const string& licensePlate);

    Client *login();

    void addVehicleClient(Client *client);

    string getNewLicensePlate();

    int categoryInput() const;

    static bool viaVerdeInput();

    static int getNumberInput();

    Client *createNewClient();

    static int countDigit(int num);

    static bool confirmation() ;

    static string getName() ;

    int getNif();

    int findVehicle(const string &licensePlate);

    Employee *loginEmployee();

    void printVehiclesListed(Client *client);

    void changeName(Client *client);

    void changeNIF(Client *client);


    Lane *findEmployeeLane(Employee *pEmployee);

    Toll *findLaneToll(Lane *lane);

    Highway *findTollHighway(Toll *toll);


    void managerAddHighway();

    void managerRemoveHighway();

    void managerViewHighways();

    void manageExistingHighways();

    int selectHighway();

    void managerAddToll(Highway *phighway);

    void managerManageToll(Highway *phighway);

    void viewHighwayTolls(Highway *phighway);

    void managerRemoveToll(Highway *phighway);

    Toll* selectToll(Highway *pHighway);

    void managerAddLane(Toll *pToll,bool viaVerde);

    void printEmployeesNumbered();

    Employee *selectEmployee();

    void viewLanes(Toll *pToll);

    void removeLane(Toll *pToll);

    void changeLaneEmployee(Toll *pToll);

    void loadVehicles(const string &vehiclesFileName);

    void loadEmployees(const string &employeesFileName);

    void loadClients(const string &clientsFileName);

    void loadTolls(const string &tollsFileName);
};

class ConfirmationExitException : exception {
public:
    static void showMessage() {
        cout << "OPERATION CANCELED\n";
    }
};

class VehicleInCirculationException : exception {
public:
    static void showMessage() {
        cout << "Vehicle is already in circulation!\n";
    }
};

#endif //AEDA_T8G6_SYSTEMMONITOR_H
