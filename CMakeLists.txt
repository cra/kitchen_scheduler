project(kitchen-scheduler)
cmake_minimum_required(VERSION 2.6)

set(Boost_USE_STATIC_LIBS ON)
set(DOC_FILES README docs/PLAN)
add_definitions(-Wall -Wextra -pedantic -std=c++0x)

find_package(Boost COMPONENTS filesystem system REQUIRED)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    add_executable(kitchen_scheduler main.cpp InputParser.cpp DutyManager.cpp)
    target_link_libraries(kitchen_scheduler ${Boost_LIBRARIES} ${Boost_FILESYSTEM_LIBRARY} ${Boost_SYSTEM_LIBRARY} boost_program_options)
endif()
