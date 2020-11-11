#ifndef AEDA_T8G6_TIME_H
#define AEDA_T8G6_TIME_H


class Time {
private:
    int hour, minute, second;
public:
    Time(int h, int m, int s): hour(h), minute(m), second(s){};

    int getHour() const;

    int getMinute() const;

    int getSecond() const;

    void setTime(int h, int m, int s);

    Time& operator=(const Time &rhs);
};


#endif //AEDA_T8G6_TIME_H
