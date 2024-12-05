cmake_minimum_required(VERSION 3.30)

project(FazonEngine 	VERSION 0.01
						DESCRIPTION "My first game engine"
						LANGUAGES CXX)
						
add_library(Fazon STATIC
	Fazon/src/Fazon/Application.cpp
	Fazon/src/Fazon/Application.h
	Fazon/src/Fazon/Core.h
	Fazon/src/Fazon/EntryPoint.h

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
	message(FATAL_ERROR "Fazon Engine only supports 64-bit")
endif()

target_include_directories(Sandbox PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/Fazon/src
)