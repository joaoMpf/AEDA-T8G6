#include <stdio.h>

#ifdef _WIN32
inline int getchar_unlocked() { return _getchar_nolock(); }
#endif

#include "menu.h"
#include <conio.h>
#include <stdexcept>


menu::menu() {
    this->systemMonitor = new SystemMonitor;
    Highway highway("A4");
    vector<Lane *> lanes;
    queue<pair<string, double>> queue1;
    lanes.push_back(new Lane(3,queue1));
    lanes.push_back(new ViaVerdeLane);
    highway.addToll(new InToll("A", "Custoias", lanes, 0, 0.0));
    highway.addToll(new OutToll("B", "Matosinhos", lanes, 10, 2.60));
    systemMonitor->addHighway(&highway);
    Client client1("Joao",123123123);
    Vehicle vehicle1("XX-XX-XX",1,true);
    client1.addVehicle(&vehicle1);
    systemMonitor->addClient(&client1);
    mainMenu();
    systemMonitor->save();
    free(systemMonitor);
}

void menu::mainMenu() {
    int c;
    bool firstLoop = true;

    while (true) {

        cout << "\nMAIN MENU\n"
             << "\nPlease enter number:\n"
             << "1 - EMPLOYEE\n"
             << "2 - MANAGER\n"
             << "3 - CLIENT\n"
             << "0 - Save and quit\n";

        if (!firstLoop)
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        cin.clear();
        c = getchar_unlocked();

        firstLoop = false;


        switch (c) {
            case employee:
                monitorEmployee();
                break;
            case manager:
                monitorManager();
                break;
            case client:
                clientManager();
                break;
            case quit:
                return;
            default:
                cout << "\nPlease enter another number\n";
        }
    }
}

void menu::monitorEmployee() {
    Employee *employee = this->systemMonitor->loginEmployee();
    if (employee == nullptr)
        return;
    Lane* lane=systemMonitor->findEmployeeLane(employee);
    Toll* toll=systemMonitor->findLaneToll(lane);
    Highway* highway=systemMonitor->findTollHighway(toll);
    while (true) {
        cout << "\nEMPLOYEE MENU:\n\n"
        <<"HIGHWAY: " <<highway->getName()<<"\n"
        <<"TOLL: "<<toll->getName()<<"\n"
        <<"THERE'S "<<lane->numberVehiclesWaiting()<<" VEHICLES WAITING IN YOUR LANE\n\n";
        if(lane->numberVehiclesWaiting()>0) {
            cout << "\nPLEASE ENTER NUMBER:\n"
                 << "1 - PASS NEXT VEHICLE\n"
                 << "0 - GO BACK\n\n";
        }
        else{
            cout << "\nPLEASE ENTER NUMBER:\n"
                 << "NO VEHICLES TO PASS\n"
                 << "0 - GO BACK\n\n";
        }
        switch (SystemMonitor::getNumberInput()) {
            case 1:
                if(lane->passVehicle()) {
                    lane->addCrossing();
                    cout<<"VEHICLE PASSED";
                }
                else cout<<"NO VEHICLE'S TO PASS";
                break;
            case back:
                return;
            default:
                cout << "\nPlease enter another number\n";
        }
    }
}

void menu::monitorManager() {
    while (true) {
        cout << "\nMANAGER MENU\n"
             << "\nPlease enter number:\n"
             << "1 - MANAGE HIGHWAYS\n"
             << "2 - MANAGE EMPLOYEES\n"//FALTA ESTE
             << "0 - GO BACK\n";

        switch (SystemMonitor::getNumberInput()) {
            case '1':
                manageHighways();
                break;
            case '2':
                //manageEmployees()
                break;
            case back:
                return;
            default:
                cout << "\nPlease enter another number\n";
        }
    }
}

void menu::clientManager() {
    Client *client = this->systemMonitor->login();
    if (client == nullptr)
        return;

    cout << "WELCOME " << client->getName() << endl;
    while (true) {
        cout << "\nCLIENT MENU\n"
             << "\nPlease enter number:\n"
             << "1 - MANAGE VEHICLES\n"
             << "2 - MANAGE COSTS\n"
             << "3 - PASS TOLLS\n"
             << "4 - MANAGE INFO\n"
             << "0 - GO BACK\n";

        switch (SystemMonitor::getNumberInput()) {
            case '1':
                manageVehicles(client);
                break;
            case '2':
                manageCosts(client);
                break;
            case '3':
                operateToll(client);
                break;
            case '4':
                manageInfo(client);
            case back:
                return;
            default:
                cout << "\nPlease enter another number\n";
        }
    }
}

void menu::manageVehicles(Client *client) {
    while (true) {
        cout << "\nVehicles MENU\n"
             << "\nPlease enter number:\n"
             << "1 - ADD VEHICLES\n"
             << "2 - REMOVE VEHICLES\n"
             << "3 - VIEW VEHICLES\n"
             << "4 - UPDATE VEHICLES\n"
             << "0 - GO BACK\n";

        switch (SystemMonitor::getNumberInput()) {
            case '1':
                this->systemMonitor->addVehicleClient(client);
                break;
            case '2':
                this->systemMonitor->removeVehicle(client);
                break;
            case '3':
                this->systemMonitor->viewVehicles(client);
                break;
            case '4':
                this->systemMonitor->updateVehicles(client);
                break;
            case back:
                return;
            default:
                cout << "\nPlease enter another number\n";
        }
    }
}

void menu::operateToll(Client *client) {
    while (true) {
        cout << "\nOPERATE TOLL\n"
             << "\nPlease enter number:\n"
             << "1 - ENTRY TOLL\n"
             << "2 - EXIT TOLL\n"
             << "0 - GO BACK\n";

        switch (SystemMonitor::getNumberInput()) {
            case entry_toll:
                operatePassToll(client, false);
                break;
            case exit_toll:
                operatePassToll(client, true);
                break;
            case back:
                return;
            default:
                cout << "\nPlease enter another number\n";
        }
    }
}

void menu::operatePassToll(Client *client, bool exit) {
    Highway *highway = getHighway();
    if (highway == nullptr) {
        cout << "INVALID HIGHWAY\n";
        return;
    }

    highway->printTollsNumbered(exit);
    Toll *toll = getTollInput(exit, highway);
    if (toll == nullptr) {
        cout << "INVALID TOLL\n";
        return;
    }

    if (toll->getLanes().empty()) {
        cout << "TOLL EMPTY\n";
        return;
    }

    string licensePlate;
    Vehicle *vehicle;

    while (true) {
        licensePlate = SystemMonitor::licensePlateInput(); //controla o input
        if (licensePlate == "0") return;
        vehicle = client->getVehicle(licensePlate);
        if (vehicle == nullptr) {
            cout << "YOU DO NOT HAVE THIS VEHICLE REGISTERED, PLEASE ADD VEHICLE AND TRY AGAIN LATER\n";
            continue;
        }
        Lane *lane = toll->getRecommendedLane(vehicle->isViaVerde());

        if (lane == nullptr) {
            if (vehicle->isViaVerde())
                cout << "NO VIA VERDE LANE\n";
            else
                cout << "NO NORMAL LANE\n";

            continue;
        }
        if (!exit) {
            lane->addVehicle(vehicle->getLicensePlate(), 0.0);
            vehicle->startTrip(toll, new Time);
            return;
        } else {
            float price; //CALCULAR PREÇO
            price = toll->getPrice() - vehicle->getLastTrip()->getBegin()->getPrice();
            vehicle->addPayment(price);
            if (vehicle->isViaVerde()){
                vehicle->endTrip(toll, new Time);
                return;
            }
            lane->addVehicle(vehicle->getLicensePlate(), price);
            return;

        }

    }
}

Toll *menu::getTollInput(bool exit, Highway *highway) const {
    cout << "CHOOSE TOLL\n";
    int tollNum;
    cin >> tollNum;
    cin.ignore(1000, '\n');
    cin.clear();
    Toll *toll = highway->getTollAt(tollNum,exit);
    return toll;
}

Highway *menu::getHighway() {
    systemMonitor->printHighwaysNumbered();
    cout << "CHOOSE HIGHWAY\n";
    int highwayNum;
    cin >> highwayNum;
    cin.ignore(1000, '\n');
    cin.clear();
    Highway *highway = systemMonitor->getHighwayAt(highwayNum - 1);
    return highway;
}

void menu::manageCosts(Client *client) {
    while(true){
        systemMonitor->showCosts(client);

        cout<<"ENTER 0 TO GO BACK"<<endl;
        if(SystemMonitor::getNumberInput()=='0'){
            return;
        }
    }

}

void menu::manageInfo(Client *client){
    while(true){
        cout << "\nCLIENT INFO:\n\n";
        client->printInfo();
        cout<< "\nPlease enter number:\n"
             << "1 - CHANGE NAME\n"
             << "2 - CHANGE NIF\n"
             << "0 - GO BACK\n";
        switch (SystemMonitor::getNumberInput()) {
            case '1':
                systemMonitor->changeName(client);
                break;
            case '2':
                systemMonitor->changeNIF(client);
                break;
            case back:
                return;
            default:
                cout << "\nPlease enter another number\n";
        }
    }
}

void menu::manageHighways() {
    while(true){
        cout << "\nHIGHWAY MANAGER MENU:\n\n";
        cout<< "\nPlease enter number:\n"
            << "1 - ADD HIGHWAY\n"
            << "2 - REMOVE HIGHWAY\n"
            << "3 - CHANGE EXISTING HIGHWAY(ADD OR REMOVE TOLLS,LANES,ETC)\n"
            << "4 - VIEW HIGHWAY LIST\n"
            << "0 - GO BACK\n";
        switch (SystemMonitor::getNumberInput()) {
            case '1':
                systemMonitor->managerAddHighway();
                break;
            case '2':
                systemMonitor->managerRemoveHighway();
                break;
            case '3':
                 manageExistingHighways();
            case '4':
                systemMonitor->managerViewHighways();
            case back:
                return;
            default:
                cout << "\nPlease enter another number\n";
        }
    }

}

void menu::manageExistingHighways() {
    if(systemMonitor->getHighways().size()==0){
        cout<<"NO HIGHWAYS TO MANAGE"<<endl;
        return;
    }
    Highway* highway=systemMonitor->getHighwayAt((systemMonitor->selectHighway()));
    while(true){
        cout << "\nHIGHWAY MANAGER MENU:\n\n";
        cout<< "\nPlease enter number:\n"
            << "1 - ADD TOLL\n"
            << "2 - REMOVE TOLL\n"
            << "3 - MANAGE TOLLS\n" //NOT DONE
            << "4 - VIEW HIGHWAY TOLLS\n"
            << "0 - GO BACK\n";
        switch (SystemMonitor::getNumberInput()) {
            case '1':
                systemMonitor->managerAddToll(highway);
                break;
            case '2':
                systemMonitor->managerRemoveToll(highway);
                break;
            case '3':
                managerManageToll(highway);
                break;
            case '4':
                systemMonitor->viewHighwayTolls(highway);
                break;
            case '0':
                return;
            default:
                cout << "\nPlease enter another number\n";
        }
    }
}

void menu::managerManageToll(Highway* highway) {
    Toll *toll=systemMonitor->selectToll(highway);
    while(true){
        cout << "\nTOLL MANAGER MENU:\n\n";
        cout<< "\nPlease enter number:\n"
            << "1 - ADD NORMAL LANE\n"
            << "2 - ADD VIA VERDE LANE\n"
            << "3 - CHANGE LANE EMPLOYEES\n"
            << "4 - REMOVE LANE\n"
            << "5 - VIEW LANES\n"
            << "0 - GO BACK\n";
        switch (SystemMonitor::getNumberInput()) {
            case '1':
                systemMonitor->managerAddLane(toll,false);
                break;
            case '2':
                systemMonitor->managerAddLane(toll,true);
                break;
            case '3':
                systemMonitor->changeLaneEmployee(toll);
                break;
            case '4':
                systemMonitor->removeLane(toll);
                break;
            case '5':
                systemMonitor->viewLanes(toll);
                break;
            case '0':

                return;
            default:
                cout << "\nPlease enter another number\n";
        }
    }
}
