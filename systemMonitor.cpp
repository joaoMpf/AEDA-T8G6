#include "systemMonitor.h"

#ifdef _WIN32
inline int getchar_unlocked() { return _getchar_nolock(); }
#endif

const vector<Employee *> &SystemMonitor::getEmployees() const {
    return employees;
}

bool SystemMonitor::addEmployee(Employee *employee) {
    employees.push_back(employee);
    return false;
}

bool SystemMonitor::removeEmployee(const Employee *&employee) {
    return false;
}

int SystemMonitor::findEmployee(const Employee *employee) {
    return sequentialSearch(employees, employee);
}

void SystemMonitor::sortEmployees() {

}

void SystemMonitor::addClient(Client *client) {//?????????
    clients.push_back(client);
}

bool SystemMonitor::removeClient(const Client *client) {//?????????
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

int SystemMonitor::findVehicle(const string &licensePlate) {
    return sequentialSearch(vehicles, new Vehicle(licensePlate));
}

int SystemMonitor::findClient(const Client *client) {
    return sequentialSearch(clients, client);
}


void SystemMonitor::sortClients() {

}

void SystemMonitor::save() {
    string vehiclesFileName = "vehicles.txt";
    string employeesFileName = "employees.txt";
    string clientsFileName = "clients.txt";
    string tollsFileName = "tolls.txt";

    saveVectorToFile(vehiclesFileName, vehicles);
    saveVectorToFile(employeesFileName, employees);
    saveVectorToFile(clientsFileName, clients);
    saveVectorToFile(tollsFileName, highways);
}

template<class T>
void SystemMonitor::saveVectorToFile(const string &vectorFileName, vector<T *> &vec) const {
    ofstream file(vectorFileName);
    if (!vec.empty() && file.is_open())
        for (int i = 0; i < vec.size(); ++i) {
            file << *vec[i];
            if (i != vec.size() - 1)
                file << endl;
        }
    else if (!file.is_open()) throw invalid_argument("Not able to open " + vectorFileName + " file");

    file.close();
}

void SystemMonitor::load() {
    string vehiclesFileName = "vehicles.txt";
    string employeesFileName = "employees.txt";
    string clientsFileName = "clients.txt";
    string tollsFileName = "tolls.txt";

    loadVectorFromFile(vehiclesFileName, vehicles);
    loadVectorFromFile(employeesFileName, employees);
    loadVectorFromFile(clientsFileName, clients);
    finishLoadingClients();
    loadVectorFromFile(tollsFileName, highways);
    finishLoadingLanes();
}

template<class T>
void SystemMonitor::loadVectorFromFile(string &vectorFileName, vector<T *> &vec) {
    ifstream file(vectorFileName);
    if (file.is_open()) {
        T *newElement = new T();
        while (file >> *newElement) {
//            cout << *newElement << endl;
            vec.push_back(newElement);
            newElement = new T();
        }
    } else throw invalid_argument("Not able to open " + vectorFileName + " file");
    file.close();
}

void SystemMonitor::loadTolls(const string &tollsFileName) {//load tolls into vector
//exemplo ficheiro portagens:
//highwayName numTolls
//tipo nome1 localização numeroDeVias pos price
//numPassagens veiculo preco veiculo preco ...
//tipo nome2 localização numeroDeVias pos price
//numPassagens veiculo preco
//...
//tipo nomex localização numeroDeVias pos price
    ifstream tollfs(tollsFileName);

    if (tollfs.is_open()) {
        string highway_name;
        int numTolls;
        while (tollfs >> highway_name >> numTolls) {
            Highway *highway = new Highway(highway_name);
            bool type;
            while (numTolls > 0 && tollfs >> type) {
                if (type)//type = true -> is exit toll
                {
                    OutToll *outToll = new OutToll();
                    tollfs >> *outToll;
                    highway->addToll(outToll);
                } else {
                    InToll *inToll = new InToll();
                    tollfs >> *inToll;
                    highway->addToll(inToll);
                }
                numTolls--;
            }
            highways.push_back(highway);
        }
        tollfs.close();
    } else throw invalid_argument("Not able to open tolls file");
}

//void SystemMonitor::loadClients(const string &clientsFileName) {//load employees into vector
////exemplo ficheiro client:
////name nif numCarros
////matricula1 matricula2 etc
////name nif numCarros
////matricula3
//    ifstream clientsfs(clientsFileName);
//
//    if (clientsfs.is_open()) {
//        string cName, licensePlate;
//        int nif, numVehicles;
//
//        while (clientsfs >> cName >> nif >> numVehicles) {
//            Client *client = new Client(cName, nif);
//            while (numVehicles > 0 && clientsfs >> licensePlate) {
//                client->addVehicle(getVehicle(licensePlate));
//                numVehicles--;
//            }
//            clients.push_back(client);
//        }
//        clientsfs.close();
//    } else throw invalid_argument("Not able to open clients file");
//}
//
//void SystemMonitor::loadEmployees(const string &employeesFileName) {//load employees into vector
////exemplo ficheiro empregado:
////nome1 numeroDeSS 1
////nome2 numeroDeSS 0
////...
////nomex numeroDeSS
//    ifstream employeesfs(employeesFileName);
//
//    if (employeesfs.is_open()) {
//        string eName;
//        int ssNumber;
//        bool working;
//
//        while (employeesfs >> eName >> ssNumber >> working) {
//            Employee *employee = new Employee(eName, ssNumber);
//            if (working) employee->changeWorkStatus();
//            employees.push_back(employee);
//        }
//        employeesfs.close();
//    } else throw invalid_argument("Not able to open employees file");
//}
//
//void SystemMonitor::loadVehicles(
//        const string &vehiclesFileName) {//considerando um ficheiro do texto em que cada linha representa um objeto
////exemplo ficheiro veiculo:
////matricula1 categoria viaVerde numTrips
////begLocation begPrice endLocation endPrice beginTime endTime finished pricePaid
////begLocation begPrice endLocation endPrice beginTime endTime finished pricePaid
////matricula2 categoria !viaVerde numTrips
////...
////matriculax categoria viaverde numTrips
////load vehicles into vector
//    ifstream vehiclefs(vehiclesFileName);
//
//    if (vehiclefs.is_open()) {
//        Vehicle *vehicle = new Vehicle();
//
//        while (vehiclefs >> *vehicle) {
//            vehicles.push_back(vehicle);
//            vehicle = new Vehicle();
//        }
//        vehiclefs.close();
//    } else throw invalid_argument("Not able to open " + vehiclesFileName + " file");
//}


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
    if (highways.empty() || i < 0 || i > highways.size())
        return nullptr;
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
    int i = findVehicle(licensePlate);
    if (i != -1)
        return vehicles[i];
    return nullptr;
}

//Vehicle *SystemMonitor::getVehicle(const string &licensePlate) {
//    Vehicle *vehicle;
//
//    if (findVehicle(licensePlate) != -1)
//        throw VehicleInCirculationException();
//    vehicle = findVehicleClients(licensePlate);
//    if (vehicle != nullptr)
//        return vehicle;
//
//    return firstTimeClient(licensePlate);
//}
//
//Vehicle *SystemMonitor::firstTimeClient(const string &licensePlate) {
//    cout << "\nVEHICLE IS NOT IN THE SYSTEM\n";
//    int category = categoryInput();
//
//    addVehicle(new Vehicle(licensePlate, category));
//
//    if (findVehicle(licensePlate) != -1)
//        throw VehicleInCirculationException();
//}

void SystemMonitor::addVehicle(Vehicle *vehicle) {
    vehicles.push_back(vehicle);
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

Employee *SystemMonitor::loginEmployee() {
    int ss, pos;

    while (true) {
        cout << "ENTER EMPLOYEE SS NUMBER: \n";
        cin >> ss;
        if (countDigit(ss) == 9) break;
        else if (ss == 0) return nullptr;
        cout << "NOT A VALID LOGIN NUMBER. TRY AGAIN OR PRESS 0 TO RETURN\n";
    }
    pos = findEmployee(new Employee("Joao", ss));

    if (pos != -1) return employees[pos];

    return nullptr;
}

void SystemMonitor::addVehicleClient(Client *client) {
    cout << "Enter 0 to cancel and exit\n";

    string licensePlate;
    int category;
    bool viaVerde; //true se tiver via verde

    try {
        category = categoryInput() - '0';
        if (category == 0)
            throw CreatingVehicleException();

        viaVerde = viaVerdeInput();

        licensePlate = getNewLicensePlate();

    } catch (CreatingVehicleException &exception) {
        CreatingVehicleException::showMessage();
        return;
    }
    Vehicle *vehicle = new Vehicle(licensePlate, category, viaVerde);
    client->addVehicle(vehicle);
    vehicles.push_back(vehicle);
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
        ConfirmationExitException::showMessage();
        return nullptr;
    }

    client = new Client(name, nif);
    clients.push_back(client);
    cout << *client << endl;
    return client;
}

int SystemMonitor::getNif() {
    int nif;

    while (true) {
        cout << "ENTER NIF\n";
        cin >> nif;
        if (confirmation() && countDigit(nif) == 9 && findClient(new Client(nif)) == -1)
            break;
        else cout << "ENTER A VALID 9 DIGIT NIF\n";

    }

    return nif;
}

string SystemMonitor::getName() {
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
    while (true) {
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
}

int SystemMonitor::countDigit(int n) {
    int cnt = 0;
    while (n != 0) {
        n = n / 10;
        ++cnt;
    }
    return cnt;

}

void SystemMonitor::removeVehicle(Client *client) {
    Vehicle *vehicle;
    string licensePlate;
    while (true) {
        licensePlate = licensePlateInput();
        if (licensePlate == "0") return;
        vehicle = client->getVehicle(licensePlate);
        if (vehicle != nullptr) {
            client->removeVehicle(vehicle);
            return;
        }
        cout << "YOU DO NOT HAVE THIS VEHICLE REGISTERED\n";
    }
}

void SystemMonitor::viewVehicles(Client *client) {

    if (client->getVehicles().empty()) {
        cout << "NO VEHICLES TO SHOW\n";
        return;
    }
    vector<Vehicle *>::iterator it;
    it = client->getVehicles().begin();
    char c;
    while (true) {
        client->printVehicles();
        cout << "SELECT A VEHICLE TO VIEW ITS TRIPS (OR 0 TO GO BACK)" << endl;
        switch (c = (char) getNumberInput()) {
            case '0':
                return;
            default:
                if (isdigit(c) || c < 1 || c > client->getVehicles().size()) {
                    cout << endl;
                    client->getVehicles()[(c - '0') - 1]->printTrips();
                    cout << endl << endl;
                    break;
                } else {
                    cout << endl << "NOT A VALID INPUT" << endl << endl;
                }
        }

    }
}

void SystemMonitor::updateVehicles(Client *client) {
    vector<Vehicle *> vehicles = client->getVehicles();
    bool viaverde;
    while (true) {
        cout << "WHICH VEHICLE DO YOU WANT TO UPDATE THE VIA-VERDE'S STATUS:" << endl;
        client->printVehicles();
        cout << "ENTER A NUMBER (OR PRESS 0 TO RETURN) ";
        switch (char c = getNumberInput()) {
            case '0':
                return;
            default:
                if (isdigit(c)) {

                    viaverde = (*vehicles.begin() + (atoi(&c) - 1))->isViaVerde();
                    if (viaverde) {
                        cout << endl << "DO YOU WISH TO REMOVE THIS VEHICLE'S VIA VERDE? (PRESS Y/N FOR YES OR NO)";
                    } else {
                        cout << endl << "DO YOU WISH TO ADD VIA VERDE TO THIS VEHICLE? (PRESS Y/N FOR YES OR NO)";
                    }
                    if (toupper(getNumberInput()) == 'Y') {
                        (*vehicles.begin() + (atoi(&c) - 1))->changeViaVerde();
                        cout << endl << endl << "DONE" << endl << endl;
                        return;
                    } else {
                        cout << endl << endl << "NO CHANGE WAS DONE" << endl << endl;
                        return;
                    }
                } else {
                    cout << endl << "NOT A VALID INPUT" << endl << endl;
                }
                break;
        }
    }
}

void SystemMonitor::showCosts(Client *client) {
    if (!(client->getVehicles().empty())) {
        for (auto x:(client->getVehicles())) {
            cout << "VEHICLE " << (x)->getLicensePlate() << endl << endl;
            if (!x->getTrips().empty()) {
                for (auto y:(x->getTrips())) {
                    cout << "FROM: " << (y)->getBegin().first << endl;
                    cout << "TO: " << (y)->getEnd().first << endl;
                    cout << "WHEN: " << (y)->getEndTime()->getDate() << endl;
                    cout << "PRICE PAID: " << (y)->getPrice() << endl;
                }
            } else {
                cout << "NO TRIPS TO SHOW" << endl << endl;
            }
        }
    } else cout << "NO VEHICLES TO SHOW" << endl << endl;

}

void SystemMonitor::changeNIF(Client *client) {

    int newNif = getNif();
    client->changeNIF(newNif);

}

void SystemMonitor::changeName(Client *client) {
    string newName = getName();
    client->changeName(newName);

}

Lane *SystemMonitor::findEmployeeLane(Employee *pEmployee) {

    for (auto h:highways) {
        for (auto t:h->getTolls()) {
            for (auto l:t->getLanes()) {

                if (l->getEmployee() == pEmployee) {
                    return l;
                };

            }
        }
    }
    return nullptr;
}

Toll *SystemMonitor::findLaneToll(Lane *lane) {
    for (auto h:highways) {
        for (auto t:h->getTolls()) {
            for (auto l:t->getLanes()) {
                if (l == lane) {
                    return t;
                }
            }
        }
    }
    return nullptr;
}

Highway *SystemMonitor::findTollHighway(Toll *toll) {
    for (auto h:highways) {
        for (auto t:h->getTolls()) {
            if (t == toll) return h;
        }
    }
    return nullptr;

}

void SystemMonitor::managerAddHighway() {

    while (true) {

        cout << "ENTER HIGHWAY NAME\n";
        string name;
        cin >> name;
        try {
            if (confirmation()) {
                addHighway(new Highway(name));
                cout << "HIGHWAY ADDED! \n"
                     << "TO CUSTOMIZE IT GO TO THE \"CHANGE EXISTING HIGHWAY\" MENU\n";
                return;
            } else continue;
        }
        catch (ConfirmationExitException &exception) {
            ConfirmationExitException::showMessage();
            return;
        }
    }

}

void SystemMonitor::managerRemoveHighway() {
    if (highways.size() > 0) {
        printHighwaysNumbered();
        while (true) {
            cout << "WHICH HIGHWAY DO YOU WISH TO REMOVE\n";
            int i;
            cin >> i;
            try {
                if (confirmation()) {
                    if (i > 0 && i <= highways.size()) {
                        highways.erase(highways.begin() + (i - 1));
                    }
                    cout << "HIGHWAY ERASED SUCCESSFULLY\n";
                    return;
                } else continue;
            }
            catch (ConfirmationExitException &exception) {
                ConfirmationExitException::showMessage();
                return;
            }
        }
    } else {
        cout << "NO HIGHWAYS TO DISPLAY";
        return;
    }

}

void SystemMonitor::managerViewHighways() {
    printHighwaysNumbered();
    int i;
    while (true) {
        cout << "PRESS 0 TO LEAVE\n";
        cin >> i;
        if (i == 0) return;
    }

}


int SystemMonitor::selectHighway() {
    printHighwaysNumbered();
    int i;
    while (true) {
        cout << "SELECT A HIGHWAY TO MANAGE:\n";
        cin >> i;
        if (i > 0 && i <= highways.size()) {
            return i - 1;
        } else cout << "ENTER A VALID NUMBER\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }

}

void SystemMonitor::managerAddToll(Highway *phighway, bool exit) {

    string name, location;
    while (true) {
        cout << "ENTER TOLL NAME: \n";
        cin >> name;

        try {
            if (confirmation()) {
                break;
            } else continue;
        }
        catch (ConfirmationExitException &exception) {
            ConfirmationExitException::showMessage();
            return;
        }
    }
    while (true) {
        cout << "ENTER TOLL LOCATION: \n";
        cin >> location;

        try {
            if (confirmation()) {
                break;
            } else continue;
        }
        catch (ConfirmationExitException &exception) {
            ConfirmationExitException::showMessage();
            return;
        }
    }
    int position;
    while (true) {
        cout << "ENTER TOLL POSITION : \n";
        cin >> position;

        try {
            if (confirmation()) {
                break;
            } else continue;
        }
        catch (ConfirmationExitException &exception) {
            ConfirmationExitException::showMessage();
            return;
        }
    }
    double price;
    while (true) {
        cout << "ENTER TOLL PRICE : \n";
        cin >> price;

        try {
            if (confirmation()) {
                break;
            } else continue;
        }
        catch (ConfirmationExitException &exception) {
            ConfirmationExitException::showMessage();
            return;
        }
    }
    vector<Lane *> l;
    if (exit) phighway->addToll(new OutToll(name, location, l, position, price));
    else phighway->addToll(new InToll(name, location, l, position, price));
    cout << "\n\nTOLL ADDED SUCCESSFULLY\n ";
    return;
}


vector<Highway *> SystemMonitor::getHighways() {
    return highways;
}

void SystemMonitor::viewHighwayTolls(Highway *phighway) {
    if (phighway->getTolls().empty()) {
        cout << "NO TOLLS TO SHOW\n";
        return;
    }
    phighway->printTollsNumbered();
    int i;
    while (true) {
        cout << "PRESS 0 TO LEAVE\n";
        cin >> i;
        if (i == 0) return;
    }
}

void SystemMonitor::managerRemoveToll(Highway *phighway) {
    if (!phighway->getTolls().empty()) {
        phighway->printTollsNumbered();
        while (true) {
            cout << "WHICH HIGHWAY DO YOU WISH TO REMOVE\n";
            int i;
            cin >> i;
            try {
                if (confirmation()) {
                    if (i > 0 && i <= phighway->getTolls().size()) {
                        phighway->eraseTollAt(i - 1);
                    }
                    cout << "TOLL ERASED SUCCESSFULLY\n";
                    return;
                } else continue;
            }
            catch (ConfirmationExitException &exception) {
                ConfirmationExitException::showMessage();
                return;
            }
        }
    } else {
        cout << "NO TOLLS TO DISPLAY";
        return;
    }
}

Toll *SystemMonitor::selectToll(Highway *pHighway) {
    pHighway->printTollsNumbered();
    int i;
    while (true) {
        cout << "SELECT A TOLL TO MANAGE:\n";
        cin >> i;
        if (i > 0 && i <= pHighway->getTolls().size()) {
            return pHighway->getTolls()[i - 1];
        } else cout << "ENTER A VALID NUMBER\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }
}

void SystemMonitor::managerAddLane(Toll *pToll, bool viaVerde) {
    if (!pToll->isExitToll()) pToll->addLane(new Lane);
    if (viaVerde) pToll->addLane(new ViaVerdeLane);
    else {
        if (pToll->isExitToll()) {
            while (true) {
                cout << "DO YOU WANT TO ADD AN EMPLOYEE TO THIS LANE NOW?\n"
                        "YOU CAN DO IT LATER AT THE EMPLOYEE MENU (PRESS Y/N FOR YES OR NO)\n";
                char ans;
                while (true) {
                    cin >> ans;
                    if (toupper(ans) == 'Y') {
                        Employee *employee = selectEmployee();
                        if (employee->isWorking()) {
                            cout << "THIS EMPLOYEE IS ALREADY WORKING IN A LANE DO YOU WANT TO MOVE HIM?\n";
                            while (true) {

                                cin >> ans;
                                if (toupper(ans) == 'Y') {
                                    Lane *oldLane = findEmployeeLane(employee);
                                    oldLane->setEmployee(nullptr);
                                    queue<pair<string, double>> vehicleQueue;
                                    vector<Employee *> lastEmployees;
                                    employee->changeWorkStatus();
                                    pToll->addLane(new NormalExitLane(0, vehicleQueue, employee, lastEmployees));
                                    cout << "LANE WAS CREATED\n\n";
                                    return;
                                } else if (toupper(ans) == 'N') {
                                    cout
                                            << "LANE WAS CREATED. YOU CAN ALWAYS ADD AN EMPLOYER LATER IN THE EMPLOYEE MENU.\n";
                                    queue<pair<string, double>> vehicleQueue;
                                    vector<Employee *> lastEmployees;
                                    pToll->addLane(new NormalExitLane(0, vehicleQueue, nullptr, lastEmployees));
                                    return;
                                } else if (ans == '0') return;
                                cin.clear();
                                cin.ignore(10000, '\n');
                                cout << "ENTER A VALID INPUT (Y/N) OR 0 TO RETURN\n";
                            }


                        } else {
                            queue<pair<string, double>> vehicleQueue;
                            vector<Employee *> lastEmployees;
                            employee->changeWorkStatus();
                            pToll->addLane(new NormalExitLane(0, vehicleQueue, employee, lastEmployees));
                            cout << "LANE WAS CREATED\n\n";
                            return;
                        }
                    } else if (toupper(ans) == 'N') {
                        cout << "LANE WAS CREATED. YOU CAN ALWAYS ADD AN EMPLOYER LATER IN THE EMPLOYEE MENU.\n";
                        queue<pair<string, double>> vehicleQueue;
                        vector<Employee *> lastEmployees;
                        pToll->addLane(new NormalExitLane(0, vehicleQueue, nullptr, lastEmployees));
                        return;
                    } else if (ans == '0') {
                        return;
                    }
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "ENTER A VALID INPUT (Y/N) OR 0 TO RETURN\n";
                }
            }

        }
    }
}

void SystemMonitor::printEmployeesNumbered() {
    vector<Employee *>::const_iterator it;
    int i = 1;
    for (it = employees.begin(); it != employees.end(); it++) {
        cout << i << ": " << (*it)->getName() << endl;
        if ((*it)->isWorking()) cout << "WORKING" << endl << endl;
        else cout << "NOT WORKING" << endl << endl;
        i++;
    }
}

Employee *SystemMonitor::selectEmployee() {
    printEmployeesNumbered();
    int i;
    while (true) {
        cout << "SELECT AN EMPLOYEE:\n";
        cin >> i;
        if (i > 0 && i <= employees.size()) {
            return employees[i - 1];
        } else cout << "ENTER A VALID NUMBER\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }
}

void SystemMonitor::removeLane(Toll *pToll) {
    pToll->viewLanes();
    int i;
    while (true) {
        cout << "SELECT A LANE TO ERASE:\n";
        cin >> i;
        if (i > 0 && i <= pToll->getLanes().size()) {
            pToll->removeLaneAt(i - 1);
            return;
        } else cout << "ENTER A VALID NUMBER\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }
}

void SystemMonitor::changeLaneEmployee(Toll *pToll) {
    pToll->viewLanes();

    Lane *lane;
    int i;
    while (true) {
        cout << "SELECT A LANE:\n";
        cin >> i;
        if (i > 0 && i <= pToll->getLanes().size()) {
            lane = pToll->getLanes()[i - 1];
            break;
        } else cout << "ENTER A VALID NUMBER\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    Employee *employee = selectEmployee();
    if (employee->isWorking()) {
        cout << "THIS EMPLOYEE IS ALREADY WORKING IN A LANE DO YOU WANT TO MOVE HIM?\n"
                "(PRESS Y/N FOR YES OR NO)\n";
        char ans;
        while (true) {
            cin >> ans;
            if (toupper(ans) == 'Y') {
                Lane *oldLane = findEmployeeLane(employee);
                oldLane->setEmployee(nullptr);
                if (lane->getEmployee() != nullptr) {
                    lane->getEmployee()->changeWorkStatus();
                }

                employee->changeWorkStatus();
                lane->setEmployee(employee);
                lane->addToEmployeeList(employee);
                return;
            } else if ((toupper(ans) == 'N') || (ans == '0')) return;
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "ENTER A VALID INPUT (Y/N) OR 0 TO RETURN\n";
        }
    } else {
        if (lane->getEmployee() != nullptr) {
            lane->getEmployee()->changeWorkStatus();
        }

        employee->changeWorkStatus();
        lane->setEmployee(employee);
        lane->addToEmployeeList(employee);
        return;
    }

}

void SystemMonitor::managerAddEmployee() {
    while (true) {

        cout << "ENTER EMPLOYEE NAME\n";
        string name;
        cin >> name;
        try {
            if (confirmation()) {
                cout << "ENTER EMPLOYEE SS NUMBER (9 DIGITS):\n";
                int ss;
                while (true) {
                    cout << "ENTER SS\n";
                    cin >> ss;
                    if (confirmation() && countDigit(ss) == 9 && findEmployee(new Employee(name, ss)) == -1) {
                        employees.push_back(new Employee(name, ss));
                        return;
                    }

                }

            } else continue;
        }
        catch (ConfirmationExitException &exception) {
            ConfirmationExitException::showMessage();
            return;
        }
    }

}

void SystemMonitor::managerRemoveEmployee() {
    int cnt = 1;
    for (auto x:employees) {
        cout << cnt << ": " << x->getName() << endl << endl;
        cnt++;
    }
    while (true) {
        cout << "SELECT AN EMPLOYEE OR PRESS 0 TO RETURN\n";
        cin >> cnt;
        if (cnt < 1 || cnt > employees.size()) {
            cout << "ENTER A VALID INPUT\n";
            cin.clear();
            cin.ignore(10000, '\n');
        } else break;
    }
    employees.erase(employees.begin() + (cnt - 1));
    return;
}

void SystemMonitor::changeEmployeeLane() {
    Employee *employee = selectEmployee();
    Highway *highway = highways[selectHighway()];
    Toll *pToll;
    highway->printTollsNumbered(true);
    int i;
    while (true) {
        cout << "SELECT A TOLL TO MANAGE OR PRESS 0 TO RETURN:\n";
        cin >> i;
        if (i == 0) return;
        if (i > 0 && i <= highway->getTolls().size()) {
            pToll = highway->getTollAt(i - 1, true);
            break;
        } else cout << "ENTER A VALID NUMBER\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    i = 0;
    for (int j = 0; j < pToll->getLanes().size(); j++) {
        cout << "LANE " << j + 1 << endl << "MANUAL EXIT LANE: ";
        if ((pToll->getLanes()[j])->isNormalExitLane()) {
            cout << "YES\n";
        } else cout << "NO\n";
    }
    Lane *lane;

    while (true) {
        cout << "SELECT A LANE OR PRESS 0 TO RETURN:\n";
        cin >> i;
        if (i > 0 && i <= pToll->getLanes().size() && (pToll->getLanes()[i - 1])->isNormalExitLane()) {
            lane = pToll->getLanes()[i - 1];
            break;
        } else if (i == 0) return;
        else if (!(pToll->getLanes()[i - 1])->isNormalExitLane()) cout << "ONLY MANUAL EXIT LANES HAVE EMPLOYEES\n";
        else cout << "ENTER A VALID NUMBER\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    if (employee->isWorking()) {
        cout << "THIS EMPLOYEE IS ALREADY WORKING IN A LANE DO YOU WANT TO MOVE HIM?\n"
                "(PRESS Y/N FOR YES OR NO)\n";
        char ans;
        while (true) {
            cin >> ans;
            if (toupper(ans) == 'Y') {
                Lane *oldLane = findEmployeeLane(employee);
                oldLane->setEmployee(nullptr);
                if (lane->getEmployee() != nullptr) {
                    lane->getEmployee()->changeWorkStatus();
                }
                employee->changeWorkStatus();
                lane->setEmployee(employee);
                lane->addToEmployeeList(employee);

                return;
            } else if ((toupper(ans) == 'N') || (ans == '0')) return;
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "ENTER A VALID INPUT (Y/N) OR 0 TO RETURN\n";
        }
    } else {

        if (lane->getEmployee() != nullptr) {

            lane->getEmployee()->changeWorkStatus();
        }
        employee->changeWorkStatus();
        lane->setEmployee(employee);
        lane->addToEmployeeList(employee);
        return;
    }
}

void SystemMonitor::viewEmployees() {
    printEmployeesNumbered();
    int i;
    while (true) {
        cout << "PRESS 0 TO LEAVE\n";
        cin >> i;
        if (i == 0) return;
    }
}

void SystemMonitor::viewLastEmployees(Toll *pToll) {
    int cnt = 0;
    for (auto x:pToll->getLanes()) {
        cnt++;
        if (x->isNormalExitLane()) {
            if (x->getLastEmployees().size() == 0) {
                cout << "LANE " << cnt << ": ";
                cout << "NO EMPLOYEE HISTORY FOR THIS LANE\n\n";
                continue;
            }


            cout << "LANE " << cnt << ":" << endl << endl;
            for (int i = 0; i < x->getLastEmployees().size() - 1; i++) {
                cout << x->getLastEmployees()[i]->getName() << endl;
            }
            cout << "CURRENT EMPLOYEE :";
            if (x->getEmployee() != nullptr) {
                cout << x->getEmployee()->getName() << endl << endl;
            } else cout << "NO EMPLOYEE" << endl << endl;

        } else {
            cout << "LANE " << cnt << ": ";
            cout << "NOT A MANUAL EXIT LANE\n\n";
        }

    }

}

void SystemMonitor::finishLoadingClients() {
    if (!clients.empty())
        for (auto &client : clients) {
            if (!client->getVehicles().empty()) {
                vector<Vehicle *> vecVehicles;
                for (auto &vehic : client->getVehicles()) {
                    Vehicle *vehicle = getVehicle(vehic->getLicensePlate());
                    if (vehicle != nullptr)
                        vecVehicles.push_back(getVehicle(vehic->getLicensePlate()));
                    else cout << "Error loading client vehicle!\n";
                }
                client->setVehicles(vecVehicles);
            }
        }
}

void SystemMonitor::finishLoadingLanes() {
    if (!employees.empty())
        for (auto &employee : employees)
            if (employee->isWorking())
                for (auto &highway : highways)
                    for (auto &toll : highway->getTolls())
                        for (auto &lane : toll->getLanes())
                            if (lane->getEmployee() != nullptr)
                                if (*lane->getEmployee() == *employee)
                                    lane->setEmployee(employee);


}
