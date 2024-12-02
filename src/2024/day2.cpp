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
    // Report is safe if all numbers are increasing or decreasing.
    // Each adjacent pair can increase or decrease by 1-3, cannot be the same
    // If removing any number makes the report safe, it is safe. So it can tolerate 1 bad number
    if (report.size() < 2) return true; // A report with less than 2 numbers is trivially safe

    bool isIncrease = report[0] < report[1];
    
    for (size_t i = 0; i < report.size() - 1; ++i) {
        int diff = report[i + 1] - report[i];
        
        if (diff == 0 || abs(diff) > 3) {
            return false;
        }
        
        if ((isIncrease && diff < 0) || (!isIncrease && diff > 0)) {
            return false;
        }
    }
    return true;
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
