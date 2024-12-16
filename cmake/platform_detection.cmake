# cmake/platform_detection.cmake

# Platform-specific compile definitions
if(WIN32)
    add_compile_definitions(
        FZ_PLATFORM_WINDOWS
    )
else()
    message(FATAL_ERROR "Fazon Engine only supports Windows")
endif()