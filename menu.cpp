#include "menu.h"
#include <conio.h>

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
             << "1 - monitor tolls\n"
             << "2 - pass vehicles through tolls\n"
             << "3 - info vehicles\n"
             << "4 - info employees\n"
             << "0 - save and quit\n";

        c = getchar_unlocked();

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

    cout << "\nTOLL MENU\n"
         << "\nPlease enter number:\n"
         << "\n1 - choose toll\n"
         << "\n0 - back to main menu\n";

    while (!end) {
        c = getc(stdin);
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
        c = getc(stdin);
        switch (c) {
            case quit:
                end = true;
                break;
            default:
                systemMonitor->showToll(c);
                cout << "\nPlease enter another number\n";
        }
    }
}
