if(NOT EXAMPLE_EXE)
    message(FATAL_ERROR "EXAMPLE_EXE is not set")
endif()
if(NOT EXAMPLE_PATH)
    message(FATAL_ERROR "EXAMPLE_PATH is not set")
endif()

message(STATUS "IntelDFPExample working directory: ${EXAMPLE_PATH}")
message(STATUS "IntelDFPExample executable: ${EXAMPLE_EXE}")

execute_process(
    COMMAND "${EXAMPLE_EXE}"
    WORKING_DIRECTORY "${EXAMPLE_PATH}"
    RESULT_VARIABLE example_result
    OUTPUT_VARIABLE example_output
    ERROR_VARIABLE example_error
)

if(example_output)
    message(STATUS "${example_output}")
endif()
if(example_error)
    message(STATUS "${example_error}")
endif()

if(NOT example_result EQUAL 0)
    message(FATAL_ERROR "IntelDFPExample failed with exit code ${example_result}")
endif()
