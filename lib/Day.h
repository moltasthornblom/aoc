#ifndef DAY_H
#define DAY_H

#include <string>

class Day
{
public:
    virtual std::string solvePart1(std::string input) = 0;
    virtual std::string solvePart2(std::string input) = 0;

    bool run();
protected: 
    int year;
    int day;
};

#endif // DAY_H