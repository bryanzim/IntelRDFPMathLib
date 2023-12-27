#Execute the IntelDFPTest
execute_process(COMMAND "${TEST_PATH}/${TEST_EXE}"
                INPUT_FILE "readtest.in"
                WORKING_DIRECTORY "${TEST_PATH}"
                ECHO_OUTPUT_VARIABLE
                ECHO_ERROR_VARIABLE
                COMMAND_ERROR_IS_FATAL ANY
               )