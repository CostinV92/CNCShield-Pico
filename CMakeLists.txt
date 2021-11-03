cmake_minimum_required(VERSION 3.12)

# Pull in SDK (must be before project)
include(pico_sdk_import.cmake)

project(CNCShield C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Set top directory of library
set(CNCSHIELD_TOP_DIR ${CMAKE_CURRENT_LIST_DIR})

# Initialize the SDK
pico_sdk_init()

# Add src folder
ADD_SUBDIRECTORY(src)

# Add examples folder
add_subdirectory(examples)

# disable usb output, enable uart output
if (CMAKE_BUILD_TYPE MATCHES Debug)
    pico_enable_stdio_usb(CNCShieldExample 0)
    pico_enable_stdio_uart(CNCShieldExample 1)
    add_definitions(-DDEBUG)
endif(CMAKE_BUILD_TYPE MATCHES Debug)
