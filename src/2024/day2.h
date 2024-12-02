#include "Day.h"
#include <vector>
#include <string>
class Day2 : public Day
{
public:
    Day2() {
        year = 2024;
        day = 2;
    }
    std::string solvePart1(std::string input) override;
    std::string solvePart2(std::string input) override;
};
