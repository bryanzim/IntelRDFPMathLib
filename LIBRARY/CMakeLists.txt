# Use special types only under Intel Compiler
if (IntelCompiler)
    set(USE_COMPILER_F128_TYPE ON)
    set(USE_COMPILER_F80_TYPE ON)
    set(IDFP_LIBRARY_INTEL_EXTENDED_FLOAT ON)
else()
    set(USE_COMPILER_F128_TYPE OFF)
    set(USE_COMPILER_F80_TYPE OFF)
    set(IDFP_LIBRARY_INTEL_EXTENDED_FLOAT OFF)
endif()

set(FLOATING_POINT_WRAPPERS OFF)
if (IDFP_CALL_BY_REFERENCE OR IDFP_GLOBAL_ROUNDING OR IDFP_GLOBAL_EXCEPTION_FLAGS)
    set(FLOATING_POINT_WRAPPERS OFF)
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
# Operations
    "bid32_add"
    "bid32_compare"
    "bid32_div"
    "bid32_fdimd"
    "bid32_fma"
    "bid32_fmod"
    "bid32_frexp"
    "bid32_ldexp"
    "bid32_llrintd"
    "bid32_llround"
    "bid32_llquantexpd"
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
    "bid32_quantumd"
    "bid32_rem"
    "bid32_round_integral"
    "bid32_scalb"
    "bid32_scalbl"
    "bid32_sqrt"
    "bid32_string"
    "bid32_sub"
    "bid32_tanh"
    "bid32_tgamma"
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
 # String operations
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
# Operations
    "bid64_add"
    "bid64_compare"
    "bid64_div"
    "bid64_fdimd"
    "bid64_fma"
    "bid64_fmod"
    "bid64_frexp"
    "bid64_ldexp"
    "bid64_llrintd"
    "bid64_llround"
    "bid64_llquantexpd"
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
    "bid64_quantumd"
    "bid64_rem"
    "bid64_round_integral"
    "bid64_scalb"
    "bid64_scalbl"
    "bid64_sqrt"
    "bid64_string"
    "bid64_tanh"
    "bid64_tgamma"
    "bid64_to_bid128"
    "bid64_to_int16"
    "bid64_to_int32"
    "bid64_to_int64"
    "bid64_to_int8"
    "bid64_to_uint16"
    "bid64_to_uint32"
    "bid64_to_uint64"
    "bid64_to_uint8"
 # String operations
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
# Operations
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
    "bid128_llround"
    "bid128_llquantexpd"
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
    "bid128_quantumd"
    "bid128_rem"
    "bid128_round_integral"
    "bid128_scalb"
    "bid128_scalbl"
    "bid128_sqrt"
    "bid128_string"
    "bid128_tanh"
    "bid128_tgamma"
    "bid128_to_int16"
    "bid128_to_int32"
    "bid128_to_int64"
    "bid128_to_int8"
    "bid128_to_uint16"
    "bid128_to_uint32"
    "bid128_to_uint64"
    "bid128_to_uint8"
 # String operations
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


# Create F128 COMMON Functions
# List of quad functions that are required by the BID package
set(F128_FUNCTIONS
    "bessel"
    "bid"
    "cbrt"
    "erf"
    "exp"
    "int"
    "inv_hyper"
    "inv_trig"
    "lgamma"
    "log"
    "mod"
    "ops"
    "ops_64"
    "pow"
    "powi"
    "sqrt"
    "trig"
   )

# Create F128 Sources And Headers
set(F128_HEADERS "")
set(F128_SOURCES "")
foreach(F128_FUNCTION ${F128_FUNCTIONS})
    LIST(APPEND F128_HEADERS "float128/dpml_ux_${F128_FUNCTION}.c")
    set(F128_FUNCTION_HEADER "float128/dpml_${F128_FUNCTION}_x.h")
    if (EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/${F128_FUNCTION_HEADER}")
        LIST(APPEND F128_HEADERS "${F128_FUNCTION_HEADER}")
    endif()
endforeach()

# Add following additional functions
LIST(APPEND F128_SOURCES
     "float128/dpml_exception.c"
     "float128/dpml_four_over_pi.c"
     "float128/sqrt_tab_t.c"
    )
LIST(APPEND F128_HEADERS
     "float128/dpml_exception.h"
    )

# Create F128 Object Library
add_library(IntelDFPF128 OBJECT ${F128_SOURCES} ${F128_HEADERS})
target_compile_definitions(IntelDFPF128 PRIVATE "USE_NATIVE_QUAD_TYPE=0")
idfp_apply_library_target_settings(IntelDFPF128)
idfp_apply_float128_clang_relaxations(IntelDFPF128)
if (IntelCompiler AND FLOATING_POINT_WRAPPERS)
    target_compile_definitions(IntelDFPF128 PRIVATE "__DFP_WRAPPERS_ON=1")
endif()

# Create the library
if (BUILD_SHARED_LIBS)
    add_library(IntelDFP SHARED ${BID_SOURCES} ${BID_HEADERS})
else()
    add_library(IntelDFP STATIC ${BID_SOURCES} ${BID_HEADERS})
endif()
target_link_libraries(IntelDFP PRIVATE IntelDFPF128)
idfp_apply_library_target_settings(IntelDFP)
if (IntelCompiler AND FLOATING_POINT_WRAPPERS)
    target_compile_definitions(IntelDFP PRIVATE "__DFP_WRAPPERS_ON=1")
endif()

target_include_directories(IntelDFP PUBLIC
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>"
    "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/IntelDFP>"
)

idfp_apply_standard_output_dirs(IntelDFP)
set_target_properties(IntelDFP PROPERTIES DEBUG_POSTFIX "d")

if (IDFP_ENABLE_INSTALL)
    include(IntelDFPInstall)
endif()

