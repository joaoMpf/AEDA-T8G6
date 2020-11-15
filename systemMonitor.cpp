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

Vehicle *SystemMonitor::findVehicleClients(const string &licensePlate) {
    int pos;
    if (!clients.empty())
        for (int i = 0; i < clients.size(); ++i) {
            pos = sequentialSearch(clients[i]->getVehicles(), new Vehicle(licensePlate));
            if (pos != -1)
                return clients[i]->getVehicles()[pos];
        }
    return nullptr;
}

int SystemMonitor::findCirculatingVehicle(const string &licensePlate) {
    return sequentialSearch(circulatingVehicles, new Vehicle(licensePlate));
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
    //load circulatingVehicles into vector
    ifstream vehiclefs("circulatingVehicles.txt");
    string licensePlate;
    int category;

    if (vehiclefs.is_open()) {
        while (!vehiclefs.eof()) {
            vehiclefs >> licensePlate >> category;
            circulatingVehicles.push_back(new Vehicle(licensePlate, category));
        }
    } else throw invalid_argument("Not able to open circulatingVehicles file");
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

int SystemMonitor::findVehicleClients(string licensePlate) {
    for (int i=0;i<circulatingVehicles.size();i++){
        if(circulatingVehicles[i]->getLicensePlate()==licensePlate){
            return i;
        }
    }
    return -1;
}*/
/*

void SystemMonitor::load() {
    ifstream vehiclefs("circulatingVehicles.txt");
    string licensePlate;
    int category;

    if (vehiclefs.is_open()) {
        while (!vehiclefs.eof()) {
            vehiclefs >> licensePlate >> category;
            circulatingVehicles.push_back(new Vehicle(licensePlate, category));
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
            return licensePlate;
        }

        cout << "ENTER A VALID LICENSE PLACE\n(LICENSE PLATE FORMAT SHOULD BE XX-XX-XX)\n";
    }
}

Vehicle *SystemMonitor::getVehicle(const string &licensePlate) {
    Vehicle *vehicle;

    if (findCirculatingVehicle(licensePlate) != -1)
        throw VehicleInCirculationException();
    vehicle = findVehicleClients(licensePlate);
    if (vehicle != nullptr)
        return vehicle;

    return firstTimeClient(licensePlate);
}

Vehicle *SystemMonitor::firstTimeClient(const string &licensePlate) {
    cout << "\nVEHICLE IS NOT IN THE SYSTEM\n";
    int category = categoryInput();

    addVehicle(new Vehicle(licensePlate, category));
    vector<Vehicle *>::const_iterator it;
    if (findCirculatingVehicle(licensePlate) != -1)
        throw VehicleInCirculationException();
}

void SystemMonitor::addVehicle(Vehicle *vehicle) {
    circulatingVehicles.push_back(vehicle);
}

void SystemMonitor::addHighway(Highway *highway) {
    highways.push_back(highway);
}

Client *SystemMonitor::login() {
    int nif, pos;

    for (int i = 0; i < 5; ++i) {
        cout << "Please enter nif: (enter 0 if new client)\n";
        cin >> nif;
        if (nif == 0)
            return createNewClient();
        try {
            if (confirmation()) {
                pos = findClient(new Client(nif));
                if (pos != -1)
                    return clients[pos];
            }
        } catch (ConfirmationExitException &exception) {
            ConfirmationExitException::showMessage();
            return nullptr;
        }
    }

    cout << "TOO MANY TRIES\n";
    return nullptr;
}

void SystemMonitor::addVehicleClient(Client *client) {
    cout << "Enter 0 to cancel and exit\n";

    string licensePlate;
    int category;
    bool viaVerde; //true se tiver via verde

    try {
        category = categoryInput();
        if (category == 0)
            throw CreatingVehicleException();

        viaVerde = viaVerdeInput();

        licensePlate = getNewLicensePlate();

    } catch (CreatingVehicleException &exception) {
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
            return category;
    }
}

string SystemMonitor::getNewLicensePlate() {
    string licensePlate;
    while (true) {
        cout << "Please enter new license plate:\n";
        licensePlate = licensePlateInput();

        if (licensePlate == "0")
            throw CreatingVehicleException();
        else if (findVehicleClients(licensePlate) == nullptr)
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

Client *SystemMonitor::createNewClient() {
    Client *client;
    string name;
    int nif;

    try {
        name = getName();
        nif = getNif();
    }
    catch (ConfirmationExitException &exception) {
        exception.showMessage();
    }

    client = new Client(name, nif);
    clients.push_back(client);

    return client;
}

int SystemMonitor::getNif() {
    int nif;

    while (true) {
        cout << "ENTER NIF\n";
        cin >> nif;
        if (confirmation() && countDigit(nif) == 9 && findClient(new Client(nif)) == -1)
            break;
    }

    return nif;
}

string SystemMonitor::getName() const {
    string name;

    while (true) {
        cout << "ENTER USERNAME\n";
        cin >> name;
        if (confirmation())
            break;
    }

    return name;
}

bool SystemMonitor::confirmation() {
    cout << "ENTER:\n"
         << "1 - CONFIRM\n"
         << "2 - ENTER AGAIN\n"
         << "0 - EXIT\n";

    switch (getNumberInput()) {
        case '1':
            return true;
        case '2':
            return false;
        case '0':
            throw ConfirmationExitException();
        default:
            break;
    }
}

int SystemMonitor::countDigit(int n) {
    int count = 0;
    while (n != 0) {
        n = n / 10;
        ++count;
    }
    return count;

}
