cmake_minimum_required (VERSION 2.6)
project (AddressBook)

# Set the output folder where your program will be created
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)

# The version number.
set (AddBook_VERSION_MAJOR 0)
set (AddBook_VERSION_MINOR 1)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
  "${PROJECT_SOURCE_DIR}/AddBookConfig.h.in"
  "${PROJECT_BINARY_DIR}/AddBookConfig.h"
  )

# The following folder will be included
include_directories("${PROJECT_SOURCE_DIR}")

add_executable(AddBook addbook_mainprog.cpp)
target_compile_features(AddBook PRIVATE cxx_range_for)