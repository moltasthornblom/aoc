#include "day3.h"
#include <vector>
#include <sstream>
#include <iostream>
#include <string>
#include <regex>

std::string Day3::solvePart1(std::string input)
{
    std::regex regex_pattern(R"(mul\((\d{1,3}),(\d{1,3})\))");
    std::smatch matches;
    int sum = 0;

    while (std::regex_search(input, matches, regex_pattern)) {
        sum += std::stoi(matches[1]) * std::stoi(matches[2]);
        input = matches.suffix();
    }

    return std::to_string(sum);
}

std::string Day3::solvePart2(std::string input)
{
    std::regex regex_pattern(R"((do\(\)|don't\(\)|mul\((\d{1,3}),(\d{1,3})\)))");
    std::smatch matches;
    int sum = 0;
    bool mul_enabled = true;

    while (std::regex_search(input, matches, regex_pattern)) {
        const std::string& match_str = matches[0];
        if (match_str == "do()") {
            mul_enabled = true;
        } else if (match_str == "don't()") {
            mul_enabled = false;
        } else if (mul_enabled && matches.size() > 2) {
            sum += std::stoi(matches[2]) * std::stoi(matches[3]);
        }
        input = matches.suffix();
    }
    return std::to_string(sum);
}
