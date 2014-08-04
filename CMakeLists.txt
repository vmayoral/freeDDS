cmake_minimum_required (VERSION 2.8)

project (freeDDS)

# It tells the compiler to look for the headers at the include directory
include_directories(include)
# Execute CMakeLists within src
add_subdirectory(src)