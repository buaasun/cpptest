cmake_minimum_required(VERSION 3.6)
project(cpptest)

set(CMAKE_CXX_STANDARD 11)
link_libraries(pthread)

add_library(libp3_1 SHARED  p3_1.cpp)
add_library(libp3_2 SHARED  p3_2.cpp)

add_executable(p3_link12 p3.cpp)
target_link_libraries(p3_link12 libp3_1 libp3_2)

add_executable(p3_link21 p3.cpp)
target_link_libraries(p3_link21 libp3_2 libp3_1)

add_executable(p3_12 p3.cpp p3_1.cpp p3_2.cpp)
add_executable(p3_21 p3.cpp p3_2.cpp p3_1.cpp)

#target_link_libraries(p3 p3_1 p3_2)
