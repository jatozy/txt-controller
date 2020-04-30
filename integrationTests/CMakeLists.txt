if(NOT BUILD_TESTS)
    message( FATAL_ERROR "You must set the flag BUILD_TEST for building the integration test project.")
endif()

ADD_EXECUTABLE(TxtControllerIntegrationTests main.cpp)

include(${CMAKE_SOURCE_DIR}/3rdParty/TxtCInterface.cmake)

TARGET_LINK_LIBRARIES(TxtControllerIntegrationTests
    PRIVATE TxtController
    PRIVATE gtest
)

ADD_TEST(NAME TxtControllerIntegrationTests COMMAND TxtControllerIntegrationTests)