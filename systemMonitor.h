#ifndef AEDA_T8G6_SYSTEMMONITOR_H
#define AEDA_T8G6_SYSTEMMONITOR_H

#include "toll.h"
#include "client.h"
#include <string>

using namespace std;

//Main class com Menu
class SystemMonitor {
private:
    vector<Toll *> tolls;
    vector<Employee *> employees;
    vector<Client *> clients;

public:
    SystemMonitor(){}

    SystemMonitor(const vector<Toll*> &t, const vector<Employee*> &emp, const vector<Client*> &cl):
        tolls(t), employees(emp), clients(cl){}

    ~SystemMonitor(){};

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

};


#endif //AEDA_T8G6_SYSTEMMONITOR_H
