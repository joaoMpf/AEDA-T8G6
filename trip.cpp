#include "trip.h"

#include <utility>

Trip::Trip(string begLocation, double begPrice, Time *begTime) : beginTime(begTime), endTime(new Time(0, 0, 0)) {
    pricepaid = 0;
    begin.first = std::move(begLocation);
    begin.second = begPrice;
}

Trip::Trip(const pair<string, double> &begin, const pair<string, double> &anEnd, Time *beginTime, Time *endTime,
           bool finished, double pricepaid) : begin(begin), end(anEnd), beginTime(beginTime), endTime(endTime),
                                              finished(finished), pricepaid(pricepaid) {}

void Trip::setEnd(string location, double price) {
    end.first = std::move(location);
    end.second = price;
    finished = true;
}

void Trip::setEndTime(Time *time) {
    endTime = time;
}

pair<string, double> Trip::getBegin() const {
    return begin;
}

Time *Trip::getBeginTime() const {
    return beginTime;
}

pair<string, double> Trip::getEnd() const {
    return end;
}

bool Trip::isFinished() {
    return finished;
}

Time *Trip::getEndTime() const {
    return endTime;
}

void Trip::setPrice(double price) {
    pricepaid = price;
}

double Trip::getPrice() const {
    return pricepaid;
}

ostream &operator<<(ostream &os, const Trip &trip) {
    os << trip.begin.first << " " << trip.begin.second << " " << trip.end.first << " " << trip.end.second << " "
       << *trip.beginTime << " " << *trip.endTime << " " << trip.finished << " " << trip.pricepaid;
    return os;
}

istream &operator>>(istream &is, Trip &trip) {
    pair<string, double> begin, end;
    Time *beginTime = new Time;
    Time *endTime = new Time;
    bool finished;
    double pricepaid;

    is >> begin.first >> begin.second >> end.first >> end.second >> *beginTime >> *endTime >> finished >> pricepaid;

    trip = Trip(begin, end, beginTime, endTime, finished, pricepaid);

    return is;
}
