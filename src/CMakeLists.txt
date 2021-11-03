# Add headers
add_library(CNCShield_headers INTERFACE)
target_include_directories(CNCShield_headers INTERFACE ${CNCSHIELD_TOP_DIR}/include)

# Add sources
add_library(CNCShield INTERFACE)
target_sources(CNCShield INTERFACE 
    ${CMAKE_CURRENT_LIST_DIR}/CNCShield.cpp
    ${CMAKE_CURRENT_LIST_DIR}/StepperMotor.cpp
    )

target_link_libraries(CNCShield INTERFACE CNCShield_headers pico_stdlib)
