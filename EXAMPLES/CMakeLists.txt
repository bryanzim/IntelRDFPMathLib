if (IDFP_CALL_BY_REFERENCE)
    set(BIT2 "1")
else()
    set(BIT2 "0")
endif()
if (IDFP_GLOBAL_ROUNDING)
    set(BIT1 "1")
else()
    set(BIT1 "0")
endif()
if (IDFP_GLOBAL_EXCEPTION_FLAGS)
    set(BIT0 "1")
else()
    set(BIT0 "0")
endif()

set(EXAMPLE_VARIANT "${BIT2}${BIT1}${BIT0}")
configure_file("${CMAKE_CURRENT_SOURCE_DIR}/decimal.h_${EXAMPLE_VARIANT}"
               "${CMAKE_CURRENT_BINARY_DIR}/decimal.h" COPYONLY)
configure_file("${CMAKE_CURRENT_SOURCE_DIR}/main.c_${EXAMPLE_VARIANT}"
               "${CMAKE_CURRENT_BINARY_DIR}/main.c" COPYONLY)

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
idfp_apply_application_target_settings(IntelDFPExample)
idfp_apply_standard_output_dirs(IntelDFPExample)
idfp_link_libm_if_needed(IntelDFPExample)

if (CMAKE_C_COMPILER_ID STREQUAL "Clang" AND
    CMAKE_C_COMPILER_FRONTEND_VARIANT STREQUAL "MSVC")
    target_compile_options(IntelDFPExample PRIVATE "$<$<CONFIG:Debug>:/RTC->")
endif()

add_test(NAME IntelDFPExample
         COMMAND "${CMAKE_COMMAND}"
                 -DEXAMPLE_PATH=$<TARGET_FILE_DIR:IntelDFPExample>
                 -DEXAMPLE_EXE=$<TARGET_FILE:IntelDFPExample>
                 -P "${CMAKE_CURRENT_SOURCE_DIR}/example_test.cmake"
        )
