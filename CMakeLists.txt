cmake_minimum_required(VERSION 3.20.0)
project(foo VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(${PROJECT_NAME} src/main.cpp src/application.cpp src/manager/input_manager.cpp src/manager/texture_manager.cpp src/object/vector2d.cpp src/object/character.cpp src/object/player.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC include)

find_library(LIB_SDL NAMES SDL2 PATHS lib REQUIRED)
find_library(LIB_SDL_MAIN NAMES SDL2_main PATHS lib REQUIRED)
find_library(LIB_SDL_IMAGE NAMES SDL2_image PATHS lib REQUIRED)

target_link_libraries(${PROJECT_NAME} ${LIB_SDL} ${LIB_SDL_MAIN} ${LIB_SDL_IMAGE})
