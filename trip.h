#ifndef AEDA_T8G6_TRIP_H
#define AEDA_T8G6_TRIP_H

#include "time.h"
#include "toll.h"
#include <iostream>
#include <utility>

using namespace std;

class Trip {
private:
//    Toll* begin;
//    Toll* end;
    pair<string, double> begin, end;
    Time *beginTime;
    Time *endTime;
    bool finished = false;
    double pricepaid;
public:
    Trip(string begLocation, double begPrice, Time *begTime);

    Trip(const pair<string, double> &begin, const pair<string, double> &anEnd, Time *beginTime, Time *endTime,
         bool finished, double pricepaid);

    void setEnd(string location, double price);

    void setPrice(double price);

    bool isFinished();

    double getPrice() const;

    void setEndTime(Time *time);

    pair<string, double> getBegin() const;

    pair<string, double> getEnd() const;

    Time *getBeginTime() const;

    Time *getEndTime() const;

    friend ostream &operator<<(ostream &os, const Trip &trip);

    friend istream &operator>>(istream &is, Trip &trip);

};


#endif //PORTAGENS_TRIP_H
