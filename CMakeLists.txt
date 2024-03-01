cmake_minimum_required(VERSION 3.16)
project(XOREncrypt)

set(CMAKE_CXX_STANDARD 20)

add_library(XOREncrypt STATIC source/XOREncrypt.cpp)

target_include_directories(XOREncrypt PUBLIC include)
target_link_libraries(XOREncrypt Base Vector)
