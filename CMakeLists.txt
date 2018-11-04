cmake_minimum_required(VERSION 3.1)

set(CMAKE_C_FLA)

include_directories(include)
include_directories(deps/inut/include)

add_subdirectory(deps/inut/src)
add_subdirectory(src)
add_subdirectory(test)
