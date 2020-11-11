#include "time.h"

int Time::getHour() const {
    return hour;
}

int Time::getMinute() const {
    return minute;
}

int Time::getSecond() const {
    return second;
}

void Time::setTime(int h, int m, int s) {
    hour = h; minute = m; second = s;
}

Time & Time::operator=(const Time &rhs) {
    setTime(rhs.getHour(), rhs.getMinute(), rhs.getSecond()); return *this;
}
