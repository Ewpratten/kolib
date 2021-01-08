

# add_library(raygui
#     STATIC

#     raygui/src/gui_textbox_extended.h
#     raygui/src/raygui.h
#     raygui/src/ricons.h
#     )

# include(ExternalProject)
# find_program(MAKE_EXE NAMES gmake nmake make)
# ExternalProject_Add(rawdraw 
#     SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/rawdraw
#     CONFIGURE_COMMAND ""
#     BUILD_COMMAND ${MAKE_EXE}
#     )

# add_subdirectory(raylib)

find_package(X11 COMPONENTS X11 Xft)
add_library(rawdraw
    STATIC

    rawdraw/rawdraw.c
    rawdraw/CNFG.h
    )