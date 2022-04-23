add_executable(eXcelSystem main.cpp)
target_compile_features(eXcelSystem PRIVATE cxx_std_17)

# Implementation Library
add_library(IMPL_ARR STATIC impl/arraystruct.cpp)
add_library(IMPL_BASE STATIC impl/base.cpp)
add_library(IMPL_LL STATIC impl/linkedlist.cpp)

# Types and Struct
add_library(TYPES_CENTER STATIC types/center.cpp)
add_library(TYPES_DATE STATIC types/date.cpp)
add_library(TYPES_SUBJECT STATIC types/subject.cpp)

# Utilities and other
add_library(UTILS_FILEIO STATIC utils/fileio.cpp)
add_library(UTILS_MENU STATIC utils/menu.cpp)
add_library(UTILS_UTIL STATIC utils/utils.cpp)

# Link libraries
target_link_libraries(
    eXcelSystem UTILS_FILEIO UTILS_MENU UTILS_UTIL
)
target_link_libraries(
    eXcelSystem TYPES_CENTER TYPES_DATE TYPES_SUBJECT
)
target_link_libraries(
    eXcelSystem IMPL_ARR IMPL_BASE IMPL_LL
)