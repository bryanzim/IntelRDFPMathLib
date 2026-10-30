/*
Copyright (c) 2007-2025, Intel Corp.
All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

    * Redistributions of source code must retain the above copyright notice,
      this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright notice,
      this list of conditions and the following disclaimer in the documentation
      and/or other materials provided with the distribution.
    * Neither the name of Intel Corporation nor the names of its contributors
      may be used to endorse or promote products derived from this software
      without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

// readtest.c - read tests from stdin
//
// This programs reads test of the form:
//
// <TESTID> <FUNCTION> <OP1> <OP2> <OP3> <RESULT> <STATUS>
//
// The testID is simply a string used to help identify which tail may be failing.
// The function name is generally one of the BID library function names.  Up to 3
// operands follow the function name, and then the expected result and expected
// status value.
//
// Each test is read, the appropriate function is called, and the results are
// compared with the expected results.  The operands, and results can appear as
// decimal numbers (e.g. 6.25), or as hexadecimal representations surrounded by
// square brackets (e.g. [31c0000000012345]).  The status value is a hexadecimal
// value (without the leading 0x).

#define STRMAX 1024
#include <stdbool.h>
#include <stdio.h> // for printf
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <wchar.h>
#if !defined _MSC_VER && !defined __INTEL_COMPILER
#include <fenv.h>
#endif

#include "test_bid_conf.h"
#include "test_bid_functions.h"

enum OPTYPE { OP_NONE,
              OP_DEC128,
              OP_DPD128,
              OP_DEC64,
              OP_DPD64,
              OP_DEC32,
              OP_DPD32,
              OP_INT64,
              OP_BID_UINT64,
              OP_INT32,
              OP_BID_UINT32,
              OP_BIN64,
              OP_BIN32,
              OP_BIN80,
              OP_BIN128,
              OP_INT16,
              OP_BID_UINT16,
              OP_INT8,
              OP_BID_UINT8,
              OP_LINT,
              OP_STRING
};

// Compare modes: EXACT does a bitwise compare, FUZZY does a bitwise unless NaN vs. NaN
//                EQUAL uses bid<size>_quiet_equal

enum CMPTYPE { CMP_NONE,
               CMP_EXACT,
               CMP_FUZZY,
               CMP_EXACTSTATUS,
               CMP_FUZZYSTATUS,
               CMP_EQUAL,
               CMP_EQUALSTATUS,
               CMP_RELATIVEERR
};

typedef BID_UINT32 decimal32;
typedef BID_UINT64 decimal64;
typedef BID_UINT128 decimal128;

#define GETTEST1(res, op1) \
  restype = (res);         \
  op1type = (op1);         \
  get_test();
#define GETTEST2(res, op1, op2) \
  restype = (res);              \
  op1type = (op1);              \
  op2type = (op2);              \
  get_test();
#define GETTEST3(res, op1, op2, op3) \
  restype = (res);                   \
  op1type = (op1);                   \
  op2type = (op2);                   \
  op3type = (op3);                   \
  get_test();

BID_EXTERN_C char *dec_status_to_string(const int status);
BID_EXTERN_C int check128(BID_UINT128 a, BID_UINT128 b);
BID_EXTERN_C int check64(BID_UINT64 a, BID_UINT64 b);
BID_EXTERN_C int compare_status(BID_FPSC bid, int dpd);
BID_EXTERN_C void print_status(int st);
BID_EXTERN_C void get_status(int st, char *status_str);
BID_EXTERN_C char *func;
BID_EXTERN_C double fabs(double);
double ulp; // current integer difference computed_result-expected_result
double ulp_add;
int underflow_before;
int li_size_test, li_size_run;
double mre;
float snan_check32;
double snan_check64;
long double snan_check80;
double mre_max[5] = {2.0, 2.0, 2.0, 2.0, 2.0};
unsigned int trans_flags_mask = 0x05;
int not_special_arg_res;
int s_na_n_passed_incorrectly32 = 0;
int s_na_n_passed_incorrectly64 = 0;
int s_na_n_passed_incorrectly80 = 0;
int den_passed_incorrectly32 = 0;
int den_passed_incorrectly64 = 0;
int den_passed_incorrectly80 = 0;
int arg32_den, res32_den, arg32_snan;
int arg64_den, res64_den, arg64_snan;
int arg80_den, res80_den, arg80_snan;
int res128_den;
int pollution_workaround;

fexcept_t ini_binary_flags, saved_binary_flags, test_binary_flags;
int ini_binary_rmode, saved_binary_rmode, test_binary_rmode;
fexcept_t fp_fl;

int copy_str_to_wstr(void);
void save_binary_status(void);
int check_restore_binary_status(void);
int check_pollution_workaround(void);

#ifndef HPUX_OS
#ifndef FE_UNNORMAL
#define FE_UNNORMAL 2
#endif
#ifndef FE_DENORMAL
#define FE_DENORMAL 2
#endif
#else
#ifndef FE_UNNORMAL
#define FE_UNNORMAL 0x4000
#endif
#ifndef FE_DENORMAL
#define FE_DENORMAL 0x4000
#endif
#endif

#define GETOP128(bid, dpd, op, str)                                                                                                                                                \
  if(*op == '[') {                                                                                                                                                                 \
    if((sscanf(op + 1, BID_FMT_LLX16 "" BID_FMT_LLX16, &(bid.w[BID_HIGH_128W]), &(bid.w[BID_LOW_128W])) == 2) ||                                                                   \
       (sscanf(op + 1, "" BID_FMT_LLX16 "," BID_FMT_LLX16 "", &(bid.w[BID_HIGH_128W]), &(bid.w[BID_LOW_128W])) == 2)) {                                                            \
      dpd = bid;                                                                                                                                                                   \
      BIDECIMAL_CALL1_NORND_RESREF(bid128_to_string, str, bid);                                                                                                                    \
    } else {                                                                                                                                                                       \
      printf("Internal error - can't read number form string %s\n", op + 1);                                                                                                       \
      exit(1);                                                                                                                                                                     \
    }                                                                                                                                                                              \
  } else {                                                                                                                                                                         \
    BIDECIMAL_CALL1_RESARG(bid128_from_string, (bid), (op));                                                                                                                       \
    dpd = bid;                                                                                                                                                                     \
    if(!strcmp(func, "bid128_from_string") || !strcmp(func, "bid_strtod128") || !strcmp(func, "bid_wcstod128") || !strcmp(func, "bid_strtod128") || !strcmp(func, "bid128_nan")) { \
      strcpy(str, op);                                                                                                                                                             \
    } else {                                                                                                                                                                       \
      BIDECIMAL_CALL1_NORND_RESREF(bid128_to_string, str, bid);                                                                                                                    \
    }                                                                                                                                                                              \
  }

#define GETOP32(bid, dpd, op, str)                                                                                                           \
  if(*op == '[') {                                                                                                                           \
    if(sscanf((op) + 1, BID_FMT_X8, &(bid))) {                                                                                               \
      dpd = (bid);                                                                                                                           \
      BIDECIMAL_CALL1_NORND_RESREF(bid32_to_string, str, bid);                                                                               \
    } else {                                                                                                                                 \
      printf("Internal error - can't read number form string %s\n", (op) + 1);                                                               \
      exit(1);                                                                                                                               \
    }                                                                                                                                        \
  } else {                                                                                                                                   \
    BIDECIMAL_CALL1_RESARG(bid32_from_string, bid, op);                                                                                      \
    dpd = bid;                                                                                                                               \
    if(!strcmp(func, "bid32_from_string") || !strcmp(func, "bid_strtod32") || !strcmp(func, "bid_wcstod32") || !strcmp(func, "bid32_nan")) { \
      strcpy(str, op);                                                                                                                       \
    } else {                                                                                                                                 \
      BIDECIMAL_CALL1_NORND_RESREF(bid32_to_string, str, bid);                                                                               \
    }                                                                                                                                        \
  }

#define GETOP64(bid, dpd, op, str)                                                                                                           \
  if(*op == '[') {                                                                                                                           \
    if(sscanf(op + 1, BID_FMT_LLX16, &bid)) {                                                                                                \
      dpd = bid;                                                                                                                             \
      BIDECIMAL_CALL1_NORND_RESREF(bid64_to_string, str, bid);                                                                               \
    } else {                                                                                                                                 \
      printf("Internal error - can't read number form string %s\n", (op) + 1);                                                               \
      exit(1);                                                                                                                               \
    }                                                                                                                                        \
  } else {                                                                                                                                   \
    BIDECIMAL_CALL1_RESARG(bid64_from_string, bid, op);                                                                                      \
    dpd = bid;                                                                                                                               \
    if(!strcmp(func, "bid64_from_string") || !strcmp(func, "bid_strtod64") || !strcmp(func, "bid_wcstod64") || !strcmp(func, "bid64_nan")) { \
      strcpy(str, op);                                                                                                                       \
    } else {                                                                                                                                 \
      BIDECIMAL_CALL1_NORND_RESREF(bid64_to_string, str, bid);                                                                               \
    }                                                                                                                                        \
  }

#define GETOP32I(bid, op, str)                                                 \
  if(*op == '[') {                                                             \
    if(!sscanf(op + 1, "%08x", &bid)) {                                        \
      printf("Internal error - can't read number form string %s\n", (op) + 1); \
      exit(1);                                                                 \
    }                                                                          \
  } else {                                                                     \
    if(!sscanf(op, "%d", &bid)) {                                              \
      printf("Internal error - can't read number form string %s\n", op);       \
      exit(1);                                                                 \
    }                                                                          \
  }                                                                            \
  sprintf(str, "%d", bid);

#define GETOP16I(bid, op, str)                                                 \
  if(*op == '[') {                                                             \
    if(!sscanf(op + 1, "%04x", &bid)) {                                        \
      printf("Internal error - can't read number form string %s\n", (op) + 1); \
      exit(1);                                                                 \
    }                                                                          \
  } else {                                                                     \
    if(!sscanf(op, "%d", &bid)) {                                              \
      printf("Internal error - can't read number form string %s\n", (op));     \
      exit(1);                                                                 \
    }                                                                          \
  }                                                                            \
  sprintf(str, "%d", bid);

#define GETOP8I(bid, op, str)                                                  \
  if(*op == '[') {                                                             \
    if(!sscanf(op + 1, "%02x", &bid)) {                                        \
    } else {                                                                   \
      printf("Internal error - can't read number form string %s\n", (op) + 1); \
      exit(1);                                                                 \
    }                                                                          \
  } else {                                                                     \
    if(!sscanf(op, "%d", &bid)) {                                              \
      printf("Internal error - can't read number form string %s\n", (op));     \
      exit(1);                                                                 \
    }                                                                          \
  }                                                                            \
  sprintf(str, "%d", bid);

#define GETOP32U(bid, op, str)                                                 \
  if(*op == '[') {                                                             \
    if(!sscanf(op + 1, "%08x", &bid)) {                                        \
      printf("Internal error - can't read number form string %s\n", (op) + 1); \
      exit(1);                                                                 \
    }                                                                          \
  } else {                                                                     \
    if(!sscanf(op, "%u", &bid)) {                                              \
      printf("Internal error - can't read number form string %s\n", (op));     \
      exit(1);                                                                 \
    }                                                                          \
  }                                                                            \
  sprintf(str, "%u", bid);

#define GETOP16U(bid, op, str)                                                 \
  if(*op == '[') {                                                             \
    if(!sscanf(op + 1, "%04x", &bid)) {                                        \
      printf("Internal error - can't read number form string %s\n", (op) + 1); \
      exit(1);                                                                 \
    }                                                                          \
  } else {                                                                     \
    if(!sscanf(op, "%u", &bid)) {                                              \
      printf("Internal error - can't read number form string %s\n", (op));     \
      exit(1);                                                                 \
    }                                                                          \
  }                                                                            \
  sprintf(str, "%u", bid);

#define GETOP8U(bid, op, str)                                                  \
  if(*op == '[') {                                                             \
    if(!sscanf(op + 1, "%02x", &bid)) {                                        \
      printf("Internal error - can't read number form string %s\n", (op) + 1); \
      exit(1);                                                                 \
    }                                                                          \
  } else {                                                                     \
    if(!sscanf(op, "%u", &bid)) {                                              \
      printf("Internal error - can't read number form string %s\n", (op));     \
      exit(1);                                                                 \
    }                                                                          \
  }                                                                            \
  sprintf(str, "%u", bid);

#define GETOP64I(bid, op, str)                                                 \
  if(*op == '[') {                                                             \
    if(!sscanf(op + 1, BID_FMT_LLX16, &bid)) {                                 \
      printf("Internal error - can't read number form string %s\n", (op) + 1); \
      exit(1);                                                                 \
    }                                                                          \
  } else {                                                                     \
    if(!sscanf(op, BID_FMT_LLD, &bid)) {                                       \
      printf("Internal error - can't read number form string %s\n", (op));     \
      exit(1);                                                                 \
    }                                                                          \
  }                                                                            \
  sprintf(str, BID_FMT_LLD, bid);

#define GETOP64U(bid, op, str)                                                 \
  if(*op == '[') {                                                             \
    if(!sscanf(op + 1, BID_FMT_LLX16, &bid)) {                                 \
      printf("Internal error - can't read number form string %s\n", (op) + 1); \
      exit(1);                                                                 \
    }                                                                          \
  } else {                                                                     \
    if(!sscanf(op, BID_FMT_LLU, &bid)) {                                       \
      printf("Internal error - can't read number form string %s\n", (op));     \
      exit(1);                                                                 \
    }                                                                          \
  }                                                                            \
  sprintf(str, BID_FMT_LLU, bid);

#define GETOPQUAD(quad1, quad2, op, str)                                                                                                   \
  if(*op == '[') {                                                                                                                         \
    if(sscanf(op + 1, BID_FMT_LLX16 "" BID_FMT_LLX16, ((BID_UINT64 *)&quad1 + BID_HIGH_128W), (BID_UINT64 *)&quad1 + BID_LOW_128W) != 2) { \
      printf("Internal error - can't read number form string %s\n", (op) + 1);                                                             \
      exit(1);                                                                                                                             \
    }                                                                                                                                      \
  }                                                                                                                                        \
  strcpy(str, "unavalable");

#if BID_BIG_ENDIAN
#define getopldbl(ldbl1, ldbl2, op, str)                                                                                                                                                              \
  {                                                                                                                                                                                                   \
    int tmpi;                                                                                                                                                                                         \
    arg80_den = arg80_snan = 0;                                                                                                                                                                       \
    if(*op == '[') {                                                                                                                                                                                  \
      if(sscanf(op + 1, BID_FMT_LLX16 "" BID_FMT_X4, (BID_UINT64 *)&ldbl1, &tmpi) != 2) {                                                                                                             \
        printf("Internal error - can't read number form string %s\n", (op) + 1);                                                                                                                      \
        exit(1);                                                                                                                                                                                      \
      } else {                                                                                                                                                                                        \
        *((unsigned short *)((BID_UINT64 *)&ldbl1 + 1)) = tmpi & 0xffff;                                                                                                                              \
      }                                                                                                                                                                                               \
    } else {                                                                                                                                                                                          \
      double dtmp;                                                                                                                                                                                    \
      if(!sscanf(op, "%lf", &dtmp)) {                                                                                                                                                                 \
        printf("Internal error - can't read number form string %s\n", (op));                                                                                                                          \
        exit(1);                                                                                                                                                                                      \
      }                                                                                                                                                                                               \
      ldbl1 = (BINARY80)dtmp;                                                                                                                                                                         \
    }                                                                                                                                                                                                 \
    {                                                                                                                                                                                                 \
      short *px = (short *)&ldbl1;                                                                                                                                                                    \
      if(((*(px) & 0x7fff) == 0x7fff) && ((*(px + 1) & 0x8000) == 0x8000) && ((*(px + 1) & 0x3fff) || (*(px + 2) & 0xffff) || (*(px + 3) & 0xffff) || (*(px + 0) & 0xffff)) && !(*(px + 1) & 0x4000)) \
        arg80_snan = 1;                                                                                                                                                                               \
      if(((*(px) & 0x7fff) == 0x0000) && ((*(px + 1) & 0x8000) != 0x8000) && ((*(px + 1) & 0x3fff) || (*(px + 2) & 0xffff) || (*(px + 3) & 0xffff) || (*(px + 0) & 0xffff)))                          \
        arg80_den = 1;                                                                                                                                                                                \
    }                                                                                                                                                                                                 \
    sprintf(str, "%27.17e", (double)ldbl1);                                                                                                                                                           \
  }
#else
#define GETOPLDBL(ldbl1, ldbl2, op, str)                                                                                                                                                                \
  arg80_den = arg80_snan = 0;                                                                                                                                                                           \
  if(*op == '[') {                                                                                                                                                                                      \
    if(sscanf(op + 1, BID_FMT_X4 "" BID_FMT_LLX16, (unsigned int *)((BID_UINT64 *)&ldbl1 + 1), (BID_UINT64 *)&ldbl1) != 2) {                                                                            \
      printf("Internal error - can't read number form string %s\n", (op) + 1);                                                                                                                          \
      exit(1);                                                                                                                                                                                          \
    }                                                                                                                                                                                                   \
  } else {                                                                                                                                                                                              \
    double dtmp;                                                                                                                                                                                        \
    if(!sscanf(op, "%lf", &dtmp)) {                                                                                                                                                                     \
      printf("Internal error - can't read number form string %s\n", (op));                                                                                                                              \
      exit(1);                                                                                                                                                                                          \
    }                                                                                                                                                                                                   \
    ldbl1 = (BINARY80)dtmp;                                                                                                                                                                             \
  }                                                                                                                                                                                                     \
  {                                                                                                                                                                                                     \
    short *px = (short *)&ldbl1;                                                                                                                                                                        \
    if(((*(px + 4) & 0x7fff) == 0x7fff) && ((*(px + 3) & 0x8000) == 0x8000) && ((*(px + 3) & 0x3fff) || (*(px + 2) & 0xffff) || (*(px + 1) & 0xffff) || (*(px + 0) & 0xffff)) && !(*(px + 3) & 0x4000)) \
      arg80_snan = 1;                                                                                                                                                                                   \
    if(((*(px + 4) & 0x7fff) == 0x0000) && ((*(px + 3) & 0x8000) != 0x8000) && ((*(px + 3) & 0x3fff) || (*(px + 2) & 0xffff) || (*(px + 1) & 0xffff) || (*(px + 0) & 0xffff)))                          \
      arg80_den = 1;                                                                                                                                                                                    \
  }                                                                                                                                                                                                     \
  sprintf(str, "%27.17e", (double)ldbl1);
#endif

#define GETOPDBL(dbl1, dbl2, op, str)                                                                                                                                                       \
  arg64_den = arg64_snan = 0;                                                                                                                                                               \
  if(*op == '[') {                                                                                                                                                                          \
    if(!sscanf(op + 1, BID_FMT_LLX16, (BID_UINT64 *)&dbl1)) {                                                                                                                               \
      printf("Internal error - can't read number form string %s\n", (op) + 1);                                                                                                              \
      exit(1);                                                                                                                                                                              \
    }                                                                                                                                                                                       \
  } else {                                                                                                                                                                                  \
    if(!sscanf(op, "%lf", &dbl1)) {                                                                                                                                                         \
      printf("Internal error - can't read number form string %s\n", (op));                                                                                                                  \
      exit(1);                                                                                                                                                                              \
    }                                                                                                                                                                                       \
  }                                                                                                                                                                                         \
  {                                                                                                                                                                                         \
    unsigned int *px = (unsigned int *)&dbl1;                                                                                                                                               \
    if(((*(px + BID_HIGH_128W) & 0x7ff00000u) == 0x7ff00000u) && ((*(px + BID_HIGH_128W) & 0x0007ffffu) || (*(px + BID_LOW_128W) & 0xffffffffu)) && !(*(px + BID_HIGH_128W) & 0x00080000u)) \
      arg64_snan = 1;                                                                                                                                                                       \
    if(((*(px + BID_HIGH_128W) & 0x7ff00000u) == 0x00000000u) && ((*(px + BID_HIGH_128W) & 0x000fffffu) || (*(px + BID_LOW_128W) & 0xffffffffu)))                                           \
      arg64_den = 1;                                                                                                                                                                        \
  }                                                                                                                                                                                         \
  sprintf(str, "%27.17e", dbl1);

#define GETOPFLT(flt1, flt2, op, str)                                                             \
  arg32_den = arg32_snan = 0;                                                                     \
  if(*op == '[') {                                                                                \
    if(!sscanf(op + 1, BID_FMT_X8, (BID_UINT32 *)&flt1)) {                                        \
      printf("Internal error - can't read number form string %s\n", (op) + 1);                    \
      exit(1);                                                                                    \
    }                                                                                             \
  } else {                                                                                        \
    if(!sscanf(op, "%f", &flt1)) {                                                                \
      printf("Internal error - can't read number form string %s\n", (op));                        \
      exit(1);                                                                                    \
    }                                                                                             \
  }                                                                                               \
  {                                                                                               \
    unsigned int *px = (unsigned int *)&flt1;                                                     \
    if(((*(px) & 0x7f800000u) == 0x7f800000u) && (*(px) & 0x003fffffu) && !(*(px) & 0x00400000u)) \
      arg32_snan = 1;                                                                             \
    if(((*(px) & 0x7f800000u) == 0x00000000u) && (*(px) & 0x007fffffu))                           \
      arg32_den = 1;                                                                              \
  }                                                                                               \
  sprintf(str, "%18.9e", flt1);

BID_EXTERN_C void get_ops(void);
BID_EXTERN_C void get_test(void);
BID_EXTERN_C void gen_ops(void);
BID_EXTERN_C void print_mismatch(enum CMPTYPE cmp);
BID_EXTERN_C void check_results(enum CMPTYPE cmp);
BID_EXTERN_C int st_compare(char **a, char **b);
BID_EXTERN_C int status_compare(char *stat1, char *stat2);
BID_EXTERN_C int setrounding(char *s);

unsigned int fpsf_0 = 0;

int args_set;

#if !DECIMAL_GLOBAL_EXCEPTION_FLAGS
unsigned int pfpsf_value;
unsigned int *pfpsf = &pfpsf_value;
#endif

#if defined LINUX && !defined HPUX_OS
#include <getopt.h>
#endif

#ifndef __COMPAR_FN_T
#define __COMPAR_FN_T
#if !defined(WINDOWS)
typedef int (*__compar_fn_t)(__const void *, __const void *);
#endif
#endif

#define STRMAX 1024

enum OPTYPE restype, op1type, op2type, op3type;

BID_UINT128 a, b, c, t, q, r, r_1;
BID_UINT64 a64, b64, c64, c_c64, t64, q64, r64, rt64, r64_1;
BID_UINT32 a32, b32, c32, t32, q32, r32, rt32, r32_1;
BINARY128 aquad, rquad, rtquad;
BINARY80 aldbl, rldbl, rtldbl;
double adbl, rdbl, rtdbl;
float aflt, rflt, rtflt;

BID_UINT32 a32, b32, c32, q32, r32;
BID_UINT64 a64, b64, c64, q64, r64;
BID_UINT128 a, b, c, q, r;

char a_i8;
unsigned char au_i8;
short a_i16, b_i16;
unsigned short au_i16, bu_i16;
int a_i32, b_i32;
unsigned int au_i32, bu_i32, cu_i32;
BID_SINT64 a_i64;
BID_UINT64 au_i64;
long int bli, li1, li2;

unsigned int u1, u2;
int i1, i2, n;

unsigned short u1_16, u2_16;
short i1_16, i2_16;

unsigned char u1_8, u2_8;
char i1_8, i2_8;

unsigned int expected_status;

#if !DECIMAL_GLOBAL_ROUNDING
unsigned int rnd_mode;
#endif
unsigned int tmp_status;
unsigned int rnd = 0;

char funcstr[STRMAX];
char *func = funcstr;
char string[STRMAX]; // conversion buffer
char str1[STRMAX];

// Input and result operands
char op1[STRMAX], op2[STRMAX], op3[STRMAX]; // conversion strings
char res[STRMAX];

char *endptr;
wchar_t wistr1[STRMAX], *wendptr;
char str_prefix[STRMAX];
char istr1[STRMAX], istr2[STRMAX], istr3[STRMAX], str2[STRMAX];
char convstr[STRMAX];
char res[STRMAX], rstr[STRMAX];
char version[STRMAX];
int extended, precision, min_exponent, max_exponent;
char rounding[STRMAX];
int line_counter;
char result[STRMAX];
char status_str[STRMAX];
char exp_result[STRMAX], exp_status[STRMAX];
char line[STRMAX];
char full_line[STRMAX];
BID_UINT64 result_i64, qi64;
int specop_opt;
int randop_opt;
int answer_opt;
int canon_opt;
int canon_dpd_opt;
int prec;
int expon_min;
int expon_max;
int no128trans = 0;
int no64trans = 0;

int debug_opt = 0;
#if defined UNCHANGED_BINARY_STATUS_FLAGS
int check_binary_flags_opt = 1;
#else
int check_binary_flags_opt = 0;
#endif
int underflow_before_opt = 0;
int underflow_after_opt = 0;
int tests = 0, fail_res = 0, fail_status = 0;

// char * decimal32ToString(const decimal32 *, char *);
// char * decimal64ToString(const decimal64 *, char *);
// char * decimal128ToString(const decimal128 *, char *);

char *roundstr[] = {"even", "away", "up", "down", "zero"};
char *roundstr_bid[] =
    {"half_even", "down", "up", "zero", "half_away"};

int setrounding(char *s) {
  if(strcmp(s, "half_even") == 0 || strcmp(s, "even") == 0) {
    rnd = rnd_mode = BID_ROUNDING_TO_NEAREST;
    strcpy(rounding, roundstr[0]);
  } else if(strcmp(s, "half_away") == 0 || strcmp(s, "away") == 0) {
    rnd = rnd_mode = BID_ROUNDING_TIES_AWAY;
    strcpy(rounding, roundstr[1]);
  } else if(strcmp(s, "up") == 0) {
    rnd = rnd_mode = BID_ROUNDING_UP;
    strcpy(rounding, roundstr[2]);
  } else if(strcmp(s, "down") == 0) {
    rnd = rnd_mode = BID_ROUNDING_DOWN;
    strcpy(rounding, roundstr[3]);
  } else if(strcmp(s, "zero") == 0) {
    rnd = rnd_mode = BID_ROUNDING_TO_ZERO;
    strcpy(rounding, roundstr[4]);
  } else {
    printf("setrounding: unknown rounding mode string!!!  Mode unchanged.\n");
  }
  return 1;
}

// Return TRUE (1) if 'a' and 'b' are incomtible results from some BID and DPD
// functions.  Ignore the payload of NaNs
int check128(BID_UINT128 a_in, BID_UINT128 b_in) {
  if(a_in.w[BID_LOW_128W] == b_in.w[BID_LOW_128W] && a_in.w[BID_HIGH_128W] == b_in.w[BID_HIGH_128W])
    return 0;

  return 1;
}

// Get rid of 0x0D and 0x0A symbols in the string s.
void str_remove0_d0_a(char *s) {
  int i = 0;
  while((s[i] != 0) && (s[i] != 0x0D) && (s[i] != 0x0A))
    i++;
  s[i] = 0;
}

// Get rid of trailing spaces in the string s.
void str_remove_trailing_spaces(char *s) {
  int i = 0;
  while(s[i] != 0)
    i++;
  i--;
  while((s[i] == ' ') && (i >= 0)) {
    s[i] = 0;
    i--;
  }
}

int check64(BID_UINT64 a_in, BID_UINT64 b_in) {
  if(a_in == b_in)
    return 0;

  return 1;
}

int check32(BID_UINT32 a32_in, BID_UINT32 b32_in) {
  if(a32_in == b32_in)
    return 0;

  return 1;
}

#define MASK_STEERING_BITS 0x6000000000000000ull
#define MASK_EXP 0x7ffe000000000000ull
#define EXP_P1 0x0002000000000000ull
#define SMALL_COEFF_MASK128 0x0001ffffffffffffull
#define MASK_BINARY_EXPONENT2 0x1ff8000000000000ull
#define MASK_BINARY_EXPONENT1 0x7fe0000000000000ull
#define MASK_BINARY_SIG2 0x0007ffffffffffffull
#define MASK_BINARY_SIG1 0x001fffffffffffffull
#define MASK_BINARY_OR2 0x0020000000000000ull
#define MASK_STEERING_BITS32 0x60000000
#define MASK_BINARY_EXPONENT1_32 0x7f800000
#define MASK_BINARY_SIG1_32 0x007fffff
#define MASK_BINARY_EXPONENT2_32 0x1fe00000
#define MASK_BINARY_SIG2_32 0x001fffff
#define MASK_BINARY_OR2_32 0x00800000
#define SHIFT_EXP1_32 23
#define SHIFT_EXP2_32 21
#define SHIFT_EXP1_64 53
#define SHIFT_EXP2_64 51
#define SHIFT_EXP1_128 17
#define SHIFT_EXP2_128 15

#define GET_EXP_32(r, x)                                     \
  {                                                          \
    if((x & MASK_STEERING_BITS32) == MASK_STEERING_BITS32) { \
      r = (x & MASK_BINARY_EXPONENT2_32) >> SHIFT_EXP2_32;   \
    } else {                                                 \
      r = (x & MASK_BINARY_EXPONENT1_32) >> SHIFT_EXP1_32;   \
    }                                                        \
  }

#define GET_MANT_32(r, x)                                    \
  {                                                          \
    if((x & MASK_STEERING_BITS32) == MASK_STEERING_BITS32) { \
      r = (x & MASK_BINARY_SIG2_32) | MASK_BINARY_OR2_32;    \
    } else {                                                 \
      r = (x & MASK_BINARY_SIG1_32);                         \
    }                                                        \
  }

#define GET_EXP_64(r, x)                                 \
  {                                                      \
    if((x & MASK_STEERING_BITS) == MASK_STEERING_BITS) { \
      r = (x & MASK_BINARY_EXPONENT2) >> SHIFT_EXP2_64;  \
    } else {                                             \
      r = (x & MASK_BINARY_EXPONENT1) >> SHIFT_EXP1_64;  \
    }                                                    \
  }

#define GET_MANT_64(r, x)                                \
  {                                                      \
    if((x & MASK_STEERING_BITS) == MASK_STEERING_BITS) { \
      r = (x & MASK_BINARY_SIG2) | MASK_BINARY_OR2;      \
    } else {                                             \
      r = (x & MASK_BINARY_SIG1);                        \
    }                                                    \
  }

#define MASK_EXP2 0x1fff800000000000ull
#define MASK_SIG2 0x00007fffffffffffull

#define GET_EXP_128(r, x)                                \
  {                                                      \
    if((x & MASK_STEERING_BITS) == MASK_STEERING_BITS) { \
      r = (x & MASK_EXP2) >> SHIFT_EXP2_128;             \
    } else {                                             \
      r = (x & MASK_EXP) >> SHIFT_EXP1_128;              \
    }                                                    \
  }

#define GET_MANT_128(r, x)                                                \
  {                                                                       \
    if((x.w[BID_HIGH_128W] & MASK_STEERING_BITS) == MASK_STEERING_BITS) { \
      r.w[BID_HIGH_128W] = (x.w[BID_HIGH_128W] & MASK_SIG2) | EXP_P1;     \
      r.w[BID_LOW_128W] = x.w[BID_LOW_128W];                              \
    } else {                                                              \
      r.w[BID_HIGH_128W] = (x.w[BID_HIGH_128W] & SMALL_COEFF_MASK128);    \
      r.w[BID_LOW_128W] = x.w[BID_LOW_128W];                              \
    }                                                                     \
  }

int check128_rel(BID_UINT128 a_in, BID_UINT128 b_in) {
  BID_UINT128 r1, r2, m1, m2;
  BID_UINT64 e1, e2;
  int less;
  int t1, t2, t3, t4;

  BIDECIMAL_CALL1_NORND_NOSTAT(bid128_isNaN, t1, a_in);
  BIDECIMAL_CALL1_NORND_NOSTAT(bid128_isNaN, t2, b_in);
  BIDECIMAL_CALL1_NORND_NOSTAT(bid128_isInf, t3, a_in);
  BIDECIMAL_CALL1_NORND_NOSTAT(bid128_isInf, t4, b_in);

  // if (bid128_isNaN(a)||bid128_isNaN(b) || bid128_isInf(a)||bid128_isInf(b)) {
  if(t1 || t2 || t3 || t4) {
    if(a_in.w[BID_LOW_128W] == b_in.w[BID_LOW_128W] && a_in.w[BID_HIGH_128W] == b_in.w[BID_HIGH_128W])
      return 0;
    else {
      if(t3) {
        a_in.w[BID_HIGH_128W] = (a_in.w[BID_HIGH_128W] & 0x8000000000000000ull) | 0x5FFFED09BEAD87C0ull;
        a_in.w[BID_LOW_128W] = 0x378D8E63FFFFFFFFull;
      } else if(t4) {
        b_in.w[BID_HIGH_128W] = (b_in.w[BID_HIGH_128W] & 0x8000000000000000ull) | 0x5FFFED09BEAD87C0ull;
        b_in.w[BID_LOW_128W] = 0x378D8E63FFFFFFFFull;
      } else
        return 1;
    }
  }

  if((a_in.w[BID_HIGH_128W] & 0x8000000000000000ull) != (b_in.w[BID_HIGH_128W] & 0x8000000000000000ull)) {
    return 1;
  }

  GET_EXP_128(e1, a_in.w[BID_HIGH_128W])
  GET_EXP_128(e2, b_in.w[BID_HIGH_128W])
  GET_MANT_128(m1, a_in)
  GET_MANT_128(m2, b_in)

  if(e1 < e2) {
    BIDECIMAL_CALL2(bid128_quantize, r1, a_in, b_in);
    r2 = b_in;
    GET_EXP_128(e1, r1.w[BID_HIGH_128W])
    GET_EXP_128(e2, r2.w[BID_HIGH_128W])
    GET_MANT_128(m1, r1)
    GET_MANT_128(m2, r2)
  } else if(e2 < e1) {
    r1 = a_in;
    BIDECIMAL_CALL2(bid128_quantize, r2, b_in, a_in);
    GET_EXP_128(e1, r1.w[BID_HIGH_128W])
    GET_EXP_128(e2, r2.w[BID_HIGH_128W])
    GET_MANT_128(m1, r1)
    GET_MANT_128(m2, r2)
  } else {
    r1 = a_in;
    r2 = b_in;
  }

  if(e1 != e2) {
    printf("ERROR a, b " BID_FMT_LLX16 " " BID_FMT_LLX16 " " BID_FMT_LLX16 " " BID_FMT_LLX16 "\n", a_in.w[BID_HIGH_128W], a_in.w[BID_LOW_128W], b_in.w[BID_HIGH_128W], b_in.w[BID_LOW_128W]);
    printf("ERROR r1, r2 " BID_FMT_LLX16 " " BID_FMT_LLX16 " " BID_FMT_LLX16 " " BID_FMT_LLX16 "\n", r1.w[BID_HIGH_128W], r1.w[BID_LOW_128W], r2.w[BID_HIGH_128W], r2.w[BID_LOW_128W]);
    return 1;
  }

  ulp = (double)(m1.w[BID_LOW_128W] > m2.w[BID_LOW_128W] ? m1.w[BID_LOW_128W] - m2.w[BID_LOW_128W] : m2.w[BID_LOW_128W] - m1.w[BID_LOW_128W]);
  // TODO HIGH part difference
  BIDECIMAL_CALL2_NORND(bid128_quiet_less, less, a_in, b_in);
  if(less)
    ulp *= -1.0;
  // printf("ulp %f +add %f max %f\n", ulp, ulp+ulp_add, mre_max[rnd_mode]);
  if(fabs(ulp + ulp_add) > mre_max[rnd_mode]) {
    return 1;
  }

  return 0;
}

int check64_rel(BID_UINT64 a_in, BID_UINT64 b_in) {
  BID_UINT64 r1, r2;
  BID_UINT64 e1, e2, m1, m2;
  int less;
  int t1, t2, t3, t4;

  BIDECIMAL_CALL1_NORND_NOSTAT(bid64_isNaN, t1, a_in);
  BIDECIMAL_CALL1_NORND_NOSTAT(bid64_isNaN, t2, b_in);
  BIDECIMAL_CALL1_NORND_NOSTAT(bid64_isInf, t3, a_in);
  BIDECIMAL_CALL1_NORND_NOSTAT(bid64_isInf, t4, b_in);

  // if (bid64_isNaN(aIn) || bid64_isNaN(bIn) || bid64_isInf(aIn) || bid64_isInf(bIn)) {
  if(t1 || t2 || t3 || t4) {
    if(a_in == b_in)
      return 0;
    else
      return 1;
  }

  if((a_in & 0x8000000000000000ull) != (b_in & 0x8000000000000000ull)) {
    return 1;
  }
  GET_EXP_64(e1, a_in)
  GET_EXP_64(e2, b_in)
  GET_MANT_64(m1, a_in)
  GET_MANT_64(m2, b_in)

  if(e1 < e2) {
    BIDECIMAL_CALL2(bid64_quantize, r1, a_in, b_in);
    r2 = b_in;
    GET_EXP_64(e1, r1)
    GET_EXP_64(e2, r2)
    GET_MANT_64(m1, r1)
    GET_MANT_64(m2, r2)
  } else if(e2 < e1) {
    r1 = a_in;
    BIDECIMAL_CALL2(bid64_quantize, r2, b_in, a_in);
    GET_EXP_64(e1, r1)
    GET_EXP_64(e2, r2)
    GET_MANT_64(m1, r1)
    GET_MANT_64(m2, r2)
  } else {
    r1 = a_in;
    r2 = b_in;
  }

  if(e1 != e2) {
    printf("ERROR a, b " BID_FMT_LLX16 " " BID_FMT_LLX16 "\n", a_in, b_in);
    printf("ERROR r1, r2 " BID_FMT_LLX16 " " BID_FMT_LLX16 "\n", r1, r2);
    return 1;
  }

  ulp = (double)(m1 > m2 ? m1 - m2 : m2 - m1);
  BIDECIMAL_CALL2_NORND(bid64_quiet_less, less, a_in, b_in);
  if(less)
    ulp *= -1.0;
  // printf("ulp %f +add %f max %f\n", ulp, ulp+ulp_add, mre_max[rnd_mode]);
  if(fabs(ulp + ulp_add) > mre_max[rnd_mode]) {
    return 1;
  }

  return 0;
}

int check32_rel(BID_UINT32 a32_in, BID_UINT32 b32_in) {
  BID_UINT32 r1, r2;
  BID_UINT32 e1, e2, m1, m2;
  int less;
  int t1, t2, t3, t4;

  BIDECIMAL_CALL1_NORND_NOSTAT(bid32_isNaN, t1, a32_in);
  BIDECIMAL_CALL1_NORND_NOSTAT(bid32_isNaN, t2, b32_in);
  BIDECIMAL_CALL1_NORND_NOSTAT(bid32_isInf, t3, a32_in);
  BIDECIMAL_CALL1_NORND_NOSTAT(bid32_isInf, t4, b32_in);

  // if (bid32_isNaN(a32In)||bid32_isNaN(b32In)||bid32_isInf(a32In)||bid32_isInf(b32In)) {
  if(t1 || t2 || t3 || t4) {

    if(a32_in == b32_in)
      return 0;
    else
      return 1;
  }

  if((a32_in & 0x80000000) != (b32_in & 0x80000000)) {
    return 1;
  }
  GET_EXP_32(e1, a32_in)
  GET_EXP_32(e2, b32_in)
  GET_MANT_32(m1, a32_in)
  GET_MANT_32(m2, b32_in)

  if(e1 < e2) {
    BIDECIMAL_CALL2(bid32_quantize, r1, a32_in, b32_in);
    r2 = b32_in;
    GET_EXP_32(e1, r1)
    GET_EXP_32(e2, r2)
    GET_MANT_32(m1, r1)
    GET_MANT_32(m2, r2)
  } else if(e2 < e1) {
    r1 = a32_in;
    BIDECIMAL_CALL2(bid32_quantize, r2, b32_in, a32_in);
    GET_EXP_32(e1, r1)
    GET_EXP_32(e2, r2)
    GET_MANT_32(m1, r1)
    GET_MANT_32(m2, r2)
  } else {
    r1 = a32_in;
    r2 = b32_in;
  }

  if(e1 != e2) {
    printf("ERROR a, b %08x %08x\n", a32_in, b32_in);
    printf("ERROR r1, r2 %08x %08x\n", r1, r2);
    return 1;
  }

  ulp = m1 > m2 ? m1 - m2 : m2 - m1;
  BIDECIMAL_CALL2_NORND(bid32_quiet_less, less, a32_in, b32_in);
  if(less)
    ulp *= -1.0;
  // printf("ulp %f +add %f max %f\n", ulp, ulp+ulp_add, mre_max[rnd_mode]);
  if(fabs(ulp + ulp_add) > mre_max[rnd_mode]) {
    return 1;
  }

  return 0;
}

void get_ops(void) {
  unsigned int save_rnd = rnd;
  rnd = rnd_mode = BID_ROUNDING_TO_NEAREST;

  // Initialize second arg for comparing - required by modf function but can give false errors if argument is not initialized
  b32 = 0;
  b64 = 0ull;
  b.w[BID_LOW_128W] = b.w[BID_HIGH_128W] = 0ull;

  strcpy(istr1, "");
  strcpy(istr2, "");
  strcpy(istr3, "");

  switch(op1type) {
  case OP_DEC32:
    GETOP32(a32, a32, op1, istr1);
    break;
  case OP_DEC64:
    GETOP64(a64, a64, op1, istr1);
    break;
  case OP_DEC128:
    GETOP128(a, a, op1, istr1);
    break;
  case OP_INT8:
    GETOP8I(a_i32, op1, istr1);
    a_i8 = (char)a_i32;
    break;
  case OP_INT16:
    GETOP16I(a_i32, op1, istr1);
    a_i16 = (short)a_i32;
    break;
  case OP_INT32:
    GETOP32I(a_i32, op1, istr1);
    break;
  case OP_INT64:
    GETOP64I(a_i64, op1, istr1);
    break;
  case OP_BID_UINT8:
    GETOP8U(au_i32, op1, istr1);
    au_i8 = (unsigned char)au_i32;
    break;
  case OP_BID_UINT16:
    GETOP16U(au_i32, op1, istr1);
    au_i16 = (unsigned short)au_i32;
    break;
  case OP_BID_UINT32:
    GETOP32U(au_i32, op1, istr1);
    break;
  case OP_BID_UINT64:
    GETOP64U(au_i64, op1, istr1);
    break;
  case OP_BIN128:
    GETOPQUAD(aquad, Aquad, op1, istr1);
    break;
  case OP_BIN80:
    GETOPLDBL(aldbl, Aldbl, op1, istr1);
    break;
  case OP_BIN64:
    GETOPDBL(adbl, Adbl, op1, istr1);
    break;
  case OP_BIN32:
    GETOPFLT(aflt, Aflt, op1, istr1);
    break;
  case OP_NONE:
    break;
  case OP_DPD32:
  case OP_DPD64:
  case OP_DPD128:
  case OP_LINT:
  case OP_STRING:
  default:
    printf("Error: getops unexpected operand 1 type, %d\n", op1type);
  }

  switch(op2type) {
  case OP_DEC32:
    GETOP32(b32, b32, op2, istr2);
    break;
  case OP_DEC64:
    GETOP64(b64, b64, op2, istr2);
    break;
  case OP_DEC128:
    GETOP128(b, b, op2, istr2);
    break;
  case OP_INT16:
    GETOP16I(b_i32, op2, istr2);
    b_i16 = (short)b_i32;
    break;
  case OP_INT32:
    GETOP32I(b_i32, op2, istr2);
    break;
  case OP_BID_UINT32: //  Skip because converted with sscanf
    GETOP32U(bu_i32, op2, istr2);
    break;
  case OP_LINT:
    if(li_size_run == 64) {
      GETOP64I(*(BID_SINT64 *)&bli, op2, istr2);
    } else {
      GETOP32I(*(BID_SINT32 *)&bli, op2, istr2);
    }
    break;
  case OP_NONE:
    break;
  case OP_DPD32:
  case OP_DPD64:
  case OP_DPD128:
  case OP_INT8:
  case OP_INT64:
  case OP_BID_UINT8:
  case OP_BID_UINT16:
  case OP_BID_UINT64:
  case OP_BIN32:
  case OP_BIN64:
  case OP_BIN80:
  case OP_BIN128:
  case OP_STRING:
  default:
    printf("Error: getops unexpected operand 2 type, %d\n", op2type);
  }

  switch(op3type) {
  case OP_DEC32:
    GETOP32(c32, c32, op3, istr3);
    break;
  case OP_DEC64:
    GETOP64(c_c64, c64, op3, istr3);
    break;
  case OP_DEC128:
    GETOP128(c, c, op3, istr3);
    break;
  case OP_BID_UINT32: //  Skip because converted with sscanf
    GETOP32U(cu_i32, op3, istr3);
    break;
  case OP_NONE:
    break;
  case OP_DPD32:
  case OP_DPD64:
  case OP_DPD128:
  case OP_INT8:
  case OP_INT16:
  case OP_INT32:
  case OP_INT64:
  case OP_BID_UINT8:
  case OP_BID_UINT16:
  case OP_BID_UINT64:
  case OP_BIN32:
  case OP_BIN64:
  case OP_BIN80:
  case OP_BIN128:
  case OP_LINT:
  case OP_STRING:
  default:
    printf("Error: getops unexpected operand 3 type, %d\n", op3type);
    exit(EXIT_FAILURE);
  }
  rnd = rnd_mode = save_rnd;

  // true second res of frexp function
  if(!strcmp(func, "bid32_frexp") || !strcmp(func, "bid64_frexp") || !strcmp(func, "bid128_frexp")) {
    i1 = b_i32;
  }
  // true second res of modf function
  r32_1 = b32;
  r64_1 = b64;
  r_1 = b;
}

void get_test(void) {

  // initialize results so we can easy compare frexp function
  i1 = i2 = 0;
  u1_16 = u2_16 = 0;
  i1_16 = i2_16 = 0;
  u1_8 = u2_8 = 0;
  i1_8 = i2_8 = 0;
  result_i64 = qi64 = 0;

  get_ops();

  switch(restype) {
  case OP_DEC32:
  case OP_DPD32:
    GETOP32(r32, q32, res, rstr);
    break;
  case OP_DEC64:
  case OP_DPD64:
    GETOP64(r64, q64, res, rstr);
    break;
  case OP_DEC128:
  case OP_DPD128:
    GETOP128(r, q, res, rstr);
    break;
  case OP_INT8:
    GETOP8I(i1, res, rstr);
    break;
  case OP_INT16:
    GETOP16I(i1, res, rstr);
    break;
  case OP_INT32: //  Skip because converted with sscanf
    GETOP32I(i1, res, rstr);
    break;
  case OP_BID_UINT8:
    GETOP8U(i1, res, rstr);
    break;
  case OP_BID_UINT16:
    GETOP16U(i1, res, rstr);
    break;
  case OP_BID_UINT32:
    GETOP32U(i1, res, rstr);
    break;
  case OP_INT64:
    GETOP64I(qi64, res, rstr);
    break;
  case OP_BID_UINT64:
    GETOP64U(qi64, res, rstr);
    break;
  case OP_BIN128:
    GETOPQUAD(rtquad, Rtquad, res, rstr);
    break;
  case OP_BIN80:
    GETOPLDBL(rtldbl, Rtldbl, res, rstr);
    break;
  case OP_BIN64:
    GETOPDBL(rtdbl, Rtdbl, res, rstr);
    break;
  case OP_BIN32:
    GETOPFLT(rtflt, Rtflt, res, rstr);
    break;
  case OP_LINT:
    if(li_size_run == 64) {
      GETOP64I(*(BID_SINT64 *)&li1, res, rstr);
    } else {
      GETOP32I(*(BID_SINT32 *)&li1, res, rstr);
    }
    break;
  case OP_NONE:
    break;
  case OP_STRING:
  default:
    printf("Error: get_test unexpected result type, %d\n", restype);
  }
}

void print_mismatch(enum CMPTYPE cmp) {
  (void)cmp;

  if(answer_opt) {
    if(*op3)
      printf("test%d %s %s %s %s ", tests, func, op1, op2, op3);
    else if(*op2)
      printf("test%d %s %s %s ", tests, func, op1, op2);
    else
      printf("test%d %s %s ", tests, func, op1);
    switch(restype) {

    case OP_STRING:
      printf("STRING result is not implemented\n");
      break;
    case OP_DEC128:
    case OP_DPD128:
      printf("[" BID_FMT_LLX16 "" BID_FMT_LLX16 "] %02x\n", q.w[BID_HIGH_128W],
             q.w[BID_LOW_128W], *pfpsf);
      break;

    case OP_DEC64:
    case OP_DPD64:
      printf("[" BID_FMT_LLX16 "] %02x\n", q64, *pfpsf);
      break;

    case OP_DEC32:
    case OP_DPD32:
      printf("[" BID_FMT_X8 "] %02x\n", q32, *pfpsf);
      break;

    case OP_INT8:
    case OP_INT16:
    case OP_INT32:
      printf("%d %02x\n", i2, *pfpsf);
      break;

    case OP_BID_UINT8:
    case OP_BID_UINT16:
    case OP_BID_UINT32:
      printf("%u %02x\n", i2, *pfpsf);
      break;

    case OP_INT64:
      printf(BID_FMT_LLD16 " %02x\n", result_i64, *pfpsf);
      break;

    case OP_LINT:
      if(li_size_run == 64)
        printf(BID_FMT_LLD16 " %02x\n", *(BID_SINT64 *)&li2, *pfpsf);
      else
        printf("%d %02x\n", *(BID_SINT32 *)&li2, *pfpsf);
      break;

    case OP_BID_UINT64:
      printf(BID_FMT_LLU16 " %02x\n", result_i64, *pfpsf);
      break;

    case OP_BIN128:
      printf("[" BID_FMT_LLX16 " " BID_FMT_LLX16 "] %02x\n",
             *((BID_UINT64 *)&rquad + BID_HIGH_128W),
             *((BID_UINT64 *)&rquad + BID_LOW_128W), *pfpsf);
      break;

    case OP_BIN80:
#if BID_BIG_ENDIAN
      printf("[" BID_FMT_LLX16 "" BID_FMT_X4 "] %02x\n", *((BID_UINT64 *)&Rldbl),
             ((BID_UINT32)(*((BID_UINT64 *)&Rldbl + 1))) & 0xffff, *pfpsf);
#else
      printf("[" BID_FMT_X4 "" BID_FMT_LLX16 "] %02x\n",
             ((BID_UINT32)(*((BID_UINT64 *)&rldbl + 1))) & 0xffff,
             *((BID_UINT64 *)&rldbl), *pfpsf);
#endif
      break;

    case OP_BIN64:
      printf("[" BID_FMT_LLX16 "] %02x\n", *((BID_UINT64 *)&rdbl), *pfpsf);
      break;

    case OP_BIN32:
      printf("[" BID_FMT_X8 "] %02x\n", *((BID_UINT32 *)&rflt), *pfpsf);
      break;

    case OP_NONE:
    default:
      printf("print_mismatch: unknown result type %d\n", restype);
    }
    return;
  }

  // Print mismatch line
  switch(restype) {
  case OP_DEC128:
  case OP_DPD128:
    printf("// BID result: " BID_FMT_LLX16 "" BID_FMT_LLX16
           ", Expected results: " BID_FMT_LLX16 "" BID_FMT_LLX16 "\n",
           q.w[BID_HIGH_128W], q.w[BID_LOW_128W], r.w[BID_HIGH_128W],
           r.w[BID_LOW_128W]);
    if(!strcmp(func, "bid128_modf")) {
      printf("// BID second result: " BID_FMT_LLX16 "" BID_FMT_LLX16
             ", Expected results: " BID_FMT_LLX16 "" BID_FMT_LLX16 "\n",
             b.w[BID_HIGH_128W], b.w[BID_LOW_128W], r_1.w[BID_HIGH_128W],
             r_1.w[BID_LOW_128W]);
    }
    break;
  case OP_DEC64:
  case OP_DPD64:
    printf("// BID result: " BID_FMT_LLX16 ", Expected result: " BID_FMT_LLX16
           "\n",
           q64, r64);
    if(!strcmp(func, "bid64_modf")) {
      printf("// BID second result: " BID_FMT_LLX16 ", Expected result: " BID_FMT_LLX16
             "\n",
             b64, r64_1);
    }
    break;
  case OP_DEC32:
  case OP_DPD32:
    printf("// BID result: " BID_FMT_X8 ", Expected result: " BID_FMT_X8 "\n",
           q32, r32);
    if(!strcmp(func, "bid32_modf")) {
      printf("// BID second result: " BID_FMT_X8 ", Expected result: " BID_FMT_X8 "\n",
             b32, r32_1);
    }
    break;
  case OP_INT8:
  case OP_INT16:
  case OP_INT32:
    printf("// BID result: %d, Expected result: %d\n", i2, i1);
    break;
  case OP_BID_UINT8:
  case OP_BID_UINT16:
  case OP_BID_UINT32:
    printf("// BID result: %u, Expected result: %u\n", i2, i1);
    break;
  case OP_INT64:
    printf("// BID result: " BID_FMT_LLD16 ", Expected result: " BID_FMT_LLD16
           "\n",
           result_i64, qi64);
    break;
  case OP_LINT:
    if(li_size_run == 64)
      printf("// BID result: " BID_FMT_LLD16 ", Expected result: " BID_FMT_LLD16
             "\n",
             *(BID_SINT64 *)&li2, *(BID_SINT64 *)&li1);
    else
      printf("// BID result: %d, Expected result: %d \n", *(BID_SINT32 *)&li2, *(BID_SINT32 *)&li1);
    break;
  case OP_BID_UINT64:
    printf("// BID result: " BID_FMT_LLU16 ", Expected result: " BID_FMT_LLU16
           "\n",
           result_i64, qi64);
    break;
  case OP_BIN128:
    printf("// BID result: " BID_FMT_LLX16 " " BID_FMT_LLX16
           ", Expected result: " BID_FMT_LLX16 " " BID_FMT_LLX16 "\n",
           *((BID_UINT64 *)&rquad + BID_HIGH_128W),
           *((BID_UINT64 *)&rquad + BID_LOW_128W),
           *((BID_UINT64 *)&rtquad + BID_HIGH_128W),
           *((BID_UINT64 *)&rtquad + BID_LOW_128W));
    break;
  case OP_BIN80:
#if BID_BIG_ENDIAN
    printf("// BID result: " BID_FMT_LLX16 "" BID_FMT_X4 ", Expected result: " BID_FMT_LLX16 "" BID_FMT_X4 " \n", *((BID_UINT64 *)&Rldbl + 0),
           ((BID_UINT32)(*((BID_UINT64 *)&Rldbl + 1))) & 0xffff,
           *((BID_UINT64 *)&Rtldbl + 0),
           ((BID_UINT32)(*((BID_UINT64 *)&Rtldbl + 1))) & 0xffff);
#else
    printf("// BID result: " BID_FMT_X4 "" BID_FMT_LLX16 ", Expected result: " BID_FMT_X4 "" BID_FMT_LLX16 " \n",
           ((BID_UINT32)(*((BID_UINT64 *)&rldbl + 1))) & 0xffff,
           *((BID_UINT64 *)&rldbl + 0),
           ((BID_UINT32)(*((BID_UINT64 *)&rtldbl + 1))) & 0xffff,
           *((BID_UINT64 *)&rtldbl + 0));
#endif
    break;
  case OP_BIN64:
    printf("// BID result: " BID_FMT_LLX16 ", Expected result: " BID_FMT_LLX16
           "\n",
           *((BID_UINT64 *)&rdbl), *((BID_UINT64 *)&rtdbl));
    break;
  case OP_BIN32:
    printf("// BID result: " BID_FMT_X8 ", Expected result: " BID_FMT_X8 "\n",
           *((BID_UINT32 *)&rflt), *((BID_UINT32 *)&rtflt));
    break;
  case OP_NONE:
  case OP_STRING:
  default:
    printf("print_mismatch: unknown result type %d\n", restype);
    exit(EXIT_FAILURE);
  }

  if(!strcmp(func, "bid32_frexp") || !strcmp(func, "bid64_frexp") || !strcmp(func, "bid128_frexp")) {
    printf("// BID second result: %d, Expected result: %d\n", i2, i1);
  }

  // Print statuses
  printf("// BID status : %03x, Expected status: %03x (PUOZDI Bits)\n",
         *pfpsf, expected_status);

  switch(restype) {
  case OP_DEC128:
    BIDECIMAL_CALL1_NORND_RESREF(bid128_to_string, str1, q);
    BIDECIMAL_CALL1_NORND_RESREF(bid128_to_string, str2, r);
    printf("// Result BID128 String: %s\n", str1);
    printf("// Expected BID128 String: %s\n", str2);
    break;
  case OP_DEC64:
    BIDECIMAL_CALL1_NORND_RESREF(bid64_to_string, str1, q64);
    BIDECIMAL_CALL1_NORND_RESREF(bid64_to_string, str2, r64);
    printf("// Result BID64 String: %s\n", str1);
    printf("// Expected BID64 String: %s\n", str2);
    break;
  case OP_DEC32:
    BIDECIMAL_CALL1_NORND_RESREF(bid32_to_string, str1, q32);
    BIDECIMAL_CALL1_NORND_RESREF(bid32_to_string, str2, r32);
    printf("// Result BID32 String: %s\n", str1);
    printf("// Expected BID32 String: %s\n", str2);
    break;
  case OP_DPD128: {
    BID_UINT128 qbid, rbid;
    BIDECIMAL_CALL1_NORND_NOSTAT(bid_dpd_to_bid128, qbid, q);
    BIDECIMAL_CALL1_NORND_NOSTAT(bid_dpd_to_bid128, rbid, r);
    BIDECIMAL_CALL1_NORND_RESREF(bid128_to_string, str2, qbid);
    BIDECIMAL_CALL1_NORND_RESREF(bid128_to_string, str2, rbid);
    printf("// Result BID128 String: %s\n", str1);
    printf("// Expected BID128 String: %s\n", str2);
  } break;
  case OP_DPD64: {
    BID_UINT64 qbid, rbid;
    BIDECIMAL_CALL1_NORND_NOSTAT(bid_dpd_to_bid64, qbid, q64);
    BIDECIMAL_CALL1_NORND_NOSTAT(bid_dpd_to_bid64, rbid, r64);
    BIDECIMAL_CALL1_NORND_RESREF(bid64_to_string, str1, qbid);
    BIDECIMAL_CALL1_NORND_RESREF(bid64_to_string, str2, rbid);
    printf("// Result BID64 String: %s\n", str1);
    printf("// Expected BID64 String: %s\n", str2);
  } break;
  case OP_DPD32: {
    BID_UINT32 qbid, rbid;
    BIDECIMAL_CALL1_NORND_NOSTAT(bid_dpd_to_bid32, qbid, q32);
    BIDECIMAL_CALL1_NORND_NOSTAT(bid_dpd_to_bid32, rbid, r32);
    BIDECIMAL_CALL1_NORND_RESREF(bid32_to_string, str1, qbid);
    BIDECIMAL_CALL1_NORND_RESREF(bid32_to_string, str2, rbid);
    printf("// Result BID32 String: %s\n", str1);
    printf("// Expected BID32 String: %s\n", str2);
  } break;
  case OP_INT8:
  case OP_BID_UINT8:
  case OP_INT16:
  case OP_BID_UINT16:
  case OP_INT32:
  case OP_BID_UINT32:
  case OP_INT64:
  case OP_BID_UINT64:
  case OP_LINT:
    break;
  case OP_BIN128:
    /* sprintf(str1, "%.17le", Rquad); */
    /* sprintf(str2, "%.17le", Rtquad); */

    strcpy(str1, "unavailable");
    strcpy(str2, "unavailable");
    printf("// BID128 quad res: %s\n", str1);
    printf("// Expected quad res : %s\n", str2);
    break;
  case OP_BIN80:
    sprintf(str1, "%.17le", (double)rldbl);
    sprintf(str2, "%.17le", (double)rtldbl);
    printf("// BID80 double res (cast to double): %s\n", str1);
    printf("// Expected double res (cast to double): %s\n", str2);
    break;
  case OP_BIN64:
    sprintf(str1, "%.17le", rdbl);
    sprintf(str2, "%.17le", rtdbl);
    printf("// BID64 double res: %s\n", str1);
    printf("// Expected double res : %s\n", str2);
    break;
  case OP_BIN32:
    sprintf(str1, "%.9e", rflt);
    sprintf(str2, "%.9e", rtflt);
    printf("// BID32 double res: %s\n", str1);
    printf("// decimal32 double res : %s\n", str2);
    break;
  case OP_NONE:
  case OP_STRING:
  default:
    printf("print_mismatch unknown result type %d\n", restype);
    exit(EXIT_FAILURE);
  }

  printf("// Input operand strings: %s %s %s\n", istr1, istr2, istr3);
  fail_res++;
  sprintf(line, "%s %s %s %s\n", func, op1, op2, op3);
  printf("// Ulp error: %e\n", ulp + ulp_add);
  printf("// Full input string: %s\n", full_line);
  printf("// Input string number: %d\n", line_counter);
  printf("// FAILED(%s)\n\n", rounding);
}

void check_results(enum CMPTYPE cmp) {
  char *p;
  tests++;

  // printf("frexp i1 i2 %d %d \n", i1, i2);

  // printf("arg dbl %08X \n", *((int*)&Adbl+BID_HIGH_128W));
  p = strstr(func, "binary64_to");
  if(p) {
    // printf("check fo binary snan\n");
    if(s_na_n_passed_incorrectly64 && ((*((unsigned int *)&adbl + BID_HIGH_128W) & 0x7ff80000u) == 0x7ff00000u) &&
       ((*((unsigned int *)&adbl + BID_HIGH_128W) & 0x0007ffffu) || (*((unsigned int *)&adbl + BID_LOW_128W) & 0xffffffffu))) {
      // printf("set invalid for 64\n");
      *pfpsf |= BID_INVALID_EXCEPTION;
    }
  }
  p = strstr(func, "binary32_to");
  if(p) {
    if(s_na_n_passed_incorrectly32 && ((*((unsigned int *)&aflt) & 0x7fc00000u) == 0x7f800000u) &&
       ((*((unsigned int *)&aflt) & 0x003fffffu))) {
      // printf("set invalid for 32\n");
      *pfpsf |= BID_INVALID_EXCEPTION;
    }
  }
  p = strstr(func, "binary80_to");
  if(p) {
    // printf("check fo binary snan\n");
    if(s_na_n_passed_incorrectly80 && ((*((unsigned int *)&aldbl + 2) & 0x7fffu) == 0x7fffu) &&
       ((*((unsigned int *)&aldbl + BID_HIGH_128W) & 0xc0000000u) == 0x80000000u) &&
       ((*((unsigned int *)&aldbl + BID_HIGH_128W) & 0x7fffffffu) || (*((unsigned int *)&aldbl + BID_LOW_128W) & 0xffffffffu))) {
      // printf("set invalid for 80\n");
      *pfpsf |= BID_INVALID_EXCEPTION;
    }
  }

  if(check_restore_binary_status()) {
    print_mismatch(cmp);
    return;
  }

  if(debug_opt || answer_opt) {
    print_mismatch(cmp);
    return;
  }

  if(!strcmp(func, "bid64_to_string")) {
    BIDECIMAL_CALL1_RESARG(bid64_from_string, q64, convstr);
  } else if(!strcmp(func, "bid128_to_string")) {
    BIDECIMAL_CALL1_RESARG(bid128_from_string, q, convstr);
  } else if(!strcmp(func, "bid32_to_string")) {
    BIDECIMAL_CALL1_RESARG(bid32_from_string, q32, convstr);
  }

  if(restype == OP_DEC128 && cmp == CMP_EXACTSTATUS) {
    if(expected_status != *pfpsf || r.w[BID_LOW_128W] != q.w[BID_LOW_128W] || r.w[BID_HIGH_128W] != q.w[BID_HIGH_128W] || i1 != i2 || result_i64 != qi64)
      print_mismatch(cmp);
  } else if(restype == OP_DEC64 && cmp == CMP_EXACTSTATUS) {
    if(expected_status != *pfpsf || r64 != q64 || i1 != i2 || result_i64 != qi64)
      print_mismatch(cmp);
  } else if(restype == OP_DEC32 && (cmp == CMP_EXACTSTATUS || cmp == CMP_FUZZYSTATUS)) {
    if(expected_status != *pfpsf || r32 != q32 || i1 != i2 || result_i64 != qi64 || r32_1 != b32)
      print_mismatch(cmp);
  } else if(restype == OP_LINT && (cmp == CMP_EXACTSTATUS || cmp == CMP_FUZZYSTATUS)) {
    if(expected_status != *pfpsf || li1 != li2)
      print_mismatch(cmp);
  } else if(restype == OP_DEC32 && (cmp == CMP_RELATIVEERR)) {
    if((expected_status & trans_flags_mask) != (*pfpsf & trans_flags_mask) || check32_rel(r32, q32))
      print_mismatch(cmp);
  } else if(restype == OP_DEC128 && cmp == CMP_FUZZYSTATUS) {
    if(expected_status != *pfpsf || check128(r, q) || i1 != i2 || result_i64 != qi64 || check128(r_1, b))
      print_mismatch(cmp);
  } else if(restype == OP_LINT && cmp == CMP_FUZZYSTATUS) {
    if(expected_status != *pfpsf || li1 != li2)
      print_mismatch(cmp);
  } else if(restype == OP_DEC128 && cmp == CMP_RELATIVEERR) {
    if((expected_status & trans_flags_mask) != (*pfpsf & trans_flags_mask) || check128_rel(r, q))
      print_mismatch(cmp);
  } else if(restype == OP_DEC64 && cmp == CMP_FUZZYSTATUS) {
    if(expected_status != *pfpsf || check64(r64, q64) || i1 != i2 || result_i64 != qi64 || r64_1 != b64)
      print_mismatch(cmp);
  } else if(restype == OP_LINT && cmp == CMP_FUZZYSTATUS) {
    if(expected_status != *pfpsf || li1 != li2)
      print_mismatch(cmp);
  } else if(restype == OP_DEC64 && cmp == CMP_RELATIVEERR) {
    if((expected_status & trans_flags_mask) != (*pfpsf & trans_flags_mask) || check64_rel(r64, q64))
      print_mismatch(cmp);
  } else if(restype == OP_DEC128 && cmp == CMP_EQUALSTATUS) {
    int qnr_result;
    unsigned int tmp_pfpsf = *pfpsf;
    BIDECIMAL_CALL2_NORND(bid128_quiet_not_equal, qnr_result, q, r);
    if(expected_status != tmp_pfpsf || (check128(r, q) && qnr_result))
      print_mismatch(cmp);
  } else if(restype == OP_DEC64 && cmp == CMP_EQUALSTATUS) {
    int qnr_result;
    unsigned int tmp_pfpsf = *pfpsf;
    BIDECIMAL_CALL2_NORND(bid64_quiet_not_equal, qnr_result, q64, r64);
    if(expected_status != tmp_pfpsf || (check64(r64, q64) && qnr_result))
      print_mismatch(cmp);
  } else if(restype == OP_DEC32 && cmp == CMP_EQUALSTATUS) {
    int qnr_result;
    unsigned int tmp_pfpsf = *pfpsf;
    BIDECIMAL_CALL2_NORND(bid32_quiet_not_equal, qnr_result, q32, r32);
    if(expected_status != tmp_pfpsf || (check32(r32, q32) && qnr_result))
      print_mismatch(cmp);
  } else if(restype == OP_DPD32 && cmp == CMP_FUZZYSTATUS) {
    if(expected_status != *pfpsf || check32(r32, q32))
      print_mismatch(cmp);
  } else if(restype == OP_DPD64 && cmp == CMP_FUZZYSTATUS) {
    if(expected_status != *pfpsf || check64(r64, q64))
      print_mismatch(cmp);
  } else if(restype == OP_DPD128 && cmp == CMP_FUZZYSTATUS) {
    if(expected_status != *pfpsf || check128(r, q))
      print_mismatch(cmp);
  } else if(restype == OP_INT32 || restype == OP_INT16 || restype == OP_INT8) {
    if(expected_status != *pfpsf || i1 != i2)
      print_mismatch(cmp);
  } else if(restype == OP_BID_UINT32 || restype == OP_BID_UINT16 || restype == OP_BID_UINT8) {
    if(expected_status != *pfpsf || i1 != i2)
      print_mismatch(cmp);
  } else if(restype == OP_INT64) {
    if(expected_status != *pfpsf || result_i64 != qi64)
      print_mismatch(cmp);
  } else if(restype == OP_BID_UINT64) {
    if(expected_status != *pfpsf || result_i64 != qi64)
      print_mismatch(cmp);
  } else if(restype == OP_BIN128) {
    if(expected_status != *pfpsf || *((BID_UINT64 *)&rquad) != *((BID_UINT64 *)&rtquad) || *((BID_UINT64 *)&rquad + 1) != *((BID_UINT64 *)&rtquad + 1))
      print_mismatch(cmp);
  } else if(restype == OP_BIN80) {
    if(expected_status != *pfpsf || *((BID_UINT64 *)&rldbl) != *((BID_UINT64 *)&rtldbl) || (*((BID_UINT64 *)&rldbl + 1) & 0xffff) != (*((BID_UINT64 *)&rtldbl + 1) & 0xffff))
      print_mismatch(cmp);
  } else if(restype == OP_BIN64) {
    if(expected_status != *pfpsf || (*(BID_UINT64 *)&rdbl != *(BID_UINT64 *)&rtdbl))
      print_mismatch(cmp);
  } else if(restype == OP_BIN32) {
    if(expected_status != *pfpsf || (*(BID_UINT32 *)&rflt != *(BID_UINT32 *)&rtflt))
      print_mismatch(cmp);
  } else if(restype == OP_DPD64 && cmp == CMP_EXACTSTATUS) {
    if(expected_status != *pfpsf || r64 != q64)
      print_mismatch(cmp);
  } else if(restype == OP_DPD32 && cmp == CMP_EXACTSTATUS) {
    if(expected_status != *pfpsf || r32 != q32)
      print_mismatch(cmp);
  } else if(restype == OP_DPD128 && cmp == CMP_EXACTSTATUS) {
    if(expected_status != *pfpsf || r.w[BID_LOW_128W] != q.w[BID_LOW_128W] || r.w[BID_HIGH_128W] != q.w[BID_HIGH_128W])
      print_mismatch(cmp);
  } else {
    printf("Unknown combination of result type (%d) and compare type (%d)\n",
           restype, cmp);
    // exit(EXIT_FAILURE);
  }
}

// int st_compare(void *a, void *b) {
int st_compare(char **a_in, char **b_in) {
  return strcmp(*a_in, *b_in);
}

int status_compare(char *stat1, char *stat2) {
  char s1[STRMAX], s2[STRMAX];
  char *wp1[64], *wp2[64];
  int wp1n = 0, wp2n = 0;
  char *p;
  int i;

  strcpy(s1, stat1);
  strcpy(s2, stat2);
  for(p = s1; *p; p++) {
    wp1[wp1n++] = p;
    while(*p && *++p != ' ')
      ;
    if(*p == ' ') {
      *p = 0;
      // printf("Found 1: %s\n", wp1[wp1n-1]);
      continue;
    } else {
      // printf("Found 1: %s\n", wp1[wp1n-1]);
      break;
    }
  }
  for(p = s2; *p; p++) {
    wp2[wp2n++] = p;
    while(*p && *++p != ' ')
      ;
    if(*p == ' ') {
      *p = 0;
      // printf("Found 2: %s\n", wp2[wp2n-1]);
      continue;
    } else {
      // printf("Found 2: %s\n", wp2[wp2n-1]);
      break;
    }
  }
  if(wp1n != wp2n)
    return 1;
#ifdef LINUX
  qsort(wp1, (size_t)wp1n, sizeof(char *), (__compar_fn_t)st_compare);
  qsort(wp2, (size_t)wp2n, sizeof(char *), (__compar_fn_t)st_compare);
#else
  qsort(wp1, (size_t)wp1n, sizeof(char *),
        (int(__cdecl *)(const void *, const void *))st_compare);
  qsort(wp2, (size_t)wp2n, sizeof(char *),
        (int(__cdecl *)(const void *, const void *))st_compare);
#endif
  for(i = 0; i < wp1n; i++) {
    // printf("Comparing %s and %s\n", wp1[i], wp2[i]);
    if(strcmp(wp1[i], wp2[i]))
      return 1;
  }
  return 0;
}

int check_skip(char *funcptr) {
  if(no128trans) {
    if(!strcmp(funcptr, "bid128_sin") || !strcmp(funcptr, "bid128_cos") || !strcmp(funcptr, "bid128_tan") ||
       !strcmp(funcptr, "bid128_asin") || !strcmp(funcptr, "bid128_acos") || !strcmp(funcptr, "bid128_atan") ||
       !strcmp(funcptr, "bid128_sinh") || !strcmp(funcptr, "bid128_cosh") || !strcmp(funcptr, "bid128_tanh") ||
       !strcmp(funcptr, "bid128_asinh") || !strcmp(funcptr, "bid128_acosh") || !strcmp(funcptr, "bid128_atanh") ||
       !strcmp(funcptr, "bid128_exp") || !strcmp(funcptr, "bid128_expm1") ||
       !strcmp(funcptr, "bid128_log") || !strcmp(funcptr, "bid128_log10") || !strcmp(funcptr, "bid128_log1p") ||
       !strcmp(funcptr, "bid128_atan2") || !strcmp(funcptr, "bid128_hypot") || !strcmp(funcptr, "bid128_pow") ||
       !strcmp(funcptr, "bid128_cbrt"))
      return 1;
  }
  if(no64trans) {
    if(!strcmp(funcptr, "bid64_sin") || !strcmp(funcptr, "bid64_cos") || !strcmp(funcptr, "bid64_tan") ||
       !strcmp(funcptr, "bid64_asin") || !strcmp(funcptr, "bid64_acos") || !strcmp(funcptr, "bid64_atan") ||
       !strcmp(funcptr, "bid64_sinh") || !strcmp(funcptr, "bid64_cosh") || !strcmp(funcptr, "bid64_tanh") ||
       !strcmp(funcptr, "bid64_asinh") || !strcmp(funcptr, "bid64_acosh") || !strcmp(funcptr, "bid64_atanh") ||
       !strcmp(funcptr, "bid64_exp") || !strcmp(funcptr, "bid64_expm1") ||
       !strcmp(funcptr, "bid64_log") || !strcmp(funcptr, "bid64_log10") || !strcmp(funcptr, "bid64_log1p") ||
       !strcmp(funcptr, "bid64_atan2") || !strcmp(funcptr, "bid64_hypot") || !strcmp(funcptr, "bid64_pow") ||
       !strcmp(funcptr, "bid64_cbrt"))
      return 1;
  }
  if(li_size_run != li_size_test)
    return 1;
  return 0;
}

void check_snan_passing32(float x) {
  int *px = (int *)&x;
  if(*(px) & 0x00400000)
    s_na_n_passed_incorrectly32 = 1;
}

void check_snan_passing64(double x) {
  int *px = (int *)&x;
  if(*(px + BID_HIGH_128W) & 0x00080000)
    s_na_n_passed_incorrectly64 = 1;
}

void check_snan_passing80(long double x) {
  int *px = (int *)&x;
#if BID_BIG_ENDIAN
  if(*(px + BID_HIGH_128W) & 0x40000000)
    SNaN_passed_incorrectly80 = 1;
#else
  if(*(px) & 0x00008000)
    s_na_n_passed_incorrectly80 = 1;
#endif
}

void check_den_passing32(float x) {
  (void)x;
#if !defined _MSC_VER && !defined __INTEL_COMPILER
  fexcept_t ff;
  fegetexceptflag(&ff, FE_ALL_EXCEPT);
  if(ff & FE_DENORMAL)
    Den_passed_incorrectly32 = 1;
#endif
}
void check_den_passing64(double x) {
  (void)x;
#if !defined _MSC_VER && !defined __INTEL_COMPILER
  fexcept_t ff;
  fegetexceptflag(&ff, FE_ALL_EXCEPT);
  if(ff & FE_DENORMAL)
    Den_passed_incorrectly64 = 1;
#endif
}
void check_den_passing80(long double x) {
  (void)x;
#if !defined _MSC_VER && !defined __INTEL_COMPILER
  fexcept_t ff;
  fegetexceptflag(&ff, FE_ALL_EXCEPT);
  if(ff & FE_DENORMAL)
    Den_passed_incorrectly80 = 1;
#endif
}

int main(int argc, char *argv[]) {
  int skip_test;
  char **arg;
  char *end_of_args = (char *)-1;

  strcpy(rounding, "half_even");

  const size_t size_long_int = sizeof(long int);
  if(size_long_int == 8U) {
    li_size_test = 64;
    li_size_run = 64;
  } else {
    li_size_test = 32;
    li_size_run = 32;
  }

  arg = argv + 1;                                 // point to first command-line parameter
  while((*arg) && (**arg == '-') && (argc > 0)) { // Process all options
    if(strcmp(*arg, "-d") == 0)
      debug_opt = 1;
    if(strcmp(*arg, "-ub") == 0)
      underflow_before_opt = 1;
    if(strcmp(*arg, "-ua") == 0)
      underflow_after_opt = 1;
    if(strcmp(*arg, "-h") == 0) {
      printf("Usage: runtests [-d]\n");
      exit(0);
    }
    if(strcmp(*arg, "-ulp") == 0) {
      ++arg;
      --argc;
      (void)sscanf(*arg, "%lf", &mre_max[0]);
      mre_max[4] = mre_max[3] = mre_max[2] = mre_max[1] = mre_max[0];
    }
    if(strcmp(*arg, "-bin_flags") == 0) {
      check_binary_flags_opt = 1;
      ++arg;
      --argc;
      (void)sscanf(*arg, "%x", (int *)&ini_binary_flags);
    }
    if(strcmp(*arg, "-no128trans") == 0) {
      no128trans = 1;
    }
    if(strcmp(*arg, "-no64trans") == 0) {
      no64trans = 1;
    }
    arg++;
  }

  if(underflow_before_opt && underflow_after_opt) {
    printf("Both underflow before and after rounding checking mode set, please specify just one.\n");
    printf("Usage: runtests [-d]\n");
    exit(0);
  } else if(!underflow_before_opt && !underflow_after_opt)
    underflow_before_opt = 1;

  rnd_mode = 0;
  rnd_mode |= BID_ROUNDING_TO_NEAREST;

  *((int *)&snan_check64 + BID_HIGH_128W) = 0x7ff00000;
  *((int *)&snan_check64 + BID_LOW_128W) = 0x00000001;
  check_snan_passing64(snan_check64);
  *((int *)&snan_check32) = 0x7f800010;
  check_snan_passing32(snan_check32);
#if BID_BIG_ENDIAN
  *((int *)&snan_check80) = 0x7fff8000;
  *((int *)&snan_check80 + 1) = 0;
  *((short *)&snan_check80 + 4) = 1;
#else
  *((short *)&snan_check80 + 4) = 0x7fff;
  *((unsigned int *)&snan_check80 + 1) = 0x80000000u;
  *((int *)&snan_check80 + 0) = 0x00000001;
#endif
  check_snan_passing80(snan_check80);

  *((int *)&snan_check64 + BID_HIGH_128W) = 0x00000000;
  *((int *)&snan_check64 + BID_LOW_128W) = 0x00000001;
#if !defined _MSC_VER && !defined __INTEL_COMPILER
  feclearexcept(FE_ALL_EXCEPT);
  check_den_passing64(snan_check64);
  *((int *)&snan_check32) = 0x00000001;
  feclearexcept(FE_ALL_EXCEPT);
  check_den_passing32(snan_check32);
#endif
#if BID_BIG_ENDIAN
  *((short *)&snan_check80 + 4) = 0x0000;
  *((int *)&snan_check80 + 1) = 0x00000000;
  *((int *)&snan_check80 + 0) = 0x00000001;
#else
  *((int *)&snan_check80) = 0x00000000;
  *((int *)&snan_check80 + 1) = 0;
  *((short *)&snan_check80 + 4) = 1;
#endif
#if !defined _MSC_VER && !defined __INTEL_COMPILER
  feclearexcept(FE_ALL_EXCEPT);
  check_den_passing80(snan_check80);
  feclearexcept(FE_ALL_EXCEPT);
#endif
  // printf("snan32 passed incorr %d\n", SNaN_passed_incorrectly32);
  // printf("snan64 passed incorr %d\n", SNaN_passed_incorrectly64);
  // printf("snan80 passed incorr %d\n", SNaN_passed_incorrectly80);
  // printf("den32 passed incorr %d\n", Den_passed_incorrectly32);
  // printf("den64 passed incorr %d\n", Den_passed_incorrectly64);
  // printf("den80 passed incorr %d\n", Den_passed_incorrectly80);

  line_counter = 0;
  while(!feof(stdin)) {
    char *p;

    op1type = OP_NONE;
    op2type = OP_NONE;
    op3type = OP_NONE;
    restype = OP_NONE;

    fgets(line, 1023, stdin);
    line_counter++;
    str_remove0_d0_a(line);
    strcpy(full_line, line);
    if(feof(stdin))
      break;

    // printf("Read line: %s", line);
    p = strstr(line, "--");
    if(p)
      *p = 0; // Remove comment
    str_remove_trailing_spaces(line);

    // Reset BID status flags
    *pfpsf = 0;

    if(line[0] == 0)
      continue;

    // Extract ulp field from line, if present:
    p = strstr(line, "ulp=");
    if(p) {
      if(p < end_of_args)
        end_of_args = p;
      if(sscanf(p + 4, "%le", &ulp_add) != 1)
        ulp_add = 0.0;
    } else {
      ulp_add = 0.0;
    }

    // Determine if underflow, indicated as expected have to be set only for before rounding mode
    p = strstr(line, "underflow_before_only");
    if(p) {
      if(p < end_of_args)
        end_of_args = p;
      underflow_before = 1;
    } else {
      underflow_before = 0;
    }

    // Read string prefix for from string conversions
    p = strstr(line, "str_prefix=");
    if(p) {
      if(p < end_of_args)
        end_of_args = p;
      {
        int i = 0;
        while(*(p + 12 + i) != '|' && *(p + 12 + i) != 0) {
          str_prefix[i] = *(p + 12 + i);
          i++;
        }
        str_prefix[i] = 0;
      }
    } else {
      strcpy(str_prefix, "");
    }

    // Extract long int size from line, if present:
    p = strstr(line, "longintsize=");
    if(p) {
      if(p < end_of_args)
        end_of_args = p;
      if(sscanf(p + 12, "%d", &li_size_test) != 1)
        li_size_test = 0;
    } else {
      li_size_test = li_size_run;
    }

    // printf();
    if(end_of_args != (char *)-1) {
      *end_of_args = 0;
      str_remove_trailing_spaces(line);
      end_of_args = (char *)-1;
    }

    args_set = 0;
    if(sscanf(line, "%s %d %s %s %s %s %x", funcstr, &rnd_mode,
              op1, op2, op3, res, &expected_status) == 7) {
      // printf("read8 %d\n", rnd_mode);
      args_set = 1;
    }
    if(!args_set) {
      if(sscanf(line, "%s %d %s %s %s %x", funcstr, &rnd_mode,
                op1, op2, res, &expected_status) == 6) {
        // printf("read7 %d\n", rnd_mode);
        args_set = 1;
      }
    }
    if(!args_set) {
      if(sscanf(line, "%s %d %s %s %x", funcstr, &rnd_mode, op1,
                res, &expected_status) == 5) {
        // printf("read6 %d\n", rnd_mode);
        args_set = 1;
      }
    }

    skip_test = check_skip(funcstr);
    pollution_workaround = check_pollution_workaround();

    // printf("str %s op1 %s, skip %d\n", line, op1, skip_test);
    if(args_set && !skip_test) {
      rnd = rnd_mode;
      // set ulp thresholds for transcendentals
      p = strstr(funcstr, "128");
      if(p) {
        mre_max[0] = 2.0;
        mre_max[1] = 5.0;
        mre_max[2] = 5.0;
        mre_max[3] = 5.0;
        mre_max[4] = 2.0;
      } else {
        p = strstr(funcstr, "64");
        if(p) {
          mre_max[0] = 0.55;
          mre_max[1] = 1.05;
          mre_max[2] = 1.05;
          mre_max[3] = 1.05;
          mre_max[4] = 0.55;
        } else {
          p = strstr(funcstr, "32");
          if(p) {
            mre_max[0] = 0.5;
            mre_max[1] = 1.01;
            mre_max[2] = 1.01;
            mre_max[3] = 1.01;
            mre_max[4] = 0.5;
          }
        }
      }

      strcpy(rounding, roundstr_bid[rnd]);

      // clean expected underflow if it is for before rounding mode and we are checking after rounidng
      if((expected_status & 0x10u) && underflow_before && underflow_after_opt)
        expected_status &= ~0x00000010u;

#include "readtest.h"

    } else {
      if(!skip_test)
        printf("SKIPPED (line %d): %s\n", line_counter, line);
    }
  }

  printf("Total tests: %d, failed result: %d, failed status: %d\n",
         tests, fail_res, fail_status);
  if((fail_res == 0) && (fail_status == 0)) {
    return EXIT_SUCCESS;
  }
  return EXIT_FAILURE;
}

int copy_str_to_wstr(void) {
  int i = 0;
  if(strstr(funcstr, "wcstod")) {
    while(istr1[i] != 0 && istr1[i] != '\n') {
      wistr1[i] = (wchar_t)istr1[i];
      i++;
    }
    wistr1[i] = 0;
  }
  return 1;
}

void save_binary_status(void) {
#if !defined _MSC_VER && !defined __INTEL_COMPILER
  if(check_binary_flags_opt) {
    feclearexcept(FE_ALL_EXCEPT);
    fesetexceptflag(&ini_binary_flags, FE_ALL_EXCEPT);
    fegetexceptflag(&saved_binary_flags, FE_ALL_EXCEPT);
  }
#endif
}

int check_restore_binary_status(void) {
  char *p = NULL;
  // printf("snan arg, passed incor %d %d\n", arg64_snan, SNaN_passed_incorrectly64);
  if(check_binary_flags_opt || debug_opt) {
#if !defined _MSC_VER && !defined __INTEL_COMPILER
    fegetexceptflag(&test_binary_flags, FE_ALL_EXCEPT);

    p = strstr(func, "binary32_to");
    if(p) {
      if(arg32_den && Den_passed_incorrectly32)
        saved_binary_flags |= (test_binary_flags & FE_UNNORMAL);
      if(arg32_snan && SNaN_passed_incorrectly32)
        saved_binary_flags |= (test_binary_flags & FE_INVALID);
    }
    p = strstr(func, "binary64_to");
    if(p) {
      if(arg64_den && Den_passed_incorrectly64)
        saved_binary_flags |= (test_binary_flags & FE_UNNORMAL);
      if(arg64_snan && SNaN_passed_incorrectly64)
        saved_binary_flags |= (test_binary_flags & FE_INVALID);
    }
    p = strstr(func, "binary80_to");
    if(p) {
      if(arg80_den && Den_passed_incorrectly80)
        saved_binary_flags |= (test_binary_flags & FE_UNNORMAL);
      if(arg80_snan && SNaN_passed_incorrectly80)
        saved_binary_flags |= (test_binary_flags & FE_INVALID);
    }
    // !!!! Workaround, do not favor non-standard denormal flag for now
    saved_binary_flags |= (test_binary_flags & FE_UNNORMAL);
    // !!!! Workaround, do not favor non-standard denormal flag for now
    if(test_binary_flags != saved_binary_flags && !pollution_workaround) {
      printf("// ERROR: BINARY Exception flags polluted!\n");
      printf("//        Saved value %X, value after BID call %X\n", *(int *)&saved_binary_flags, *(int *)&test_binary_flags);
      return 1;
    }
#else
    (void)p;
#endif
  }
  return 0;
}

int check_pollution_workaround(void) {
  if((strstr(func, "sin") != NULL) ||
     (strstr(func, "cos") != NULL) ||
     (strstr(func, "tan") != NULL) ||
     (strstr(func, "exp") != NULL) ||
     (strstr(func, "log") != NULL) ||
     (strstr(func, "erf") != NULL) ||
     (strstr(func, "hypot") != NULL) ||
     (strstr(func, "pow") != NULL) ||
     (strstr(func, "cbrt") != NULL) ||
     (strstr(func, "gamma") != NULL)) {
    return 1;
  } else {
    return 0;
  }
}
