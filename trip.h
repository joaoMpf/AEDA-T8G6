#ifndef AEDA_T8G6_TRIP_H
#define AEDA_T8G6_TRIP_H

#include "time.h"
#include "toll.h"
#include <iostream>

using namespace std;

///Contains info such as begin point, end point, begin time and end time
///
///@param begin points to the Toll where the trip started
///@param end points to the Toll where the trip ended
///Trips are stored in Vehicle

class Trip {
private:
    Toll* begin;
    Toll* end;
    Time* beginTime;
    Time* endTime;
    bool finished = false;
    double pricepaid;
public:

    ///Creates a trip with begin toll and begin time
    ///
    /// \param beg
    /// \param begTime
    Trip(Toll* beg, Time* begTime): begin(beg), beginTime(begTime),
    endTime(new Time(0,0,0)), end(NULL){}

    ///Sets end Toll
    ///
    /// \param toll points to end Toll
    void setEnd(Toll* toll);

    ///Sets Price
    ///
    /// \param price
    void setPrice(double price);

    ///Checks if trip is finished
    ///
    /// \return true if trip is finished, false otherwise
    bool isFinished();

    /// Returns price paid
    ///
    /// \return
    double getPrice() const;

    /// Sets end time
    ///
    /// \param time pointer to end time
    void setEndTime(Time* time);

    ///Returns pointer to begin Toll
    ///
    /// \return pointer to begin Toll
    Toll *getBegin() const;

    /// Returns pointer to end Toll
    ///
    /// \return pointer to end Toll
    Toll *getEnd() const;

    /// Returns pointer to begin Time
    ///
    /// \return pointer to begin Time
    Time *getBeginTime() const;

    /// Returns pointer to end Time
    ///
    /// \return
    Time *getEndTime() const;

};


#endif //PORTAGENS_TRIP_H
