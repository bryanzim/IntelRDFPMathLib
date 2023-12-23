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

# Set compiler specific defintions
if (CMAKE_C_COMPILER_ID STREQUAL "Clang")
    # using Clang
    add_compile_options("-Wall")
elseif (CMAKE_C_COMPILER_ID STREQUAL "GNU")
    # using GCC
    add_compile_options("-Wall")
elseif (CMAKE_C_COMPILER_ID STREQUAL "MSVC")
    # using MSVC
    add_compile_options("/Wall")
else()
endif()

# Create Example Headers
set(EXAMPLE_HEADERS
    "decimal.h"
   )

# Create Examnple Source
set(EXAMPLE_SOURCE
    "main.c"
   )

# Copy the appropriate files to build
execute_process(COMMAND ${CMAKE_COMMAND} -E copy_if_different
                "${CMAKE_CURRENT_SOURCE_DIR}/decimal.h_${BIT2}${BIT1}${BIT0}"
                "${CMAKE_CURRENT_SOURCE_DIR}/decimal.h"
               )
execute_process(COMMAND ${CMAKE_COMMAND} -E copy_if_different
                "${CMAKE_CURRENT_SOURCE_DIR}/main.c_${BIT2}${BIT1}${BIT0}"
                "${CMAKE_CURRENT_SOURCE_DIR}/main.c"
               )

# Create Example Executable
add_executable(IntelDFPExample ${EXAMPLE_SOURCE} ${EXAMPLE_HEADERS})
target_link_libraries(IntelDFPExample PRIVATE IntelDFP)
   
# Set the output directory for build artifacts.
set_target_properties(IntelDFPExample PROPERTIES
                      RUNTIME_OUTPUT_DIRECTORY     "${CMAKE_BINARY_DIR}/bin"
                      LIBRARY_OUTPUT_DIRECTORY     "${CMAKE_BINARY_DIR}/lib"
                      ARCHIVE_OUTPUT_DIRECTORY     "${CMAKE_BINARY_DIR}/lib"
                      PDB_OUTPUT_DIRECTORY         "${CMAKE_BINARY_DIR}/bin"
                      COMPILE_PDB_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
                     )
                     
# Erase the copied files
add_custom_command(TARGET IntelDFPExample POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E remove
                   "${CMAKE_CURRENT_SOURCE_DIR}/decimal.h"
                  )
add_custom_command(TARGET IntelDFPExample POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E remove
                   "${CMAKE_CURRENT_SOURCE_DIR}/main.c"
                  )

# Add a test for the example
add_test(NAME IntelDFPExample
         COMMAND IntelDFPExample
        )