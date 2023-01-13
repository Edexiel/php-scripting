cmake_minimum_required(VERSION 3.21)

project(php_scripting
        VERSION 0.1
        DESCRIPTION "A PHP scripting library for CPP"
        LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

#set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set(OpenGL_GL_PREFERENCE GLVND)

include(FetchContent)

#add_library(php STATIC IMPORTED)

add_subdirectory(vendor)

add_subdirectory(src)

add_subdirectory(apps)


#add_executable(php_scripting apps/app.cpp src/Lib.cpp include/php_scripting/Lib.hpp)
