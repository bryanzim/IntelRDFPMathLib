cmake_minimum_required(VERSION 3.25)
project(Intel_Decimal_Floating_Point_Math_Library)

if (CMAKE_C_COMILER_ID MATCHES "^Intel")
    set(IntelCompiler ON)
else()
    set(IntelCompiler OFF)
endif()

# Use special types only under Intel Compiler
if (IntelCompiler)
    SET(USE_COMPILER_F128_TYPE ON)
    SET(USE_COMPILER_F80_TYPE ON)
else()
    SET(USE_COMPILER_F128_TYPE OFF)
    SET(USE_COMPILER_F80_TYPE OFF)
endif()

# Set floating point 80 bit definitions
if (USE_COMPILER_F80_TYPE)
    add_compile_definitions("USE_COMPILER_F80_TYPE=1")
else()
    add_compile_definitions("USE_COMPILER_F80_TYPE=0")
endif()

# Set floating point 128 bit definitions
if (USE_COMPILER_F128_TYPE)
    add_compile_definitions("USE_COMPILER_F128_TYPE=1")
    if (IntelCompiler)
        add_compile_options("-Qoption,cpp,--extended_float_types")
    endif()
else()
    add_compile_definitions("USE_COMPILER_F128_TYPE=0")
endif()

# Set Endianess
if (CMAKE_C_BYTE_ORDER STREQUAL "BIG_ENDIAN" OR CMAKE_CXX_BYTE_ORDER STREQUAL "BIG_ENDIAN")
    add_compile_definitions("BID_BIG_ENDIAN=1")
else()
    add_compile_definitions("BID_BIG_ENDIAN=0")
endif()

# set Floating Point Wrappers  
set(FLOATING_POINT_WRAPPERS OFF)


# Add definitions based on options
if (CALL_BY_REFERENCE)
    add_compile_definitions("DECIMAL_CALL_BY_REFERENCE=1")    
else()
    add_compile_definitions("DECIMAL_CALL_BY_REFERENCE=0")
    set(FLOATING_POINT_WRAPPERS OFF)
endif()
if (GLOBAL_ROUNDING)
    add_compile_definitions("DECIMAL_GLOBAL_ROUNDING=1")
    set(FLOATING_POINT_WRAPPERS OFF)
else()
    add_compile_definitions("DECIMAL_GLOBAL_ROUNDING=0")
endif()
if (GLOBAL_EXCEPTIONS)
    add_compile_definitions("DECIMAL_GLOBAL_EXCEPTION_FLAGS=1")
    set(FLOATING_POINT_WRAPPERS OFF)
else()
    add_compile_definitions("DECIMAL_GLOBAL_EXCEPTION_FLAGS=0")
endif()

# Set compiler specific defintions
if (IntelCompiler)
    add_compile_options("/Qlong-double" "/Qpc80" "/Qstd=c99")
    if (FLOATING_POINT_WRAPPERS)
        add_compile_definitions("__DFP_WRAPPERS_ON=1")
    endif()
else()
endif()

# Add OS specific defintions
if (UNIX AND APPLE)
    add_compile_definitions("OSX")
elseif (UNIX AND NOT APPLE)
    add_compile_definitions("LINUX")
elseif (WIN32)
    add_compile_definitions("WINDOWS")
    if (CMAKE_SIZEOF_VOID_P EQUAL 8)
        add_compile_definitions("WIN64")
    else()
        add_compile_definitions("WNT")
    endif()
else()
    message(FATAL_ERROR "Undefined OS")
endif()

# Add Architecture specific definitions
if (CMAKE_SIZEOF_VOID_P EQUAL 8)
    add_compile_definitions("efi2")
else()
    add_compile_definitions("ia32")
endif()

# Create F128 UX Functions
# List of quad functions that are required by the BID package
set(F128_UX_FUNCTIONS
    "dpml_ux_bid"
    "dpml_ux_bessel"
    "dpml_ux_crbt"
    "dpml_ux_erf"
    "dpml_ux_exp"
    "dpml_ux_int"
    "dpml_ux_inv_hyper"
    "dpml_ux_inv_trig"
    "dpml_ux_lgamma"
    "dpml_ux_log"
    "dpml_ux_mod"
    "dpml_ux_powi"
    "dpml_ux_pow"
    "dpml_ux_sqrt"
    "dpml_ux_trig"
    "dpml_ux_ops"
    "dpml_ux_ops_64"
    "dmpl_four_over_pi"
    "dpml_exception"
    "sqrt_tab_t"
   )

# Create F128 Functions
# List of double precision functions that are required by the BID package
if (WIN32)
set(F128_FUNCTIONS
    "dpml_asinh_t"
    "dpml_acosh_t"
    "dpml_crbt_t"
    "dpml_erf_t"
    "dpml_erfc_t"
    "dpml_exmpm1_t"
    "dpml_exp10_t"
    "dpml_exp2_t"
    "dpml_lgamma_t"
    "dpml_log1p_t"
    "dpml_tgamma_t"
    "dpml_rt_lgamma_t"
    "dpml_pow_t_table"
    "dpml_cbrt_t_table"
    "dpml_special_exp_t"
   )

    if (CMAKE_SIZEOF_VOID_P EQUAL 4)
        LIST(APPEND F128_FUNCTIONS "dpml_log2_t")
    endif()
else()
    set(F128_FUNCTIONS)
endif()

# Create BID Functions
set(BID_FUNCTIONS
    "bid_binarydecimal"
    "bid_convert_data"
    "bid_decimal_data"
    "bid_decimal_globals"
    "bid_dpd"
    "bid_feclearexcept"
    "bid_fegetexceptflag"
    "bid_feraiseexcept"
    "bid_fesetexceptflag" 
    "bid_fetestexcept"
    "bid_flag_operations"
    "bid_from_int"
    "bid_round"
   )

# Create BID32 Functions
set(BID32_FUNCTIONS
    "bid32_acos"
    "bid32_acosh"
    "bid32_asin"
    "bid32_asinh"
    "bid32_atan"
    "bid32_atan2"
    "bid32_atanh"
    "bid32_cbrt"
    "bid32_cos"
    "bid32_cosh"
    "bid32_erf"
    "bid32_erfc"
    "bid32_exp"
    "bid32_exp10"
    "bid32_exp2"
    "bid32_expm1"
    "bid32_hypot"
    "bid32_lgamma"
    "bid32_log"
    "bid32_log10"
    "bid32_log1p"
    "bid32_log2"
    "bid32_pow"
    "bid32_sin"
    "bid32_sinh"
    "bid32_tan"
# operations
    "bid32_add"
    "bid32_compare"
    "bid32_div"
    "bid32_fdimd"
    "bid32_fma"
    "bid32_fmod"
    "bid32_frexp"
    "bid32_ldexp"
    "bid32_llrintd"
    "bid32_logb"
    "bid32_logbd"
    "bid32_lrintd"
    "bid32_lround"
    "bid32_minmax"
    "bid32_modf"
    "bid32_mul"
    "bid32_nearbyintd"
    "bid32_next"
    "bid32_nexttowardd"
    "bid32_noncomp"
    "bid32_quantexpd"
    "bid32_quantize"
    "bid32_rem"
    "bid32_round_integral"
    "bid32_scalb"
    "bid32_scalbl"
    "bid32_sqrt"
    "bid32_string"
    "bid32_sub"
    "bid32_to_bid64"
    "bid32_to_bid128"
    "bid32_to_int16"
    "bid32_to_int32"
    "bid32_to_int64"
    "bid32_to_int8"
    "bid32_to_uint16"
    "bid32_to_uint32"
    "bid32_to_uint64"
    "bid32_to_uint8"
    "bid32_llround"
    "bid32_llquantexpd"
    "bid32_quantumd"
    "bid32_tanh"
    "bid32_tgamma"
 #string operations
    "strtod32"
    "wcstod32"
   )

# Create BID64 Functions
set(BID64_FUNCTIONS
    "bid64_acos"
    "bid64_acosh"
    "bid64_asin"
    "bid64_asinh"
    "bid64_atan"
    "bid64_atan2"
    "bid64_atanh"
    "bid64_cbrt"
    "bid64_cos"
    "bid64_cosh"
    "bid64_erf"
    "bid64_erfc"
    "bid64_exp"
    "bid64_exp10"
    "bid64_exp2"
    "bid64_expm1"
    "bid64_hypot"
    "bid64_lgamma"
    "bid64_log"
    "bid64_log10"
    "bid64_log1p"
    "bid64_log2"
    "bid64_pow"
    "bid64_sin"
    "bid64_sinh"
    "bid64_tan"
# operations
    "bid64_add"
    "bid64_compare"
    "bid64_div"
    "bid64_fdimd"
    "bid64_fma"
    "bid64_fmod"
    "bid64_frexp"
    "bid64_ldexp"
    "bid64_llrintd"
    "bid64_logb"
    "bid64_logbd"
    "bid64_lrintd"
    "bid64_lround"
    "bid64_minmax"
    "bid64_modf"
    "bid64_mul"
    "bid64_nearbyintd"
    "bid64_next"
    "bid64_nexttowardd"
    "bid64_noncomp"
    "bid64_quantexpd"
    "bid64_quantize"
    "bid64_rem"
    "bid64_round_integral"
    "bid64_scalb"
    "bid64_scalbl"
    "bid64_sqrt"
    "bid64_string"
    "bid64_to_bid128"
    "bid64_to_int16"
    "bid64_to_int32"
    "bid64_to_int64"
    "bid64_to_int8"
    "bid64_to_uint16"
    "bid64_to_uint32"
    "bid64_to_uint64"
    "bid64_to_uint8"
    "bid64_llround"
    "bid64_llquantexpd"
    "bid64_quantumd"
    "bid64_tanh"
    "bid64_tgamma"
 #string operations
    "strtod64"
    "wcstod64"
   )

# Create BID128 Functions
set(BID128_FUNCTIONS
    "bid128_acos"
    "bid128_acosh"
    "bid128_asin"
    "bid128_asinh"
    "bid128_atan"
    "bid128_atan2"
    "bid128_atanh"
    "bid128_cbrt"
    "bid128_cos"
    "bid128_cosh"
    "bid128_erf"
    "bid128_erfc"
    "bid128_exp"
    "bid128_exp10"
    "bid128_exp2"
    "bid128_expm1"
    "bid128_hypot"
    "bid128_lgamma"
    "bid128_log"
    "bid128_log10"
    "bid128_log1p"
    "bid128_log2"
    "bid128_pow"
    "bid128_sin"
    "bid128_sinh"
    "bid128_tan"
# operations
    "bid128"
    "bid128_2_str_tables"
    "bid128_add"
    "bid128_compare"
    "bid128_div"
    "bid128_fdimd"
    "bid128_fma"
    "bid128_fmod"
    "bid128_frexp"
    "bid128_ldexp"
    "bid128_llrintd"
    "bid128_logb"
    "bid128_logbd"
    "bid128_lrintd"
    "bid128_lround"
    "bid128_minmax"
    "bid128_modf"
    "bid128_mul"
    "bid128_nearbyintd"
    "bid128_next"
    "bid128_nexttowardd"
    "bid128_noncomp"
    "bid128_quantexpd"
    "bid128_quantize"
    "bid128_rem"
    "bid128_round_integral"
    "bid128_scalb"
    "bid128_scalbl"
    "bid128_sqrt"
    "bid128_string"
    "bid128_to_int16"
    "bid128_to_int32"
    "bid128_to_int64"
    "bid128_to_int8"
    "bid128_to_uint16"
    "bid128_to_uint32"
    "bid128_to_uint64"
    "bid128_to_uint8"
    "bid128_llround"
    "bid128_llquantexpd"
    "bid128_quantumd"
    "bid128_tanh"
    "bid128_tgamma"
 #string operations
    "strtod128"
    "wcstod128"
   )

# Create combined BID Functions list
set(TOTAL_BID_FUNCTIONS ${BID_FUNCTIONS} ${BID32_FUNCTIONS} ${BID64_FUNCTIONS} ${BID128_FUNCTIONS})

# Create BID Sources which is the c file corresponding to each of the respective functions
set(BID_SOURCES "")
foreach(BID_SOURCE ${TOTAL_BID_FUNCTIONS})
    LIST(APPEND BID_SOURCES "src/${BID_SOURCE}.c")
endforeach()

# Create the BID Headers
set(BID_HEADERS
    "bid_b2d.h"
    "bid_conf.h"
    "bid_div_macros.h"
    "bid_functions.h"
    "bid_inline_add.h"
    "bid_internal.h"
    "bid_sqrt_macros.h"
    "bid_strtod.h"
    "bid_trans.h"
    "bid128_2_str_macros.h"
    "bid128_2_str.h"
   )
list(TRANSFORM BID_HEADERS PREPEND "src/")

# Add intrinsics if using GCC
if (CMAKE_C_COMPILER_ID MATCHES "GNU")
    LIST(APPEND BID_HEADERS "src/bid_gcc_intrinsics.h")
endif()


# Add in F128 functions if not using native 128 bit type
if (NOT USE_COMPILER_F128_TYPE)



endif()


if (BUILD_SHARED_LIBS)
    add_library(IntelDFP SHARED ${BID_SOURCES} ${BID_HEADERS})
else()
    add_library(IntelDFP STATIC ${BID_SOURCES} ${BID_HEADERS})
endif()

# Add public headers
#target_include_directories(IntelDFP PUBLIC "src/")
   
# Set the output directory for build artifacts.
set_target_properties(IntelDFP PROPERTIES
                      RUNTIME_OUTPUT_DIRECTORY     "${CMAKE_BINARY_DIR}/bin"
                      LIBRARY_OUTPUT_DIRECTORY     "${CMAKE_BINARY_DIR}/lib"
                      ARCHIVE_OUTPUT_DIRECTORY     "${CMAKE_BINARY_DIR}/lib"
                      PDB_OUTPUT_DIRECTORY         "${CMAKE_BINARY_DIR}/bin"
                      COMPILE_PDB_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
                     )
