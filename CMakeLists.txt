cmake_minimum_required(VERSION 3.0)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(santi)

add_executable(
    santi
    main.cpp
)

add_library(lvgl OBJECT EXCLUDE_FROM_ALL)
file(GLOB_RECURSE lvgl_sources "lv_sim_vscode_sdl/lvgl/*.c")
target_sources(lvgl PRIVATE
    ${lvgl_sources}
)

target_include_directories(lvgl SYSTEM PUBLIC lv_sim_vscode_sdl/lvgl/lvgl.h)
target_include_directories(lvgl SYSTEM PUBLIC lv_sim_vscode_sdl/lvgl/)
target_include_directories(lvgl SYSTEM PUBLIC lv_sim_vscode_sdl/lvgl/../)

add_library(lv_drivers OBJECT EXCLUDE_FROM_ALL)
file(GLOB_RECURSE lv_drivers_sources "lv_sim_vscode_sdl/lv_drivers/*.c")
target_sources(lv_drivers PRIVATE
    ${lv_drivers_sources}
)

target_link_libraries(lv_drivers PUBLIC lvgl)
target_include_directories(lv_drivers SYSTEM PUBLIC "lv_sim_vscode_sdl/lv_drivers/")

add_library(lv_examples OBJECT EXCLUDE_FROM_ALL)
file(GLOB_RECURSE lv_examples_sources "lv_sim_vscode_sdl/lv_examples/src/lv_demo_widgets/*.c")
target_sources(lv_examples PRIVATE
    ${lv_examples_sources}
)

target_link_libraries(lv_examples PUBLIC lvgl)
target_include_directories(lv_examples SYSTEM PUBLIC "lv_sim_vscode_sdl/lv_examples/src/lv_demo_widgets/")

find_package(SDL2 REQUIRED)
include_directories(santi ${SDL2_INCLUDE_DIRS})

target_link_libraries(santi PRIVATE
    lvgl
    lv_drivers
    lv_examples
    ${SDL2_LIBRARIES}
)