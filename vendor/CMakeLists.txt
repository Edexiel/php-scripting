# FMT library
FetchContent_Declare(
        fmt
        GIT_REPOSITORY https://github.com/fmtlib/fmt.git
        GIT_TAG 8.1.1
)

# Raylib library
FetchContent_Declare(
        raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib.git
        GIT_TAG 4.0.0
)

FetchContent_MakeAvailable(raylib fmt)

# PHP library
add_library(php STATIC IMPORTED GLOBAL)

set_target_properties(
        php
        PROPERTIES
        IMPORTED_LOCATION "${PROJECT_SOURCE_DIR}/vendor/php/lib/libphp.a"
)
set(PHP_INCLUDES "${PROJECT_SOURCE_DIR}/vendor/php/include/php"
        "${PROJECT_SOURCE_DIR}/vendor/php/include/php/Zend"
        "${PROJECT_SOURCE_DIR}/vendor/php/include/php/main"
        "${PROJECT_SOURCE_DIR}/vendor/php/include/php/TSRM"
        "${PROJECT_SOURCE_DIR}/vendor/php/include/php/ext"
        )
set_target_properties(
        php
        PROPERTIES
        INTERFACE_INCLUDE_DIRECTORIES "${PHP_INCLUDES}"
)

#set(PHP_LIB ${PROJECT_SOURCE_DIR}/vendor/php/lib/libphp.a PARENT_SCOPE)
#
#file(GLOB PHP_INCLUDES CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/include/php_scripting/*.hpp")
#

