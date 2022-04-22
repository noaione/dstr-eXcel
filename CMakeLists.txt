cmake_minimum_required(VERSION 3.1)

# Project name and a few useful settings. Other commands can pick up the results
project(
    eXcelSystem
    VERSION 0.1
    DESCRIPTION "A tutor management system for eXcel Tuition Centre"
    LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

option(DEBUG_MODE "DebugMode" OFF)
option(ARRAY_STRUCT "ArrayStruct" OFF)
set(APP_NAME "eXcelSystem")

# Source code
add_subdirectory(src)

if(DEBUG_MODE)
    message(STATUS "Will build with Debug flags")
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DDEBUG")
    set(APP_NAME "${APP_NAME}_DEBUG")
endif()
if (ARRAY_STRUCT)
    message(STATUS "Will build Array Struct version")
    SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -DARRAY_STRUCT")
    set(APP_NAME "${GAME_NAME}_array")
else()
    message(STATUS "Will build Linked List version")
    SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS}")
    set(APP_NAME "${GAME_NAME}_linkedlist")
endif()
set_target_properties(eXcelSystem PROPERTIES OUTPUT_NAME "${GAME_NAME}")

SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -O1 -s")
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
