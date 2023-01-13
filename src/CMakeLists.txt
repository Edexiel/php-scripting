file(GLOB HEADER_LIST CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/include/php_scripting/*.hpp")


add_library(Pachy STATIC vm.cpp php_module.cpp ${HEADER_LIST})

target_include_directories(Pachy PUBLIC ../include)

target_link_libraries(Pachy PUBLIC php raylib)

