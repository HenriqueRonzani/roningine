cmake_minimum_required(VERSION 4.1)
project(roningine)

set(CMAKE_CXX_STANDARD 20)

find_package(SDL3 REQUIRED CONFIG REQUIRED COMPONENTS SDL3-shared)

add_executable(roningine
        src/input/Key.h
        src/event/Event.h
        src/platform/sdl/PlatformSDL.cpp
        src/platform/sdl/PlatformSDL.h
        src/event/EventQueue.cpp
        src/event/EventQueue.h
        src/engine/Engine.cpp
        src/engine/Engine.h
        src/main.cpp
        src/input/Input.cpp
        src/input/Input.h
)

target_link_libraries(roningine PRIVATE SDL3::SDL3)
