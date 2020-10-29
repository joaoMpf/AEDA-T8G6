#include "systemMonitor.h"

const vector<Toll *> &SystemMonitor::getTolls() const {
    return tolls;
}

void SystemMonitor::setTolls(const vector<Toll *> &tolls) {
    SystemMonitor::tolls = tolls;
}

void SystemMonitor::save() {

}

void SystemMonitor::showTollsNumbered() {

}

void SystemMonitor::showToll(int toll) {

}
