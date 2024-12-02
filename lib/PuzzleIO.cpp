#include "PuzzleIO.h"
#include <fmt/format.h>
#include <iostream>
#include "Http.h"
#include <unordered_map>
#include <functional>

Cache PuzzleIO::cache;
const std::string PuzzleIO::input_url = "https://adventofcode.com/{}/day/{}/input";
const std::string PuzzleIO::submit_url = "https://adventofcode.com/{}/day/{}/answer";

std::string PuzzleIO::getInputData(const int year, const int day)
{
    std::string url = fmt::format(input_url, year, day);
    if (cache.hit(url))
    {
        return cache.get(url);
    }
    std::string cookie = getSessionCookie();
    std::string data = Http::get(url, cookie);
    cache.store(url, data);
    return data;
}

bool PuzzleIO::submitAnswer(const int year, const int day, const int level, const std::string &answer)
{
    std::string url = fmt::format(submit_url, year, day);
    std::string cookie = getSessionCookie();
    std::string data = Http::post(url, fmt::format("level={}&answer={}", level, answer), cookie);
    std::unordered_map<std::string, std::function<bool()>> responseActions = {
        {"That's the right answer!", []() -> bool {std::cout << "That's the right answer!" << std::endl;  return true; }},
        {"You gave an answer too recently", []() -> bool { std::cout << "You gave an answer too recently" << std::endl; return false; }},
        {"That's not the right answer", []() -> bool { std::cout << "That's not the right answer" << std::endl; return false; }},
        {"Did you already complete it?", []() -> bool { std::cout << "Did you already complete it?" << std::endl; return true; }}
    };

    for (const auto& [key, action] : responseActions) {
        if (data.find(key) != std::string::npos) {
            return action();
        }
    }

    throw std::runtime_error(data);
}

std::string PuzzleIO::getSessionCookie()
{
    const char* sessionEnv = std::getenv("AOC_SESSION");
    if (!sessionEnv) {
        std::cerr << "Environment variable AOC_SESSION not set." << std::endl;
        return "";
    }
    return "session=" + std::string(sessionEnv);
}

