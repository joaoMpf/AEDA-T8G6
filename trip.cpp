//
// Created by Pedro Figueiredo on 10/11/2020.
//

#include "trip.h"

void Trip::setEnd(Toll *toll) {
    end = toll;
    finished=true;
}

void Trip::setEndTime(Time *time) {
    endTime = time;
}

Toll *Trip::getBegin() const {
    return begin;
}

Time *Trip::getBeginTime() const{
    return beginTime;
}

Toll *Trip::getEnd() const {
    return end;
}

bool Trip::isFinished() {
    return finished;
}

Time *Trip::getEndTime() const {
    return endTime;
}

void Trip::setPrice(double price) {
    pricepaid=price;
}

double Trip::getPrice() const {
    return pricepaid;
}
