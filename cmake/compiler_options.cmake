# cmake/compiler_options.cmake

# Remove default build types and define custom ones
set(CMAKE_CONFIGURATION_TYPES Debug Release Dist CACHE STRING "Available configurations" FORCE)

# Function to set compiler flags
function(set_compiler_flags target)
    # Common compiler warnings and standards
    if(MSVC)
        target_compile_options(${target} PRIVATE 
            /W4     # Enable high-level warnings
            /WX     # Treat warnings as errors
        )
    else()
        target_compile_options(${target} PRIVATE 
            -Wall   # Enable all warnings
            -Werror # Treat warnings as errors
        )
    endif()
endfunction()

# MSVC-specific compiler flags
if(MSVC)
    set(CMAKE_CXX_FLAGS_DEBUG "/Zi /Od /D_DEBUG" CACHE STRING "Debug build compiler flags" FORCE)
    set(CMAKE_CXX_FLAGS_RELEASE "/O2 /DNDEBUG" CACHE STRING "Release build compiler flags" FORCE)
    set(CMAKE_CXX_FLAGS_DIST "/O3 /DNDEBUG" CACHE STRING "Dist build compiler flags" FORCE)
else()
    # GCC/Clang compiler flags
    set(CMAKE_CXX_FLAGS_DEBUG "-g" CACHE STRING "Debug build compiler flags" FORCE)
    set(CMAKE_CXX_FLAGS_RELEASE "-O2 -DNDEBUG" CACHE STRING "Release build compiler flags" FORCE)
    set(CMAKE_CXX_FLAGS_DIST "-O3 -DNDEBUG" CACHE STRING "Dist build compiler flags" FORCE)
endif()