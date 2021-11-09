# CNCShield-Pico
CNC Shield (https://blog.protoneer.co.nz/arduino-cnc-shield) library for Raspberry Pi Pico.

## How to build the example
1. `cp <PICO_SDK_PATH>/external/pico_sdk_import.cmake <CNCSHIELD_LIB_PATH>/examples/`
1. `mkdir <BUILD_DIR> && cd <BUILD_DIR>`
1. `cmake -DCNCSHIELD_LIB_PATH=<CNCSHIELD_LIB_PATH> <CNCSHIELD_LIB_PATH>/examples/`
1. `make`

## How to link with the library
1. `cp <PICO_SDK_PATH>/external/pico_sdk_import.cmake <YOUR_PROJECT_PATH>/`
1. `cp <CNCSHIELD_LIB_PATH>/examples/cncshield_lib_import.cmake <YOUR_PROJECT_PATH>/`
1. include `cncshield_lib_import.cmake` into your `CMakeLists.txt` file
    * CMake function: `include(cncshield_lib_import.cmake)`
1. add `CNCShield` as a dependency to your target
    * CMake function: `target_link_libraries(target CNCShield)`
