cmake_minimum_required(VERSION 3.5)

project(piechart4 LANGUAGES C)
find_package(gd)

add_executable(piechart4 main.c)
target_link_libraries (piechart4 gd -lm)

install(TARGETS piechart4
LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
