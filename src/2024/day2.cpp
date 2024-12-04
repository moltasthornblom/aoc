#include "day2.h"
#include <vector>
#include <sstream>
#include <iostream>
#include <string>
std::vector<std::vector<int>> parse_input(std::string input)
{
    std::vector<std::vector<int>> matrix;
    std::stringstream ss(input);
    std::string line;
    
    while (std::getline(ss, line)) {
        std::stringstream lineStream(line);
        std::vector<int> row;
        int value;
        
        while (lineStream >> value) {
            row.push_back(value);
        }
        
        matrix.push_back(row);
    }
    return matrix;
}

bool is_report_safe(std::vector<int> report)
{
    if (report.size() < 2) return true;

    bool isIncrease = report[0] < report[1];
    bool hasViolation = false;

    for (size_t i = 0; i < report.size() - 1; ++i) {
        int diff = report[i + 1] - report[i];

        if (diff == 0 || abs(diff) > 3) {
            hasViolation = true;
            break;
        }

        if ((isIncrease && diff < 0) || (!isIncrease && diff > 0)) {
            hasViolation = true;
            break;
        }
    }
    return !hasViolation;
}


std::string Day2::solvePart1(std::string input)
{
    std::vector<std::vector<int>> matrix = parse_input(input);
    int count = 0;
    for (auto row : matrix) {
        if(is_report_safe(row))
        {
            count++;
        }
    }
    return std::to_string(count);
}

std::string Day2::solvePart2(std::string input)
{
    std::vector<std::vector<int>> matrix = parse_input(input);
    int count = 0;

    for (auto row : matrix) {
        bool safe = false;

        for (size_t i = 0; i < row.size(); ++i) {
            std::vector<int> modifiedRow = row;
            modifiedRow.erase(modifiedRow.begin() + i);

            if (is_report_safe(modifiedRow)) {
                safe = true;
                break;
            }
        }

        if (safe) {
            count++;
        }
    }
    std::cout << count << std::endl;
    return std::to_string(count);
}
