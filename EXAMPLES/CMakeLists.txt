cmake_minimum_required(VERSION 3.25)
project(Intel_Decimal_Floating_Point_Math_Example)

# Set Endianess
if (CMAKE_C_BYTE_ORDER STREQUAL "BIG_ENDIAN")
    add_compile_definitions("BID_BIG_ENDIAN=1")
else()
    add_compile_definitions("BID_BIG_ENDIAN=0")
endif()

# Add definitions based on options
if (CALL_BY_REFERENCE)
    set(BIT2 "1")    
else()
    set(BIT2 "0")
endif()
if (GLOBAL_ROUNDING)
    set(BIT1 "1")
else()
    set(BIT1 "0")
endif()
if (GLOBAL_EXCEPTIONS)
    set(BIT0 "1")
else()
    set(BIT0 "0")
endif()

# Set compiler specific defintions
if (CMAKE_C_COMPILER_ID STREQUAL "Clang")
    # Using Clang
    add_compile_options(#"-Wall"
                        "-Wextra"
                        #"-pedantic"
                        "-Wno-error=unused-command-line-argument"
                       )
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

# Create Example Headers
set(EXAMPLE_HEADERS
    "${CMAKE_CURRENT_SOURCE_DIR}/decimal.h"
   )

# Create Examnple Source
set(EXAMPLE_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/main.c"
   )

set(EXAMPLE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/decimal.h_${BIT2}${BIT1}${BIT0}"
    "${CMAKE_CURRENT_SOURCE_DIR}/main.c_${BIT2}${BIT1}${BIT0}"
   )

# Create files if necessary
add_custom_command(OUTPUT ${EXAMPLE_HEADERS} ${EXAMPLE_SOURCES}
                   COMMAND "${CMAKE_COMMAND}" ARGS "-E" "copy_if_different"
                           "${CMAKE_CURRENT_SOURCE_DIR}/decimal.h_${BIT2}${BIT1}${BIT0}"
                           "${CMAKE_CURRENT_SOURCE_DIR}/decimal.h"
                   COMMAND "${CMAKE_COMMAND}" ARGS "-E" "copy_if_different"
                           "${CMAKE_CURRENT_SOURCE_DIR}/main.c_${BIT2}${BIT1}${BIT0}"
                           "${CMAKE_CURRENT_SOURCE_DIR}/main.c"
                   DEPENDS ${EXAMPLE_DEPENDS}
                  )     

# Create Example Executable
add_executable(IntelDFPExample ${EXAMPLE_HEADERS} ${EXAMPLE_SOURCES})
target_link_libraries(IntelDFPExample PRIVATE IntelDFP)
   
# Set the output directory for build artifacts.
set_target_properties(IntelDFPExample PROPERTIES
                      RUNTIME_OUTPUT_DIRECTORY     "${CMAKE_BINARY_DIR}/bin"
                      LIBRARY_OUTPUT_DIRECTORY     "${CMAKE_BINARY_DIR}/lib"
                      ARCHIVE_OUTPUT_DIRECTORY     "${CMAKE_BINARY_DIR}/lib"
                      PDB_OUTPUT_DIRECTORY         "${CMAKE_BINARY_DIR}/bin"
                      COMPILE_PDB_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
                      DEBUG_POSTFIX                "d"
                     )

# Add a test for the example
add_test(NAME IntelDFPExample
         COMMAND "$<TARGET_FILE:IntelDFPExample>"
        )