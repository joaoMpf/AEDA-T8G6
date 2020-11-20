#ifndef AEDA_T8G6_TIME_H
#define AEDA_T8G6_TIME_H
#include <ctime>
#include <string>
#include <ostream>

using namespace std;
class Time {
private:
    int day,month,year,hour, minute, second;
    time_t theTime = time(NULL);
    struct tm *aTime = localtime(&theTime);
public:
    Time(){
        day=aTime->tm_mday;
        month=aTime->tm_mon;
        year=aTime->tm_year;
        hour=aTime->tm_hour;
        minute=aTime->tm_min;
        second=aTime->tm_sec;
    }
    Time(int h, int m, int s): hour(h), minute(m), second(s){};

    Time(int day, int month, int year, int hour, int minute, int second);

    string getDate() const;

    int getHour() const;

    int getMinute() const;

    int getSecond() const;

    void setTime(int h, int m, int s);

    void setDay(int day);

    void setMonth(int month);

    void setYear(int year);

    void setHour(int hour);

    void setMinute(int minute);

    void setSecond(int second);

    Time& operator=(const Time &rhs);

    friend ostream &operator<<(ostream &os, const Time &time1);

    friend istream &operator>>(istream &is, Time &time);
};


#endif //AEDA_T8G6_TIME_H
