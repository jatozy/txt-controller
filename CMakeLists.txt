cmake_minimum_required(VERSION 3.10.0)

set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR arm)

set(CMAKE_SYSROOT /opt/sysroot/)

set(CMAKE_C_COMPILER /opt/compiler/bin/arm-linux-gnueabihf-gcc)
set(CMAKE_CXX_COMPILER /opt/compiler/bin/arm-linux-gnueabihf-g++)

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

project (TxtController)

add_subdirectory(src)