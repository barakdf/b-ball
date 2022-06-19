cmake_minimum_required(VERSION 3.16)
project(b_ball)

set(CMAKE_CXX_STANDARD 17)

add_executable(b_ball Sources/Team.cpp Sources/Team.hpp Sources/Game.cpp Sources/Game.hpp Sources/League.cpp Sources/Schedule.cpp Sources/Schedule.hpp Sources/League.hpp)
