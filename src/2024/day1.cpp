#include "day1.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <chrono>
using namespace std;

pair<vector<int>, vector<int>> parse_input(const string& input) {
    stringstream ss(input);
    vector<int> first_column;
    vector<int> second_column;
    int first, second;

    first_column.reserve(1000);
    second_column.reserve(1000);

    while (ss >> first >> second) {
        first_column.push_back(first);
        second_column.push_back(second);
    }
    return make_pair(first_column, second_column);
}
int total_distance(vector<int>& first_column, vector<int>& second_column) {
    int total = 0;
    for (size_t i = 0; i < first_column.size(); ++i) {
        total += abs(first_column[i] - second_column[i]);
    }
    return total;
}

int similarity_score(vector<int>& first_column, vector<int>& second_column) {
    int score = 0;
    unordered_map<int, int> count_map;

    for (int num : second_column) {
        count_map[num]++;
    }

    for (int num : first_column) {
        if (count_map.find(num) != count_map.end()) {
            score += num * count_map[num];
        }
    }

    return score;
}

std::string Day1::solvePart1(std::string input)
{
    auto [first_column, second_column] = parse_input(input);
    
    sort(first_column.begin(), first_column.end());
    sort(second_column.begin(), second_column.end());

    return std::to_string(total_distance(first_column, second_column));
}

std::string Day1::solvePart2(std::string input)
{
    auto [first_column, second_column] = parse_input(input);
    
    sort(first_column.begin(), first_column.end());
    sort(second_column.begin(), second_column.end());

    return std::to_string(similarity_score(first_column, second_column));
}