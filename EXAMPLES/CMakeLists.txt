cmake_minimum_required(VERSION 3.25)
project(Intel_Decimal_Floating_Point_Math_Example LANGUAGES C)

# Set Endianess
if (CMAKE_C_BYTE_ORDER STREQUAL "BIG_ENDIAN")
    add_compile_definitions("BID_BIG_ENDIAN=1")
else()
    add_compile_definitions("BID_BIG_ENDIAN=0")
endif()

# Add definitions based on options (must match LIBRARY/TESTS ABI)
if (IDFP_CALL_BY_REFERENCE)
    set(BIT2 "1")
    add_compile_definitions("DECIMAL_CALL_BY_REFERENCE=1")
else()
    set(BIT2 "0")
    add_compile_definitions("DECIMAL_CALL_BY_REFERENCE=0")
endif()
if (IDFP_GLOBAL_ROUNDING)
    set(BIT1 "1")
    add_compile_definitions("DECIMAL_GLOBAL_ROUNDING=1")
else()
    set(BIT1 "0")
    add_compile_definitions("DECIMAL_GLOBAL_ROUNDING=0")
endif()
if (IDFP_GLOBAL_EXCEPTION_FLAGS)
    set(BIT0 "1")
    add_compile_definitions("DECIMAL_GLOBAL_EXCEPTION_FLAGS=1")
else()
    set(BIT0 "0")
    add_compile_definitions("DECIMAL_GLOBAL_EXCEPTION_FLAGS=0")
endif()

# Set compiler specific defintions
if (CMAKE_C_COMPILER_ID STREQUAL "Clang")
    # Using Clang / ClangCL
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

# Add OS specific defintions (match LIBRARY/TESTS so headers agree with the lib)
if (UNIX AND APPLE)
    add_compile_definitions("LINUX")
elseif (CMAKE_SYSTEM_NAME MATCHES "(FreeBSD|OpenBSD|NetBSD)")
    add_compile_definitions("LINUX")
elseif (UNIX AND NOT APPLE)
    add_compile_definitions("LINUX")
elseif (WIN32)
    add_compile_definitions("WINDOWS" "WINT" "winnt")
else()
    message(FATAL_ERROR "Undefined OS")
endif()

if (CMAKE_SIZEOF_VOID_P EQUAL 8)
    add_compile_definitions("efi2" "EFI2")
else()
    add_compile_definitions("ia32" "IA32")
endif()

set(EXAMPLE_VARIANT "${BIT2}${BIT1}${BIT0}")
configure_file("${CMAKE_CURRENT_SOURCE_DIR}/decimal.h_${EXAMPLE_VARIANT}"
               "${CMAKE_CURRENT_BINARY_DIR}/decimal.h" COPYONLY)
configure_file("${CMAKE_CURRENT_SOURCE_DIR}/main.c_${EXAMPLE_VARIANT}"
               "${CMAKE_CURRENT_BINARY_DIR}/main.c" COPYONLY)

# Create Example Executable
add_executable(IntelDFPExample
    "${CMAKE_CURRENT_BINARY_DIR}/main.c"
    "${CMAKE_CURRENT_BINARY_DIR}/decimal.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/example_shim.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/example_shim.h")
target_include_directories(IntelDFPExample PRIVATE
    "${CMAKE_CURRENT_BINARY_DIR}"
    "${CMAKE_CURRENT_SOURCE_DIR}"
    "${CMAKE_SOURCE_DIR}/LIBRARY/src")
target_compile_definitions(IntelDFPExample PRIVATE "INTEL_DFP_USE_EXAMPLE_SHIM=1")
target_link_libraries(IntelDFPExample PRIVATE IntelDFP)

# ClangCL /RTC checks in the example can fault when calling into the static library.
if (CMAKE_C_COMPILER_ID STREQUAL "Clang" AND
    CMAKE_C_COMPILER_FRONTEND_VARIANT STREQUAL "MSVC")
    target_compile_options(IntelDFPExample PRIVATE "$<$<CONFIG:Debug>:/RTC->")
endif()
   
# Set the output directory for build artifacts.
set_target_properties(IntelDFPExample PROPERTIES
                      RUNTIME_OUTPUT_DIRECTORY     "${CMAKE_BINARY_DIR}/bin"
                      LIBRARY_OUTPUT_DIRECTORY     "${CMAKE_BINARY_DIR}/lib"
                      ARCHIVE_OUTPUT_DIRECTORY     "${CMAKE_BINARY_DIR}/lib"
                      PDB_OUTPUT_DIRECTORY         "${CMAKE_BINARY_DIR}/bin"
                      COMPILE_PDB_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
                     )

add_test(NAME IntelDFPExample
         COMMAND "${CMAKE_COMMAND}"
                 -DEXAMPLE_PATH=$<TARGET_FILE_DIR:IntelDFPExample>
                 -DEXAMPLE_EXE=$<TARGET_FILE:IntelDFPExample>
                 -P "${CMAKE_CURRENT_SOURCE_DIR}/example_test.cmake"
        )