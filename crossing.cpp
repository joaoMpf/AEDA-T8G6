#include "crossing.h"

const Time &Crossing::getTime() const {
    return time;
}

const Vehicle &Crossing::getVehicle() const {
    return vehicle;
}

float Crossing::getPricePaid() const {
    return pricePaid;
}
