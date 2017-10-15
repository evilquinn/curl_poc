
#include <curl_initialiser.hpp>
#include <curl/curl.h>

boost::shared_ptr<curl_initialiser> curl_initialiser::get()
{
    static boost::shared_ptr<curl_initialiser> handle(
        // uses new because constructor is privte
        new curl_initialiser());
    return handle;
}

curl_initialiser::curl_initialiser()
{
    curl_global_init(CURL_GLOBAL_DEFAULT);
}

curl_initialiser::~curl_initialiser()
{
    curl_global_cleanup();
}
