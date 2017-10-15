
#include <sstream>
#include <curl_handle.hpp>

curl_handle::curl_handle():
    curl_(NULL, curl_easy_cleanup)
{
    CURL* temp_handle = curl_easy_init();
    if ( !temp_handle )
    {
        throw std::runtime_error("Error constructing curl_handle");
    }
    curl_ = internal_handle(temp_handle, curl_easy_cleanup);
}
