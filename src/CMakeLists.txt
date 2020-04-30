add_library(${CMAKE_PROJECT_NAME} SHARED Controller.cpp)
set_property(TARGET ${CMAKE_PROJECT_NAME} PROPERTY CXX_STANDARD 14)

include(${CMAKE_SOURCE_DIR}/3rdParty/TxtCInterface.cmake)

if(BUILD_TESTS)

elseif(BUILD_FOR_CONTROLLER)
    target_link_libraries(${CMAKE_PROJECT_NAME} ${TXT_C_LIBRARY_LIBS})
endif()