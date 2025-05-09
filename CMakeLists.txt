# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.1.1)
set(toolchainVersion 14_2_Rel1)
set(picotoolVersion 2.1.1)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
set(PICO_BOARD pico CACHE STRING "Board type")

cmake_minimum_required(VERSION 3.13)
include(pico_sdk_import.cmake)

project(galton_board)

pico_sdk_init()

add_executable(galton_board
    main.c
    src/galton.c
    src/display.c
    src/ball.c
    lib/ssd1306/ssd1306_i2c.c
)

target_include_directories(galton_board PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/inc
    ${CMAKE_CURRENT_LIST_DIR}/lib/ssd1306
)

target_link_libraries(galton_board pico_stdlib hardware_i2c)
pico_add_extra_outputs(galton_board)
