cmake_minimum_required(VERSION 3.13)  # CMake version check
project(CPP)               # Create project "simple_example"
set(CMAKE_CXX_STANDARD 98)

# Add main.cpp file of project root directory as source file
set(SOURCE_FILES ChessPGM.cpp Board.h Board.cpp Pieces.h Pieces.cpp GamePlay.cpp GamePlay.h)

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(Run ${SOURCE_FILES})