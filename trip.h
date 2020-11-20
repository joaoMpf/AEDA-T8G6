#ifndef AEDA_T8G6_TRIP_H
#define AEDA_T8G6_TRIP_H

#include "time.h"
#include "toll.h"
#include <iostream>
#include <utility>

using namespace std;

///Contains info such as begin point, end point, begin time and end time
///
///@param begin points to the Toll where the trip started
///@param end points to the Toll where the trip ended
///Trips are stored in Vehicle

class Trip {
private:
    pair<string, double> begin, end;
    Time *beginTime;
    Time *endTime;
    bool finished = false;
    double pricePaid;
public:

    ///Creates a trip with begin toll and begin time
    ///
    /// \param begLocation
    /// \param begPrice
    /// \param begTime
    Trip(string begLocation, double begPrice, Time *begTime);

    //FALTA COMENTAR!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    Trip(const pair<string, double> &begin, const pair<string, double> &anEnd, Time *beginTime, Time *endTime,
         bool finished, double pricepaid);

    ///Sets end Toll
    ///
    /// \param endLocation
    /// \param endPrice
    void setEnd(string location, double price);

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

    ///Returns pair to begin toll distance and begin toll price
    ///
    /// \return pair to begin distance and price
    pair<string, double> getBegin() const;

    ///Returns pair to end toll distance and end toll price
    ///
    /// \return pair to end distance and price
    pair<string, double> getEnd() const;

    /// Returns pointer to begin Time
    ///
    /// \return pointer to begin Time
    Time *getBeginTime() const;

    /// Returns pointer to end Time
    ///
    /// \return
    Time *getEndTime() const;

    //FALTA COMENTAR!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    friend ostream &operator<<(ostream &os, const Trip &trip);

    //FALTA COMENTAR!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    friend istream &operator>>(istream &is, Trip &trip);

    Trip();
};


#endif //PORTAGENS_TRIP_H
