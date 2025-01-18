# cmake/build_definitions.cmake/build_definitions

# Build type specific definitions
add_compile_definitions(
    $<$<CONFIG:Debug>:FZ_BUILD_DEBUG>
	$<$<CONFIG:Debug>:FZ_ENABLE_ASSERTS>
	
    $<$<CONFIG:Release>:FZ_BUILD_RELEASE>
	
    $<$<CONFIG:Dist>:FZ_BUILD_DIST>
	
)