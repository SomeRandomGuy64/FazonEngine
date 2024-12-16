# Sandbox/CMakeLists.txt
add_executable(Sandbox
    src/SandboxApp.cpp
)

# Include project-wide compiler options function
include(${CMAKE_SOURCE_DIR}/cmake/compiler_options.cmake)
set_compiler_flags(Sandbox)

# Link Fazon library and Catch2
target_link_libraries(Sandbox PUBLIC 
    Fazon
    Catch2
)

# Include directories
target_include_directories(Sandbox PUBLIC 
    ${CMAKE_SOURCE_DIR}/Fazon/src
)