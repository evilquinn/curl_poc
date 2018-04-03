
#ifndef CURL_HANDLE_HPP_
#define CURL_HANDLE_HPP_

#include <curl/curl.h>
#include <boost/move/unique_ptr.hpp>
#include <boost/typeof/typeof.hpp>

class curl_handle
{
public:
    curl_handle();
    CURL* get()
    {
        return curl_.get();
    }
    operator CURL* ()
    {
        return curl_.get();
    }
private:
    typedef boost::movelib::unique_ptr<CURL,
                            BOOST_TYPEOF(&curl_easy_cleanup)> internal_handle;
    internal_handle curl_;
};

#endif // CURL_HANDLE_HPP_
