
project(CW)

set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_C_FLAGS "-std=c99 -fdump-rtl-expand")

include_directories(Unity/include)

add_executable(GOL main.c Game_logic.c Game_interface.c)
add_executable(GOL-test test_Logic.c Game_logic.c Game_interface.c Unity/src/unity.c)

install(TARGETS GOL RUNTIME DESTINATION bin)