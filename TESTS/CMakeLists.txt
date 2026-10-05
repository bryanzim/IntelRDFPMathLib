set(TEST_HEADERS
    "readtest.h"
    "test_bid_conf.h"
    "test_bid_functions.h"
)

set(TEST_SOURCES
    "readtest.c"
)

add_executable(IntelDFPTest ${TEST_HEADERS} ${TEST_SOURCES})
target_link_libraries(IntelDFPTest PRIVATE IntelDFP)
idfp_apply_application_target_settings(IntelDFPTest)
idfp_apply_standard_output_dirs(IntelDFPTest)
idfp_link_libm_if_needed(IntelDFPTest)

add_custom_command(TARGET IntelDFPTest POST_BUILD
                   COMMAND "${CMAKE_COMMAND}" -E copy_if_different
                           "${CMAKE_CURRENT_SOURCE_DIR}/readtest_smoke.in"
                           "$<TARGET_FILE_DIR:IntelDFPTest>/readtest_smoke.in"
                   COMMAND "${CMAKE_COMMAND}" -E copy_if_different
                           "${CMAKE_CURRENT_SOURCE_DIR}/readtest.in"
                           "$<TARGET_FILE_DIR:IntelDFPTest>/readtest.in"
                  )

add_test(NAME IntelDFPTest
         COMMAND "${CMAKE_COMMAND}"
                 -DTEST_PATH=$<TARGET_FILE_DIR:IntelDFPTest>
                 -DTEST_EXE=$<TARGET_FILE:IntelDFPTest>
                 -DTEST_INPUT=$<TARGET_FILE_DIR:IntelDFPTest>/readtest_smoke.in
                 -P "${CMAKE_CURRENT_SOURCE_DIR}/test.cmake"
        )
