#ifndef CURL_INITIALISER_HPP_
#define CURL_INITIALISER_HPP_

#include <boost/shared_ptr.hpp>

class curl_initialiser
{
public:
    ~curl_initialiser();
    static boost::shared_ptr<curl_initialiser> get();

private:
    curl_initialiser();
};


#endif // NCURSES_INITIALISER_HPP_
