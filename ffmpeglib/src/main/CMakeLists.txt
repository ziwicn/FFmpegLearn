# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html.
# For more examples on how to use CMake, see https://github.com/android/ndk-samples.

# Sets the minimum CMake version required for this project.
cmake_minimum_required(VERSION 3.22.1)

set(lib_src_DIR ${CMAKE_SOURCE_DIR}/libs/${ANDROID_ABI})

project("ffmpeglib")

add_library(${CMAKE_PROJECT_NAME} SHARED cpp/ffmpeglib.cpp)

include_directories(${CMAKE_SOURCE_DIR}/cpp/include)

add_library(avcodec_lib SHARED IMPORTED)
set_target_properties(avcodec_lib PROPERTIES IMPORTED_LOCATION
        ${lib_src_DIR}/libavcodec.so)

add_library(avformat_lib SHARED IMPORTED)
set_target_properties(avformat_lib PROPERTIES IMPORTED_LOCATION
        ${lib_src_DIR}/libavformat.so)

add_library(avutil_lib SHARED IMPORTED)
set_target_properties(avutil_lib PROPERTIES IMPORTED_LOCATION
        ${lib_src_DIR}/libavutil.so)

add_library(swresample_lib SHARED IMPORTED)
set_target_properties(swresample_lib PROPERTIES IMPORTED_LOCATION
        ${lib_src_DIR}/libswresample.so)

add_library(swscale_lib SHARED IMPORTED)
set_target_properties(swscale_lib PROPERTIES IMPORTED_LOCATION
        ${lib_src_DIR}/libswscale.so)

target_link_libraries(
        ${CMAKE_PROJECT_NAME}
        log
        android
        OpenSLES
        avcodec_lib
        avformat_lib
        avutil_lib
        swresample_lib
        swscale_lib)