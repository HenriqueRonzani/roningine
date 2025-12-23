cmake_minimum_required(VERSION 4.1)
project(roningine)

set(CMAKE_CXX_STANDARD 20)

find_package(SDL3 REQUIRED CONFIG REQUIRED COMPONENTS SDL3-shared)

add_executable(roningine game/main.cpp
        engine/input/Key.h
        engine/event/Event.h
        platform/sdl/Adapter.cpp
        platform/sdl/PlatformSDL.h
        engine/event/EventQueue.cpp
        engine/event/EventQueue.h
)

target_link_libraries(roningine PRIVATE SDL3::SDL3)
