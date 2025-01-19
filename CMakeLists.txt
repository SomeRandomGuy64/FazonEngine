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
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

add_subdirectory(vendor/catch2)
add_subdirectory(vendor/imgui)

set_target_properties(ImGui PROPERTIES FOLDER "Dependencies")
set_target_properties(Catch2 PROPERTIES FOLDER "Dependencies")
set_target_properties(Catch2WithMain PROPERTIES FOLDER "Dependencies")