#include "Day.h"
#include "PuzzleIO.h"
#include <iostream>
#include "Report.h"
bool Day::run()
{
    std::cout << "Running day " << day << " of year " << year << std::endl;
    std::string input = PuzzleIO::getInputData(year, day);
    
    auto start = std::chrono::high_resolution_clock::now();
    std::string part1 = solvePart1(input);
    auto end = std::chrono::high_resolution_clock::now();
    auto part1ExecutionTime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    Report::reportExecutionTime(year, day, 1, part1ExecutionTime);
    
    start = std::chrono::high_resolution_clock::now();
    std::string part2 = solvePart2(input);
    end = std::chrono::high_resolution_clock::now();
    auto part2ExecutionTime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    Report::reportExecutionTime(year, day, 2, part2ExecutionTime);
    
    std::cout << "Part 1: " << part1 << " Took " << part1ExecutionTime.count() << " ms" << std::endl;
    std::cout << "Part 2: " << part2 << " Took " << part2ExecutionTime.count() << " ms" << std::endl;

    if (!part1.empty())
    {
        PuzzleIO::submitAnswer(year, day, 1, part1);
    }
    if (!part2.empty())
    {
        PuzzleIO::submitAnswer(year, day, 2, part2);
    }

    return false;
}
