add_executable(${CMAKE_PROJECT_NAME} main.cpp)
set_property(TARGET ${CMAKE_PROJECT_NAME} PROPERTY CXX_STANDARD 14)

include(3rdPartyLibs.cmake)

target_link_libraries(${CMAKE_PROJECT_NAME}
    PRIVATE KeLibTxt
    PRIVATE MotorIOLib
    PRIVATE ROBOProLib
    PRIVATE SDL
    PRIVATE SDLWidgetsLib
    PRIVATE SDL_gfx
    PRIVATE SDL_image
    PRIVATE SDL_ttf
    PRIVATE TxtControlLib
    PRIVATE asound
    PRIVATE bz2
    PRIVATE crypto
    PRIVATE freefare
    PRIVATE freetype
    PRIVATE jpeg
    PRIVATE jsoncpp
    PRIVATE nfc
    PRIVATE opencv_core
    PRIVATE opencv_imgcodecs
    PRIVATE opencv_imgproc
    PRIVATE opencv_videoio
    PRIVATE paho-mqtt3a
    PRIVATE paho-mqtt3c
    PRIVATE paho-mqttpp3
    PRIVATE png16
    PRIVATE ts
    PRIVATE z
)
