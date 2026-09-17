cmake_minimum_required(VERSION 3.25)
project(Intel_Decimal_Floating_Point_Math_Tests LANGUAGES C)

if (CMAKE_C_COMPILER_ID MATCHES "^Intel")
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
if (IDFP_GLOBAL_EXCEPTION_FLAGS)
    add_compile_definitions("DECIMAL_GLOBAL_EXCEPTION_FLAGS=1")
else()
    add_compile_definitions("DECIMAL_GLOBAL_EXCEPTION_FLAGS=0")
endif()

# Set compiler specific defintions
if (IntelCompiler)
    # Using Intel compiler
    add_compile_options("-Qoption,cpp,--extended_float_types"
                        "-Qlong-double"
                        "-Qpc80"
                        "-Qstd=c99"
                       )
elseif (CMAKE_C_COMPILER_ID STREQUAL "Clang")
    # Using Clang / ClangCL
    add_compile_definitions("_CRT_SECURE_NO_WARNINGS")
    add_compile_options(#"-Wall"
                        "-Wextra"
                        #"-pedantic"
                        "-Wno-error=unused-command-line-argument"
                        "-Wno-missing-braces"
                        "-Wno-missing-field-initializers"
                        "-Wno-unused-but-set-variable"
                        "-Wno-sign-compare"
                        "-Wno-sometimes-uninitialized"
                        "-Wno-constant-conversion"
                        "-Wno-unterminated-string-initialization"
                        "-Wno-comment"
                        "-Wno-misleading-indentation"
                       )
    if (CMAKE_C_COMPILER_FRONTEND_VARIANT STREQUAL "MSVC")
        add_compile_options("/wd4242"
                            "/wd4244"
                            "/wd4267"
                            "/wd4305")
    endif()
elseif (CMAKE_C_COMPILER_ID STREQUAL "GNU")
    # Using GCC
    add_compile_options(#"-Wall"
                        "-Wextra"
                        #"-pedantic"
                       )
elseif (CMAKE_C_COMPILER_ID STREQUAL "MSVC")
    # Using MSVC
    add_compile_definitions("_CRT_SECURE_NO_WARNINGS")
    add_compile_options("/W3"
                        "/WX"
                        "/wd4242"
                        "/wd4244"
                        "/wd4267"
                        "/wd4305"
                        "/Zc:__cplusplus"
                       )
else()
    message(FATAL_ERROR "Unsupported compiler ${CMAKE_C_COMPILER_ID}")
endif()

# Add debugging info
if (CMAKE_C_COMPILER_ID STREQUAL "MSVC")
    add_compile_options("$<$<CONFIG:Debug,RelWithDebInfo>:/Zi>")
elseif (CMAKE_C_COMPILER_ID STREQUAL "Clang")
    if (CMAKE_C_COMPILER_FRONTEND_VARIANT STREQUAL "MSVC")
        add_compile_options("$<$<CONFIG:Debug,RelWithDebInfo>:/Zi>")
    else()
        add_compile_options("$<$<CONFIG:Debug,RelWithDebInfo>:-g>")
    endif()
elseif (CMAKE_C_COMPILER_ID STREQUAL "GNU")
    add_compile_options("$<$<CONFIG:Debug,RelWithDebInfo>:-g>")
else()
    message(FATAL_ERROR "Unsupported compiler ${CMAKE_C_COMPILER_ID}")
endif()

# Link with static C/C++ libraries
if (IDFP_LINK_STATIC_RUNTIME)
    if (CMAKE_C_COMPILER_ID STREQUAL "MSVC")
        set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
    elseif (CMAKE_C_COMPILER_ID STREQUAL "Clang")
        if (WIN32)
            set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
        else()
            add_compile_options("-static-libstdc++")
            # add_compile_options("-lstdc++")
        endif()
    elseif (CMAKE_C_COMPILER_ID STREQUAL "GNU")
        add_compile_options("-static-libstdc++" "-static-libgcc")
        # add_compile_options("-lstdc++" "-lgcc")
    else()
        message(FATAL_ERROR "Unsupported compiler ${CMAKE_C_COMPILER_ID}")
    endif()
endif()

# Enable static flag
if (NOT BUILD_SHARED_LIBS)
    if (CMAKE_C_COMPILER_ID STREQUAL "MSVC")
    elseif (CMAKE_C_COMPILER_ID STREQUAL "Clang")
    	if (CMAKE_C_COMPILER_FRONTEND_VARIANT STREQUAL "MSVC")
        else()
            add_compile_options("-static")
        endif()
    elseif (CMAKE_C_COMPILER_ID STREQUAL "GNU")
        add_compile_options("-static")
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
                     )

# Copy test inputs next to the executable (VS multi-config safe).
add_custom_command(TARGET IntelDFPTest POST_BUILD
                   COMMAND "${CMAKE_COMMAND}" -E copy_if_different
                           "${CMAKE_CURRENT_SOURCE_DIR}/readtest_smoke.in"
                           "$<TARGET_FILE_DIR:IntelDFPTest>/readtest_smoke.in"
                   COMMAND "${CMAKE_COMMAND}" -E copy_if_different
                           "${CMAKE_CURRENT_SOURCE_DIR}/readtest.in"
                           "$<TARGET_FILE_DIR:IntelDFPTest>/readtest.in"
                  )

# CTest smoke suite: fast, stable checks used by CI and IDE test runs.
add_test(NAME IntelDFPTest
         COMMAND "${CMAKE_COMMAND}"
                 -DTEST_PATH=$<TARGET_FILE_DIR:IntelDFPTest>
                 -DTEST_EXE=$<TARGET_FILE:IntelDFPTest>
                 -DTEST_INPUT=$<TARGET_FILE_DIR:IntelDFPTest>/readtest_smoke.in
                 -P "${CMAKE_CURRENT_SOURCE_DIR}/test.cmake"
        )