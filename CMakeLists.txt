cmake_minimum_required(VERSION 3.30)

project(FazonEngine 	VERSION 0.01
						DESCRIPTION "My first game engine"
						LANGUAGES CXX)

# Remove default build types and define custom ones
set(CMAKE_CONFIGURATION_TYPES Debug Release Dist CACHE STRING "Available configurations" FORCE)

# Set compiler flags for each configuration
set(CMAKE_C_FLAGS_DEBUG "-g" CACHE STRING "Debug build compiler flags" FORCE)         # Enable debug symbols
set(CMAKE_C_FLAGS_RELEASE "-O2 -DNDEBUG" CACHE STRING "Release build compiler flags" FORCE) # Optimization for Release
set(CMAKE_C_FLAGS_DIST "-O3 -DNDEBUG" CACHE STRING "Dist build compiler flags" FORCE)      # Maximum optimization for Dist

set(CMAKE_CXX_FLAGS_DEBUG "-g" CACHE STRING "Debug build compiler flags" FORCE)
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -DNDEBUG" CACHE STRING "Release build compiler flags" FORCE)
set(CMAKE_CXX_FLAGS_DIST "-O3 -DNDEBUG" CACHE STRING "Dist build compiler flags" FORCE)

add_library(Fazon STATIC
	Fazon/src/Fazon/Application.cpp
	Fazon/src/Fazon/Application.h
	Fazon/src/Fazon/Core.h
	Fazon/src/Fazon/EntryPoint.h
	Fazon/src/Fazon/Log.h
	Fazon/src/Fazon/Log.cpp

	Fazon/src/Fazon/Events/ApplicationEvent.h
	Fazon/src/Fazon/Events/Event.h
	Fazon/src/Fazon/Events/KeyEvent.h
	Fazon/src/Fazon/Events/MouseEvent.h
	Fazon/src/Fazon/Events/WindowEvent.h

	Fazon/src/Fazon.h
	)
target_include_directories(Fazon PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Fazon)
target_compile_features(Fazon PUBLIC cxx_std_23)
target_compile_options(Fazon PRIVATE
	$<$<CXX_COMPILER_ID:MSVC>:/W4 /WX>
)

add_executable(Sandbox
	Sandbox/src/SandboxApp.cpp
	)
target_link_libraries(Sandbox PUBLIC Fazon)
target_compile_options(Sandbox PRIVATE
	$<$<CXX_COMPILER_ID:MSVC>:/W4 /WX>
)

target_compile_definitions(Fazon PUBLIC 
	FAZON_VERSION="0.01"
)

# Platform selection
if(WIN32)
	target_compile_definitions(Fazon PUBLIC
		FZ_PLATFORM_WINDOWS
	)
else()
	message(FATAL_ERROR "Fazon Engine only supports Windows")
endif()

target_compile_definitions(Fazon PUBLIC
	$<$<CONFIG:Debug>:FZ_BUILD_DEBUG>
	$<$<CONFIG:Release>:FZ_BUILD_RELEASE>
	$<$<CONFIG:Dist>:FZ_BUILD_DIST>
)

target_include_directories(Sandbox PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/Fazon/src
) 

target_include_directories(Fazon PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/Fazon/src
)

find_package(Git QUIET)
# Check if Git is available and the vendor directory contains submodules
if (GIT_FOUND AND EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/Fazon/vendor/.git")
    # Update submodules as needed
    option(GIT_SUBMODULE "Check submodules during build" ON)
    if (GIT_SUBMODULE)
        message(STATUS "Updating all submodules in Fazon/vendor")
        execute_process(
            COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/Fazon/vendor
            RESULT_VARIABLE GIT_SUBMOD_RESULT
        )
        if (NOT GIT_SUBMOD_RESULT EQUAL 0)
            message(FATAL_ERROR "git submodule update --init --recursive failed with ${GIT_SUBMOD_RESULT}, please check out submodules manually.")
        endif()
    endif()
endif()

if (NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/Fazon/vendor/spdlog/.git")
    message(FATAL_ERROR "Submodules not properly initialized. Please run 'git submodule update --init --recursive'")
endif()

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Fazon/vendor/spdlog)
target_link_libraries(Fazon PUBLIC spdlog)