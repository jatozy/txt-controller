add_executable(${CMAKE_PROJECT_NAME} main.cpp)
set_property(TARGET ${CMAKE_PROJECT_NAME} PROPERTY CXX_STANDARD 14)

include(${PROJECT_SOURCE_DIR}/3rdParty/TxtCInterface.cmake)

target_link_libraries(${CMAKE_PROJECT_NAME} ${TXT_C_LIBRARY_LIBS})
