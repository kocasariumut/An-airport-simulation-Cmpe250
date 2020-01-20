cmake_minimum_required(VERSION 2.6)
project(project2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    main.cpp
    Passenger.cpp
    Passenger.h Event.h Event.cpp mycompare.h mycompare1.h mycompare.cpp mycompare1.cpp executive.h executive.cpp mycompare2.cpp mycompare2.h)

add_executable(project2 ${SOURCE_FILES})