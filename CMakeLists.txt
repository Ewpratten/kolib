project(kolib CXX C)
cmake_minimum_required(VERSION 3.13)

set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR arm)

set(tools /root/x-tools/arm-kobo-linux-gnueabihf)
set(CMAKE_C_COMPILER ${tools}/bin/arm-kobo-linux-gnueabihf-gcc)
set(CMAKE_CXX_COMPILER ${tools}/bin/arm-kobo-linux-gnueabihf-g++)

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)


# External deps
# add_subdirectory(thirdparty)

# KoLib
add_library(kolib
    STATIC

    src/koboconf.cc
    src/koboconf.hh

    # hw
    src/hw/battery.hh
    src/hw/power.hh
    src/hw/board.cc
    src/hw/board.hh

    # util
    src/util/fio.cc
    src/util/fio.hh

    # net
    src/net/interfaces.cc
    src/net/interfaces.hh
)
include_directories(src)
# add_dependencies(kolib rawdraw)
# target_link_libraries(kolib rawdraw)
