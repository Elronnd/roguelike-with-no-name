cmake_minimum_required (VERSION 2.6)
project (roguelike)
SET( CMAKE_CXX_FLAGS  "-I../game/include -std=c++11" )
add_executable (main ../game/src/main.cc)
