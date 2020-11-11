#include <stdio.h>
#ifdef _WIN32
inline int getchar_unlocked() { return _getchar_nolock(); }
#endif
#include "menu.h"
#include <conio.h>
#include <stdexcept>



menu::menu() {
    this->systemMonitor = new SystemMonitor;
    systemMonitor->addVehicle(new Vehicle("AA-AA-AA", 1));
    systemMonitor->addVehicle(new Vehicle("XX-AA-00", 1));
    Highway highway("A4");
    vector<Lane*> lanes;
    highway.addToll(new Toll("A", "Custóias",0,lanes));
    highway.addToll(new Toll("B", "Matosinhos",1,lanes));
    systemMonitor->addHighway(&highway);
    mainMenu();


    systemMonitor->save();
    free(systemMonitor);
}

void menu::mainMenu() {
    bool end = false;
    int c;

    while (!end) {

        cout << "\nMAIN MENU\n"
             << "\nPlease enter number:\n"
             << "1 - EMPLOYEE\n"
             << "2 - MANAGER\n"
             << "0 - Save and quit\n";

        c=getchar_unlocked();

        switch (c) {
            case employee:
                monitorEmployee();
                break;
            case manager:
//                passTolls();
                break;
            case quit:
                end = true;
                break;
            default:
                cout << "\nPlease enter another number\n";
        }
    }
}

void menu::monitorEmployee(){
    bool end = false;
    int c;

    while (!end) {
        cout << "\nEMPLOYEE MENU\n"
             << "\nPlease enter number:\n"
             << "1 - OPERATE TOLL\n"
             << "0 - GO BACK\n";

        c=getchar_unlocked();

        switch (c) {
            case employee:
                operateToll();
                break;
            case back:
                end = true;
                break;
            default:
                cout << "\nPlease enter another number\n";
        }
    }
}

void menu::operateToll() {
    int c;
    while (1) {
        cout << "\nOPERATE TOLL\n"
             << "\nPlease enter number:\n"
             << "1 - ENTRY TOLL\n"
             << "2 - EXIT TOLL\n"
             << "0 - GO BACK\n";

        c=getchar_unlocked();

        switch (c) {
            case entry_toll:
                operateEntryToll();
                break;
            case exit_toll:
                operateExitToll();
                break;
            case back:
                return;
            default:
                cout << "\nPlease enter another number\n";
        }
    }
}

void menu::operateEntryToll(){
    systemMonitor->printHighwaysNumbered();
    cout << "CHOOSE HIGHWAY\n"; int highwayNum;
    cin >> highwayNum; cin.ignore(1000, '\n'); cin.clear();
    Highway* highway = systemMonitor->getHighwayAt(highwayNum - 1);

    highway->printTollsNumbered();
    cout << "CHOOSE TOLL\n"; int tollNum;
    cin >> tollNum; cin.ignore(1000, '\n'); cin.clear();
    Toll* toll = highway->getTollAt(tollNum - 1 );

    string licensePlate; Vehicle* vehicle;

    while(1){
        cout << "\nENTER LICENSE PLATE\n(OR 0 TO EXIT)\n";
        cin >> licensePlate;
        if (licensePlate == "0")
            break;
        vehicle = systemMonitor->getVehicle(licensePlate);
        systemMonitor->startTrip(vehicle, toll, new Time(0,0,0));
        vehicle->printTrips();
    }
}

void menu::operateExitToll() {
    return;
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
    cout<<"Enter the vehicle's license plate: ";
    cin>>licenseP;

*//*

}
*/

