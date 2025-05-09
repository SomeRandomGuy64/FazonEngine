# Fazon/CMakeLists.txt
add_library(Fazon STATIC
    src/Fazon/Application.cpp
    src/Fazon/Application.h
    src/Fazon/Core.h
    src/Fazon/EntryPoint.h
    src/Fazon/Log.h
    src/Fazon/Log.cpp
	
    src/Fazon/KeyCodes.h
	src/Fazon/KeyCodes.cpp
    src/Fazon/MouseCodes.h
    src/Fazon/Input.h
    src/Fazon/InputState.h
    src/Fazon/InputState.cpp

    src/Fazon/Layer.cpp
    src/Fazon/Layer.h
    src/Fazon/LayerStack.cpp
    src/Fazon/LayerStack.h

    src/Fazon/Events/ApplicationEvent.h
    src/Fazon/Events/Event.h
    src/Fazon/Events/KeyEvent.h
    src/Fazon/Events/MouseEvent.h
    src/Fazon/Events/WindowEvent.h

    src/Fazon/Window.h

    src/Fazon/Platform/Windows/WindowsWindow.cpp
    src/Fazon/Platform/Windows/WindowsWindow.h

    src/Fazon/Platform/Windows/WindowsInput.h
    src/Fazon/Platform/Windows/WindowsInput.cpp

    src/Fazon/Platform/OpenGL/OpenGLContext.h
    src/Fazon/Platform/OpenGL/OpenGLContext.cpp

    src/Fazon/Platform/OpenGL/OpenGLBuffer.h
    src/Fazon/Platform/OpenGL/OpenGLBuffer.cpp

    src/Fazon/Platform/OpenGL/OpenGLShader.h
    src/Fazon/Platform/OpenGL/OpenGLShader.cpp

    src/Fazon/Platform/OpenGL/OpenGLVertexArray.h
    src/Fazon/Platform/OpenGL/OpenGLVertexArray.cpp

	src/Fazon/ImGui/ImGuiLayer.h
	src/Fazon/ImGui/ImGuiLayer.cpp
    src/Fazon/ImGui/ImGuiBuild.cpp

    src/Fazon/Renderer/RenderContext.h
    src/Fazon/Renderer/RenderContext.cpp

    src/Fazon/Renderer/Renderer.h
    src/Fazon/Renderer/Renderer.cpp

    src/Fazon/Renderer/Shader.h
    src/Fazon/Renderer/Shader.cpp

    src/Fazon/Renderer/Buffer.h
    src/Fazon/Renderer/Buffer.cpp

    src/Fazon/Renderer/VertexArray.h
    src/Fazon/Renderer/VertexArray.cpp

    src/Fazon/Networking/Server.h
    src/Fazon/Networking/Server.cpp

    src/Fazon/Networking/Client.h
    src/Fazon/Networking/Client.cpp
	
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
    src/Fazon/KeyCodes.h
	src/Fazon/KeyCodes.cpp
    src/Fazon/MouseCodes.h
    src/Fazon/Input.h
    src/Fazon/InputState.h
    src/Fazon/InputState.cpp
)

source_group("Fazon\\Events" FILES
    src/Fazon/Events/ApplicationEvent.h
    src/Fazon/Events/Event.h
    src/Fazon/Events/KeyEvent.h
    src/Fazon/Events/MouseEvent.h
    src/Fazon/Events/WindowEvent.h
)

source_group("Fazon\\ImGui" FILES
	src/Fazon/ImGui/ImGuiLayer.h
	src/Fazon/ImGui/ImGuiLayer.cpp
    src/Fazon/ImGui/ImGuiBuild.cpp
)

source_group("Fazon\\Platform\\Windows" FILES
    src/Fazon/Platform/Windows/WindowsWindow.cpp
    src/Fazon/Platform/Windows/WindowsWindow.h
    src/Fazon/Platform/Windows/WindowsInput.h
    src/Fazon/Platform/Windows/WindowsInput.cpp

)

source_group("Fazon\\Platform\\OpenGL" FILES
    src/Fazon/Platform/OpenGL/OpenGLContext.h
    src/Fazon/Platform/OpenGL/OpenGLContext.cpp
    src/Fazon/Platform/OpenGL/OpenGLBuffer.h
    src/Fazon/Platform/OpenGL/OpenGLBuffer.cpp
    src/Fazon/Platform/OpenGL/OpenGLShader.h
    src/Fazon/Platform/OpenGL/OpenGLShader.cpp
    src/Fazon/Platform/OpenGL/OpenGLVertexArray.h
    src/Fazon/Platform/OpenGL/OpenGLVertexArray.cpp
)

source_group("Fazon\\Renderer" FILES
    src/Fazon/Renderer/RenderContext.h
    src/Fazon/Renderer/RenderContext.cpp
    src/Fazon/Renderer/Shader.h
    src/Fazon/Renderer/Shader.cpp
    src/Fazon/Renderer/Buffer.h
    src/Fazon/Renderer/Buffer.cpp
    src/Fazon/Renderer/Renderer.h
    src/Fazon/Renderer/Renderer.cpp
    src/Fazon/Renderer/VertexArray.h
    src/Fazon/Renderer/VertexArray.cpp
)

source_group("Fazon\\Networking" FILES
    src/Fazon/Networking/Server.h
    src/Fazon/Networking/Server.cpp
    src/Fazon/Networking/Client.h
    src/Fazon/Networking/Client.cpp

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
# add_subdirectory(tests)

# Vendor dependencies
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(SPDLOG_FMT_EXTERNAL OFF CACHE BOOL "Use external fmt library instead of bundled" FORCE)

set(GLM_DIR "${CMAKE_CURRENT_SOURCE_DIR}/vendor/glm")
set(GLM_LIB_DIR "${CMAKE_SOURCE_DIR}/libs/glm")
include_directories("${GLM_DIR}")

set(SDL3_DIR "${CMAKE_CURRENT_SOURCE_DIR}/vendor/SDL")
set(SDL3_INCLUDE_DIR "${SDL3_DIR}/include")
set(SDL3_LIB_DIR "${CMAKE_SOURCE_DIR}/libs/SDL3")
include_directories(${SDL3_INCLUDE_DIR})

set(GLAD_DIR "${CMAKE_CURRENT_SOURCE_DIR}/vendor/glad")
set(GLAD_LIB_DIR "${CMAKE_SOURCE_DIR}/libs/glad")
set(GLAD_INCLUDE_DIR "${GLAD_DIR}/include")
include_directories(${GLAD_INCLUDE_DIR})

set(IMGUI_DIR "${CMAKE_SOURCE_DIR}/vendor/imgui")
set(IMGUI_LIB_DIR "${CMAKE_SOURCE_DIR}/libs/ImGui")
set(IMGUI_BACKEND_DIR "${IMGUI_DIR}/backends")
include_directories(${IMGUI_DIR})

add_subdirectory(vendor/spdlog)
add_subdirectory(vendor/SDL)
add_subdirectory(vendor/glad)
add_subdirectory(vendor/glm)

set_target_properties(spdlog PROPERTIES FOLDER "Dependencies")
set_target_properties(glm PROPERTIES FOLDER "Dependencies")
set_target_properties(SDL3-shared PROPERTIES FOLDER "Dependencies")
set_target_properties(SDL_uclibc PROPERTIES FOLDER "Dependencies")
set_target_properties(SDL3_test PROPERTIES FOLDER "Dependencies")
set_target_properties(glad PROPERTIES FOLDER "Dependencies")

target_link_libraries(Fazon PUBLIC
    spdlog
	"${GLM_LIB_DIR}/glm.lib"
    "${SDL3_LIB_DIR}/SDL3.lib"
	"${GLAD_LIB_DIR}/glad.lib"
	"${IMGUI_LIB_DIR}/ImGui.lib"
)

target_include_directories(Fazon PUBLIC vendor/asio/include)

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