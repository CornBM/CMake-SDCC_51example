cmake_minimum_required(VERSION 3.12)

set(CMAKE_TOOLCHAIN_FILE cmake/TC-sdcc-msc51.cmake)

project(test C ASM)

include_directories(
    ${PROJECT_SOURCE_DIR}/include
)

include_directories(
    ${PROJECT_SOURCE_DIR}/tool
)

add_subdirectory(src)
