#include "Day.h"
#include <vector>
#include <string>
class Day4 : public Day
{
public:
    Day4() {
        year = 2024;
        day = 4;
    }
    std::string solvePart1(std::string input) override;
    std::string solvePart2(std::string input) override;
};
