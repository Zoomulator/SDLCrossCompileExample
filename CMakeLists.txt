cmake_minimum_required(VERSION 3.6)
project(CROSSCOMPILEEXAMPLE C CXX)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -static-libgcc -static-libstdc++")

add_executable(main main.cpp)

find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS})
target_link_libraries(main ${SDL2_LIBRARIES})
