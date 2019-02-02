cmake_minimum_required(VERSION 3.7)
project(NavierStokes)

set(CMAKE_MODULE_PATH CMakeModule/)
set(CMAKE_CXX_FLAGS "-std=c++17")

set(Executable output)

set(THREADS_PREFER_PTHREAD_FLAD ON)
find_package(Threads REQUIRED)

add_executable(${Executable} main.cpp)

target_link_libraries(${Executable} Threads::Threads ${WinSDK})
