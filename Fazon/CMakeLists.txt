# Fazon/CMakeLists.txt
add_library(Fazon STATIC
    src/Fazon/Application.cpp
    src/Fazon/Application.h
    src/Fazon/Core.h
    src/Fazon/EntryPoint.h
    src/Fazon/Log.h
    src/Fazon/Log.cpp

    src/Fazon/Events/ApplicationEvent.h
    src/Fazon/Events/Event.h
    src/Fazon/Events/KeyEvent.h
    src/Fazon/Events/MouseEvent.h
    src/Fazon/Events/WindowEvent.h

    src/Fazon.h
)

# Include project-wide compiler options function
include(${CMAKE_SOURCE_DIR}/cmake/compiler_options.cmake)
set_compiler_flags(Fazon)

# Precompiled headers
target_precompile_headers(Fazon PUBLIC src/Fazon/fzpch.h)

# Include directories
target_include_directories(Fazon PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# Compiler features and definitions
target_compile_features(Fazon PRIVATE cxx_std_23)
target_compile_definitions(Fazon PRIVATE 
    FAZON_VERSION="0.01"
)

# Test project
add_subdirectory(tests)

# Vendor dependencies
set(SPDLOG_FMT_EXTERNAL OFF CACHE BOOL "Use external fmt library instead of bundled" FORCE)

set(SDL3_DIR "${CMAKE_CURRENT_SOURCE_DIR}/vendor/SDL")
set(SDL3_INCLUDE_DIR "${SDL3_DIR}/include/SDL3")
set(SDL3_LIB_DIR "${CMAKE_SOURCE_DIR}/libs/SDL3")

include_directories(${SDL3_INCLUDE_DIR})

add_subdirectory(vendor/spdlog)
add_subdirectory(vendor/SDL)
target_link_libraries(Fazon PRIVATE 
	spdlog
	"${SDL3_LIB_DIR}/SDL3.lib"
)