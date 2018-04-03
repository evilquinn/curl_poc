cmake_minimum_required(VERSION 2.8)

project ( curl_poc C CXX )

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11")

option(BUILD_BOOST "Downloads required boost headers" OFF)
add_subdirectory(third_party)

include_directories ( ${CMAKE_SOURCE_DIR} )

add_executable ( curl_poc main.cpp
                          curl_initialiser.cpp
                          curl_handle.cpp )

target_link_libraries ( curl_poc curl )

if( BUILD_BOOST )
    target_link_libraries ( curl_poc boost )
endif()
