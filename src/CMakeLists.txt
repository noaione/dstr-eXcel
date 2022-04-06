add_executable(eXcelSystem main.cpp)
target_compile_features(eXcelSystem PUBLIC cxx_std_17)

# Linked List Implementation
add_library(LL_IMPL STATIC linkedlist/impl.cpp)

# Array Struct Implementation

# Types and Struct
add_library(TYPES_DATE STATIC types/date.cpp)

# Link libraries
target_link_libraries(eXcelSystem LL_IMPL)
target_link_libraries(eXcelSystem TYPES_DATE)
