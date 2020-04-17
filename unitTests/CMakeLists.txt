if(NOT BUILD_TESTS)
    message( FATAL_ERROR "You must set the flag BUILD_TEST for building the unit test project.")
endif()

ADD_EXECUTABLE(TxtControllerUnitTests main.cpp)

include(${CMAKE_SOURCE_DIR}/3rdParty/TxtCInterface.cmake)

TARGET_LINK_LIBRARIES(TxtControllerUnitTests
    PRIVATE TxtController
    PRIVATE gtest
)

ADD_TEST(NAME TxtControllerUnitTests COMMAND TxtControllerUnitTests)