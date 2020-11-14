#include "systemMonitor.h"


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

bool SystemMonitor::addClient(const Client *&client) {//?????????
    return false;
}

bool SystemMonitor::removeClient(const Client *&client) {//?????????
    return false;
}

int SystemMonitor::findVehicle(const string &licensePlate) {
    int pos;
    if (!clients.empty())
        for (int i = 0; i < clients.size(); ++i) {
            pos = sequentialSearch(clients[i]->getVehicles(), new Vehicle(licensePlate));
            if (pos != -1)
                return pos;
        }
    return -1;
}

int SystemMonitor::findClient(const Client *client) {
    return sequentialSearch(clients, client);
}

void SystemMonitor::sortClients() {

}

void SystemMonitor::save() {

}

/*void SystemMonitor::showTollsNumbered() {
    for (int i=0;i<tolls.size();i++){
        cout<<i+1<<") "<<tolls[i]->getName()<<" - "
        <<tolls[i]->getLocation()<<" - "<<
        tolls[i]->getType()<<endl;
    }
}*/

/*
void SystemMonitor::showToll(int toll) {

    cout << "Name: " << tolls[toll]->getName() << endl
         << "Location: " << tolls[toll]->getLocation() << endl
         << "Type: " << tolls[toll]->getType() << endl
         << "Number of lanes: " << tolls[toll]->getLanes().size() << " lanes" << endl;

}

*/
/*
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
            vector<Lane*> lanes;
            tollfs >> name >> location >> type >> numLanes;
            for (int i = 0; i < numLanes; i++) {
                Lane e;
                lanes.push_back(&e);
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
}*/
/*

void SystemMonitor::load() {
    ifstream vehiclefs("vehicles.txt");
    string licensePlate;
    int category;

    if (vehiclefs.is_open()) {
        while (!vehiclefs.eof()) {
            vehiclefs >> licensePlate >> category;
            vehicles.push_back(new Vehicle(licensePlate, category));
        }
        vehiclefs.close();
    }

    ifstream highwaysfs("highways.txt");




}
*/

const vector<Client *> &SystemMonitor::getClients() const {
    return clients;
}

void SystemMonitor::startTrip(Vehicle *vehicle, Toll *toll, Time *time) {
    vehicle->startTrip(toll, time);

}

void SystemMonitor::endTrip(Vehicle *vehicle, Toll *toll, Time *time) {
    vehicle->endTrip(toll, time);
}

void SystemMonitor::printHighwaysNumbered() {
    vector<Highway *>::const_iterator it;
    int i = 1;
    for (it = highways.begin(); it != highways.end(); it++) {
        cout << i << ": " << (*it)->getName() << endl;
        i++;
    }
}

Highway *SystemMonitor::getHighwayAt(int i) {
    return highways[i];
}

string SystemMonitor::licensePlateInput() {
    string licensePlate;
    cout << "\nENTER LICENSE PLATE "
            "(LICENSE PLATE FORMAT SHOULD BE XX-XX-XX)"
            "\n(OR 0 TO EXIT)\n";
    while (true) {

        cin >> licensePlate;
        for (int i = 0; i < licensePlate.size(); i++) licensePlate[i] = toupper(licensePlate[i]);
        if (licensePlate == "0") return "0";
        if (licensePlate.length() == 8 && licensePlate[2] == '-' && licensePlate[5] == '-') {
            break;
        }
//        cin.ignore(1000, '\n');
//        cin.clear();
        cout << "ENTER A VALID LICENSE PLACE\n(LICENSE PLATE FORMAT SHOULD BE XX-XX-XX)\n";
    }
    return licensePlate;
}

Vehicle *SystemMonitor::getVehicle(string licensePlate) {
    vector<Vehicle *>::const_iterator it;
    for (it = vehicles.begin(); it != vehicles.end(); it++) {
        if ((*it)->getLicensePlate() == licensePlate)
            return *it;
    }
    return firstTimeClient(licensePlate);

}

Vehicle *SystemMonitor::firstTimeClient(string licensePlate) {
    cout << "\nVEHICLE IS NOT IN THE SYSTEM\n";
    int category = categoryInput();

    addVehicle(new Vehicle(licensePlate, category));
    vector<Vehicle *>::const_iterator it;
    for (it = vehicles.begin(); it != vehicles.end(); it++) {
        if ((*it)->getLicensePlate() == licensePlate)
            return *it;
    }
}

void SystemMonitor::addVehicle(Vehicle *vehicle) {
    vehicles.push_back(vehicle);
}

void SystemMonitor::addHighway(Highway *highway) {
    highways.push_back(highway);
}

Client *SystemMonitor::login() {
    int nif, pos;
    for (int i = 0; i < 5; ++i) {
        cout << "Please enter nif:\n";
        cin >> nif;
        pos = findClient(new Client(nif));
        if (pos != -1)
            return clients[pos];
    }
    return nullptr;
}

void SystemMonitor::addVehicleClient(Client *client) {
    cout << "Enter \"0\" at anytime to cancel and exit\n";

    string licensePlate;
    int category;
    bool viaVerde; //true se tiver via verde

    try {
        category = categoryInput();
        if (category == 0)
            throw CreatingVehicleException();

        viaVerde = viaVerdeInput();

        licensePlate = getNewLicensePlate();

    } catch (CreatingVehicleException exception) {
        exception.showMessage();
        return;
    }


    client->addVehicle(new Vehicle(licensePlate, category, viaVerde));
}

int SystemMonitor::categoryInput() const {
    int category;
    while (true) {
        cout << "\nPLEASE ENTER A VALID VEHICLE CATEGORY. CATEGORY MUST BE A NUMBER BETWEEN 1 AND 5 (0 TO EXIT)\n";
        category = getNumberInput();

        if (category == '0')
            return 0;
        if (category > '0' && category < '6')
            break;
    }
    return category;
}

string SystemMonitor::getNewLicensePlate() {
    string licensePlate;
    while (true) {
        cout << "Please enter new license plate:\n";
        licensePlate = licensePlateInput();

        if (licensePlate == "0")
            throw CreatingVehicleException();
        else if (findVehicle(licensePlate) == -1)
            return licensePlate;

        cout << "LICENSE PLATE ALREADY IN USE\n";
    }
}

bool SystemMonitor::viaVerdeInput() {
    int viaVerde;
    while (true) {
        cout << "THIS CAR HAS VIA VERDE?\n"
             << "1 - FALSE (DOES NOT HAVE)\n"
             << "2 - TRUE (HAS)\n"
             << "0 - EXIT AND CANCEL\n";

        viaVerde = SystemMonitor::getNumberInput();

        switch (viaVerde) {
            case '0':
                throw CreatingVehicleException();
            case '1':
                return false;
            case '2':
                return true;
            default:
                break;
        }
    }
}

int SystemMonitor::getNumberInput() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cin.clear();
    return getchar_unlocked();
}
