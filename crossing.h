#ifndef AEDA_T8G6_CROSSING_H
#define AEDA_T8G6_CROSSING_H

#include "vehicle.h"
#include "time.h"

class Crossing {
private:
    Time time;
    Vehicle vehicle;
    float pricePaid;
public:
    const Time &getTime() const;

    const Vehicle &getVehicle() const;

    float getPricePaid() const;
};


#endif //AEDA_T8G6_CROSSING_H
