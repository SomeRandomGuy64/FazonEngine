# Sandbox/CMakeLists.txt
add_executable(Sandbox
    src/SandboxApp.cpp
)

# Include project-wide compiler options function
include(${CMAKE_SOURCE_DIR}/cmake/compiler_options.cmake)
set_compiler_flags(Sandbox)

# Compiler features
target_compile_features(Sandbox PRIVATE cxx_std_23)

# Link Fazon library and Catch2
target_link_libraries(Sandbox PUBLIC 
    Fazon
)

# Include directories
target_include_directories(Sandbox PUBLIC 
    ${CMAKE_SOURCE_DIR}/Fazon/src
)