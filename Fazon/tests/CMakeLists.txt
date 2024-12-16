# Fazon/tests/CMakeLists.txt
add_executable(FazonTest
	src/MainTestRunner.cpp
	src/LogTests.cpp
	
	src/Events/ApplicationEventTests.cpp
	src/Events/KeyEventTests.cpp
	src/Events/MouseEventTests.cpp
	src/Events/WindowEventTests.cpp
)

# Link against Fazon library and Catch2
target_link_libraries(FazonTest PRIVATE
	Fazon
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
		/W4
		/WX
	)
else()
	target_compile_options(FazonTest PRIVATE
		-Wall
		-Wextra
		-Werror
	)
endif()