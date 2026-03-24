cmake_minimum_required(VERSION 3.10)
project(Tetris)
set(CMAKE_CXX_STANDARD 17)
add_executable(Tetris src/main.cpp src/board.cpp src/piece.cpp src/game.cpp)
