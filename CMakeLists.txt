cmake_minimum_required(VERSION 3.30)

project(FazonEngine 
    VERSION 0.01
    DESCRIPTION "My first game engine"
    LANGUAGES CXX
)

# Add cmake directory to module path
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

# Include modular cmake configurations
include(compiler_options)
include(platform_detection)
include(build_definitions)
include(submodules)

# Add main project targets
add_subdirectory(Fazon)
add_subdirectory(Sandbox)

# Add vendor targets
add_subdirectory(vendor/catch2)