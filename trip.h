//
// Created by Pedro Figueiredo on 10/11/2020.
//

#ifndef AEDA_T8G6_TRIP_H
#define AEDA_T8G6_TRIP_H

#include "time.h"
#include "toll.h"
#include <iostream>

using namespace std;

class Trip {
private:
    Toll* begin;
    Toll* end;
    Time* beginTime;
    Time* endTime;
    bool finished=false;
public:
    Trip(Toll* beg, Time* begTime): begin(beg), beginTime(begTime),
    endTime(new Time(0,0,0)), end(NULL){}

    void setEnd(Toll* toll);

    bool isFinished();

    void setEndTime(Time* time);

    Toll *getBegin() const;

    Toll *getEnd() const;

    Time *getBeginTime() const;

    Time *getEndTime() const;

};


#endif //PORTAGENS_TRIP_H
