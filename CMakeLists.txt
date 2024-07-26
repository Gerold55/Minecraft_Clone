cmake_minimum_required(VERSION 3.10)
project(MinecraftClone)

set(CMAKE_CXX_STANDARD 17)

# Specify SDL2 directories
set(SDL2_INCLUDE_DIR "C:/Libraries/SDL2/include")
set(SDL2_LIB_DIR "C:/Libraries/SDL2/lib")

# Find SDL2
include_directories(${SDL2_INCLUDE_DIR})
link_directories(${SDL2_LIB_DIR})

# Find GLEW and OpenGL
find_package(GLEW REQUIRED)
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

# Link SDL2, GLEW, and OpenGL
target_link_libraries(MinecraftClone ${GLEW_LIBRARIES} SDL2main SDL2 ${OPENGL_LIBRARIES})
