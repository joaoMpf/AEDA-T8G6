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
    highway.addToll(new InToll("A", "Custóias", lanes));
    highway.addToll(new OutToll("B", "Matosinhos", lanes));
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
    while (true) {
        cout << "\nEMPLOYEE MENU\n";
        cout << "\nPlease enter number:\n"
             << "1 - OPERATE TOLL\n"
             << "0 - GO BACK\n";


        switch (SystemMonitor::getNumberInput()) {
            case 1:
//               employeeMenu();
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
             << "2 - MANAGE EMPLOYEES\n"
             //<< "3 - MANAGE CLIENTS\n"
             << "0 - GO BACK\n";

        switch (SystemMonitor::getNumberInput()) {
            case '1':
                //manageHighways();
                break;
            case '2':
                //manageEmployees()
                break;
            case '3':
                //manageClients()
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
    systemMonitor->printHighwaysNumbered();
    cout << "CHOOSE HIGHWAY\n";
    int highwayNum;
    cin >> highwayNum;
    cin.ignore(1000, '\n');
    cin.clear();
    Highway *highway = systemMonitor->getHighwayAt(highwayNum - 1);

    highway->printTollsNumbered(exit);
    cout << "CHOOSE TOLL\n";
    int tollNum;
    cin >> tollNum;
    cin.ignore(1000, '\n');
    cin.clear();
    Toll *toll = highway->getTollAt(tollNum,exit);
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
            int price = 0; //FALTA CALCULAR PREÇO
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


/*
void menu::monitorTolls() {
   bool end = false;
   int c;

   while (!end) {

       c=getchar_unlocked();
       cout << "\nTOLL MENU\n"
            << "\nPlease enter number:\n"
            << "\n1 - Choose toll\n"
            << "\n0 - Back to main menu\n";

       switch (c) {
           case choose_toll_monitor:
               chooseTollMonitor();
               break;
           case quit:
               end = true;
               break;
           default:
               cout << "\nPlease enter another number\n";

       }
   }
}

void menu::chooseTollMonitor() {
   bool end = false;
   int c;


   systemMonitor->showTollsNumbered();

   cout << "\nTOLL MENU\n"
        << "\nPlease enter number of a toll:\n"
        << "\n0 - back to main menu\n";

   while (!end) {
       cin>>c;
       if (c==0){
           end = true;
           break;
       }
       else if ((c-1)>=0&&c-1<(systemMonitor->getTolls().size())) {
           systemMonitor->showToll(c - 1);
           cout << "\nPlease enter another number\n";
       }
       else{
           cout<<"\nEnter a valid input\n";
       }
       cin.clear();
       cin.ignore(10000, '\n');

   }
}

void menu::passTolls() {
*/
/*    string licenseP;
    cout<<"Enter the circulatingVehicles's license plate: ";
    cin>>licenseP;

*//*

}
*/

