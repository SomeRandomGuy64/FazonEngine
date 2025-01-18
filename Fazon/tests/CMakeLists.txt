# Fazon/tests/CMakeLists.txt
add_executable(FazonTest
	src/MainTestRunner.cpp
	
	src/Events/ApplicationEventTests.cpp
	src/Events/KeyEventTests.cpp
	src/Events/MouseEventTests.cpp
	src/Events/WindowEventTests.cpp
)

source_group("Tests" FILES
    src/MainTestRunner.cpp
)

source_group("Tests\\Events" FILES
    src/Events/ApplicationEventTests.cpp
    src/Events/KeyEventTests.cpp
    src/Events/MouseEventTests.cpp
    src/Events/WindowEventTests.cpp
)

# Link against Fazon library and Catch2
set(SPDLOG_FMT_EXTERNAL OFF CACHE BOOL "Use external fmt library instead of bundled" FORCE)
target_link_libraries(FazonTest PRIVATE
	Fazon
	spdlog
	Catch2::Catch2WithMain
)

# Include Fazon and Catch2 headers
target_include_directories(FazonTest PRIVATE
	${CMAKE_SOURCE_DIR}/Fazon/src
	${CMAKE_SOURCE_DIR}/vendor/catch2/src
)

# Explicitly include Catch2's CMake module path
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/vendor/catch2/extras")

# Add test to CTest
include(CTest)
include(Catch)
catch_discover_tests(FazonTest)

# Compiler-specific settings
if(MSVC)
	target_compile_options(FazonTest PRIVATE
		/W3
	)
endif()

# Hide CMake generated files
set_target_properties(FazonTest PROPERTIES 
    VS_JUST_MY_CODE_DEBUGGING ON
    EXCLUDE_FROM_ALL_BOM TRUE
)

source_group("CMake Generated Files" FILES 
    "${CMAKE_CURRENT_BINARY_DIR}/CMakeFiles/FazonTest.dir/Debug/cmake_pch.hxx"
    "${CMAKE_CURRENT_BINARY_DIR}/CMakeFiles/FazonTest.dir/Release/cmake_pch.hxx"
    "${CMAKE_CURRENT_BINARY_DIR}/CMakeFiles/FazonTest.dir/Dist/cmake_pch.hxx"
    "${CMAKE_CURRENT_BINARY_DIR}/CMakeFiles/FazonTest.dir/cmake_pch.cxx"
)