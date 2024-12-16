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
add_subdirectory(vendor/spdlog)
target_link_libraries(Fazon PUBLIC 
	spdlog
)

find_package(GameNetworkingSockets CONFIG REQUIRED)
target_link_libraries(Fazon PUBLIC 
    GameNetworkingSockets::GameNetworkingSockets
)