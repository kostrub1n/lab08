cmake_minimum_required(VERSION 3.10)

project(logger)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(message_writer logger.cpp)
