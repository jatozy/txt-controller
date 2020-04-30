cmake_minimum_required(VERSION 3.13.0)

project (TxtController)

OPTION(BUILD_TESTS "Build unit tests" OFF)
OPTION(BUILD_FOR_CONTROLLER "Build cross for TXT Controller" OFF)

include_directories(BEFORE ${PROJECT_SOURCE_DIR}/includes)

if(BUILD_TESTS AND BUILD_FOR_CONTROLLER)
    message( FATAL_ERROR "You have set the flags so that the tests and the cross binaries shall be compiled. This is not possible. You have to compile them separately.")
elseif(NOT BUILD_TESTS AND NOT BUILD_FOR_CONTROLLER)
    message( FATAL_ERROR "You must set one of the flags BUILD_TESTS or BUILD_FOR_CONTROLLER.")
elseif(BUILD_TESTS)
    set(CMAKE_C_FLAGS "-m32")
    set(CMAKE_CXX_FLAGS "-m32")
    
	enable_testing()
    add_subdirectory(3rdParty/googletest)
    add_subdirectory(unitTests)
elseif(BUILD_FOR_CONTROLLER)
    set(CMAKE_SYSTEM_NAME Linux)
    set(CMAKE_SYSTEM_PROCESSOR arm)
    
    set(CMAKE_SYSROOT /opt/sysroot/)
    
    set(CMAKE_C_COMPILER /opt/compiler/bin/arm-linux-gnueabihf-gcc)
    set(CMAKE_CXX_COMPILER /opt/compiler/bin/arm-linux-gnueabihf-g++)
    
    set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
    set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
    set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
endif()

add_subdirectory(src)