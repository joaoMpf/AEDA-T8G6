#ifndef AEDA_T8G6_MENU_H
#define AEDA_T8G6_MENU_H

#include <iostream>
#include "systemMonitor.h"

using namespace std;

///Class with interactive functions with display
class menu {
private:
    SystemMonitor *systemMonitor;

    ///Displays main menu
    ///
    ///1 - EMPLOYEE calls monitorEmployee()
    ///2 - MANAGER calls monitorManager()
    ///3 - CLIENT calls clientManager()
    void mainMenu();

    ///Starts Employee monitor
    ///
    ///Allows login by calling SystemMonitor::loginEmployee()
    ///Then displays information about the Lane where the Employee is working
    ///And allows to pass Vehicles
    void monitorEmployee();

    ///Starts Manager monitor
    ///
    ///Allows manager to manage Highways or Employees
    ///1 - MANAGE HIGHWAYS calls manageHighways()
    ///2 - MANAGE EMPLOYEES calls manageEmployees()
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

    void operatePassToll(Client *client, bool exit);

    void manageCosts(Client *pClient);

    void manageInfo(Client *client);

    ///Displays Highway Management Menu
    ///
    ///1 - ADD HIGHWAY\n"
    ///2 - REMOVE HIGHWAY\n"
    ///3 - CHANGE EXISTING HIGHWAY(ADD OR REMOVE TOLLS,LANES,ETC)\n"
    ///4 - VIEW HIGHWAY LIST\n"
    void manageHighways();

    void manageExistingHighways(Highway* highway);

    void managerManageToll(Highway *highway);

    Highway *getHighway();

    Toll *getTollInput(bool exit, Highway *highway) const;

    ///Displays Employee Manangement Menu
    ///
    ///1 - ADD EMPLOYEE\n"
    ///2 - REMOVE EMPLOYEE\n"
    ///3 - CHANGE EMPLOYEE'S WORK LANE\n"
    ///4 - VIEW EMPLOYEE LIST\n"
    void manageEmployees();
};

enum main_menu {
    quit = '0', employee, manager, client
};
enum employee_menu {
    back = '0', operate
};

enum operate_toll {
    entry_toll = '1', exit_toll
};

enum monitor_tolls_menu {
    choose_toll_monitor = '1'
};


#endif //AEDA_T8G6_MENU_H
