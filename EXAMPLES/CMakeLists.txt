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

# Create Example Headers
set(EXAMPLE_HEADERS
    "decimal.h"
   )

# Create Examnple Source
set(EXAMPLE_SOURCES
    "main.c"
   )

# Copy the files once during CMake generation
execute_process(COMMAND "${CMAKE_COMMAND}" -E copy_if_different
                        "${CMAKE_CURRENT_SOURCE_DIR}/decimal.h_${BIT2}${BIT1}${BIT0}"
                        "${CMAKE_CURRENT_SOURCE_DIR}/decimal.h"
               )
execute_process(COMMAND "${CMAKE_COMMAND}" -E copy_if_different
                        "${CMAKE_CURRENT_SOURCE_DIR}/main.c_${BIT2}${BIT1}${BIT0}"
                        "${CMAKE_CURRENT_SOURCE_DIR}/main.c"
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
         COMMAND IntelDFPExample
        )