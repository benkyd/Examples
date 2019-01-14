cmake_minimum_required(VERSION 3.7)
project(gl-cube)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} CMakeModules/)
cmake_policy(SET CMP0037 OLD)
set(CMAKE_BUILD_TYPE Debug)

set(executable cube.a)
set(SrcDIR ./src)
set(IncludeDIR ./include)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(PNG REQUIRED)
find_package(JPEG REQUIRED)

set(THREADS_PREFER_PTHREAD_FLAD ON)
find_package(Threads REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)

include_directories(${executable}
    ${SDL2_INCLUDE_DIR}
    ${SDL2_IMAGE_INCLUDE_DIR}
    ${PNG_INCLUDE_DIR}
    ${JPEG_INCLUDE_DIR}
    ${GLEW_INCLUDE_DIRS}
    ${IncludeDIR}
)

file(GLOB_RECURSE SourceFiles 
    ${SrcDIR}/*
)

add_executable(${executable} ${SourceFiles})

set_target_properties(${executable} PROPERTIES
    CXX_STANDARD 17
    CXX_EXTENSIONS OFF
)

target_link_libraries(${executable}
    SDL2
    SDL2_image
    PNG::PNG
    JPEG::JPEG
    Threads::Threads
    OpenGL::OpenGL
    OpenGL::GL
    GLEW
)
