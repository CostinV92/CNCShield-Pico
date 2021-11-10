# Add headers
add_library(CNCShield_headers INTERFACE)
target_include_directories(CNCShield_headers INTERFACE ${CNC_SHIELD_LIB_PATH}/include)

# Add target
add_library(CNCShield INTERFACE)

# Add sources
target_sources(CNCShield INTERFACE 
    ${CNC_SHIELD_LIB_PATH}/src/CNCShield.cpp
    )

# Add dependencies
target_link_libraries(CNCShield INTERFACE CNCShield_headers pico_stdlib)
