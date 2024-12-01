#include "Report.h"
#include <fstream>
#include <sstream>
#include <string>

void Report::reportExecutionTime(int year, int day, int part, std::chrono::milliseconds duration)
{
    std::ifstream readmeFile("README.md");
    std::stringstream buffer;
    buffer << readmeFile.rdbuf();
    std::string content = buffer.str();
    readmeFile.close();

    std::string searchString = "| " + std::to_string(day) + "   |";
    size_t pos = content.find(searchString);
    if (pos != std::string::npos)
    {
        size_t lineEnd = content.find("\n", pos);
        std::string line = content.substr(pos, lineEnd - pos);

        std::string timeString = std::to_string(duration.count()) + " ms";
        if (part == 1)
        {
            line.replace(line.find("|", 5) + 1, 23, " " + timeString + " ");
        }
        else if (part == 2)
        {
            line.replace(line.find_last_of("|") + 1, 23, " " + timeString + " ");
        }

        if (line.back() != '|') {
            line += " |";
        }

        content.replace(pos, lineEnd - pos, line);
    }

    std::ofstream outFile("README.md");
    outFile << content;
    outFile.close();
}