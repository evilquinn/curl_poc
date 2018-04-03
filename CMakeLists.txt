cmake_minimum_required(VERSION 2.8)

project ( curl_poc C CXX )

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11")

include_directories ( ${CMAKE_SOURCE_DIR} )

add_executable ( curl_poc main.cpp
                          curl_initialiser.cpp
                          curl_handle.cpp )

target_link_libraries ( curl_poc curl )
