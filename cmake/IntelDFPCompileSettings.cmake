# Shared compiler, platform, and runtime settings for Intel RDFP Math Lib targets.

function(idfp_detect_intel_compiler)
    if (CMAKE_C_COMPILER_ID MATCHES "^Intel")
        set(IntelCompiler ON PARENT_SCOPE)
    else()
        set(IntelCompiler OFF PARENT_SCOPE)
    endif()
endfunction()

function(idfp_set_static_runtime_and_link_flags)
    if (NOT IDFP_LINK_STATIC_RUNTIME)
        return()
    endif()

    if (CMAKE_C_COMPILER_ID STREQUAL "MSVC")
        set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>" PARENT_SCOPE)
    elseif (CMAKE_C_COMPILER_ID STREQUAL "Clang")
        if (WIN32)
            set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>" PARENT_SCOPE)
        else()
            add_compile_options("-static-libstdc++")
        endif()
    elseif (CMAKE_C_COMPILER_ID STREQUAL "GNU")
        add_compile_options("-static-libstdc++" "-static-libgcc")
    elseif (CMAKE_C_COMPILER_ID STREQUAL "Intel")
        # Intel Windows/Linux use project defaults.
    else()
        message(FATAL_ERROR "Unsupported compiler ${CMAKE_C_COMPILER_ID}")
    endif()

    if (NOT BUILD_SHARED_LIBS)
        if (CMAKE_C_COMPILER_ID STREQUAL "Clang" AND NOT CMAKE_C_COMPILER_FRONTEND_VARIANT STREQUAL "MSVC")
            add_compile_options("-static")
        elseif (CMAKE_C_COMPILER_ID STREQUAL "GNU")
            add_compile_options("-static")
        endif()
    endif()
endfunction()

function(idfp_apply_compiler_warning_flags target)
    if (IDFP_STRICT_CLANG_WARNINGS)
        if (CMAKE_C_COMPILER_ID STREQUAL "Clang")
            set(_idfp_f128_target FALSE)
            if (${target} STREQUAL "IntelDFPF128")
                set(_idfp_f128_target TRUE)
            endif()
            if (CMAKE_C_COMPILER_FRONTEND_VARIANT STREQUAL "MSVC")
                target_compile_options(${target} PRIVATE "/W4" "/WX")
                if (IDFP_EXTRA_STRICT_CLANG_WARNINGS AND NOT _idfp_f128_target)
                    # /Wall flags thousands of reserved-identifier hits in legacy headers; use
                    # Clang-specific diagnostics that we can fix incrementally instead.
                    target_compile_options(${target} PRIVATE
                        "-Wconversion"
                        "-Wno-sign-conversion"
                        "-Wno-shorten-64-to-32"
                        "-Wno-implicit-int-float-conversion"
                        "-Wimplicit-fallthrough"
                        "-Wformat=2")
                endif()
            else()
                target_compile_options(${target} PRIVATE
                    "-Wall" "-Wextra" "-Wpedantic" "-Werror")
                if (IDFP_EXTRA_STRICT_CLANG_WARNINGS AND NOT _idfp_f128_target)
                    target_compile_options(${target} PRIVATE
                        "-Wconversion"
                        "-Wno-sign-conversion"
                        "-Wno-shorten-64-to-32"
                        "-Wno-implicit-int-float-conversion"
                        "-Wimplicit-fallthrough"
                        "-Wformat=2")
                endif()
            endif()
        endif()
        return()
    endif()

    if (IntelCompiler)
        target_compile_options(${target} PRIVATE
            "-Qlong-double"
            "-Qpc80"
            "-Qstd=c99"
        )
        if (IDFP_LIBRARY_INTEL_EXTENDED_FLOAT)
            target_compile_options(${target} PRIVATE "-Qoption,cpp,--extended_float_types")
        endif()
        return()
    endif()

    if (CMAKE_C_COMPILER_ID STREQUAL "Clang")
        target_compile_options(${target} PRIVATE
            "-Wno-reserved-identifier"
            "-Wextra"
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
            target_compile_options(${target} PRIVATE
                "/wd4242" "/wd4244" "/wd4267" "/wd4305")
        endif()
    elseif (CMAKE_C_COMPILER_ID STREQUAL "GNU")
        target_compile_options(${target} PRIVATE "-Wextra")
    elseif (CMAKE_C_COMPILER_ID STREQUAL "MSVC")
        target_compile_options(${target} PRIVATE
            "/W3" "/WX"
            "/wd4242" "/wd4244" "/wd4267" "/wd4305"
            "/Zc:__cplusplus"
        )
    else()
        message(FATAL_ERROR "Unsupported compiler ${CMAKE_C_COMPILER_ID}")
    endif()
endfunction()

# float128 table headers use macro initializers that trigger -Wmissing-braces.
function(idfp_apply_float128_clang_relaxations target)
    if (NOT IDFP_STRICT_CLANG_WARNINGS)
        return()
    endif()
    if (NOT CMAKE_C_COMPILER_ID STREQUAL "Clang")
        return()
    endif()
    target_compile_options(${target} PRIVATE "-Wno-missing-braces")
    if (NOT IDFP_EXTRA_STRICT_CLANG_WARNINGS)
        target_compile_options(${target} PRIVATE "-Wno-sign-compare")
    endif()
endfunction()

function(idfp_apply_debug_info_flags target)
    if (CMAKE_C_COMPILER_ID STREQUAL "MSVC")
        target_compile_options(${target} PRIVATE "$<$<CONFIG:Debug,RelWithDebInfo>:/Zi>")
    elseif (CMAKE_C_COMPILER_ID STREQUAL "Clang")
        if (CMAKE_C_COMPILER_FRONTEND_VARIANT STREQUAL "MSVC")
            target_compile_options(${target} PRIVATE "$<$<CONFIG:Debug,RelWithDebInfo>:/Zi>")
        else()
            target_compile_options(${target} PRIVATE "$<$<CONFIG:Debug,RelWithDebInfo>:-g>")
        endif()
    elseif (CMAKE_C_COMPILER_ID STREQUAL "GNU")
        target_compile_options(${target} PRIVATE "$<$<CONFIG:Debug,RelWithDebInfo>:-g>")
    elseif (IntelCompiler)
        return()
    else()
        message(FATAL_ERROR "Unsupported compiler ${CMAKE_C_COMPILER_ID}")
    endif()
endfunction()

function(idfp_apply_platform_definitions target)
    if (CMAKE_C_BYTE_ORDER STREQUAL "BIG_ENDIAN")
        target_compile_definitions(${target} PRIVATE "BID_BIG_ENDIAN=1")
    else()
        target_compile_definitions(${target} PRIVATE "BID_BIG_ENDIAN=0")
    endif()

    if (UNIX AND APPLE)
        target_compile_definitions(${target} PRIVATE "LINUX" "darwin" "mach")
    elseif (CMAKE_SYSTEM_NAME MATCHES "(FreeBSD|OpenBSD|NetBSD)")
        target_compile_definitions(${target} PRIVATE "LINUX" "freebsd")
    elseif (UNIX AND NOT APPLE)
        target_compile_definitions(${target} PRIVATE "LINUX" "linux")
    elseif (WIN32)
        target_compile_definitions(${target} PRIVATE "WINDOWS" "WINT" "winnt")
    else()
        message(FATAL_ERROR "Undefined OS")
    endif()

    if (CMAKE_SIZEOF_VOID_P EQUAL 8)
        target_compile_definitions(${target} PRIVATE "efi2" "EFI2")
    else()
        target_compile_definitions(${target} PRIVATE "ia32" "IA32")
    endif()
endfunction()

function(idfp_apply_decimal_abi_definitions target)
    if (IDFP_CALL_BY_REFERENCE)
        target_compile_definitions(${target} PRIVATE "DECIMAL_CALL_BY_REFERENCE=1")
    else()
        target_compile_definitions(${target} PRIVATE "DECIMAL_CALL_BY_REFERENCE=0")
    endif()
    if (IDFP_GLOBAL_ROUNDING)
        target_compile_definitions(${target} PRIVATE "DECIMAL_GLOBAL_ROUNDING=1")
    else()
        target_compile_definitions(${target} PRIVATE "DECIMAL_GLOBAL_ROUNDING=0")
    endif()
    if (IDFP_GLOBAL_EXCEPTION_FLAGS)
        target_compile_definitions(${target} PRIVATE "DECIMAL_GLOBAL_EXCEPTION_FLAGS=1")
    else()
        target_compile_definitions(${target} PRIVATE "DECIMAL_GLOBAL_EXCEPTION_FLAGS=0")
    endif()
endfunction()

function(idfp_apply_library_target_settings target)
    idfp_apply_platform_definitions(${target})
    idfp_apply_decimal_abi_definitions(${target})
    idfp_apply_compiler_warning_flags(${target})
    idfp_apply_debug_info_flags(${target})

    if (CMAKE_SYSTEM_PROCESSOR MATCHES "^(arm|ARM|aarch64|AARCH64)")
        target_compile_definitions(${target} PRIVATE "__NO_BINARY80__")
    endif()

    if (USE_COMPILER_F80_TYPE)
        target_compile_definitions(${target} PRIVATE "USE_COMPILER_F80_TYPE=1")
    else()
        target_compile_definitions(${target} PRIVATE "USE_COMPILER_F80_TYPE=0")
    endif()

    if (USE_COMPILER_F128_TYPE)
        target_compile_definitions(${target} PRIVATE "USE_COMPILER_F128_TYPE=1")
    else()
        target_compile_definitions(${target} PRIVATE "USE_COMPILER_F128_TYPE=0")
    endif()
endfunction()

function(idfp_apply_application_target_settings target)
    idfp_apply_platform_definitions(${target})
    idfp_apply_decimal_abi_definitions(${target})
    idfp_apply_compiler_warning_flags(${target})
    idfp_apply_debug_info_flags(${target})

    if (CMAKE_C_COMPILER_ID STREQUAL "MSVC" OR CMAKE_C_COMPILER_ID STREQUAL "Clang")
        target_compile_definitions(${target} PRIVATE "_CRT_SECURE_NO_WARNINGS")
    endif()
endfunction()

function(idfp_apply_standard_output_dirs target)
    set_target_properties(${target} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY     "${CMAKE_BINARY_DIR}/bin"
        LIBRARY_OUTPUT_DIRECTORY     "${CMAKE_BINARY_DIR}/lib"
        ARCHIVE_OUTPUT_DIRECTORY     "${CMAKE_BINARY_DIR}/lib"
        PDB_OUTPUT_DIRECTORY         "${CMAKE_BINARY_DIR}/bin"
        COMPILE_PDB_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    )
endfunction()

function(idfp_link_libm_if_needed target)
    if (UNIX AND NOT APPLE)
        target_link_libraries(${target} PRIVATE m)
    endif()
endfunction()
