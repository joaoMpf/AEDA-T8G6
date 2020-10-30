#include "systemMonitor.h"


const vector<Toll *> &SystemMonitor::getTolls() const {
    return tolls;
}

bool SystemMonitor::addToll(const Toll *&toll) {
    return false;
}

bool SystemMonitor::removeToll(const Toll *&toll) {
    return false;
}

int SystemMonitor::findToll(const Toll *&toll) {
    return 0;
}

void SystemMonitor::sortTolls() {

}

const vector<Employee *> &SystemMonitor::getEmployees() const {
    return employees;
}

bool SystemMonitor::addEmployee(const Employee *&employee) {
    return false;
}

bool SystemMonitor::removeEmployee(const Employee *&employee) {
    return false;
}

int SystemMonitor::findEmployee(const Employee *&employee) {
    return 0;
}

void SystemMonitor::sortEmployees() {

}

/*const vector<Client *> &SystemMonitor::getClients() const {
    return clients;
}
*/
bool SystemMonitor::addClient(const Client *&client) {
    return false;
}

bool SystemMonitor::removeClient(const Client *&client) {
    return false;
}

int SystemMonitor::findClient(const Client *&client) {
    return 0;
}

void SystemMonitor::sortClients() {

}

void SystemMonitor::save() {

}

void SystemMonitor::showTollsNumbered() {
    for (int i=0;i<tolls.size();i++){
        cout<<i+1<<") "<<tolls[i]->getName()<<" - "
        <<tolls[i]->getLocation()<<" - "<<
        tolls[i]->getType()<<endl;
    }
}

void SystemMonitor::showToll(int toll) {

    cout << "Name: " << tolls[toll]->getName() << endl
         << "Location: " << tolls[toll]->getLocation() << endl
         << "Type: " << tolls[toll]->getType() << endl
         << "Number of lanes: " << tolls[toll]->getLanes().size() << " lanes" << endl;

}


void SystemMonitor::load() { //provavelmente vai ter de ser
    //alterado mas já fica estruturado

    //considerando um ficheiro do texto em que cada linha representa um objeto
    //exemplo ficheiro veiculo:
    //matricula1 categoria
    //matricula2 categoria
    //...
    //matriculax categoria
    //load vehicles into vector
    ifstream vehiclefs("vehicles.txt");
    string licensePlate;
    int category;

    if (vehiclefs.is_open()) {
        while (!vehiclefs.eof()) {
            vehiclefs >> licensePlate >> category;
            vehicles.push_back(new Vehicle(licensePlate, category));
        }
    } else throw invalid_argument("Not able to open vehicles file");
    //load employees into vector
    //exemplo ficheiro empregado:
    //nome1 numeroDeSS
    //nome2 numeroDeSS
    //...
    //nomex numeroDeSS
    ifstream employeesfs("employees.txt");
    string eName;
    int ssNumber;
    if (employeesfs.is_open()) {
        while (!employeesfs.eof()) {
            employeesfs >> eName >> ssNumber;
            employees.push_back(new Employee(eName, ssNumber));
        }
    } else throw invalid_argument("Not able to open employees file");
    //load tolls into vector
    //exemplo ficheiro portagens:
    //nome1 localização tipo numeroDeVias
    //nome2 localização tipo numeroDeVias
    //...
    //nomex localização tipo numeroDeVias
    ifstream tollfs("tolls.txt");
    string name, location;
    bool type;
    int numLanes;

    if (tollfs.is_open()) {
        while (!tollfs.eof()) {
            vector<Lane> lanes;
            tollfs >> name >> location >> type >> numLanes;
            for (int i = 0; i < numLanes; i++) {
                Lane e;
                lanes.push_back(e);
            }
            tolls.push_back(new Toll(name, location, type, lanes));
        }
    } else throw invalid_argument("Not able to open tolls file");
}

int SystemMonitor::findVehicle(string licensePlate) {
    for (int i=0;i<vehicles.size();i++){
        if(vehicles[i]->getLicensePlate()==licensePlate){
            return i;
        }
    }
    return -1;
}

const vector<Client *> &SystemMonitor::getClients() const {
    return clients;
}
