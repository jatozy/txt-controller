if(BUILD_TESTS)
    message( FATAL_ERROR "You must set the flag BUILD_TEST to OFF. Otherwise you can not build the test application. This application will run on the embedded controller.")
endif()
if(NOT BUILD_FOR_CONTROLLER)
    message( FATAL_ERROR "You must set the flag BUILD_FOR_CONTROLLER for building the test application for the controller.")
endif()

ADD_EXECUTABLE(TestApplication main.cpp)
set_property(TARGET TestApplication PROPERTY CXX_STANDARD 14)

include(${CMAKE_SOURCE_DIR}/3rdParty/TxtCInterface.cmake)

TARGET_LINK_LIBRARIES(TestApplication
    PRIVATE TxtController
#    PRIVATE ${TXT_C_LIBRARY_LIBS}
    )
