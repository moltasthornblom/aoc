#include <chrono>
#include <string>

class Report
{
public:
    static void reportExecutionTime(int year, int day, int part, std::chrono::milliseconds duration);
};