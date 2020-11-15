#ifndef AEDA_T8G6_MENU_H
#define AEDA_T8G6_MENU_H

#include <iostream>
#include "systemMonitor.h"

using namespace std;

class menu {
private:
    SystemMonitor *systemMonitor;

    void mainMenu();

    void monitorEmployee();

    void monitorManager();

    void operateToll(Client *client);

    void operateEntryToll(Client *client);

    void operateExitToll(Client *client);

/*    void monitorTolls();

    void chooseTollMonitor();

    void passTolls();

    void infoVehicles();

    void infoEmployees();*/

public:
    menu();

    void clientManager();

    void manageVehicles(Client *client);

    void operatePassToll(Client *client, bool entry);
};

enum main_menu {
    quit= '0', employee, manager, client
};
enum employee_menu {
    back= '0', operate
};

enum operate_toll {
    entry_toll = '1', exit_toll
};

enum monitor_tolls_menu {
    choose_toll_monitor = '1'
};



#endif //AEDA_T8G6_MENU_H
