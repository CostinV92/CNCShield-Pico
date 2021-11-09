cmake_minimum_required(VERSION 3.12)

# Pull in SDK (must be before project)
include(pico_sdk_import.cmake)

project(CNCShieldExample C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Initialize the SDK
pico_sdk_init()

# Pull in CNCSHield library
include(cncshield_lib_import.cmake)

# Check if Debug build
if (CMAKE_BUILD_TYPE MATCHES Debug)
    pico_enable_stdio_usb(CNCShieldExample 0)
    pico_enable_stdio_uart(CNCShieldExample 1)
    add_definitions(-DDEBUG)
endif(CMAKE_BUILD_TYPE MATCHES Debug)

# Add sources
add_executable(CNCShieldExample
            src/CNCShieldExample.cpp
            )

# Pull in dependencies
target_link_libraries(CNCShieldExample CNCShield)

# create map/bin/hex file etc.
pico_add_extra_outputs(CNCShieldExample)
