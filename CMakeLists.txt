cmake_minimum_required(VERSION 3.21)
project(great_project)

set(CMAKE_CXX_STANDARD 17)

add_executable(great_project main.cpp sqlite3.c sqlite3.h dbFuncs.h alg_funcs.h alg_funcs.cpp
        mySelect.cpp myNoSelect.cpp alg.cpp alg.h mapSch.cpp mapSch.h)
