cmake_minimum_required(VERSION 3.25)
project(Intel_Decimal_Floating_Point_Math)

# Set required C++ standard which will cause appropriate compile flags per generator
if (MSVC)
    set(CMAKE_C_STANDARD 17)
else()
    set(CMAKE_C_STANDARD 23)
endif()
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# Define options
option(CALL_BY_REFERENCE 
       "Whether to pass function arguments and return values by reference or value" ON)
option(GLOBAL_ROUNDING
       "Whether the rounding option is stored in global varibale '_IDEC_round __bid_IDEC_glbround;'" OFF)
option(GLOBAL_EXCEPTION_FLAGS
       "Whether exceptions are stored a global varibale '_IDEC_flags __bid_IDEC_glbflags;'" OFF)
option(BUILD_TESTS "Whether to build the tests or not" ON)
option(BUILD_EXAMPLES "Whether to build the examples or not" ON)
option(BUILD_SHARED_LIBS "Whether to build libs as shared" OFF)

if (BUILD_TESTS)
    # Enable testing for CTest
    enable_testing()
endif()

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()

# Add subdirectories
add_subdirectory("LIBRARY")
if (BUILD_TESTS)
    add_subdirectory("TESTS")
endif()
if (BUILD_EXAMPLES)
    add_subdirectory("EXAMPLES")
endif()

