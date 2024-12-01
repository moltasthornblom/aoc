#include "Cache.h"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <functional>
Cache::Cache(const std::string &cache_dir) : cache_dir(cache_dir)
{
    std::filesystem::create_directory(cache_dir);
}

bool Cache::hit(const std::string &key)
{
    std::hash<std::string> hasher;
    std::string hashed_key = std::to_string(hasher(key));
    return std::filesystem::exists(cache_dir + "/" + hashed_key);
}

void Cache::store(const std::string &key, const std::string &data)
{
    std::hash<std::string> hasher;
    std::string hashed_key = std::to_string(hasher(key));
    std::ofstream file(cache_dir + "/" + hashed_key, std::ios::binary | std::ios::app);
    if (file.is_open())
    {
        file.write(data.c_str(), data.size());
    }
}

std::string Cache::get(const std::string &key)
{
    std::hash<std::string> hasher;
    std::string hashed_key = std::to_string(hasher(key));
    std::ifstream file(cache_dir + "/" + hashed_key);
    return std::string(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>());
}

