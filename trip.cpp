//
// Created by Pedro Figueiredo on 10/11/2020.
//

#include "trip.h"

void Trip::setEnd(Toll *toll) {
    end = toll;
}

void Trip::setEndTime(Time *time) {
    endTime = time;
}

Toll *Trip::getBegin() const {
    return begin;
}
