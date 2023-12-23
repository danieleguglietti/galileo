cmake_minimum_required(VERSION 3.24)
project(Galileo)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(include/raylib)

set(sources ${sources} src/main.cpp src/vector.h)
add_executable(${PROJECT_NAME} ${sources})
target_link_libraries(${PROJECT_NAME} raylib)

if (APPLE)
    target_link_libraries(${PROJECT_NAME} "-framework IOKit")
    target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
endif()