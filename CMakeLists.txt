cmake_minimum_required(VERSION 3.25)
if (POLICY CMP0091)
    cmake_policy(SET CMP0091 NEW)  # Needed for CMAKE_MSVC_RUNTIME_LIBRARY
endif()

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(IntelDFPCompileSettings)

# VS always injects CMAKE_CXX_COMPILER even for C projects; accept CXX so
# configure does not warn and the IDE can attach a startup target.
project(Intel_Decimal_Floating_Point_Math LANGUAGES C CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set required C standard which will cause appropriate compile flags per generator
if ((CMAKE_C_COMPILER_ID STREQUAL "MSVC") OR (CMAKE_C_COMPILER_ID STREQUAL "Clang"))
    set(CMAKE_C_STANDARD 17)
    set(CMAKE_CXX_STANDARD 17)
else()
    set(CMAKE_C_STANDARD 23)
    set(CMAKE_CXX_STANDARD 23)
endif()
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_CXX_EXTENSIONS OFF)

if (MSVC)
    set_property(GLOBAL PROPERTY USE_FOLDERS ON) # turn on folder hierarchies
endif()

idfp_detect_intel_compiler()
idfp_set_static_runtime_and_link_flags()

# Define options
option(IDFP_CALL_BY_REFERENCE
       "Whether to pass function arguments and return values by reference or value" OFF)
option(IDFP_GLOBAL_ROUNDING
       "Whether the rounding option is stored in global varibale '_IDEC_round __bid_IDEC_glbround;'" OFF)
option(IDFP_GLOBAL_EXCEPTION_FLAGS
       "Whether exceptions are stored a global varibale '_IDEC_flags __bid_IDEC_glbflags;'" OFF)
option(IDFP_BUILD_TESTS "Whether to build the tests or not" ON)
option(IDFP_BUILD_EXAMPLES "Whether to build the examples or not" ON)
option(IDFP_BUILD_SHARED_LIBS "Whether to build libs as shared" OFF)
option(IDFP_LINK_STATIC_RUNTIME "Whether to use the C/C++ static linked runtime libraries" ON)
option(IDFP_ENABLE_INSTALL "Install IntelDFP targets and headers" ON)
option(IDFP_STRICT_CLANG_WARNINGS "Use strict Clang/ClangCL warning flags (no suppressions)" OFF)

# Drive CMake's standard shared-library switch from the project option.
set(BUILD_SHARED_LIBS ${IDFP_BUILD_SHARED_LIBS})

if (IDFP_BUILD_TESTS)
    enable_testing()
endif()

# Single-config generators (Ninja, Makefiles) need CMAKE_BUILD_TYPE.
# Visual Studio is multi-config and ignores it; setting it confuses VS.
if(NOT CMAKE_CONFIGURATION_TYPES AND NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()

add_subdirectory("LIBRARY")
if (IDFP_BUILD_TESTS)
    add_subdirectory("TESTS")
endif()
if (IDFP_BUILD_EXAMPLES)
    add_subdirectory("EXAMPLES")
endif()

if (TARGET IntelDFPExample)
    set_property(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}" PROPERTY VS_STARTUP_PROJECT IntelDFPExample)
elseif (TARGET IntelDFPTest)
    set_property(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}" PROPERTY VS_STARTUP_PROJECT IntelDFPTest)
endif()
