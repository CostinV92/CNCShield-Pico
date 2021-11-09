# Add headers
add_library(CNCShield_headers INTERFACE)
target_include_directories(CNCShield_headers INTERFACE ${CNCSHIELD_LIB_PATH}/include)

# Add sources
add_library(CNCShield INTERFACE)
target_sources(CNCShield INTERFACE 
    ${CNCSHIELD_LIB_PATH}/src/CNCShield.cpp
    ${CNCSHIELD_LIB_PATH}/src/StepperMotor.cpp
    )

target_link_libraries(CNCShield INTERFACE CNCShield_headers pico_stdlib)
