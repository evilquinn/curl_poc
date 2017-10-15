

#include <iostream>
#include <curl_initialiser.hpp>
#include <curl/curl.h>
#include <boost/typeof/typeof.hpp>

int main(int argc, char* agv[])
{
    CURL *curl;
    CURLcode res;
    BOOST_AUTO ( curl_initialised, curl_initialiser::get() );

    BOOST_AUTO ( curl_info, curl_version_info(CURLVERSION_NOW) );
    std::cout << "Age:             " << curl_info->age << "\n"
              << "Version:         " << curl_info->version << "\n"
              << "Version Num:     " << curl_info->version_num << "\n"
              << "Host:            " << curl_info->host << "\n"
              << "SSL Version:     " << curl_info->ssl_version << "\n"
              << "SSL Version Num: " << curl_info->ssl_version_num << "\n"
              << "libz Version:    " << curl_info->libz_version << std::endl;

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "https://gist.githubusercontent.com/joshuashaffer/24e9d3de5f41aaca1fbb605f762fb115/raw/2ddfa20bdbaac972e6090e92fd9ee1899df71b9c/clockRadian.py");
        /* Perform the request, res will get the return code */
        res = curl_easy_perform(curl);
        /* Check for errors */
        if(res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
        /* always cleanup */
        curl_easy_cleanup(curl);
    }
    return 0;
}
