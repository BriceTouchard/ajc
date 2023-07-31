cmake_minimum_required(VERSION 3.5)

project(piechart LANGUAGES C)
find_package(gd)

add_executable(piechart main.c)
target_link_libraries (piechart gd -lm)

install(TARGETS piechart
LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
