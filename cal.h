
#ifndef CAL_H
#define CAL_H

#include <iostream>
#include <iomanip>

class Calendar {
private:
    int month;


public:
    // Const
    Calendar(int _month);

    // Print the calendar
    void print();
};

#endif
