#include <iostream>

using namespace std;

class Clock
{
protected:
    int hour = 0, minute = 0, second = 0;

    Clock(int hour, int minute, int second) : hour(hour), minute(minute), second(second)
    {

    }
public:
    void setHour(int hour) { this->hour = hour; }
    int getHour() { return hour; }
    void setMinute(int minute) { this->minute = minute; }
    int getMinute() { return minute; }
    void setSecond(int second) { this->second = second; }
    int getSecond() { return second; }

    virtual void printTime() = 0;
};

class DigitClock : public Clock
{
private:
    long millis = 0;

public:
    void setMillis(int millis) { this->millis = millis; }
    int getMillis() { return millis; }

    void printTime()
    {
        cout << "Digit clock" << endl;
        cout << "Human readable time - " << getHour() << ':' << getMinute() << ':' << getSecond() << '.' << getMillis() << endl;
    }

    DigitClock(int hour, int minute, int second, long millis) : Clock(hour, minute, second), millis(millis)
    {

    }
};

class MechanicClock : public Clock
{
public:
    void printTime()
    {
        cout << "Mechanic clock" << endl;
        cout << "Human readable time - " << getHour() << ':' << getMinute() << ':' << getSecond() << endl;
    }

    MechanicClock(int hour, int minute, int second) : Clock(hour, minute, second)
    {

    }
};

int main()
{
    cout << "1. Digit clock" << endl;
    cout << "2. Mechanic clock" << endl;
    int choose;
    cin >> choose;

    cout << "Hour: ";
    int hour;
    cin >> hour;

    cout << "Minute: ";
    int minute;
    cin >> minute;

    cout << "Second: ";
    int second;
    cin >> second;

    if (choose == 1) {
        cout << "Millis: ";
        long millis;
        cin >> millis;

        DigitClock clock{ hour, minute, second, millis };
        clock.printTime();
    }
    else if (choose == 2) {
        MechanicClock clock{ hour, minute, second };
        clock.printTime();
    }

    return 0;
}
