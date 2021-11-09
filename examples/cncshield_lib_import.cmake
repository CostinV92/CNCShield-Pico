# This is a copy of <CNCSHIELD_LIB_PATH>/cncshield_lib_import.cmake

# This can be dropped into an external project to help locate the CNCShield lib

if (DEFINED ENV{CNCSHIELD_LIB_PATH} AND (NOT CNCSHIELD_LIB_PATH))
    set(CNCSHIELD_LIB_PATH $ENV{CNCSHIELD_LIB_PATH})
    message("Using CNCSHIELD_LIB_PATH from environment ('${CNCSHIELD_LIB_PATH}')")
endif ()

set(CNCSHIELD_LIB_PATH "${CNCSHIELD_LIB_PATH}" CACHE PATH "Path to the CNCShield library")

if (NOT CNCSHIELD_LIB_PATH)
    message(FATAL_ERROR
            "CNCShield location was not specified. Please set CNCSHIELD_LIB_PATH."
            )
endif ()

get_filename_component(CNCSHIELD_LIB_PATH "${CNCSHIELD_LIB_PATH}" REALPATH BASE_DIR "${CMAKE_BINARY_DIR}")
if (NOT EXISTS ${CNCSHIELD_LIB_PATH})
    message(FATAL_ERROR "Directory '${CNCSHIELD_LIB_PATH}' not found")
endif ()

set(CNCSHIELD_LIB_PATH ${CNCSHIELD_LIB_PATH} CACHE PATH "Path to the CNCShield library" FORCE)

add_subdirectory(${CNCSHIELD_LIB_PATH}/src ${CMAKE_BINARY_DIR}/CNCShield)
