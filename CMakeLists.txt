
project ( curl_poc C CXX )

include_directories ( ${CMAKE_SOURCE_DIR} )

add_executable ( curl_poc main.cpp
                          curl_initialiser.cpp )

target_link_libraries ( curl_poc curl )
