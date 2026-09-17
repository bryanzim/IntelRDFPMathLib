# Run IntelDFPTest with the configured input file.
if(NOT TEST_EXE)
    message(FATAL_ERROR "TEST_EXE is not set")
endif()
if(NOT TEST_PATH)
    message(FATAL_ERROR "TEST_PATH is not set")
endif()
if(NOT TEST_INPUT)
    set(TEST_INPUT "${TEST_PATH}/readtest_smoke.in")
endif()

message(STATUS "IntelDFPTest working directory: ${TEST_PATH}")
message(STATUS "IntelDFPTest executable: ${TEST_EXE}")
message(STATUS "IntelDFPTest input: ${TEST_INPUT}")

if(NOT EXISTS "${TEST_INPUT}")
    message(FATAL_ERROR "Test input file not found: ${TEST_INPUT}")
endif()

execute_process(
    COMMAND "${TEST_EXE}"
    INPUT_FILE "${TEST_INPUT}"
    WORKING_DIRECTORY "${TEST_PATH}"
    RESULT_VARIABLE test_result
    OUTPUT_VARIABLE test_output
    ERROR_VARIABLE test_error
)

if(test_output)
    message(STATUS "${test_output}")
endif()
if(test_error)
    message(STATUS "${test_error}")
endif()

if(NOT test_result EQUAL 0)
    message(FATAL_ERROR "IntelDFPTest failed with exit code ${test_result}")
endif()
