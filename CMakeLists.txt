cmake_minimum_required(VERSION 3.26)

include("C:/Users/Moltas/vcpkg/scripts/buildsystems/vcpkg.cmake")
project(Aoc VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add include directories


include_directories(
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/lib
)
file(GLOB_RECURSE SRC_FILES "${CMAKE_SOURCE_DIR}/src/*")
file(GLOB_RECURSE LIB_FILES "${CMAKE_SOURCE_DIR}/lib/*")
add_executable(Aoc main.cpp ${SRC_FILES} ${LIB_FILES})

find_package(CURL REQUIRED)
target_link_libraries(Aoc PRIVATE CURL::libcurl)
find_package(fmt CONFIG REQUIRED)
target_link_libraries(Aoc PRIVATE fmt::fmt)
