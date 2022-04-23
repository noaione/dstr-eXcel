message(STATUS "Adding Entrypoint")
add_executable(eXcelSystem main.cpp)
target_compile_features(eXcelSystem PRIVATE cxx_std_17)

# Implementation Library
message(STATUS "Adding Implementation Library")
add_library(IMPL_ARR STATIC impl/arraystruct.cpp)
add_library(IMPL_BASE STATIC impl/base.cpp)
add_library(IMPL_LL STATIC impl/linkedlist.cpp)

# Types and Struct
message(STATUS "Adding Types and Struct Library")
add_library(TYPES_CENTER STATIC types/center.cpp)
add_library(TYPES_DATE STATIC types/date.cpp)
add_library(TYPES_SUBJECT STATIC types/subject.cpp)

# Utilities and other
message(STATUS "Adding Utilities related Library")
add_library(UTILS_FILEIO STATIC utils/fileio.cpp)
add_library(UTILS_MENU STATIC utils/menu.cpp)
add_library(UTILS_UTIL STATIC utils/utils.cpp)

# Link libraries
message(STATUS "Linking Libraries")
target_link_libraries(eXcelSystem PRIVATE UTILS_FILEIO)
target_link_libraries(eXcelSystem PRIVATE UTILS_MENU)
target_link_libraries(eXcelSystem PRIVATE UTILS_UTIL)

target_link_libraries(eXcelSystem PRIVATE TYPES_CENTER)
target_link_libraries(eXcelSystem PRIVATE TYPES_DATE)
target_link_libraries(eXcelSystem PRIVATE TYPES_SUBJECT)

target_link_libraries(eXcelSystem PRIVATE IMPL_BASE)
target_link_libraries(eXcelSystem PRIVATE IMPL_ARR)
target_link_libraries(eXcelSystem PRIVATE IMPL_LL)
