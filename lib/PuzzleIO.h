#ifndef PUZZLEIO_H
#define PUZZLEIO_H

#include "Cache.h"
#include <string>
#include <chrono>

class PuzzleIO
{
public:
    static std::string getInputData(const int year, const int day);
    static bool submitAnswer(const int year, const int day, const int level, const std::string &answer);

private:
    static std::string getSessionCookie();
    static Cache cache;
    static const std::string input_url;
    static const std::string submit_url;
};

#endif // PUZZLEIO_H
