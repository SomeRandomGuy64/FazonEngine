# Sandbox/CMakeLists.txt
add_executable(Sandbox
    src/SandboxApp.cpp
)

source_group("Sandbox" FILES
    src/SandboxApp.cpp
)

# Include project-wide compiler options function
include(${CMAKE_SOURCE_DIR}/cmake/compiler_options.cmake)
set_compiler_flags(Sandbox)

# Compiler features
target_compile_features(Sandbox PRIVATE cxx_std_23)

# Link Fazon library and spdlog
target_link_libraries(Sandbox PRIVATE
    Fazon
	spdlog
)

# Include directories
target_include_directories(Sandbox PUBLIC 
    ${CMAKE_SOURCE_DIR}/Fazon/src
)

# Hide CMake generated files
set_target_properties(Sandbox PROPERTIES 
    VS_JUST_MY_CODE_DEBUGGING ON
    EXCLUDE_FROM_ALL_BOM TRUE
)

source_group("CMake Generated Files" FILES 
    "${CMAKE_CURRENT_BINARY_DIR}/CMakeFiles/Sandbox.dir/Debug/cmake_pch.hxx"
    "${CMAKE_CURRENT_BINARY_DIR}/CMakeFiles/Sandbox.dir/Release/cmake_pch.hxx"
    "${CMAKE_CURRENT_BINARY_DIR}/CMakeFiles/Sandbox.dir/Dist/cmake_pch.hxx"
    "${CMAKE_CURRENT_BINARY_DIR}/CMakeFiles/Sandbox.dir/cmake_pch.cxx"
)

add_custom_command(TARGET Sandbox POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy
	"${CMAKE_SOURCE_DIR}/libs/SDL3/SDL3.dll"
	"$<TARGET_FILE_DIR:Sandbox>/SDL3.dll"
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/bin/Debug")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/bin/Release")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/bin/Dist")

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/bin/Debug")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/bin/Release")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/bin/Dist")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/bin/Debug")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/bin/Release")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/bin/Dist")