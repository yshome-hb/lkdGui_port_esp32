
file(GLOB_RECURSE SOURCES "source/*.c" "port/*.c")

set(LKDGUI_INCLUDE_DIRS . "include")
list(APPEND LKDGUI_INCLUDE_DIRS port/lcdDriver)

idf_component_register(SRCS ${SOURCES}
                       INCLUDE_DIRS ${LKDGUI_INCLUDE_DIRS})
