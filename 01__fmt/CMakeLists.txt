cmake_minimum_required(VERSION 3.5)

project(fmt_test LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(fmt_test main.cpp)

find_package(fmt)
target_link_libraries(fmt_test fmt::fmt)

find_package(Qt5 REQUIRED COMPONENTS Core)
target_link_libraries(fmt_test Qt::Core)
#also works
#find_library(FMT_LIB fmt)
#target_link_libraries(fmt_test ${FMT_LIB})
