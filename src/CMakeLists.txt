add_library(${CMAKE_PROJECT_NAME} SHARED Controller.cpp)
set_property(TARGET ${CMAKE_PROJECT_NAME} PROPERTY CXX_STANDARD 14)

if(BUILD_TESTS)

elseif(BUILD_FOR_CONTROLLER)
target_link_libraries(${CMAKE_PROJECT_NAME} 
    ${PROJECT_SOURCE_DIR}/3rdParty/txt_demo_c_download/deps/lib/libKeLibTxt.so
    ${PROJECT_SOURCE_DIR}/3rdParty/txt_demo_c_download/deps/lib/libMotorIOLib.so
    ${PROJECT_SOURCE_DIR}/3rdParty/txt_demo_c_download/deps/lib/libROBOProLib.so
    ${PROJECT_SOURCE_DIR}/3rdParty/txt_demo_c_download/deps/lib/libSDL.so
    ${PROJECT_SOURCE_DIR}/3rdParty/txt_demo_c_download/deps/lib/libSDLWidgetsLib.so
    ${PROJECT_SOURCE_DIR}/3rdParty/txt_demo_c_download/deps/lib/libSDL_gfx.so
    ${PROJECT_SOURCE_DIR}/3rdParty/txt_demo_c_download/deps/lib/libSDL_image.so
    ${PROJECT_SOURCE_DIR}/3rdParty/txt_demo_c_download/deps/lib/libSDL_ttf.so
    ${PROJECT_SOURCE_DIR}/3rdParty/txt_demo_c_download/deps/lib/libTxtControlLib.so
    ${PROJECT_SOURCE_DIR}/3rdParty/txt_demo_c_download/deps/lib/libasound.so
    ${PROJECT_SOURCE_DIR}/3rdParty/txt_demo_c_download/deps/lib/libbz2.so
    ${PROJECT_SOURCE_DIR}/3rdParty/txt_demo_c_download/deps/lib/libcrypto.so
    ${PROJECT_SOURCE_DIR}/3rdParty/txt_demo_c_download/deps/lib/libfreefare.so
    ${PROJECT_SOURCE_DIR}/3rdParty/txt_demo_c_download/deps/lib/libfreetype.so
    ${PROJECT_SOURCE_DIR}/3rdParty/txt_demo_c_download/deps/lib/libjpeg.so
    ${PROJECT_SOURCE_DIR}/3rdParty/txt_demo_c_download/deps/lib/libjsoncpp.so
    ${PROJECT_SOURCE_DIR}/3rdParty/txt_demo_c_download/deps/lib/libnfc.so
    ${PROJECT_SOURCE_DIR}/3rdParty/txt_demo_c_download/deps/lib/libopencv_core.so
    ${PROJECT_SOURCE_DIR}/3rdParty/txt_demo_c_download/deps/lib/libopencv_imgcodecs.so
    ${PROJECT_SOURCE_DIR}/3rdParty/txt_demo_c_download/deps/lib/libopencv_imgproc.so
    ${PROJECT_SOURCE_DIR}/3rdParty/txt_demo_c_download/deps/lib/libopencv_videoio.so
    ${PROJECT_SOURCE_DIR}/3rdParty/txt_demo_c_download/deps/lib/libpaho-mqtt3a.so
    ${PROJECT_SOURCE_DIR}/3rdParty/txt_demo_c_download/deps/lib/libpaho-mqtt3c.so
    ${PROJECT_SOURCE_DIR}/3rdParty/txt_demo_c_download/deps/lib/libpaho-mqttpp3.so
    ${PROJECT_SOURCE_DIR}/3rdParty/txt_demo_c_download/deps/lib/libpng16.so
    ${PROJECT_SOURCE_DIR}/3rdParty/txt_demo_c_download/deps/lib/libts.so
    ${PROJECT_SOURCE_DIR}/3rdParty/txt_demo_c_download/deps/lib/libz.so
)
endif()