project(kitchen-scheduler)
cmake_minimum_required(VERSION 2.6)

find_package(Boost REQUIRED)

add_definitions(-Wall -Wextra -pedantic -std=c++0x)

set(DOC_FILES README docs/PLAN)

add_executable(kitchen_scheduler main.cpp DutyPerson.cpp InputParser.cpp)
