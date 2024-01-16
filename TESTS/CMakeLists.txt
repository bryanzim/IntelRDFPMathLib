cmake_minimum_required(VERSION 3.25)
project(Intel_Decimal_Floating_Point_Math_Tests)

if (CMAKE_C_COMILER_ID MATCHES "^Intel")
    set(IntelCompiler ON)
else()
    set(IntelCompiler OFF)
endif()

# Set Endianess
if (CMAKE_C_BYTE_ORDER STREQUAL "BIG_ENDIAN")
    add_compile_definitions("BID_BIG_ENDIAN=1")
else()
    add_compile_definitions("BID_BIG_ENDIAN=0")
endif()

# Add definitions based on options
if (IDFP_CALL_BY_REFERENCE)
    add_compile_definitions("DECIMAL_CALL_BY_REFERENCE=1")    
else()
    add_compile_definitions("DECIMAL_CALL_BY_REFERENCE=0")
endif()
if (IDFP_GLOBAL_ROUNDING)
    add_compile_definitions("DECIMAL_GLOBAL_ROUNDING=1")
else()
    add_compile_definitions("DECIMAL_GLOBAL_ROUNDING=0")
endif()
if (IDFP_GLOBAL_EXCEPTIONS)
    add_compile_definitions("DECIMAL_GLOBAL_EXCEPTION_FLAGS=1")
else()
    add_compile_definitions("DECIMAL_GLOBAL_EXCEPTION_FLAGS=0")
endif()

# Set compiler specific defintions
if (IntelCompiler)
    # Using Intel compiler
    add_compile_options("-Qoption,cpp,--extended_float_types")
    add_compile_options("-Qlong-double" "-Qpc80" "-Qstd=c99")
elseif (CMAKE_C_COMPILER_ID STREQUAL "Clang")
    # Using Clang
    add_compile_definitions("_CRT_SECURE_NO_WARNINGS")
    #add_compile_options("-Wall")
    add_compile_options("-Wextra")
    #add_compile_options("-pedantic")
elseif (CMAKE_C_COMPILER_ID STREQUAL "GNU")
    # Using GCC
    #add_compile_options("-Wall")
    add_compile_options("-Wextra")
    #add_compile_options("-pedantic")
elseif (CMAKE_C_COMPILER_ID STREQUAL "MSVC")
    # Using MSVC
    add_compile_definitions("_CRT_SECURE_NO_WARNINGS")
    add_compile_options("/W3")
    add_compile_options("/WX")
    add_compile_options("/Zc:__cplusplus")
else()
    message(FATAL_ERROR "Unsupported compiler ${CMAKE_C_COMPILER_ID}")
endif()

# Add debugging info
if ((CMAKE_BUILD_TYPE STREQUAL "Debug") OR (CMAKE_BUILD_TYPE STREQUAL "RelWithDebInfo"))
    if (CMAKE_C_COMPILER_ID STREQUAL "MSVC")
        add_compile_options("/Zi")
    elseif (CMAKE_C_COMPILER_ID STREQUAL "Clang")
        add_compile_options("-g") 
    elseif (CMAKE_C_COMPILER_ID STREQUAL "GNU")
        add_compile_options("-g") 
    else()
        message(FATAL_ERROR "Unsupported compiler ${CMAKE_C_COMPILER_ID}")
    endif()
endif()

# Link with static C/C++ libraries
if (IDFP_LINK_STATIC_RUNTIME)
    if (CMAKE_C_COMPILER_ID STREQUAL "MSVC")
        set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
    elseif (CMAKE_C_COMPILER_ID STREQUAL "Clang")
        if (WIN32)
            set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
        else()
            add_compile_options("-static-libstdc++" "-static-libgcc")
        endif()
    elseif (CMAKE_C_COMPILER_ID STREQUAL "GNU")
        add_compile_options("-static-libstdc++" "-static-libgcc")
    else()
        message(FATAL_ERROR "Unsupported compiler ${CMAKE_C_COMPILER_ID}")
    endif()
endif()

# Add OS specific defintions
if (UNIX AND APPLE)
    add_compile_definitions("LINUX")
elseif (CMAKE_SYSTEM_NAME MATCHES "(FreeBSD|OpenBSD|NetBSD)")
    add_compile_definitions("LINUX")
elseif (UNIX AND NOT APPLE)
    add_compile_definitions("LINUX")
elseif (WIN32)
    add_compile_definitions("WINDOWS")
else()
    message(FATAL_ERROR "Undefined OS")
endif()

# Create Test Headers
set(TEST_HEADERS
    "readtest.h"
    "test_bid_conf.h"
    "test_bid_functions.h"
   )

# Create Test Source
set(TEST_SOURCES
    "readtest.c"
   )

# Create Test Executable
add_executable(IntelDFPTest ${TEST_HEADERS} ${TEST_SOURCES})
target_link_libraries(IntelDFPTest PRIVATE IntelDFP)
   
# Set the output directory for build artifacts.
set_target_properties(IntelDFPTest PROPERTIES
                      RUNTIME_OUTPUT_DIRECTORY     "${CMAKE_BINARY_DIR}/bin"
                      LIBRARY_OUTPUT_DIRECTORY     "${CMAKE_BINARY_DIR}/lib"
                      ARCHIVE_OUTPUT_DIRECTORY     "${CMAKE_BINARY_DIR}/lib"
                      PDB_OUTPUT_DIRECTORY         "${CMAKE_BINARY_DIR}/bin"
                      COMPILE_PDB_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
                      DEBUG_POSTFIX                "d"
                     )

# Copy the test file to the build directory
add_custom_command(TARGET IntelDFPTest POST_BUILD
                   COMMAND "${CMAKE_COMMAND}" -E copy_if_different
                           "${CMAKE_CURRENT_SOURCE_DIR}/readtest.in"
                           "${CMAKE_BINARY_DIR}/bin/readtest.in"
                  )

# Build executable name
set(TEST_EXECUTABLE "IntelDFPTest")
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(TEST_EXECUTABLE "${TEST_EXECUTABLE}d")
endif()

# Add a test
set(TEST_PATH "${CMAKE_BINARY_DIR}/bin")
add_test(NAME IntelDFPTest
         COMMAND "${CMAKE_COMMAND}" "-DTEST_PATH=${TEST_PATH}" "-DTEST_EXE=${TEST_EXECUTABLE}${CMAKE_EXECUTABLE_SUFFIX}" -P "${CMAKE_CURRENT_SOURCE_DIR}/test.cmake"
        )