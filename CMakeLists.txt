project(kolib CXX)
cmake_minimum_required(VERSION 3.18)


add_executable(hello hello/main.cc)
# 

# External deps
# add_subdirectory(thirdparty)

# KoLib
# add_library(kolib
#     STATIC

#     src/fs/paths.hh

#     # DEPENDS thirdparty/raygui
# )
# set_property(TARGET kolib PROPERTY CXX_STANDARD 20)