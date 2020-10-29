#ifndef AEDA_T8G6_MENU_H
#define AEDA_T8G6_MENU_H

#include <iostream>
#include "systemMonitor.h"

using namespace std;

enum main_menu {
    quit= 0, monitor_tolls, pass_tolls, info_vehicles, info_employees
};

enum monitor_tolls_menu {
    choose_toll_monitor = 1
};

class menu {
private:
    SystemMonitor *systemMonitor;

    void mainMenu();

    void monitorTolls();

    void chooseTollMonitor();

    void passTolls();

    void infoVehicles();

    void infoEmployees();

public:
    menu();
};


#endif //AEDA_T8G6_MENU_H
