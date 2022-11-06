cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

set(PROJECT_NAME OpenGL)
project(${PROJECT_NAME})

set(CXX_STANDARD 17)

add_executable(${PROJECT_NAME} src/main.cpp
    src/shaders/shader_s.h
    src/shaders/shader.vs
    src/shaders/shader.fs
    src/textures/stb_image.h
    src/textures/stb_image.cpp
)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)

add_subdirectory(external/glfw)
target_link_libraries(${PROJECT_NAME} glfw)


add_subdirectory(external/glad)
target_link_libraries(${PROJECT_NAME} glad)
