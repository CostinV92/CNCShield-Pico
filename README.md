# CNCShield-Pico
CNC Shield (https://blog.protoneer.co.nz/arduino-cnc-shield) library for Raspberry Pi Pico.

## How to build the example
1. `cp <PICO_SDK_PATH>/external/pico_sdk_import.cmake <CNC_SHIELD_LIB_PATH>/examples/`
1. `mkdir <BUILD_DIR> && cd <BUILD_DIR>`
1. `cmake -DCNC_SHIELD_LIB_PATH=<CNC_SHIELD_LIB_PATH> <CNC_SHIELD_LIB_PATH>/examples/`
1. `make`

## How to link with the library
1. `cp <PICO_SDK_PATH>/external/pico_sdk_import.cmake <YOUR_PROJECT_PATH>/`
1. `cp <CNC_SHIELD_LIB_PATH>/examples/cnc_shield_lib_import.cmake <YOUR_PROJECT_PATH>/`
1. include `cnc_shield_lib_import.cmake` into your `CMakeLists.txt` file
    * CMake function: `include(cnc_shield_lib_import.cmake)`
1. add `CNCShield` as a dependency to your target
    * CMake function: `target_link_libraries(target CNCShield)`
