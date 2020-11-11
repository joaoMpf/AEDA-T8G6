#ifndef AEDA_T8G6_TIME_H
#define AEDA_T8G6_TIME_H
#include <ctime>
class Time {
private:
    int hour, minute, second;
    time_t theTime = time(NULL);
    struct tm *aTime = localtime(&theTime);
public:
    Time(){
        hour=aTime->tm_hour;
        minute=aTime->tm_min;
        second=aTime->tm_sec;
    }
    Time(int h, int m, int s): hour(h), minute(m), second(s){};

    int getHour() const;

    int getMinute() const;

    int getSecond() const;

    void setTime(int h, int m, int s);

    Time& operator=(const Time &rhs);
};


#endif //AEDA_T8G6_TIME_H
