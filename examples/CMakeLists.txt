option(DEBUG "Debug build" OFF)

# Example rules
add_executable(CNCShieldExample
            CNCShieldExample.cpp
            )

# Pull in dependencies
target_link_libraries(CNCShieldExample CNCShield)

# create map/bin/hex file etc.
pico_add_extra_outputs(CNCShieldExample)
