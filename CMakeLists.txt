cmake_minimum_required(VERSION 3.22)
project(qbrowserclient)

set(CMAKE_CXX_STANDARD 20)

add_executable(qbrowserclient main.cpp client_handler.cc client_handler.h)
