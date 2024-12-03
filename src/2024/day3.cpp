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
    std::string result;
    int sum = 0;

    while (std::regex_search(input, matches, regex_pattern)) {
        int num1 = std::stoi(matches[1].str());
        int num2 = std::stoi(matches[2].str());
        sum+=num1 * num2;
        input = matches.suffix().str();
    }

    return std::to_string(sum);
}

std::string Day3::solvePart2(std::string input)
{
    std::regex regex_pattern(R"((do\(\)|don't\(\)|mul\((\d{1,3}),(\d{1,3})\)))");
    std::smatch matches;
    std::string result;
    int sum = 0;
    bool mul_enabled = true;

    while (std::regex_search(input, matches, regex_pattern)) {
        if (matches[0].str() == "do()") {
            mul_enabled = true;
        } else if (matches[0].str() == "don't()") {
            mul_enabled = false;
        } else if (mul_enabled && matches.size() > 2 && matches[2].matched) {
            int num1 = std::stoi(matches[2].str());
            int num2 = std::stoi(matches[3].str());
            sum += num1 * num2;
        }
        input = matches.suffix().str();
    }
    return std::to_string(sum);
}
