#include "day4.h"
#include <vector>
#include <sstream>
#include <iostream>
#include <string>
#include <regex>

std::vector<std::vector<std::string>> parseInput(const std::string& input) {
    std::vector<std::vector<std::string>> array2D;
    std::istringstream input_stream(input);
    std::string line;
    while (std::getline(input_stream, line)) {
        std::vector<std::string> row;
        for (char c : line) {
            row.emplace_back(1, c);
        }
        array2D.push_back(std::move(row));
    }
    return array2D;
}

bool isValidPosition(int x, int y, int rows, int cols) {
    return x >= 0 && x < rows && y >= 0 && y < cols;
}

bool checkDirection(const std::vector<std::vector<std::string>>& array2D, int i, int j, const std::pair<int, int>& dir, const std::string& target) {
    int rows = array2D.size();
    int cols = array2D[0].size();
    for (int k = 0; k < target.size(); k++) {
        int newX = i + k * dir.first;
        int newY = j + k * dir.second;
        if (!isValidPosition(newX, newY, rows, cols) || array2D[newX][newY][0] != target[k]) {
            return false;
        }
    }
    return true;
}

int countTargetOccurrences(const std::vector<std::vector<std::string>>& array2D, const std::string& target) {
    static const std::vector<std::pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
    int count = 0;
    int rows = array2D.size();
    int cols = array2D[0].size();

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (array2D[i][j][0] != target[0]) {
                continue;
            }
            for (const auto& dir : directions) {
                if (checkDirection(array2D, i, j, dir, target)) {
                    count++;
                }
            }
        }
    }
    return count;
}

std::string Day4::solvePart1(std::string input) {
    auto array2D = parseInput(input);
    int count = countTargetOccurrences(array2D, "XMAS");
    return std::to_string(count);
}

bool checkDiagonal(const std::vector<std::vector<std::string>>& array2D, int i, int j, int rows, int cols) {
    if (!isValidPosition(i - 1, j - 1, rows, cols) || !isValidPosition(i + 1, j + 1, rows, cols)) {
        return false;
    }
    bool topLeftBottomRight = (array2D[i-1][j-1] == "M" && array2D[i+1][j+1] == "S") || 
                              (array2D[i-1][j-1] == "S" && array2D[i+1][j+1] == "M");
    
    if (!isValidPosition(i - 1, j + 1, rows, cols) || !isValidPosition(i + 1, j - 1, rows, cols)) {
        return false;
    }
    bool topRightBottomLeft = (array2D[i-1][j+1] == "M" && array2D[i+1][j-1] == "S") || 
                              (array2D[i-1][j+1] == "S" && array2D[i+1][j-1] == "M");
    
    return topLeftBottomRight && topRightBottomLeft;
}

int countDiagonalOccurrences(const std::vector<std::vector<std::string>>& array2D) {
    int count = 0;
    int rows = array2D.size();
    int cols = array2D[0].size();

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (array2D[i][j] == "A" && checkDiagonal(array2D, i, j, rows, cols)) {
                count++;
            }
        }
    }
    return count;
}

std::string Day4::solvePart2(std::string input) {
    auto array2D = parseInput(input);
    int count = countDiagonalOccurrences(array2D);
    return std::to_string(count);
}
