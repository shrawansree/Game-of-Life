
project(CW)

set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

if(COMMAND cmake_policy)
    cmake_policy(SET CMP0003 NEW)
endif(COMMAND cmake_policy)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

include_directories(Unity/include)
include_directories(${SDL2_INCLUDE_DIRS})
include_directories(${SDL2_IMAGE_DIRS})

set(CMAKE_C_FLAGS "-std=c99 -L"Coursework 2" -L"SDL2/include/SDL2" -L"SDL2/lib" -lSDL2 -lSDL2_image ")

add_executable(GOL main.c Game_logic.c Game_interface.c Game_SDL.c)
target_link_libraries(GOL ${SDL2_LIBRARIES})

add_executable(GOL-test test_Logic.c Game_logic.c Game_interface.c Unity/src/unity.c)

install(TARGETS GOL RUNTIME DESTINATION bin)