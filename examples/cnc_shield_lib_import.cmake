# This is a copy of <CNC_SHIELD_LIB_PATH>/cncshield_lib_import.cmake

# This can be dropped into an external project to help locate the CNCShield lib

if (DEFINED ENV{CNC_SHIELD_LIB_PATH} AND (NOT CNC_SHIELD_LIB_PATH))
    set(CNC_SHIELD_LIB_PATH $ENV{CNC_SHIELD_LIB_PATH})
    message("Using CNC_SHIELD_LIB_PATH from environment ('${CNC_SHIELD_LIB_PATH}')")
endif ()

set(CNC_SHIELD_LIB_PATH "${CNC_SHIELD_LIB_PATH}" CACHE PATH "Path to the CNCShield library")

if (NOT CNC_SHIELD_LIB_PATH)
    message(FATAL_ERROR
            "CNCShield location was not specified. Please set CNC_SHIELD_LIB_PATH."
            )
endif ()

get_filename_component(CNC_SHIELD_LIB_PATH "${CNC_SHIELD_LIB_PATH}" REALPATH BASE_DIR "${CMAKE_BINARY_DIR}")
if (NOT EXISTS ${CNC_SHIELD_LIB_PATH})
    message(FATAL_ERROR "Directory '${CNC_SHIELD_LIB_PATH}' not found")
endif ()

set(CNC_SHIELD_LIB_PATH ${CNC_SHIELD_LIB_PATH} CACHE PATH "Path to the CNCShield library" FORCE)

add_subdirectory(${CNC_SHIELD_LIB_PATH} ${CMAKE_BINARY_DIR}/CNCShield)
