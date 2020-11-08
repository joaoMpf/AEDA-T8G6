#include <stdio.h>
#ifdef _WIN32
inline int getchar_unlocked() { return _getchar_nolock(); }
#endif
#include "menu.h"
#include <conio.h>
#include <stdexcept>



menu::menu() {
    this->systemMonitor = new SystemMonitor;

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
             << "1 - Monitor tolls\n"
             << "2 - Pass vehicles through tolls\n"
             << "3 - Info clients\n"
             << "4 - Info employees\n"
             << "0 - Save and quit\n";

        c=getchar_unlocked();

        switch (c) {
            case monitor_tolls:
                monitorTolls();
                break;
            case pass_tolls:
//                passTolls();
                break;
            case info_vehicles:
//                infoVehicles();
                break;
            case info_employees:
//                infoEmployees();
                break;
            case quit:
                end = true;
                break;
            default:
                cout << "\nPlease enter another number\n";
        }
    }
}

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

//FALTA DAR OPÇAO DE MUDAR O FUNCIONARIO DE CADA PORTAGEM

void menu::passTolls() {
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
            systemMonitor->TollMonitor(c-1); // c-1 é o indice da toll no vetor tolls
            cout << "\nPlease enter another number\n";
        }
        else{
            cout<<"\nEnter a valid input\n";
        }
        cin.clear();
        cin.ignore(10000, '\n');

    }


}
