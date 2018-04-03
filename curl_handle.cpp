
#include <sstream>
#include <curl_handle.hpp>
#include <stdexcept>

curl_handle::curl_handle():
    curl_(curl_easy_init(), curl_easy_cleanup)
{
    if ( !curl_ )
    {
        throw std::runtime_error("Error constructing curl_handle");
    }
}
