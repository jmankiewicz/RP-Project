project(RP-project)
cmake_minimum_required(VERSION 2.8)
aux_source_directory(. SRC_LIST)

add_executable(1-Grundlagen tutorials/1-Grundlagen.cpp)

add_executable(tutorial_taschenrechner tutorials/kleiner_taschenrechner.cpp)

add_executable(tutorial_pointer_und_variablen tutorials/pointer_und_variablen.cpp)

