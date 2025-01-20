# cmake/submodules.cmake

find_package(Git QUIET)

# Function to initialise and update submodules
function(initialise_submodules)
    if(NOT GIT_FOUND)
        message(WARNING "Git not found. Unable to initialise submodules.")
        return()
    endif()

    # Potential vendor directories to check
    set(VENDOR_DIRS 
        "${CMAKE_CURRENT_SOURCE_DIR}/Fazon/vendor"
        "${CMAKE_CURRENT_SOURCE_DIR}/vendor"
    )

    foreach(VENDOR_DIR ${VENDOR_DIRS})
        if(EXISTS "${VENDOR_DIR}/.git")
            message(STATUS "Updating submodules in ${VENDOR_DIR}")
            execute_process(
                COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                WORKING_DIRECTORY ${VENDOR_DIR}
                RESULT_VARIABLE GIT_SUBMOD_RESULT
            )

            if(NOT GIT_SUBMOD_RESULT EQUAL 0)
                message(FATAL_ERROR "Git submodule update failed in ${VENDOR_DIR}")
            endif()
        endif()
    endforeach()
endfunction()

# Function to validate critical submodules
function(validate_critical_submodules)
    set(CRITICAL_SUBMODULES
        "${CMAKE_CURRENT_SOURCE_DIR}/Fazon/vendor/spdlog/.git"
        "${CMAKE_CURRENT_SOURCE_DIR}/Fazon/vendor/SDL/.git"
        "${CMAKE_CURRENT_SOURCE_DIR}/vendor/imgui/imgui/.git"
        "${CMAKE_CURRENT_SOURCE_DIR}/vendor/catch2/.git"
    )

    foreach(SUBMODULE ${CRITICAL_SUBMODULES})
        if(NOT EXISTS "${SUBMODULE}")
            message(FATAL_ERROR "Critical submodule not found: ${SUBMODULE}. Run 'git submodule update --init --recursive'")
        endif()
    endforeach()
endfunction()

# Call submodule initialization and validation functions
initialise_submodules()
validate_critical_submodules()