#include "systemMonitor.h"

const vector<Toll *> &SystemMonitor::getTolls() const {
    return tolls;
}

void SystemMonitor::setTolls(const vector<Toll *> &tolls) {
    SystemMonitor::tolls = tolls;
}
