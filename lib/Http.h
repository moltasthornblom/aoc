#include <string>

class Http
{
public:
    static std::string get(const std::string &url, const std::string &cookie);
    static std::string post(const std::string &url, const std::string &data, const std::string &cookie);

private:
    static size_t writeCallback(void *contents, size_t size, size_t nmemb, void *userp);
    static std::string getSessionCookie();
};
