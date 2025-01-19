cmake_minimum_required(VERSION 3.30)

project(glad LANGUAGES C)

set(GLAD_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(GLAD_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

set(GLAD_SOURCES ${GLAD_SRC_DIR}/glad.c)

add_library(glad STATIC ${GLAD_SOURCES})

target_include_directories(glad PUBLIC ${GLAD_INCLUDE_DIR})