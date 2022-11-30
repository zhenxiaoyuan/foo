cmake_minimum_required(VERSION 3.20.0)
project(foo VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(${PROJECT_NAME} src/main.cpp src/app.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC include)

find_library(LIB_SDL NAMES SDL3 PATHS lib REQUIRED)
find_library(LIB_SDL_MAIN NAMES SDL3_main PATHS lib REQUIRED)
find_library(LIB_SDL_IMAGE NAMES SDL2_image PATHS lib REQUIRED)

target_link_libraries(${PROJECT_NAME} ${LIB_SDL} ${LIB_SDL_MAIN} ${LIB_SDL_IMAGE})
