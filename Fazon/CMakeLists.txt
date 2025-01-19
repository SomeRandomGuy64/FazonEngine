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

    src/Fazon/Window.h
    src/Fazon/Platform/Windows/WindowsWindow.cpp
    src/Fazon/Platform/Windows/WindowsWindow.h

    src/Fazon/Layer.cpp
    src/Fazon/Layer.h
    src/Fazon/LayerStack.cpp
    src/Fazon/LayerStack.h

    src/Fazon.h
)

source_group("Fazon" FILES
    src/Fazon/Application.cpp
    src/Fazon/Application.h
    src/Fazon/Core.h
    src/Fazon/EntryPoint.h
    src/Fazon/Log.h
    src/Fazon/Log.cpp
    src/Fazon/Window.h
    src/Fazon.h
	src/fzpch.h
    src/Fazon/Layer.cpp
    src/Fazon/Layer.h
    src/Fazon/LayerStack.cpp
    src/Fazon/LayerStack.h
)

source_group("Fazon\\Events" FILES
    src/Fazon/Events/ApplicationEvent.h
    src/Fazon/Events/Event.h
    src/Fazon/Events/KeyEvent.h
    src/Fazon/Events/MouseEvent.h
    src/Fazon/Events/WindowEvent.h
)

source_group("Fazon\\Platform\\Windows" FILES
    src/Fazon/Platform/Windows/WindowsWindow.cpp
    src/Fazon/Platform/Windows/WindowsWindow.h
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
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(SPDLOG_FMT_EXTERNAL OFF CACHE BOOL "Use external fmt library instead of bundled" FORCE)
set(SDL3_DIR "${CMAKE_CURRENT_SOURCE_DIR}/vendor/SDL")
set(SDL3_INCLUDE_DIR "${SDL3_DIR}/include")
set(SDL3_LIB_DIR "${CMAKE_SOURCE_DIR}/libs/SDL3")
include_directories(${SDL3_INCLUDE_DIR})

add_subdirectory(vendor/spdlog)
add_subdirectory(vendor/SDL)

set_target_properties(spdlog PROPERTIES FOLDER "Dependencies")
set_target_properties(SDL3-shared PROPERTIES FOLDER "Dependencies")
set_target_properties(SDL_uclibc PROPERTIES FOLDER "Dependencies")
set_target_properties(SDL3_test PROPERTIES FOLDER "Dependencies")

target_link_libraries(Fazon PRIVATE 
    spdlog
    "${SDL3_LIB_DIR}/SDL3.lib"
)

# Hide CMake generated files
set_target_properties(Fazon PROPERTIES 
    VS_JUST_MY_CODE_DEBUGGING ON
    EXCLUDE_FROM_ALL_BOM TRUE
)

source_group("CMake Generated Files" FILES 
    "${CMAKE_CURRENT_BINARY_DIR}/CMakeFiles/Fazon.dir/Debug/cmake_pch.hxx"
    "${CMAKE_CURRENT_BINARY_DIR}/CMakeFiles/Fazon.dir/Release/cmake_pch.hxx"
    "${CMAKE_CURRENT_BINARY_DIR}/CMakeFiles/Fazon.dir/Dist/cmake_pch.hxx"
    "${CMAKE_CURRENT_BINARY_DIR}/CMakeFiles/Fazon.dir/cmake_pch.cxx"
)