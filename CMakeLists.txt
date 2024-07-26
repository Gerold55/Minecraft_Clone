cmake_minimum_required(VERSION 3.10)
project(MinecraftClone)

set(CMAKE_CXX_STANDARD 17)

# Find GLEW
find_package(GLEW REQUIRED)

# Include directories
include_directories(include ${GLEW_INCLUDE_DIRS})

# Find and link libraries
find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED)

# Add your source files here
set(SOURCES
    src/main.cpp
    src/Shader.cpp
    src/Cube.cpp
    src/BlockManager.cpp
    src/LuaBindings.cpp
)

add_executable(MinecraftClone ${SOURCES})

# Link GLEW, SDL2, and OpenGL
target_link_libraries(MinecraftClone ${GLEW_LIBRARIES} SDL2::SDL2 OpenGL::GL)
