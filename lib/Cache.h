#include <string>
#include <chrono>

class Cache
{
public:
    Cache(const std::string &cache_dir = "./.cache");

    bool hit(const std::string &key);

    void store(const std::string &key, const std::string &data);

    std::string get(const std::string &key);

private:
    std::string cache_dir;
};
