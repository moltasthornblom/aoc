#include "Day.h"
#include <vector>
#include <string>
class Day3 : public Day
{
public:
    Day3() {
        year = 2024;
        day = 3;
    }
    std::string solvePart1(std::string input) override;
    std::string solvePart2(std::string input) override;
};
