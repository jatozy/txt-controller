file(GLOB TxtControllerPrecompiledLibraries
  "${PROJECT_SOURCE_DIR}/3rdParty/txt_demo_c_download/deps/lib/*.so"
)
file(COPY ${TxtControllerPrecompiledLibraries} DESTINATION ${CMAKE_BINARY_DIR}/lib)

add_library(KeLibTxt UNKNOWN IMPORTED)
set_property(TARGET KeLibTxt PROPERTY IMPORTED_LOCATION "${CMAKE_BINARY_DIR}/lib/libKeLibTxt.so")

add_library(MotorIOLib UNKNOWN IMPORTED)
set_property(TARGET MotorIOLib PROPERTY IMPORTED_LOCATION "${CMAKE_BINARY_DIR}/lib/libMotorIOLib.so")

add_library(ROBOProLib UNKNOWN IMPORTED)
set_property(TARGET ROBOProLib PROPERTY IMPORTED_LOCATION "${CMAKE_BINARY_DIR}/lib/libROBOProLib.so")

add_library(SDL UNKNOWN IMPORTED)
set_property(TARGET SDL PROPERTY IMPORTED_LOCATION "${CMAKE_BINARY_DIR}/lib/libSDL.so")

add_library(SDLWidgetsLib UNKNOWN IMPORTED)
set_property(TARGET SDLWidgetsLib PROPERTY IMPORTED_LOCATION "${CMAKE_BINARY_DIR}/lib/libSDLWidgetsLib.so")

add_library(SDL_gfx UNKNOWN IMPORTED)
set_property(TARGET SDL_gfx PROPERTY IMPORTED_LOCATION "${CMAKE_BINARY_DIR}/lib/libSDL_gfx.so")

add_library(SDL_image UNKNOWN IMPORTED)
set_property(TARGET SDL_image PROPERTY IMPORTED_LOCATION "${CMAKE_BINARY_DIR}/lib/libSDL_image.so")

add_library(SDL_ttf UNKNOWN IMPORTED)
set_property(TARGET SDL_ttf PROPERTY IMPORTED_LOCATION "${CMAKE_BINARY_DIR}/lib/libSDL_ttf.so")

add_library(TxtControlLib UNKNOWN IMPORTED)
set_property(TARGET TxtControlLib PROPERTY IMPORTED_LOCATION "${CMAKE_BINARY_DIR}/lib/libTxtControlLib.so")

add_library(asound UNKNOWN IMPORTED)
set_property(TARGET asound PROPERTY IMPORTED_LOCATION "${CMAKE_BINARY_DIR}/lib/libasound.so")

add_library(bz2 UNKNOWN IMPORTED)
set_property(TARGET bz2 PROPERTY IMPORTED_LOCATION "${CMAKE_BINARY_DIR}/lib/libbz2.so")

add_library(crypto UNKNOWN IMPORTED)
set_property(TARGET crypto PROPERTY IMPORTED_LOCATION "${CMAKE_BINARY_DIR}/lib/libcrypto.so")

add_library(freefare UNKNOWN IMPORTED)
set_property(TARGET freefare PROPERTY IMPORTED_LOCATION "${CMAKE_BINARY_DIR}/lib/libfreefare.so")

add_library(freetype UNKNOWN IMPORTED)
set_property(TARGET freetype PROPERTY IMPORTED_LOCATION "${CMAKE_BINARY_DIR}/lib/libfreetype.so")

add_library(jpeg UNKNOWN IMPORTED)
set_property(TARGET jpeg PROPERTY IMPORTED_LOCATION "${CMAKE_BINARY_DIR}/lib/libjpeg.so")

add_library(jsoncpp UNKNOWN IMPORTED)
set_property(TARGET jsoncpp PROPERTY IMPORTED_LOCATION "${CMAKE_BINARY_DIR}/lib/libjsoncpp.so")

add_library(nfc UNKNOWN IMPORTED)
set_property(TARGET nfc PROPERTY IMPORTED_LOCATION "${CMAKE_BINARY_DIR}/lib/libnfc.so")

add_library(opencv_core UNKNOWN IMPORTED)
set_property(TARGET opencv_core PROPERTY IMPORTED_LOCATION "${CMAKE_BINARY_DIR}/lib/libopencv_core.so")

add_library(opencv_imgcodecs UNKNOWN IMPORTED)
set_property(TARGET opencv_imgcodecs PROPERTY IMPORTED_LOCATION "${CMAKE_BINARY_DIR}/lib/libopencv_imgcodecs.so")

add_library(opencv_imgproc UNKNOWN IMPORTED)
set_property(TARGET opencv_imgproc PROPERTY IMPORTED_LOCATION "${CMAKE_BINARY_DIR}/lib/libopencv_imgproc.so")

add_library(opencv_videoio UNKNOWN IMPORTED)
set_property(TARGET opencv_videoio PROPERTY IMPORTED_LOCATION "${CMAKE_BINARY_DIR}/lib/libopencv_videoio.so")

add_library(paho-mqtt3a UNKNOWN IMPORTED)
set_property(TARGET paho-mqtt3a PROPERTY IMPORTED_LOCATION "${CMAKE_BINARY_DIR}/lib/libpaho-mqtt3a.so")

add_library(paho-mqtt3c UNKNOWN IMPORTED)
set_property(TARGET paho-mqtt3c PROPERTY IMPORTED_LOCATION "${CMAKE_BINARY_DIR}/lib/libpaho-mqtt3c.so")

add_library(paho-mqttpp3 UNKNOWN IMPORTED)
set_property(TARGET paho-mqttpp3 PROPERTY IMPORTED_LOCATION "${CMAKE_BINARY_DIR}/lib/libpaho-mqttpp3.so")

add_library(png16 UNKNOWN IMPORTED)
set_property(TARGET png16 PROPERTY IMPORTED_LOCATION "${CMAKE_BINARY_DIR}/lib/libpng16.so")

add_library(ts UNKNOWN IMPORTED)
set_property(TARGET ts PROPERTY IMPORTED_LOCATION "${CMAKE_BINARY_DIR}/lib/libts.so")

add_library(z UNKNOWN IMPORTED)
set_property(TARGET z PROPERTY IMPORTED_LOCATION "${CMAKE_BINARY_DIR}/lib/libz.so")

set(TXT_C_LIBRARY_LIBS KeLibTxt)
LIST(APPEND TXT_C_LIBRARY_LIBS "MotorIOLib")
LIST(APPEND TXT_C_LIBRARY_LIBS "ROBOProLib")
LIST(APPEND TXT_C_LIBRARY_LIBS "SDL")
LIST(APPEND TXT_C_LIBRARY_LIBS "SDLWidgetsLib")
LIST(APPEND TXT_C_LIBRARY_LIBS "SDL_gfx")
LIST(APPEND TXT_C_LIBRARY_LIBS "SDL_image")
LIST(APPEND TXT_C_LIBRARY_LIBS "SDL_ttf")
LIST(APPEND TXT_C_LIBRARY_LIBS "TxtControlLib")
LIST(APPEND TXT_C_LIBRARY_LIBS "asound")
LIST(APPEND TXT_C_LIBRARY_LIBS "bz2")
LIST(APPEND TXT_C_LIBRARY_LIBS "crypto")
LIST(APPEND TXT_C_LIBRARY_LIBS "freefare")
LIST(APPEND TXT_C_LIBRARY_LIBS "freetype")
LIST(APPEND TXT_C_LIBRARY_LIBS "jpeg")
LIST(APPEND TXT_C_LIBRARY_LIBS "jsoncpp")
LIST(APPEND TXT_C_LIBRARY_LIBS "nfc")
LIST(APPEND TXT_C_LIBRARY_LIBS "opencv_core")
LIST(APPEND TXT_C_LIBRARY_LIBS "opencv_imgcodecs")
LIST(APPEND TXT_C_LIBRARY_LIBS "opencv_imgproc")
LIST(APPEND TXT_C_LIBRARY_LIBS "opencv_videoio")
LIST(APPEND TXT_C_LIBRARY_LIBS "paho-mqtt3a")
LIST(APPEND TXT_C_LIBRARY_LIBS "paho-mqtt3c")
LIST(APPEND TXT_C_LIBRARY_LIBS "paho-mqttpp3")
LIST(APPEND TXT_C_LIBRARY_LIBS "png16")
LIST(APPEND TXT_C_LIBRARY_LIBS "ts")
LIST(APPEND TXT_C_LIBRARY_LIBS "z")