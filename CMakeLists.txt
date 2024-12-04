cmake_minimum_required(VERSION 3.30)

project(FazoneEngine 	VERSION 0.01
						DESCRIPTION "My first game engine"
						LANGUAGES CXX)
						
add_library(Fazon STATIC
	Fazon/Application.cpp
	Fazon/Application.h
	Fazon/src/Fazon/Core.h
	)
target_include_directories(Fazon PUBLIC include)
target_compile_features(Fazon PUBLIC cxx_std_23)

add_executable(Sandbox
	Sandbox/src/Application.cpp
	)
target_link_libraries(Sandbox PUBLIC Fazon)