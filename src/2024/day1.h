#include "Day.h"
#include <vector>
class Day1 : public Day
{
public:
    Day1() {
        year = 2024;
        day = 1;
    }
    std::string solvePart1(std::string input) override;
    std::string solvePart2(std::string input) override;
};
