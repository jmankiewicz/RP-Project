project(RP-project)
cmake_minimum_required(VERSION 2.8.12)

set(PROJECT_NAME RP-project)
set(PROJECT_BRIEF_DESCRIPTION "A little project to make pen&paper more fun.")
#set(DOCUMENTATION_DIR ${CMAKE_CURRENT_SOURCE_DIR}/doc)
#set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules)
#set(CMAKE_TOOLCHAIN_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/toolchains)
#set(PROJECT_LOGO)

add_compile_options(-std=c++11) #Enable C++11 support

aux_source_directory(. SRC_LIST)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)
# Instruct CMake to automatically process .ui files of Qt with uic.
set(CMAKE_AUTOUIC ON)

### Find needed Packages

find_package(Boost COMPONENTS system filesystem program_options regex date_time timer random log chrono thread REQUIRED)
find_package(Doxygen)
find_package(Qt5 COMPONENTS Widgets REQUIRED)

### Setup directories for including files and linking libraries
include_directories(${INCLUDE_DIRS} ${Boost_INCLUDE_DIRS} ${Qt5_INCLUDES})
link_directories(${LINK_DIRS} ${Boost_LIBRARY_DIRS})
#add_definitions(${QT_DEFINITIONS})

### Taget for generating Doxygen documentation (if Doygen is found)

if(DOXYGEN_FOUND)
 configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)
 add_custom_target(doc
 ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
 #COMMAND ${CMAKE_MAKE_PROGRAM} -C ${CMAKE_CURRENT_SOURCE_DIR}/doc/latex/proc/
 #COMMAND cmake -E copy ${CMAKE_CURRENT_SOURCE_DIR}/doc/latex/proc/refman.pdf ${CMAKE_CURRENT_SOURCE_DIR}/doc/latex/manual.pdf
 WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
 COMMENT "Generating API documentation with Doxygen" VERBATIM
 )
endif(DOXYGEN_FOUND)

### Targets to build software

#Tutorial thingies

add_executable(1-Grundlagen tutorials/1-Grundlagen.cpp)

add_executable(tutorial_taschenrechner tutorials/kleiner_taschenrechner.cpp)

add_executable(tutorial_pointer_und_variablen tutorials/pointer_und_variablen.cpp)

#Our own libraries

add_library(exception src/exception.cpp)

add_library(log src/log.cpp)
target_link_libraries(log ${Boost_LOG_LIBRARY_DEBUG} ${Boost_THREAD_LIBRARY_DEBUG} boost_log_setup)

#Main executable

add_executable(rpProject src/main.cpp src/mainwindow.cpp)
add_dependencies(rpProject log)
target_link_libraries(rpProject log exception ${Boost_PROGRAM_OPTIONS_LIBRARY_DEBUG} ${Boost_SYSTEM_LIBRARY_DEBUG} pthread)
qt5_use_modules(rpProject Widgets)
