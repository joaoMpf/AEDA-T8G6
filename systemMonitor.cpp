#include "systemMonitor.h"
#ifdef _WIN32
inline int getchar_unlocked() { return _getchar_nolock(); }
#endif

const vector<Employee *> &SystemMonitor::getEmployees() const {
    return employees;
}

bool SystemMonitor::addEmployee(const Employee *&employee) {
    return false;
}

bool SystemMonitor::removeEmployee(const Employee *&employee) {
    return false;
}

int SystemMonitor::findEmployee(const Employee *employee) {
    return sequentialSearch(employees,employee);
}

void SystemMonitor::sortEmployees() {

}

/*const vector<Client *> &SystemMonitor::getClients() const {
    return clients;
}
*/

void SystemMonitor::addClient(Client *client) {//?????????
    clients.push_back(client);
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
    //highwayName numTolls
    //nome1 localização tipo numeroDeVias pos price
    //nome2 localização tipo numeroDeVias pos price
    //...
    //nomex localização tipo numeroDeVias pos price
    ifstream tollfs("tolls.txt");
    string name, location, highway_name;
    bool type;
    int numLanes, numTolls, pos; double price;

    if (tollfs.is_open()) {
        while (!tollfs.eof()) {
            tollfs >> highway_name >> numTolls;
            vector<Toll*> tolls;
            Highway highway(highway_name);
            while(numTolls > 0) {
                vector<Lane *> lanes;
                tollfs >> name >> location >> type >> numLanes >> price;
                for (int i = 0; i < numLanes; i++) {
                    Lane e;
                    lanes.push_back(&e);
                }
                highway.addToll(new Toll(name, location, lanes, pos, price));
                numTolls--;
            }
            highways.push_back(&highway);
        }
    } else throw invalid_argument("Not able to open tolls file");
}
/*
int SystemMonitor::findVehicleClients(string licensePlate) {
    for (int i=0;i<circulatingVehicles.size();i++){
        if(circulatingVehicles[i]->getLicensePlate()==licensePlate){
            return i;
        }
    }
    return -1;
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

//Vehicle *SystemMonitor::getVehicle(const string &licensePlate) {
//    Vehicle *vehicle;
//
//    if (findCirculatingVehicle(licensePlate) != -1)
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
//    if (findCirculatingVehicle(licensePlate) != -1)
//        throw VehicleInCirculationException();
//}

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

Employee *SystemMonitor::loginEmployee(){
    int nif,pos;
    string name;
    for (int i = 0; i < 5; ++i) {
        name = getName();
        nif = getNif();
        try {
            if (confirmation()) {
                pos = findEmployee(new Employee(name, nif));
                if (pos != -1)
                    return employees[pos];
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
        ConfirmationExitException::showMessage();
        return nullptr;
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
    int count = 0;
    while (n != 0) {
        n = n / 10;
        ++count;
    }
    return count;

}

void SystemMonitor::removeVehicle(Client *client) {
    Vehicle *vehicle;
    string licensePlate;
    while(true) {
        licensePlate = licensePlateInput();
        if (licensePlate == "0") return;
        vehicle = client->getVehicle(licensePlate);
        if (vehicle == nullptr) {
            cout << "YOU DO NOT HAVE THIS VEHICLE REGISTERED\n";
            continue;
        }
        client->removeVehicle(vehicle);
        return;
    }
}

void SystemMonitor::viewVehicles(Client *client) {

    vector <Vehicle*>::iterator it;
    it=client->getVehicles().begin();

    while(true){
        client->printVehicles();
        cout<<"SELECT A VEHICLE TO VIEW ITS TRIPS (OR 0 TO GO BACK)"<<endl;
        switch(char c=getNumberInput()){
            case '0':
                return;
            default:
                if(isdigit(c)){
                    cout<<endl;
                    (*(it+atoi(&c)-1))->printTrips();
                    cout<<endl<<endl;
                    break;
                }
                else{
                    cout<<endl<<"NOT A VALID INPUT"<<endl<<endl;
                }
        }

    }
    return;

}

void SystemMonitor::updateVehicles(Client *client) {
    vector <Vehicle*> vehicles=client->getVehicles();
    bool viaverde;
    while(true){
        cout<<"WHICH VEHICLE DO YOU WANT TO UPDATE THE VIA-VERDE'S STATUS:"<<endl;
        client->printVehicles();
        cout<<"ENTER A NUMBER (OR PRESS 0 TO RETURN) ";
        switch(char c=getNumberInput()){
            case '0':
                return;
            default:
                if(isdigit(c)){

                    viaverde=(*vehicles.begin()+(atoi(&c)-1))->isViaVerde();
                    if(viaverde) {
                        cout<<endl<<"DO YOU WISH TO REMOVE THIS VEHICLE'S VIA VERDE? (PRESS Y/N FOR YES OR NO)";
                    }
                    else{
                        cout<<endl<<"DO YOU WISH TO ADD VIA VERDE TO THIS VEHICLE? (PRESS Y/N FOR YES OR NO)";
                    }
                    if(toupper(getNumberInput())=='Y'){
                        (*vehicles.begin()+(atoi(&c)-1))->changeViaVerde();
                        cout<<endl<<endl<<"DONE"<<endl<<endl;
                        return;
                    }
                    else{
                        cout<<endl<<endl<<"NO CHANGE WAS DONE"<<endl<<endl;
                        return;
                    }
                }
                else{
                    cout<<endl<<"NOT A VALID INPUT"<<endl<<endl;
                }
                break;
        }
    }
}

void SystemMonitor::showCosts(Client *client) {
    if(!(client->getVehicles().empty())) {
        for (auto x:(client->getVehicles())) {
            cout << "VEHICLE " << (x)->getLicensePlate() << endl << endl;
            if (!x->getTrips().empty()) {
                for (auto y:(x->getTrips())) {
                    cout << "FROM: " << (y)->getBegin()->getLocation() << endl;
                    cout << "TO: " << (y)->getEnd()->getLocation() << endl;
                    cout << "WHEN: " << (y)->getEndTime()->getDate() << endl;
                    cout << "PRICE PAID: " << (y)->getPrice() << endl;
                }
            }
            else{
                cout<<"NO TRIPS TO SHOW"<<endl<<endl;
            }
        }
    }
    else cout<<"NO VEHICLES TO SHOW"<<endl<<endl;

}

void SystemMonitor::changeNIF(Client *client) {
    int newNif=getNif();
    client->changeNIF(newNif);

}

void SystemMonitor::changeName(Client *client) {
    string newName=getName();
    client->changeName(newName);

}
Lane *SystemMonitor::findEmployeeLane(Employee *pEmployee) {

    for(auto h:highways){
        for(auto t:h->getTolls()){
            for(auto l:t->getLanes()){
                if(l->isNormalExitLane()){
                    if(l->getEmployee()==pEmployee){
                        return l;
                    };
                }
            }
        }
    }
    return nullptr;
}

Toll *SystemMonitor::findLaneToll(Lane *lane) {
    for(auto h:highways){
        for(auto t:h->getTolls()){
            for(auto l:t->getLanes()){
                if(l=lane){
                    return t;
                }
            }
        }
    }
    return nullptr;
}

Highway *SystemMonitor::findTollHighway(Toll *toll) {
    for(auto h:highways){
        for(auto t:h->getTolls()){
            if(t=toll) return h;
        }
    }
    return nullptr;

}

void SystemMonitor::managerAddHighway() {

    while(true) {

        cout<<"ENTER HIGHWAY NAME\n";
        string name;
        cin>>name;
        try {
            if (confirmation()) {
                addHighway(new Highway(name));
                cout << "HIGHWAY ADDED! \n"
                     << "TO CUSTOMIZE IT GO TO THE \"CHANGE EXISTING HIGHWAY\" MENU\n";
                return;
            }
            else continue;
        }
        catch (ConfirmationExitException &exception) {
            ConfirmationExitException::showMessage();
            return;
        }
    }

}

void SystemMonitor::managerRemoveHighway() {
    if(highways.size()>0) {
        printHighwaysNumbered();
        while(true) {
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
                }
                else continue;
            }
            catch (ConfirmationExitException &exception) {
                ConfirmationExitException::showMessage();
                return;
            }
        }
    }
    else{
        cout<<"NO HIGHWAYS TO DISPLAY";
        return;
    }

}

void SystemMonitor::managerViewHighways() {
    printHighwaysNumbered();
    while(true){
        cout<<"PRESS 0 TO LEAVE\n";
        if(getNumberInput()=='0') return;
    }

}



int SystemMonitor::selectHighway() {
    printHighwaysNumbered();
    int i;
    while(true){
        cout<<"SELECT A HIGHWAY TO MANAGE:\n";
        cin>>i;
        if(i>0&&i<=highways.size()){
            return i-1;
        }
        else cout<<"ENTER A VALID NUMBER\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }

}

void SystemMonitor::managerAddToll(Highway *phighway) {

    string name,location;
    while(true) {
        cout<<"ENTER TOLL NAME: \n";
        cin>>name;

        try {
            if (confirmation()) {
                break;
            }
            else continue;
        }
        catch (ConfirmationExitException &exception) {
            ConfirmationExitException::showMessage();
            return;
        }
    }
    while(true) {
        cout<<"ENTER TOLL LOCATION: \n";
        cin>>location;

        try {
            if (confirmation()) {
                break;
            }
            else continue;
        }
        catch (ConfirmationExitException &exception) {
            ConfirmationExitException::showMessage();
            return;
        }
    }
    int position;
    while(true) {
        cout<<"ENTER TOLL POSITION : \n";
        cin>>position;

        try {
            if (confirmation()) {
                break;
            }
            else continue;
        }
        catch (ConfirmationExitException &exception) {
            ConfirmationExitException::showMessage();
            return;
        }
    }
    float price;
    while(true) {
        cout<<"ENTER TOLL PRICE : \n";
        cin>>price;

        try {
            if (confirmation()) {
                break;
            }
            else continue;
        }
        catch (ConfirmationExitException &exception) {
            ConfirmationExitException::showMessage();
            return;
        }
    }
    vector<Lane*> l;
    phighway->addToll(new Toll(name,location,l,position,price));
    cout<<"\n\nTOLL ADDED SUCCESSFULLY\n ";
    return;
}



vector<Highway *> SystemMonitor::getHighways() {
    return highways;
}

void SystemMonitor::viewHighwayTolls(Highway *phighway) {
    if(phighway->getTolls().size()==0){
        cout<<"NO TOLLS TO SHOW\n";
        return;
    }
    phighway->printTollsNumbered();
    while(true){
        cout<<"PRESS 0 TO LEAVE\n";
        if(getNumberInput()=='0') return;
    }
}

void SystemMonitor::managerRemoveToll(Highway *phighway) {
    if(phighway->getTolls().size()>0) {
        phighway->printTollsNumbered();
        while(true) {
            cout << "WHICH HIGHWAY DO YOU WISH TO REMOVE\n";
            int i;
            cin >> i;
            try {
                if (confirmation()) {
                    if (i > 0 && i <= phighway->getTolls().size()) {
                        phighway->eraseTollAt(i-1);
                    }
                    cout << "TOLL ERASED SUCCESSFULLY\n";
                    return;
                }
                else continue;
            }
            catch (ConfirmationExitException &exception) {
                ConfirmationExitException::showMessage();
                return;
            }
        }
    }
    else{
        cout<<"NO TOLLS TO DISPLAY";
        return;
    }
}

Toll* SystemMonitor::selectToll(Highway *pHighway) {
    pHighway->printTollsNumbered();
    int i;
    while(true){
        cout<<"SELECT A TOLL TO MANAGE:\n";
        cin>>i;
        if(i>0&&i<=pHighway->getTolls().size()){
            return pHighway->getTolls()[i-1];
        }
        else cout<<"ENTER A VALID NUMBER\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }
}

void SystemMonitor::managerAddLane(Toll *pToll,bool viaVerde) {
    if (viaVerde) pToll->addLane(new ViaVerdeLane );
    else {
        if (pToll->isExitToll()){
            while(true) {
                cout << "DO YOU WANT TO ADD AN EMPLOYEE TO THIS LANE NOW?\n"
                        "YOU CAN DO IT LATER AT THE EMPLOYEE MENU (PRESS Y/N FOR YES OR NO)\n";
                char ans;
                while(true) {
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
                                    pToll->addLane(new NormalExitLane(0, vehicleQueue, employee, lastEmployees));
                                    return;
                                } else if (toupper(ans) == 'N') {
                                    cout
                                            << "LANE WAS CREATED. YOU CAN ALWAYS ADD AN EMPLOYER LATER IN THE EMPLOYEE MENU.\n";
                                    queue<pair<string, double>> vehicleQueue;
                                    vector<Employee *> lastEmployees;
                                    pToll->addLane(new NormalExitLane(0, vehicleQueue, nullptr, lastEmployees));
                                    return;
                                }
                                else if(ans=='0') return;
                                cin.clear();
                                cin.ignore(10000, '\n');
                                cout << "ENTER A VALID INPUT (Y/N) OR 0 TO RETURN\n";
                            }


                        } else {
                            queue<pair<string, double>> vehicleQueue;
                            vector<Employee *> lastEmployees;
                            pToll->addLane(new NormalExitLane(0, vehicleQueue, employee, lastEmployees));
                            return;
                        }
                    } else if(toupper(ans) == 'N') {
                        cout<< "LANE WAS CREATED. YOU CAN ALWAYS ADD AN EMPLOYER LATER IN THE EMPLOYEE MENU.\n";
                        queue<pair<string, double>> vehicleQueue;
                        vector<Employee *> lastEmployees;
                        pToll->addLane(new NormalExitLane(0, vehicleQueue, nullptr, lastEmployees));
                        return;
                    }
                    else if(ans=='0'){
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
    vector<Employee*>::const_iterator it; int i = 1;
    for(it = employees.begin(); it!= employees.end(); it++) {
        cout << i << ": " << (*it)->getName()<<endl;
        if ((*it)->isWorking()) cout<<"WORKING"<<endl<<endl;
        else cout<<"NOT WORKING"<<endl<<endl;
        i++;
    }
}

Employee *SystemMonitor::selectEmployee() {
    printEmployeesNumbered();
    int i;
    while(true){
        cout<<"SELECT AN EMPLOYEE:\n";
        cin>>i;
        if(i>0&&i<=employees.size()){
            return employees[i-1];
        }
        else cout<<"ENTER A VALID NUMBER\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }
}

void SystemMonitor::viewLanes(Toll *pToll) {
    vector<Lane*>::const_iterator it; int i = 1;
    for(it = pToll->getLanes().begin(); it!= pToll->getLanes().end(); it++) {
        cout << "LANE "<<i << ":\n";
        cout <<"VIA VERDE: ";
        if ((*it)->isViaVerde()){
            cout<<"YES\n\n";
        }
        else cout<<"NO\n\n";
        i++;
    }
}

void SystemMonitor::removeLane(Toll *pToll) {
    viewLanes(pToll);
    int i;
    while(true){
        cout<<"SELECT A LANE TO ERASE:\n";
        cin>>i;
        if(i>0&&i<=pToll->getLanes().size()){
            pToll->removeLaneAt(i-1);
            return;
        }
        else cout<<"ENTER A VALID NUMBER\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }
}

void SystemMonitor::changeLaneEmployee(Toll *pToll) {
    viewLanes(pToll);
    Lane* lane;
    int i;
    while(true){
        cout<<"SELECT A LANE:\n";
        cin>>i;
        if(i>0&&i<=pToll->getLanes().size()){
            lane=pToll->getLanes()[i-1];
            break;
        }
        else cout<<"ENTER A VALID NUMBER\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    Employee* employee=selectEmployee();
    if (employee->isWorking()) {
        cout << "THIS EMPLOYEE IS ALREADY WORKING IN A LANE DO YOU WANT TO MOVE HIM?\n"
                "(PRESS Y/N FOR YES OR NO)\n";
        char ans;
        while (true) {
            cin >> ans;
            if (toupper(ans) == 'Y') {
                Lane *oldLane = findEmployeeLane(employee);
                oldLane->setEmployee(nullptr);
                if(lane->getEmployee()!= nullptr){
                    lane->getEmployee()->changeWorkStatus();
                }
                lane->setEmployee(employee);
                return;
            } else if (toupper(ans) == 'N') return;
            else if (ans == '0') return;
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "ENTER A VALID INPUT (Y/N) OR 0 TO RETURN\n";
        }
    }
    else{
        if(lane->getEmployee()!= nullptr){
            lane->getEmployee()->changeWorkStatus();
        }
        lane->setEmployee(employee);
        return;
    }

}


