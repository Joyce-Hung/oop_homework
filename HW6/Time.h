#ifndef TIME_H
#define TIME_H
class Time
{
public:
    Time(int =0);

    Time &setTime(int=0,int=0,int=0);
    Time &setHour(int);
    Time &setMinute(int);
    Time &setSecond(int);

    int getHour();
    int getMinute();
    int getSecond();

    void printUniversal() const;
    void printStandard() const;
private:
    int time;
};
#endif