#ifndef AEDA_T8G6_TIME_H
#define AEDA_T8G6_TIME_H
#include <ctime>
#include <string>
#include <ostream>

using namespace std;

///Contains info such as day, month, year, hour, minute, second
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

    ///Returns date in format DD-MM-YY
    string getDate() const;

    ///Returns Hour
    ///
    /// \return Hour
    int getHour() const;

    ///Returns Minute
    ///
    /// \return Minute
    int getMinute() const;

    ///Returns Second
    ///
    /// \return Second
    int getSecond() const;

    ///Sets time to h:m:s
    ///
    /// \param h hour
    /// \param m minute
    /// \param s second
    void setTime(int h, int m, int s);

    void setDay(int day);

    void setMonth(int month);

    void setYear(int year);

    void setHour(int hour);

    void setMinute(int minute);

    void setSecond(int second);

    Time& operator=(const Time &rhs);

    ///Returns ostream with Time
    ///
    /// \param os
    /// \param time1
    /// \return ostream with Time in the format: day month year hour minute second

    friend ostream &operator<<(ostream &os, const Time &time1);

    /// Sets Time with info in istream
    ///
    /// Allows Time to be set with an istream with the following format:\n
    /// day month year hour minute second
    /// \param is
    /// \param time
    /// \return
    friend istream &operator>>(istream &is, Time &time);
};


#endif //AEDA_T8G6_TIME_H
