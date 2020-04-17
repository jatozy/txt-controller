add_library(${CMAKE_PROJECT_NAME} txtController.cpp)
set_property(TARGET ${CMAKE_PROJECT_NAME} PROPERTY CXX_STANDARD 14)

include_directories(BEFORE ${PROJECT_SOURCE_DIR}/includes)

include(${PROJECT_SOURCE_DIR}/3rdParty/TxtCInterface.cmake)

if(BUILD_TESTS)

else()
    message( FATAL_ERROR "You must set the flag BUILD_TEST for building the unit test project.")
endif()