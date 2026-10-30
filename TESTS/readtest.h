/******************************************************************************
  Copyright (c) 2007-2025, Intel Corp.
  All rights reserved.

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions are met:

    * Redistributions of source code must retain the above copyright notice,
      this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of Intel Corporation nor the names of its contributors
      may be used to endorse or promote products derived from this software
      without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
  THE POSSIBILITY OF SUCH DAMAGE.
******************************************************************************/

if(strcmp(func, "bid64_add") == 0) {
  GETTEST2(OP_DEC64, OP_DEC64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2(bid64_add, q64, a64, b64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_sub") == 0) {
  GETTEST2(OP_DEC64, OP_DEC64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2(bid64_sub, q64, a64, b64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_mul") == 0) {
  GETTEST2(OP_DEC64, OP_DEC64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2(bid64_mul, q64, a64, b64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64dq_add") == 0) {
  GETTEST2(OP_DEC64, OP_DEC64, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2(bid64dq_add, q64, a64, b);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64qd_add") == 0) {
  GETTEST2(OP_DEC64, OP_DEC128, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2(bid64qd_add, q64, a, b64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64qq_add") == 0) {
  GETTEST2(OP_DEC64, OP_DEC128, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2(bid64qq_add, q64, a, b);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64dq_sub") == 0) {
  GETTEST2(OP_DEC64, OP_DEC64, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2(bid64dq_sub, q64, a64, b);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64qd_sub") == 0) {
  GETTEST2(OP_DEC64, OP_DEC128, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2(bid64qd_sub, q64, a, b64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64qq_sub") == 0) {
  GETTEST2(OP_DEC64, OP_DEC128, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2(bid64qq_sub, q64, a, b);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64dq_mul") == 0) {
  GETTEST2(OP_DEC64, OP_DEC64, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2(bid64dq_mul, q64, a64, b);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64qd_mul") == 0) {
  GETTEST2(OP_DEC64, OP_DEC128, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2(bid64qd_mul, q64, a, b64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64qq_mul") == 0) {
  GETTEST2(OP_DEC64, OP_DEC128, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2(bid64qq_mul, q64, a, b);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_div") == 0) {
  GETTEST2(OP_DEC64, OP_DEC64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2(bid64_div, q64, a64, b64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64dq_div") == 0) {
  GETTEST2(OP_DEC64, OP_DEC64, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2(bid64dq_div, q64, a64, b);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64qd_div") == 0) {
  GETTEST2(OP_DEC64, OP_DEC128, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2(bid64qd_div, q64, a, b64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64qq_div") == 0) {
  GETTEST2(OP_DEC64, OP_DEC128, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2(bid64qq_div, q64, a, b);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_rem") == 0) {
  GETTEST2(OP_DEC64, OP_DEC64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND(bid64_rem, q64, a64, b64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_fmod") == 0) {
  GETTEST2(OP_DEC64, OP_DEC64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND(bid64_fmod, q64, a64, b64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_minnum") == 0) {
  GETTEST2(OP_DEC32, OP_DEC32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND(bid32_minnum, q32, a32, b32);
    fpsf_0 = 0;
    check_results(CMP_EQUALSTATUS);
  }
}
if(strcmp(func, "bid32_maxnum") == 0) {
  GETTEST2(OP_DEC32, OP_DEC32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND(bid32_maxnum, q32, a32, b32);
    fpsf_0 = 0;
    check_results(CMP_EQUALSTATUS);
  }
}
if(strcmp(func, "bid32_minnum_mag") == 0) {
  GETTEST2(OP_DEC32, OP_DEC32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND(bid32_minnum_mag, q32, a32, b32);
    fpsf_0 = 0;
    check_results(CMP_EQUALSTATUS);
  }
}
if(strcmp(func, "bid32_maxnum_mag") == 0) {
  GETTEST2(OP_DEC32, OP_DEC32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND(bid32_maxnum_mag, q32, a32, b32);
    fpsf_0 = 0;
    check_results(CMP_EQUALSTATUS);
  }
}
if(strcmp(func, "bid64_minnum") == 0) {
  GETTEST2(OP_DEC64, OP_DEC64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND(bid64_minnum, q64, a64, b64);
    fpsf_0 = 0;
    check_results(CMP_EQUALSTATUS);
  }
}
if(strcmp(func, "bid64_maxnum") == 0) {
  GETTEST2(OP_DEC64, OP_DEC64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND(bid64_maxnum, q64, a64, b64);
    fpsf_0 = 0;
    check_results(CMP_EQUALSTATUS);
  }
}
if(strcmp(func, "bid64_minnum_mag") == 0) {
  GETTEST2(OP_DEC64, OP_DEC64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND(bid64_minnum_mag, q64, a64, b64);
    fpsf_0 = 0;
    check_results(CMP_EQUALSTATUS);
  }
}
if(strcmp(func, "bid64_maxnum_mag") == 0) {
  GETTEST2(OP_DEC64, OP_DEC64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND(bid64_maxnum_mag, q64, a64, b64);
    fpsf_0 = 0;
    check_results(CMP_EQUALSTATUS);
  }
}
if(strcmp(func, "bid64_quantize") == 0) {
  GETTEST2(OP_DEC64, OP_DEC64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2(bid64_quantize, q64, a64, b64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64q_sqrt") == 0) {
  GETTEST1(OP_DEC64, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid64q_sqrt, q64, a);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_sqrt") == 0) {
  GETTEST1(OP_DEC64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid64_sqrt, q64, a64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_round_integral_nearest_even") == 0) {
  GETTEST1(OP_DEC32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid32_round_integral_nearest_even, q32, a32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_round_integral_nearest_away") == 0) {
  GETTEST1(OP_DEC32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid32_round_integral_nearest_away, q32, a32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_round_integral_positive") == 0) {
  GETTEST1(OP_DEC32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid32_round_integral_positive, q32, a32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_round_integral_negative") == 0) {
  GETTEST1(OP_DEC32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid32_round_integral_negative, q32, a32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_round_integral_zero") == 0) {
  GETTEST1(OP_DEC32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid32_round_integral_zero, q32, a32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_round_integral_exact") == 0) {
  GETTEST1(OP_DEC32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid32_round_integral_exact, q32, a32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_nearbyint") == 0) {
  GETTEST1(OP_DEC32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid32_nearbyint, q32, a32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_round_integral_nearest_even") == 0) {
  GETTEST1(OP_DEC64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid64_round_integral_nearest_even, q64, a64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_round_integral_nearest_away") == 0) {
  GETTEST1(OP_DEC64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid64_round_integral_nearest_away, q64, a64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_round_integral_positive") == 0) {
  GETTEST1(OP_DEC64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid64_round_integral_positive, q64, a64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_round_integral_negative") == 0) {
  GETTEST1(OP_DEC64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid64_round_integral_negative, q64, a64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_round_integral_zero") == 0) {
  GETTEST1(OP_DEC64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid64_round_integral_zero, q64, a64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_round_integral_exact") == 0) {
  GETTEST1(OP_DEC64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid64_round_integral_exact, q64, a64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_nearbyint") == 0) {
  GETTEST1(OP_DEC64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid64_nearbyint, q64, a64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_nextup") == 0) {
  GETTEST1(OP_DEC32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid32_nextup, q32, a32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_nextdown") == 0) {
  GETTEST1(OP_DEC32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid32_nextdown, q32, a32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_nextafter") == 0) {
  GETTEST2(OP_DEC32, OP_DEC32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND(bid32_nextafter, q32, a32, b32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_nexttoward") == 0) {
  GETTEST2(OP_DEC32, OP_DEC32, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND(bid32_nexttoward, q32, a32, b);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_nextup") == 0) {
  GETTEST1(OP_DEC64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid64_nextup, q64, a64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_nextdown") == 0) {
  GETTEST1(OP_DEC64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid64_nextdown, q64, a64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_nextafter") == 0) {
  GETTEST2(OP_DEC64, OP_DEC64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND(bid64_nextafter, q64, a64, b64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_nexttoward") == 0) {
  GETTEST2(OP_DEC64, OP_DEC64, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND(bid64_nexttoward, q64, a64, b);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_nextup") == 0) {
  GETTEST1(OP_DEC128, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid128_nextup, q, a);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_nextdown") == 0) {
  GETTEST1(OP_DEC128, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid128_nextdown, q, a);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_nextafter") == 0) {
  GETTEST2(OP_DEC128, OP_DEC128, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND(bid128_nextafter, q, a, b);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_nexttoward") == 0) {
  GETTEST2(OP_DEC128, OP_DEC128, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND(bid128_nexttoward, q, a, b);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_fma") == 0) {
  GETTEST3(OP_DEC64, OP_DEC64, OP_DEC64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL3(bid64_fma, q64, a64, b64, c_c64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64ddq_fma") == 0) {
  GETTEST3(OP_DEC64, OP_DEC64, OP_DEC64, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL3(bid64ddq_fma, q64, a64, b64, c);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64dqd_fma") == 0) {
  GETTEST3(OP_DEC64, OP_DEC64, OP_DEC128, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL3(bid64dqd_fma, q64, a64, b, c_c64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64dqq_fma") == 0) {
  GETTEST3(OP_DEC64, OP_DEC64, OP_DEC128, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL3(bid64dqq_fma, q64, a64, b, c);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64qdd_fma") == 0) {
  GETTEST3(OP_DEC64, OP_DEC128, OP_DEC64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL3(bid64qdd_fma, q64, a, b64, c_c64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64qdq_fma") == 0) {
  GETTEST3(OP_DEC64, OP_DEC128, OP_DEC64, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL3(bid64qdq_fma, q64, a, b64, c);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64qqd_fma") == 0) {
  GETTEST3(OP_DEC64, OP_DEC128, OP_DEC128, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL3(bid64qqd_fma, q64, a, b, c_c64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64qqq_fma") == 0) {
  GETTEST3(OP_DEC64, OP_DEC128, OP_DEC128, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL3(bid64qqq_fma, q64, a, b, c);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "str64") == 0) {
  GETTEST1(OP_DEC64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    q64 = a64;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_from_string") == 0) {
  GETTEST1(OP_DEC64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_RESARG(bid64_from_string, q64, istr1);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_from_string") == 0) {
  GETTEST1(OP_DEC128, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_RESARG(bid128_from_string, q, istr1);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_to_string") == 0) {
  GETTEST1(OP_DEC64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND_RESREF(bid64_to_string, convstr, a64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_to_string") == 0) {
  GETTEST1(OP_DEC128, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND_RESREF(bid128_to_string, convstr, a);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_copy") == 0) {
  GETTEST1(OP_DEC32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND_NOSTAT(bid32_copy, q32, a32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_negate") == 0) {
  GETTEST1(OP_DEC32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND_NOSTAT(bid32_negate, q32, a32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_abs") == 0) {
  GETTEST1(OP_DEC32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND_NOSTAT(bid32_abs, q32, a32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_copySign") == 0) {
  GETTEST2(OP_DEC32, OP_DEC32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND_NOSTAT(bid32_copySign, q32, a32, b32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_copy") == 0) {
  GETTEST1(OP_DEC64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND_NOSTAT(bid64_copy, q64, a64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_negate") == 0) {
  GETTEST1(OP_DEC64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND_NOSTAT(bid64_negate, q64, a64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_abs") == 0) {
  GETTEST1(OP_DEC64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND_NOSTAT(bid64_abs, q64, a64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_copySign") == 0) {
  GETTEST2(OP_DEC64, OP_DEC64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND_NOSTAT(bid64_copySign, q64, a64, b64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_copy") == 0) {
  GETTEST1(OP_DEC128, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND_NOSTAT(bid128_copy, q, a);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_class") == 0) {
  GETTEST1(OP_INT32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND_NOSTAT(bid32_class, i2, a32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_class") == 0) {
  GETTEST1(OP_INT32, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND_NOSTAT(bid64_class, i2, a64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_class") == 0) {
  GETTEST1(OP_INT32, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND_NOSTAT(bid128_class, i2, a);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_negate") == 0) {
  GETTEST1(OP_DEC128, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND_NOSTAT(bid128_negate, q, a);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_abs") == 0) {
  GETTEST1(OP_DEC128, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND_NOSTAT(bid128_abs, q, a);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_copySign") == 0) {
  GETTEST2(OP_DEC128, OP_DEC128, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND_NOSTAT(bid128_copySign, q, a, b);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid_dpd_to_bid32") == 0) {
  GETTEST1(OP_DEC32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND_NOSTAT(bid_dpd_to_bid32, q32, *(BID_UINT32 *)&a32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid_dpd_to_bid64") == 0) {
  GETTEST1(OP_DEC64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND_NOSTAT(bid_dpd_to_bid64, q64, *(BID_UINT64 *)&a64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid_dpd_to_bid128") == 0) {
  GETTEST1(OP_DEC128, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND_NOSTAT(bid_dpd_to_bid128, q, *(BID_UINT128 *)&a);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid_to_dpd32") == 0) {
  GETTEST1(OP_DPD32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND_NOSTAT(bid_to_dpd32, *(BID_UINT32 *)&q32, a32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid_to_dpd64") == 0) {
  GETTEST1(OP_DPD64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND_NOSTAT(bid_to_dpd64, *(BID_UINT64 *)&q64, a64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid_to_dpd128") == 0) {
  GETTEST1(OP_DPD128, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND_NOSTAT(bid_to_dpd128, *(BID_UINT128 *)&q, a);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_quiet_not_equal") == 0) {
  GETTEST2(OP_INT32, OP_DEC64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND(bid64_quiet_not_equal, i2, a64, b64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_quiet_not_equal") == 0) {
  GETTEST2(OP_INT32, OP_DEC128, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND(bid128_quiet_not_equal, i2, a, b);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_quiet_ordered") == 0) {
  GETTEST2(OP_INT32, OP_DEC64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND(bid64_quiet_ordered, i2, a64, b64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_quiet_ordered") == 0) {
  GETTEST2(OP_INT32, OP_DEC128, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND(bid128_quiet_ordered, i2, a, b);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_quiet_unordered") == 0) {
  GETTEST2(OP_INT32, OP_DEC64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND(bid64_quiet_unordered, i2, a64, b64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_quiet_unordered") == 0) {
  GETTEST2(OP_INT32, OP_DEC128, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND(bid128_quiet_unordered, i2, a, b);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_quiet_greater_unordered") == 0) {
  GETTEST2(OP_INT32, OP_DEC64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND(bid64_quiet_greater_unordered, i2, a64, b64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_quiet_greater_unordered") == 0) {
  GETTEST2(OP_INT32, OP_DEC128, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND(bid128_quiet_greater_unordered, i2, a, b);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_quiet_less_unordered") == 0) {
  GETTEST2(OP_INT32, OP_DEC64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND(bid64_quiet_less_unordered, i2, a64, b64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_quiet_less_unordered") == 0) {
  GETTEST2(OP_INT32, OP_DEC128, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND(bid128_quiet_less_unordered, i2, a, b);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_quiet_greater_equal") == 0) {
  GETTEST2(OP_INT32, OP_DEC64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND(bid64_quiet_greater_equal, i2, a64, b64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_quiet_greater_equal") == 0) {
  GETTEST2(OP_INT32, OP_DEC128, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND(bid128_quiet_greater_equal, i2, a, b);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_quiet_not_less") == 0) {
  GETTEST2(OP_INT32, OP_DEC64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND(bid64_quiet_not_less, i2, a64, b64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_quiet_not_less") == 0) {
  GETTEST2(OP_INT32, OP_DEC128, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND(bid128_quiet_not_less, i2, a, b);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_quiet_less") == 0) {
  GETTEST2(OP_INT32, OP_DEC64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND(bid64_quiet_less, i2, a64, b64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_quiet_less") == 0) {
  GETTEST2(OP_INT32, OP_DEC128, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND(bid128_quiet_less, i2, a, b);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_quiet_less_equal") == 0) {
  GETTEST2(OP_INT32, OP_DEC64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND(bid64_quiet_less_equal, i2, a64, b64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_quiet_less_equal") == 0) {
  GETTEST2(OP_INT32, OP_DEC128, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND(bid128_quiet_less_equal, i2, a, b);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_quiet_not_greater") == 0) {
  GETTEST2(OP_INT32, OP_DEC64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND(bid64_quiet_not_greater, i2, a64, b64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_quiet_not_greater") == 0) {
  GETTEST2(OP_INT32, OP_DEC128, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND(bid128_quiet_not_greater, i2, a, b);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_quiet_greater") == 0) {
  GETTEST2(OP_INT32, OP_DEC64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND(bid64_quiet_greater, i2, a64, b64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_quiet_greater") == 0) {
  GETTEST2(OP_INT32, OP_DEC128, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND(bid128_quiet_greater, i2, a, b);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_quiet_equal") == 0) {
  GETTEST2(OP_INT32, OP_DEC64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND(bid64_quiet_equal, i2, a64, b64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_quiet_equal") == 0) {
  GETTEST2(OP_INT32, OP_DEC128, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND(bid128_quiet_equal, i2, a, b);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_signaling_greater_unordered") == 0) {
  GETTEST2(OP_INT32, OP_DEC64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND(bid64_signaling_greater_unordered, i2, a64, b64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_signaling_greater_unordered") == 0) {
  GETTEST2(OP_INT32, OP_DEC128, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND(bid128_signaling_greater_unordered, i2, a, b);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_signaling_less_unordered") == 0) {
  GETTEST2(OP_INT32, OP_DEC64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND(bid64_signaling_less_unordered, i2, a64, b64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_signaling_less_unordered") == 0) {
  GETTEST2(OP_INT32, OP_DEC128, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND(bid128_signaling_less_unordered, i2, a, b);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_signaling_greater_equal") == 0) {
  GETTEST2(OP_INT32, OP_DEC64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND(bid64_signaling_greater_equal, i2, a64, b64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_signaling_greater_equal") == 0) {
  GETTEST2(OP_INT32, OP_DEC128, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND(bid128_signaling_greater_equal, i2, a, b);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_signaling_not_less") == 0) {
  GETTEST2(OP_INT32, OP_DEC64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND(bid64_signaling_not_less, i2, a64, b64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_signaling_not_less") == 0) {
  GETTEST2(OP_INT32, OP_DEC128, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND(bid128_signaling_not_less, i2, a, b);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_signaling_less") == 0) {
  GETTEST2(OP_INT32, OP_DEC64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND(bid64_signaling_less, i2, a64, b64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_signaling_less") == 0) {
  GETTEST2(OP_INT32, OP_DEC128, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND(bid128_signaling_less, i2, a, b);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_signaling_less_equal") == 0) {
  GETTEST2(OP_INT32, OP_DEC64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND(bid64_signaling_less_equal, i2, a64, b64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_signaling_less_equal") == 0) {
  GETTEST2(OP_INT32, OP_DEC128, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND(bid128_signaling_less_equal, i2, a, b);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_signaling_not_greater") == 0) {
  GETTEST2(OP_INT32, OP_DEC64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND(bid64_signaling_not_greater, i2, a64, b64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_signaling_not_greater") == 0) {
  GETTEST2(OP_INT32, OP_DEC128, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND(bid128_signaling_not_greater, i2, a, b);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_signaling_greater") == 0) {
  GETTEST2(OP_INT32, OP_DEC64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND(bid64_signaling_greater, i2, a64, b64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_signaling_greater") == 0) {
  GETTEST2(OP_INT32, OP_DEC128, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND(bid128_signaling_greater, i2, a, b);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_add") == 0) {
  GETTEST2(OP_DEC128, OP_DEC128, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2(bid128_add, q, a, b);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_sub") == 0) {
  GETTEST2(OP_DEC128, OP_DEC128, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2(bid128_sub, q, a, b);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_mul") == 0) {
  GETTEST2(OP_DEC128, OP_DEC128, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2(bid128_mul, q, a, b);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128dq_add") == 0) {
  GETTEST2(OP_DEC128, OP_DEC64, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2(bid128dq_add, q, a64, b);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128qd_add") == 0) {
  GETTEST2(OP_DEC128, OP_DEC128, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2(bid128qd_add, q, a, b64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128dd_add") == 0) {
  GETTEST2(OP_DEC128, OP_DEC64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2(bid128dd_add, q, a64, b64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128dq_sub") == 0) {
  GETTEST2(OP_DEC128, OP_DEC64, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2(bid128dq_sub, q, a64, b);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128qd_sub") == 0) {
  GETTEST2(OP_DEC128, OP_DEC128, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2(bid128qd_sub, q, a, b64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128dd_sub") == 0) {
  GETTEST2(OP_DEC128, OP_DEC64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2(bid128dd_sub, q, a64, b64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128dd_mul") == 0) {
  GETTEST2(OP_DEC128, OP_DEC64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2(bid128dd_mul, q, a64, b64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128dq_mul") == 0) {
  GETTEST2(OP_DEC128, OP_DEC64, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2(bid128dq_mul, q, a64, b);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128qd_mul") == 0) {
  GETTEST2(OP_DEC128, OP_DEC128, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2(bid128qd_mul, q, a, b64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_div") == 0) {
  GETTEST2(OP_DEC128, OP_DEC128, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2(bid128_div, q, a, b);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128dq_div") == 0) {
  GETTEST2(OP_DEC128, OP_DEC64, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2(bid128dq_div, q, a64, b);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128qd_div") == 0) {
  GETTEST2(OP_DEC128, OP_DEC128, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2(bid128qd_div, q, a, b64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128dd_div") == 0) {
  GETTEST2(OP_DEC128, OP_DEC64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2(bid128dd_div, q, a64, b64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_fma") == 0) {
  GETTEST3(OP_DEC128, OP_DEC128, OP_DEC128, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL3(bid128_fma, q, a, b, c);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128ddd_fma") == 0) {
  GETTEST3(OP_DEC128, OP_DEC64, OP_DEC64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL3(bid128ddd_fma, q, a64, b64, c_c64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128ddq_fma") == 0) {
  GETTEST3(OP_DEC128, OP_DEC64, OP_DEC64, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL3(bid128ddq_fma, q, a64, b64, c);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128dqd_fma") == 0) {
  GETTEST3(OP_DEC128, OP_DEC64, OP_DEC128, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL3(bid128dqd_fma, q, a64, b, c_c64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128dqq_fma") == 0) {
  GETTEST3(OP_DEC128, OP_DEC64, OP_DEC128, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL3(bid128dqq_fma, q, a64, b, c);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128qdd_fma") == 0) {
  GETTEST3(OP_DEC128, OP_DEC128, OP_DEC64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL3(bid128qdd_fma, q, a, b64, c_c64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128qdq_fma") == 0) {
  GETTEST3(OP_DEC128, OP_DEC128, OP_DEC64, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL3(bid128qdq_fma, q, a, b64, c);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128qqd_fma") == 0) {
  GETTEST3(OP_DEC128, OP_DEC128, OP_DEC128, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL3(bid128qqd_fma, q, a, b, c_c64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_rem") == 0) {
  GETTEST2(OP_DEC128, OP_DEC128, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND(bid128_rem, q, a, b);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_fmod") == 0) {
  GETTEST2(OP_DEC128, OP_DEC128, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND(bid128_fmod, q, a, b);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_sqrt") == 0) {
  GETTEST1(OP_DEC128, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid128_sqrt, q, a);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128d_sqrt") == 0) {
  GETTEST1(OP_DEC128, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid128d_sqrt, q, a64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_minnum") == 0) {
  GETTEST2(OP_DEC128, OP_DEC128, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND(bid128_minnum, q, a, b);
    fpsf_0 = 0;
    check_results(CMP_EQUALSTATUS);
  }
}
if(strcmp(func, "bid128_maxnum") == 0) {
  GETTEST2(OP_DEC128, OP_DEC128, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND(bid128_maxnum, q, a, b);
    fpsf_0 = 0;
    check_results(CMP_EQUALSTATUS);
  }
}
if(strcmp(func, "bid128_minnum_mag") == 0) {
  GETTEST2(OP_DEC128, OP_DEC128, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND(bid128_minnum_mag, q, a, b);
    fpsf_0 = 0;
    check_results(CMP_EQUALSTATUS);
  }
}
if(strcmp(func, "bid128_maxnum_mag") == 0) {
  GETTEST2(OP_DEC128, OP_DEC128, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND(bid128_maxnum_mag, q, a, b);
    fpsf_0 = 0;
    check_results(CMP_EQUALSTATUS);
  }
}
if(strcmp(func, "bid128_quantize") == 0) {
  GETTEST2(OP_DEC128, OP_DEC128, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2(bid128_quantize, q, a, b);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_ilogb") == 0) {
  GETTEST1(OP_INT32, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid128_ilogb, i2, a);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_ilogb") == 0) {
  GETTEST1(OP_INT32, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid64_ilogb, i2, a64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_logb") == 0) {
  GETTEST1(OP_DEC128, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid128_logb, q, a);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_logb") == 0) {
  GETTEST1(OP_DEC64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid64_logb, q64, a64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_scalbn") == 0) {
  GETTEST2(OP_DEC128, OP_DEC128, OP_INT32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2(bid128_scalbn, q, a, b_i32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_scalbn") == 0) {
  GETTEST2(OP_DEC64, OP_DEC64, OP_INT32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2(bid64_scalbn, q64, a64, b_i32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_round_integral_nearest_even") == 0) {
  GETTEST1(OP_DEC128, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid128_round_integral_nearest_even, q, a);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_round_integral_nearest_away") == 0) {
  GETTEST1(OP_DEC128, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid128_round_integral_nearest_away, q, a);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_round_integral_positive") == 0) {
  GETTEST1(OP_DEC128, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid128_round_integral_positive, q, a);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_round_integral_negative") == 0) {
  GETTEST1(OP_DEC128, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid128_round_integral_negative, q, a);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_round_integral_zero") == 0) {
  GETTEST1(OP_DEC128, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid128_round_integral_zero, q, a);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_round_integral_exact") == 0) {
  GETTEST1(OP_DEC128, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid128_round_integral_exact, q, a);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_nearbyint") == 0) {
  GETTEST1(OP_DEC128, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid128_nearbyint, q, a);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_to_int8_rnint") == 0) {
  GETTEST1(OP_INT8, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid64_to_int8_rnint, i2_8, a64);
    i2 = (int)i2_8;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_to_int8_rninta") == 0) {
  GETTEST1(OP_INT8, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid64_to_int8_rninta, i2_8, a64);
    i2 = (int)i2_8;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_to_int8_ceil") == 0) {
  GETTEST1(OP_INT8, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid64_to_int8_ceil, i2_8, a64);
    i2 = (int)i2_8;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_to_int8_floor") == 0) {
  GETTEST1(OP_INT8, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid64_to_int8_floor, i2_8, a64);
    i2 = (int)i2_8;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_to_int8_int") == 0) {
  GETTEST1(OP_INT8, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid64_to_int8_int, i2_8, a64);
    i2 = (int)i2_8;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_to_int8_xrnint") == 0) {
  GETTEST1(OP_INT8, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid64_to_int8_xrnint, i2_8, a64);
    i2 = (int)i2_8;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_to_int8_xrninta") == 0) {
  GETTEST1(OP_INT8, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid64_to_int8_xrninta, i2_8, a64);
    i2 = (int)i2_8;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_to_int8_xceil") == 0) {
  GETTEST1(OP_INT8, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid64_to_int8_xceil, i2_8, a64);
    i2 = (int)i2_8;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_to_int8_xfloor") == 0) {
  GETTEST1(OP_INT8, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid64_to_int8_xfloor, i2_8, a64);
    i2 = (int)i2_8;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_to_int8_xint") == 0) {
  GETTEST1(OP_INT8, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid64_to_int8_xint, i2_8, a64);
    i2 = (int)i2_8;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_to_uint8_rnint") == 0) {
  GETTEST1(OP_BID_UINT8, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid64_to_uint8_rnint, u2_8, a64);
    i2 = (int)u2_8;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_to_uint8_rninta") == 0) {
  GETTEST1(OP_BID_UINT8, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid64_to_uint8_rninta, u2_8, a64);
    i2 = (int)u2_8;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_to_uint8_ceil") == 0) {
  GETTEST1(OP_BID_UINT8, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid64_to_uint8_ceil, u2_8, a64);
    i2 = (int)u2_8;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_to_uint8_floor") == 0) {
  GETTEST1(OP_BID_UINT8, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid64_to_uint8_floor, u2_8, a64);
    i2 = (int)u2_8;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_to_uint8_int") == 0) {
  GETTEST1(OP_BID_UINT8, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid64_to_uint8_int, u2_8, a64);
    i2 = (int)u2_8;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_to_uint8_xrnint") == 0) {
  GETTEST1(OP_BID_UINT8, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid64_to_uint8_xrnint, u2_8, a64);
    i2 = (int)u2_8;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_to_uint8_xrninta") == 0) {
  GETTEST1(OP_BID_UINT8, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid64_to_uint8_xrninta, u2_8, a64);
    i2 = (int)u2_8;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_to_uint8_xceil") == 0) {
  GETTEST1(OP_BID_UINT8, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid64_to_uint8_xceil, u2_8, a64);
    i2 = (int)u2_8;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_to_uint8_xfloor") == 0) {
  GETTEST1(OP_BID_UINT8, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid64_to_uint8_xfloor, u2_8, a64);
    i2 = (int)u2_8;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_to_uint8_xint") == 0) {
  GETTEST1(OP_BID_UINT8, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid64_to_uint8_xint, u2_8, a64);
    i2 = (int)u2_8;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_to_int16_rnint") == 0) {
  GETTEST1(OP_INT16, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid64_to_int16_rnint, i2_16, a64);
    i2 = (int)i2_16;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_to_int16_rninta") == 0) {
  GETTEST1(OP_INT16, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid64_to_int16_rninta, i2_16, a64);
    i2 = (int)i2_16;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_to_int16_ceil") == 0) {
  GETTEST1(OP_INT16, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid64_to_int16_ceil, i2_16, a64);
    i2 = (int)i2_16;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_to_int16_floor") == 0) {
  GETTEST1(OP_INT16, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid64_to_int16_floor, i2_16, a64);
    i2 = (int)i2_16;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_to_int16_int") == 0) {
  GETTEST1(OP_INT16, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid64_to_int16_int, i2_16, a64);
    i2 = (int)i2_16;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_to_int16_xrnint") == 0) {
  GETTEST1(OP_INT16, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid64_to_int16_xrnint, i2_16, a64);
    i2 = (int)i2_16;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_to_int16_xrninta") == 0) {
  GETTEST1(OP_INT16, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid64_to_int16_xrninta, i2_16, a64);
    i2 = (int)i2_16;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_to_int16_xceil") == 0) {
  GETTEST1(OP_INT16, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid64_to_int16_xceil, i2_16, a64);
    i2 = (int)i2_16;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_to_int16_xfloor") == 0) {
  GETTEST1(OP_INT16, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid64_to_int16_xfloor, i2_16, a64);
    i2 = (int)i2_16;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_to_int16_xint") == 0) {
  GETTEST1(OP_INT16, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid64_to_int16_xint, i2_16, a64);
    i2 = (int)i2_16;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_to_uint16_rnint") == 0) {
  GETTEST1(OP_BID_UINT16, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid64_to_uint16_rnint, u2_16, a64);
    i2 = (int)u2_16;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_to_uint16_rninta") == 0) {
  GETTEST1(OP_BID_UINT16, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid64_to_uint16_rninta, u2_16, a64);
    i2 = (int)u2_16;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_to_uint16_ceil") == 0) {
  GETTEST1(OP_BID_UINT16, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid64_to_uint16_ceil, u2_16, a64);
    i2 = (int)u2_16;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_to_uint16_floor") == 0) {
  GETTEST1(OP_BID_UINT16, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid64_to_uint16_floor, u2_16, a64);
    i2 = (int)u2_16;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_to_uint16_int") == 0) {
  GETTEST1(OP_BID_UINT16, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid64_to_uint16_int, u2_16, a64);
    i2 = (int)u2_16;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_to_uint16_xrnint") == 0) {
  GETTEST1(OP_BID_UINT16, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid64_to_uint16_xrnint, u2_16, a64);
    i2 = (int)u2_16;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_to_uint16_xrninta") == 0) {
  GETTEST1(OP_BID_UINT16, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid64_to_uint16_xrninta, u2_16, a64);
    i2 = (int)u2_16;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_to_uint16_xceil") == 0) {
  GETTEST1(OP_BID_UINT16, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid64_to_uint16_xceil, u2_16, a64);
    i2 = (int)u2_16;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_to_uint16_xfloor") == 0) {
  GETTEST1(OP_BID_UINT16, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid64_to_uint16_xfloor, u2_16, a64);
    i2 = (int)u2_16;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_to_uint16_xint") == 0) {
  GETTEST1(OP_BID_UINT16, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid64_to_uint16_xint, u2_16, a64);
    i2 = (int)u2_16;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_to_int32_rnint") == 0) {
  GETTEST1(OP_INT32, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid64_to_int32_rnint, i2, a64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_to_int32_rninta") == 0) {
  GETTEST1(OP_INT32, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid64_to_int32_rninta, i2, a64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_to_int32_ceil") == 0) {
  GETTEST1(OP_INT32, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid64_to_int32_ceil, i2, a64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_to_int32_floor") == 0) {
  GETTEST1(OP_INT32, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid64_to_int32_floor, i2, a64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_to_int32_int") == 0) {
  GETTEST1(OP_INT32, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid64_to_int32_int, i2, a64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_to_int32_xrnint") == 0) {
  GETTEST1(OP_INT32, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid64_to_int32_xrnint, i2, a64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_to_int32_xrninta") == 0) {
  GETTEST1(OP_INT32, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid64_to_int32_xrninta, i2, a64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_to_int32_xceil") == 0) {
  GETTEST1(OP_INT32, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid64_to_int32_xceil, i2, a64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_to_int32_xfloor") == 0) {
  GETTEST1(OP_INT32, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid64_to_int32_xfloor, i2, a64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_to_int32_xint") == 0) {
  GETTEST1(OP_INT32, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid64_to_int32_xint, i2, a64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_to_uint32_rnint") == 0) {
  GETTEST1(OP_BID_UINT32, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid64_to_uint32_rnint, *(BID_UINT32 *)&i2, a64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_to_uint32_rninta") == 0) {
  GETTEST1(OP_BID_UINT32, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid64_to_uint32_rninta, *(BID_UINT32 *)&i2, a64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_to_uint32_ceil") == 0) {
  GETTEST1(OP_BID_UINT32, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid64_to_uint32_ceil, *(BID_UINT32 *)&i2, a64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_to_uint32_floor") == 0) {
  GETTEST1(OP_BID_UINT32, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid64_to_uint32_floor, *(BID_UINT32 *)&i2, a64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_to_uint32_int") == 0) {
  GETTEST1(OP_BID_UINT32, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid64_to_uint32_int, *(BID_UINT32 *)&i2, a64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_to_uint32_xrnint") == 0) {
  GETTEST1(OP_BID_UINT32, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid64_to_uint32_xrnint, *(BID_UINT32 *)&i2, a64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_to_uint32_xrninta") == 0) {
  GETTEST1(OP_BID_UINT32, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid64_to_uint32_xrninta, *(BID_UINT32 *)&i2, a64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_to_uint32_xceil") == 0) {
  GETTEST1(OP_BID_UINT32, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid64_to_uint32_xceil, *(BID_UINT32 *)&i2, a64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_to_uint32_xfloor") == 0) {
  GETTEST1(OP_BID_UINT32, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid64_to_uint32_xfloor, *(BID_UINT32 *)&i2, a64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_to_uint32_xint") == 0) {
  GETTEST1(OP_BID_UINT32, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid64_to_uint32_xint, *(BID_UINT32 *)&i2, a64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_to_int64_rnint") == 0) {
  GETTEST1(OP_INT64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid64_to_int64_rnint, *(BID_SINT64 *)&result_i64, a64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_to_int64_rninta") == 0) {
  GETTEST1(OP_INT64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid64_to_int64_rninta, *(BID_SINT64 *)&result_i64, a64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_to_int64_ceil") == 0) {
  GETTEST1(OP_INT64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid64_to_int64_ceil, *(BID_SINT64 *)&result_i64, a64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_to_int64_floor") == 0) {
  GETTEST1(OP_INT64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid64_to_int64_floor, *(BID_SINT64 *)&result_i64, a64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_to_int64_int") == 0) {
  GETTEST1(OP_INT64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid64_to_int64_int, *(BID_SINT64 *)&result_i64, a64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_to_int64_xrnint") == 0) {
  GETTEST1(OP_INT64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid64_to_int64_xrnint, *(BID_SINT64 *)&result_i64, a64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_to_int64_xrninta") == 0) {
  GETTEST1(OP_INT64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid64_to_int64_xrninta, *(BID_SINT64 *)&result_i64, a64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_to_int64_xceil") == 0) {
  GETTEST1(OP_INT64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid64_to_int64_xceil, *(BID_SINT64 *)&result_i64, a64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_to_int64_xfloor") == 0) {
  GETTEST1(OP_INT64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid64_to_int64_xfloor, *(BID_SINT64 *)&result_i64, a64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_to_int64_xint") == 0) {
  GETTEST1(OP_INT64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid64_to_int64_xint, *(BID_SINT64 *)&result_i64, a64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_to_uint64_rnint") == 0) {
  GETTEST1(OP_BID_UINT64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid64_to_uint64_rnint, result_i64, a64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_to_uint64_rninta") == 0) {
  GETTEST1(OP_BID_UINT64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid64_to_uint64_rninta, result_i64, a64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_to_uint64_ceil") == 0) {
  GETTEST1(OP_BID_UINT64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid64_to_uint64_ceil, result_i64, a64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_to_uint64_floor") == 0) {
  GETTEST1(OP_BID_UINT64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid64_to_uint64_floor, result_i64, a64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_to_uint64_int") == 0) {
  GETTEST1(OP_BID_UINT64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid64_to_uint64_int, result_i64, a64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_to_uint64_xrnint") == 0) {
  GETTEST1(OP_BID_UINT64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid64_to_uint64_xrnint, result_i64, a64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_to_uint64_xrninta") == 0) {
  GETTEST1(OP_BID_UINT64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid64_to_uint64_xrninta, result_i64, a64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_to_uint64_xceil") == 0) {
  GETTEST1(OP_BID_UINT64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid64_to_uint64_xceil, result_i64, a64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_to_uint64_xfloor") == 0) {
  GETTEST1(OP_BID_UINT64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid64_to_uint64_xfloor, result_i64, a64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_to_uint64_xint") == 0) {
  GETTEST1(OP_BID_UINT64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid64_to_uint64_xint, result_i64, a64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_to_int8_rnint") == 0) {
  GETTEST1(OP_INT8, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid32_to_int8_rnint, i2_8, a32);
    i2 = (int)i2_8;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_to_int8_rninta") == 0) {
  GETTEST1(OP_INT8, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid32_to_int8_rninta, i2_8, a32);
    i2 = (int)i2_8;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_to_int8_ceil") == 0) {
  GETTEST1(OP_INT8, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid32_to_int8_ceil, i2_8, a32);
    i2 = (int)i2_8;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_to_int8_floor") == 0) {
  GETTEST1(OP_INT8, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid32_to_int8_floor, i2_8, a32);
    i2 = (int)i2_8;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_to_int8_int") == 0) {
  GETTEST1(OP_INT8, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid32_to_int8_int, i2_8, a32);
    i2 = (int)i2_8;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_to_int8_xrnint") == 0) {
  GETTEST1(OP_INT8, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid32_to_int8_xrnint, i2_8, a32);
    i2 = (int)i2_8;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_to_int8_xrninta") == 0) {
  GETTEST1(OP_INT8, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid32_to_int8_xrninta, i2_8, a32);
    i2 = (int)i2_8;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_to_int8_xceil") == 0) {
  GETTEST1(OP_INT8, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid32_to_int8_xceil, i2_8, a32);
    i2 = (int)i2_8;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_to_int8_xfloor") == 0) {
  GETTEST1(OP_INT8, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid32_to_int8_xfloor, i2_8, a32);
    i2 = (int)i2_8;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_to_int8_xint") == 0) {
  GETTEST1(OP_INT8, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid32_to_int8_xint, i2_8, a32);
    i2 = (int)i2_8;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_to_uint8_rnint") == 0) {
  GETTEST1(OP_BID_UINT8, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid32_to_uint8_rnint, u2_8, a32);
    i2 = (int)u2_8;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_to_uint8_rninta") == 0) {
  GETTEST1(OP_BID_UINT8, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid32_to_uint8_rninta, u2_8, a32);
    i2 = (int)u2_8;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_to_uint8_ceil") == 0) {
  GETTEST1(OP_BID_UINT8, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid32_to_uint8_ceil, u2_8, a32);
    i2 = (int)u2_8;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_to_uint8_floor") == 0) {
  GETTEST1(OP_BID_UINT8, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid32_to_uint8_floor, u2_8, a32);
    i2 = (int)u2_8;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_to_uint8_int") == 0) {
  GETTEST1(OP_BID_UINT8, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid32_to_uint8_int, u2_8, a32);
    i2 = (int)u2_8;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_to_uint8_xrnint") == 0) {
  GETTEST1(OP_BID_UINT8, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid32_to_uint8_xrnint, u2_8, a32);
    i2 = (int)u2_8;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_to_uint8_xrninta") == 0) {
  GETTEST1(OP_BID_UINT8, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid32_to_uint8_xrninta, u2_8, a32);
    i2 = (int)u2_8;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_to_uint8_xceil") == 0) {
  GETTEST1(OP_BID_UINT8, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid32_to_uint8_xceil, u2_8, a32);
    i2 = (int)u2_8;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_to_uint8_xfloor") == 0) {
  GETTEST1(OP_BID_UINT8, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid32_to_uint8_xfloor, u2_8, a32);
    i2 = (int)u2_8;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_to_uint8_xint") == 0) {
  GETTEST1(OP_BID_UINT8, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid32_to_uint8_xint, u2_8, a32);
    i2 = (int)u2_8;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_to_int16_rnint") == 0) {
  GETTEST1(OP_INT16, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid32_to_int16_rnint, i2_16, a32);
    i2 = (int)i2_16;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_to_int16_rninta") == 0) {
  GETTEST1(OP_INT16, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid32_to_int16_rninta, i2_16, a32);
    i2 = (int)i2_16;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_to_int16_ceil") == 0) {
  GETTEST1(OP_INT16, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid32_to_int16_ceil, i2_16, a32);
    i2 = (int)i2_16;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_to_int16_floor") == 0) {
  GETTEST1(OP_INT16, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid32_to_int16_floor, i2_16, a32);
    i2 = (int)i2_16;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_to_int16_int") == 0) {
  GETTEST1(OP_INT16, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid32_to_int16_int, i2_16, a32);
    i2 = (int)i2_16;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_to_int16_xrnint") == 0) {
  GETTEST1(OP_INT16, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid32_to_int16_xrnint, i2_16, a32);
    i2 = (int)i2_16;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_to_int16_xrninta") == 0) {
  GETTEST1(OP_INT16, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid32_to_int16_xrninta, i2_16, a32);
    i2 = (int)i2_16;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_to_int16_xceil") == 0) {
  GETTEST1(OP_INT16, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid32_to_int16_xceil, i2_16, a32);
    i2 = (int)i2_16;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_to_int16_xfloor") == 0) {
  GETTEST1(OP_INT16, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid32_to_int16_xfloor, i2_16, a32);
    i2 = (int)i2_16;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_to_int16_xint") == 0) {
  GETTEST1(OP_INT16, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid32_to_int16_xint, i2_16, a32);
    i2 = (int)i2_16;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_to_uint16_rnint") == 0) {
  GETTEST1(OP_BID_UINT16, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid32_to_uint16_rnint, u2_16, a32);
    i2 = (int)u2_16;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_to_uint16_rninta") == 0) {
  GETTEST1(OP_BID_UINT16, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid32_to_uint16_rninta, u2_16, a32);
    i2 = (int)u2_16;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_to_uint16_ceil") == 0) {
  GETTEST1(OP_BID_UINT16, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid32_to_uint16_ceil, u2_16, a32);
    i2 = (int)u2_16;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_to_uint16_floor") == 0) {
  GETTEST1(OP_BID_UINT16, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid32_to_uint16_floor, u2_16, a32);
    i2 = (int)u2_16;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_to_uint16_int") == 0) {
  GETTEST1(OP_BID_UINT16, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid32_to_uint16_int, u2_16, a32);
    i2 = (int)u2_16;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_to_uint16_xrnint") == 0) {
  GETTEST1(OP_BID_UINT16, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid32_to_uint16_xrnint, u2_16, a32);
    i2 = (int)u2_16;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_to_uint16_xrninta") == 0) {
  GETTEST1(OP_BID_UINT16, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid32_to_uint16_xrninta, u2_16, a32);
    i2 = (int)u2_16;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_to_uint16_xceil") == 0) {
  GETTEST1(OP_BID_UINT16, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid32_to_uint16_xceil, u2_16, a32);
    i2 = (int)u2_16;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_to_uint16_xfloor") == 0) {
  GETTEST1(OP_BID_UINT16, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid32_to_uint16_xfloor, u2_16, a32);
    i2 = (int)u2_16;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_to_uint16_xint") == 0) {
  GETTEST1(OP_BID_UINT16, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid32_to_uint16_xint, u2_16, a32);
    i2 = (int)u2_16;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_to_int32_rnint") == 0) {
  GETTEST1(OP_INT32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid32_to_int32_rnint, i2, a32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_to_int32_rninta") == 0) {
  GETTEST1(OP_INT32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid32_to_int32_rninta, i2, a32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_to_int32_ceil") == 0) {
  GETTEST1(OP_INT32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid32_to_int32_ceil, i2, a32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_to_int32_floor") == 0) {
  GETTEST1(OP_INT32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid32_to_int32_floor, i2, a32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_to_int32_int") == 0) {
  GETTEST1(OP_INT32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid32_to_int32_int, i2, a32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_to_int32_xrnint") == 0) {
  GETTEST1(OP_INT32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid32_to_int32_xrnint, i2, a32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_to_int32_xrninta") == 0) {
  GETTEST1(OP_INT32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid32_to_int32_xrninta, i2, a32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_to_int32_xceil") == 0) {
  GETTEST1(OP_INT32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid32_to_int32_xceil, i2, a32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_to_int32_xfloor") == 0) {
  GETTEST1(OP_INT32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid32_to_int32_xfloor, i2, a32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_to_int32_xint") == 0) {
  GETTEST1(OP_INT32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid32_to_int32_xint, i2, a32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_to_uint32_rnint") == 0) {
  GETTEST1(OP_BID_UINT32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid32_to_uint32_rnint, *(BID_UINT32 *)&i2, a32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_to_uint32_rninta") == 0) {
  GETTEST1(OP_BID_UINT32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid32_to_uint32_rninta, *(BID_UINT32 *)&i2, a32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_to_uint32_ceil") == 0) {
  GETTEST1(OP_BID_UINT32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid32_to_uint32_ceil, *(BID_UINT32 *)&i2, a32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_to_uint32_floor") == 0) {
  GETTEST1(OP_BID_UINT32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid32_to_uint32_floor, *(BID_UINT32 *)&i2, a32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_to_uint32_int") == 0) {
  GETTEST1(OP_BID_UINT32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid32_to_uint32_int, *(BID_UINT32 *)&i2, a32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_to_uint32_xrnint") == 0) {
  GETTEST1(OP_BID_UINT32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid32_to_uint32_xrnint, *(BID_UINT32 *)&i2, a32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_to_uint32_xrninta") == 0) {
  GETTEST1(OP_BID_UINT32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid32_to_uint32_xrninta, *(BID_UINT32 *)&i2, a32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_to_uint32_xceil") == 0) {
  GETTEST1(OP_BID_UINT32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid32_to_uint32_xceil, *(BID_UINT32 *)&i2, a32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_to_uint32_xfloor") == 0) {
  GETTEST1(OP_BID_UINT32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid32_to_uint32_xfloor, *(BID_UINT32 *)&i2, a32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_to_uint32_xint") == 0) {
  GETTEST1(OP_BID_UINT32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid32_to_uint32_xint, *(BID_UINT32 *)&i2, a32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_to_int64_rnint") == 0) {
  GETTEST1(OP_INT64, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid32_to_int64_rnint, *(BID_SINT64 *)&result_i64, a32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_to_int64_rninta") == 0) {
  GETTEST1(OP_INT64, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid32_to_int64_rninta, *(BID_SINT64 *)&result_i64, a32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_to_int64_ceil") == 0) {
  GETTEST1(OP_INT64, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid32_to_int64_ceil, *(BID_SINT64 *)&result_i64, a32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_to_int64_floor") == 0) {
  GETTEST1(OP_INT64, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid32_to_int64_floor, *(BID_SINT64 *)&result_i64, a32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_to_int64_int") == 0) {
  GETTEST1(OP_INT64, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid32_to_int64_int, *(BID_SINT64 *)&result_i64, a32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_to_int64_xrnint") == 0) {
  GETTEST1(OP_INT64, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid32_to_int64_xrnint, *(BID_SINT64 *)&result_i64, a32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_to_int64_xrninta") == 0) {
  GETTEST1(OP_INT64, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid32_to_int64_xrninta, *(BID_SINT64 *)&result_i64, a32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_to_int64_xceil") == 0) {
  GETTEST1(OP_INT64, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid32_to_int64_xceil, *(BID_SINT64 *)&result_i64, a32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_to_int64_xfloor") == 0) {
  GETTEST1(OP_INT64, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid32_to_int64_xfloor, *(BID_SINT64 *)&result_i64, a32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_to_int64_xint") == 0) {
  GETTEST1(OP_INT64, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid32_to_int64_xint, *(BID_SINT64 *)&result_i64, a32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_to_uint64_rnint") == 0) {
  GETTEST1(OP_BID_UINT64, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid32_to_uint64_rnint, result_i64, a32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_to_uint64_rninta") == 0) {
  GETTEST1(OP_BID_UINT64, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid32_to_uint64_rninta, result_i64, a32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_to_uint64_ceil") == 0) {
  GETTEST1(OP_BID_UINT64, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid32_to_uint64_ceil, result_i64, a32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_to_uint64_floor") == 0) {
  GETTEST1(OP_BID_UINT64, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid32_to_uint64_floor, result_i64, a32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_to_uint64_int") == 0) {
  GETTEST1(OP_BID_UINT64, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid32_to_uint64_int, result_i64, a32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_to_uint64_xrnint") == 0) {
  GETTEST1(OP_BID_UINT64, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid32_to_uint64_xrnint, result_i64, a32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_to_uint64_xrninta") == 0) {
  GETTEST1(OP_BID_UINT64, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid32_to_uint64_xrninta, result_i64, a32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_to_uint64_xceil") == 0) {
  GETTEST1(OP_BID_UINT64, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid32_to_uint64_xceil, result_i64, a32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_to_uint64_xfloor") == 0) {
  GETTEST1(OP_BID_UINT64, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid32_to_uint64_xfloor, result_i64, a32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_to_uint64_xint") == 0) {
  GETTEST1(OP_BID_UINT64, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid32_to_uint64_xint, result_i64, a32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_to_int8_rnint") == 0) {
  GETTEST1(OP_INT8, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid128_to_int8_rnint, i2_8, a);
    i2 = (int)i2_8;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_to_int8_rninta") == 0) {
  GETTEST1(OP_INT8, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid128_to_int8_rninta, i2_8, a);
    i2 = (int)i2_8;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_to_int8_ceil") == 0) {
  GETTEST1(OP_INT8, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid128_to_int8_ceil, i2_8, a);
    i2 = (int)i2_8;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_to_int8_floor") == 0) {
  GETTEST1(OP_INT8, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid128_to_int8_floor, i2_8, a);
    i2 = (int)i2_8;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_to_int8_int") == 0) {
  GETTEST1(OP_INT8, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid128_to_int8_int, i2_8, a);
    i2 = (int)i2_8;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_to_int8_xrnint") == 0) {
  GETTEST1(OP_INT8, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid128_to_int8_xrnint, i2_8, a);
    i2 = (int)i2_8;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_to_int8_xrninta") == 0) {
  GETTEST1(OP_INT8, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid128_to_int8_xrninta, i2_8, a);
    i2 = (int)i2_8;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_to_int8_xceil") == 0) {
  GETTEST1(OP_INT8, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid128_to_int8_xceil, i2_8, a);
    i2 = (int)i2_8;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_to_int8_xfloor") == 0) {
  GETTEST1(OP_INT8, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid128_to_int8_xfloor, i2_8, a);
    i2 = (int)i2_8;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_to_int8_xint") == 0) {
  GETTEST1(OP_INT8, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid128_to_int8_xint, i2_8, a);
    i2 = (int)i2_8;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_to_uint8_rnint") == 0) {
  GETTEST1(OP_BID_UINT8, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid128_to_uint8_rnint, u2_8, a);
    i2 = (int)u2_8;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_to_uint8_rninta") == 0) {
  GETTEST1(OP_BID_UINT8, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid128_to_uint8_rninta, u2_8, a);
    i2 = (int)u2_8;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_to_uint8_ceil") == 0) {
  GETTEST1(OP_BID_UINT8, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid128_to_uint8_ceil, u2_8, a);
    i2 = (int)u2_8;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_to_uint8_floor") == 0) {
  GETTEST1(OP_BID_UINT8, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid128_to_uint8_floor, u2_8, a);
    i2 = (int)u2_8;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_to_uint8_int") == 0) {
  GETTEST1(OP_BID_UINT8, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid128_to_uint8_int, u2_8, a);
    i2 = (int)u2_8;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_to_uint8_xrnint") == 0) {
  GETTEST1(OP_BID_UINT8, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid128_to_uint8_xrnint, u2_8, a);
    i2 = (int)u2_8;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_to_uint8_xrninta") == 0) {
  GETTEST1(OP_BID_UINT8, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid128_to_uint8_xrninta, u2_8, a);
    i2 = (int)u2_8;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_to_uint8_xceil") == 0) {
  GETTEST1(OP_BID_UINT8, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid128_to_uint8_xceil, u2_8, a);
    i2 = (int)u2_8;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_to_uint8_xfloor") == 0) {
  GETTEST1(OP_BID_UINT8, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid128_to_uint8_xfloor, u2_8, a);
    i2 = (int)u2_8;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_to_uint8_xint") == 0) {
  GETTEST1(OP_BID_UINT8, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid128_to_uint8_xint, u2_8, a);
    i2 = (int)u2_8;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_to_int16_rnint") == 0) {
  GETTEST1(OP_INT16, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid128_to_int16_rnint, i2_16, a);
    i2 = (int)i2_16;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_to_int16_rninta") == 0) {
  GETTEST1(OP_INT16, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid128_to_int16_rninta, i2_16, a);
    i2 = (int)i2_16;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_to_int16_ceil") == 0) {
  GETTEST1(OP_INT16, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid128_to_int16_ceil, i2_16, a);
    i2 = (int)i2_16;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_to_int16_floor") == 0) {
  GETTEST1(OP_INT16, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid128_to_int16_floor, i2_16, a);
    i2 = (int)i2_16;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_to_int16_int") == 0) {
  GETTEST1(OP_INT16, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid128_to_int16_int, i2_16, a);
    i2 = (int)i2_16;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_to_int16_xrnint") == 0) {
  GETTEST1(OP_INT16, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid128_to_int16_xrnint, i2_16, a);
    i2 = (int)i2_16;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_to_int16_xrninta") == 0) {
  GETTEST1(OP_INT16, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid128_to_int16_xrninta, i2_16, a);
    i2 = (int)i2_16;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_to_int16_xceil") == 0) {
  GETTEST1(OP_INT16, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid128_to_int16_xceil, i2_16, a);
    i2 = (int)i2_16;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_to_int16_xfloor") == 0) {
  GETTEST1(OP_INT16, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid128_to_int16_xfloor, i2_16, a);
    i2 = (int)i2_16;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_to_int16_xint") == 0) {
  GETTEST1(OP_INT16, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid128_to_int16_xint, i2_16, a);
    i2 = (int)i2_16;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_to_uint16_rnint") == 0) {
  GETTEST1(OP_BID_UINT16, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid128_to_uint16_rnint, u2_16, a);
    i2 = (int)u2_16;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_to_uint16_rninta") == 0) {
  GETTEST1(OP_BID_UINT16, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid128_to_uint16_rninta, u2_16, a);
    i2 = (int)u2_16;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_to_uint16_ceil") == 0) {
  GETTEST1(OP_BID_UINT16, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid128_to_uint16_ceil, u2_16, a);
    i2 = (int)u2_16;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_to_uint16_floor") == 0) {
  GETTEST1(OP_BID_UINT16, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid128_to_uint16_floor, u2_16, a);
    i2 = (int)u2_16;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_to_uint16_int") == 0) {
  GETTEST1(OP_BID_UINT16, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid128_to_uint16_int, u2_16, a);
    i2 = (int)u2_16;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_to_uint16_xrnint") == 0) {
  GETTEST1(OP_BID_UINT16, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid128_to_uint16_xrnint, u2_16, a);
    i2 = (int)u2_16;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_to_uint16_xrninta") == 0) {
  GETTEST1(OP_BID_UINT16, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid128_to_uint16_xrninta, u2_16, a);
    i2 = (int)u2_16;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_to_uint16_xceil") == 0) {
  GETTEST1(OP_BID_UINT16, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid128_to_uint16_xceil, u2_16, a);
    i2 = (int)u2_16;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_to_uint16_xfloor") == 0) {
  GETTEST1(OP_BID_UINT16, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid128_to_uint16_xfloor, u2_16, a);
    i2 = (int)u2_16;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_to_uint16_xint") == 0) {
  GETTEST1(OP_BID_UINT16, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid128_to_uint16_xint, u2_16, a);
    i2 = (int)u2_16;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_to_int32_rnint") == 0) {
  GETTEST1(OP_INT32, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid128_to_int32_rnint, i2, a);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_to_int32_rninta") == 0) {
  GETTEST1(OP_INT32, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid128_to_int32_rninta, i2, a);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_to_int32_ceil") == 0) {
  GETTEST1(OP_INT32, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid128_to_int32_ceil, i2, a);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_to_int32_floor") == 0) {
  GETTEST1(OP_INT32, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid128_to_int32_floor, i2, a);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_to_int32_int") == 0) {
  GETTEST1(OP_INT32, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid128_to_int32_int, i2, a);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_to_int32_xrnint") == 0) {
  GETTEST1(OP_INT32, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid128_to_int32_xrnint, i2, a);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_to_int32_xrninta") == 0) {
  GETTEST1(OP_INT32, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid128_to_int32_xrninta, i2, a);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_to_int32_xceil") == 0) {
  GETTEST1(OP_INT32, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid128_to_int32_xceil, i2, a);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_to_int32_xfloor") == 0) {
  GETTEST1(OP_INT32, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid128_to_int32_xfloor, i2, a);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_to_int32_xint") == 0) {
  GETTEST1(OP_INT32, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid128_to_int32_xint, i2, a);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_to_uint32_rnint") == 0) {
  GETTEST1(OP_BID_UINT32, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid128_to_uint32_rnint, *(BID_UINT32 *)&i2, a);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_to_uint32_rninta") == 0) {
  GETTEST1(OP_BID_UINT32, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid128_to_uint32_rninta, *(BID_UINT32 *)&i2, a);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_to_uint32_ceil") == 0) {
  GETTEST1(OP_BID_UINT32, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid128_to_uint32_ceil, *(BID_UINT32 *)&i2, a);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_to_uint32_floor") == 0) {
  GETTEST1(OP_BID_UINT32, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid128_to_uint32_floor, *(BID_UINT32 *)&i2, a);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_to_uint32_int") == 0) {
  GETTEST1(OP_BID_UINT32, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid128_to_uint32_int, *(BID_UINT32 *)&i2, a);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_to_uint32_xrnint") == 0) {
  GETTEST1(OP_BID_UINT32, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid128_to_uint32_xrnint, *(BID_UINT32 *)&i2, a);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_to_uint32_xrninta") == 0) {
  GETTEST1(OP_BID_UINT32, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid128_to_uint32_xrninta, *(BID_UINT32 *)&i2, a);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_to_uint32_xceil") == 0) {
  GETTEST1(OP_BID_UINT32, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid128_to_uint32_xceil, *(BID_UINT32 *)&i2, a);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_to_uint32_xfloor") == 0) {
  GETTEST1(OP_BID_UINT32, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid128_to_uint32_xfloor, *(BID_UINT32 *)&i2, a);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_to_uint32_xint") == 0) {
  GETTEST1(OP_BID_UINT32, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid128_to_uint32_xint, *(BID_UINT32 *)&i2, a);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_to_int64_rnint") == 0) {
  GETTEST1(OP_INT64, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid128_to_int64_rnint, *(BID_SINT64 *)&result_i64, a);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_to_int64_rninta") == 0) {
  GETTEST1(OP_INT64, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid128_to_int64_rninta, *(BID_SINT64 *)&result_i64, a);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_to_int64_ceil") == 0) {
  GETTEST1(OP_INT64, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid128_to_int64_ceil, *(BID_SINT64 *)&result_i64, a);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_to_int64_floor") == 0) {
  GETTEST1(OP_INT64, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid128_to_int64_floor, *(BID_SINT64 *)&result_i64, a);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_to_int64_int") == 0) {
  GETTEST1(OP_INT64, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid128_to_int64_int, *(BID_SINT64 *)&result_i64, a);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_to_int64_xrnint") == 0) {
  GETTEST1(OP_INT64, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid128_to_int64_xrnint, *(BID_SINT64 *)&result_i64, a);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_to_int64_xrninta") == 0) {
  GETTEST1(OP_INT64, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid128_to_int64_xrninta, *(BID_SINT64 *)&result_i64, a);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_to_int64_xceil") == 0) {
  GETTEST1(OP_INT64, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid128_to_int64_xceil, *(BID_SINT64 *)&result_i64, a);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_to_int64_xfloor") == 0) {
  GETTEST1(OP_INT64, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid128_to_int64_xfloor, *(BID_SINT64 *)&result_i64, a);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_to_int64_xint") == 0) {
  GETTEST1(OP_INT64, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid128_to_int64_xint, *(BID_SINT64 *)&result_i64, a);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_to_uint64_rnint") == 0) {
  GETTEST1(OP_BID_UINT64, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid128_to_uint64_rnint, result_i64, a);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_to_uint64_rninta") == 0) {
  GETTEST1(OP_BID_UINT64, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid128_to_uint64_rninta, result_i64, a);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_to_uint64_ceil") == 0) {
  GETTEST1(OP_BID_UINT64, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid128_to_uint64_ceil, result_i64, a);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_to_uint64_floor") == 0) {
  GETTEST1(OP_BID_UINT64, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid128_to_uint64_floor, result_i64, a);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_to_uint64_int") == 0) {
  GETTEST1(OP_BID_UINT64, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid128_to_uint64_int, result_i64, a);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_to_uint64_xrnint") == 0) {
  GETTEST1(OP_BID_UINT64, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid128_to_uint64_xrnint, result_i64, a);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_to_uint64_xrninta") == 0) {
  GETTEST1(OP_BID_UINT64, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid128_to_uint64_xrninta, result_i64, a);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_to_uint64_xceil") == 0) {
  GETTEST1(OP_BID_UINT64, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid128_to_uint64_xceil, result_i64, a);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_to_uint64_xfloor") == 0) {
  GETTEST1(OP_BID_UINT64, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid128_to_uint64_xfloor, result_i64, a);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_to_uint64_xint") == 0) {
  GETTEST1(OP_BID_UINT64, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid128_to_uint64_xint, result_i64, a);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_from_int32") == 0) {
  GETTEST1(OP_DEC32, OP_INT32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid32_from_int32, q32, a_i32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_from_uint32") == 0) {
  GETTEST1(OP_DEC32, OP_BID_UINT32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid32_from_uint32, q32, au_i32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_from_int64") == 0) {
  GETTEST1(OP_DEC32, OP_INT64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid32_from_int64, q32, a_i64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_from_uint64") == 0) {
  GETTEST1(OP_DEC32, OP_BID_UINT64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid32_from_uint64, q32, au_i64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_from_int32") == 0) {
  GETTEST1(OP_DEC64, OP_INT32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND_NOSTAT(bid64_from_int32, q64, a_i32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_from_uint32") == 0) {
  GETTEST1(OP_DEC64, OP_BID_UINT32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND_NOSTAT(bid64_from_uint32, q64, au_i32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_from_int64") == 0) {
  GETTEST1(OP_DEC64, OP_INT64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid64_from_int64, q64, a_i64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_from_uint64") == 0) {
  GETTEST1(OP_DEC64, OP_BID_UINT64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid64_from_uint64, q64, au_i64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_from_int32") == 0) {
  GETTEST1(OP_DEC128, OP_INT32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND_NOSTAT(bid128_from_int32, q, a_i32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_from_uint32") == 0) {
  GETTEST1(OP_DEC128, OP_BID_UINT32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND_NOSTAT(bid128_from_uint32, q, au_i32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_from_int64") == 0) {
  GETTEST1(OP_DEC128, OP_INT64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND_NOSTAT(bid128_from_int64, q, a_i64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_from_uint64") == 0) {
  GETTEST1(OP_DEC128, OP_BID_UINT64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND_NOSTAT(bid128_from_uint64, q, au_i64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_lrint") == 0) {
  GETTEST1(OP_LINT, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid32_lrint, li2, a32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_llrint") == 0) {
  GETTEST1(OP_INT64, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid32_llrint, *(long long int *)&result_i64, a32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_lrint") == 0) {
  GETTEST1(OP_LINT, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid64_lrint, li2, a64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_llrint") == 0) {
  GETTEST1(OP_INT64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid64_llrint, *(long long int *)&result_i64, a64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_lrint") == 0) {
  GETTEST1(OP_LINT, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid128_lrint, li2, a);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_llrint") == 0) {
  GETTEST1(OP_INT64, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid128_llrint, *(long long int *)&result_i64, a);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_lround") == 0) {
  GETTEST1(OP_LINT, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid32_lround, li2, a32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_lround") == 0) {
  GETTEST1(OP_LINT, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid64_lround, li2, a64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_lround") == 0) {
  GETTEST1(OP_LINT, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid128_lround, li2, a);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_llround") == 0) {
  GETTEST1(OP_INT64, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid32_llround, *(long long int *)&result_i64, a32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_llround") == 0) {
  GETTEST1(OP_INT64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid64_llround, *(long long int *)&result_i64, a64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_llround") == 0) {
  GETTEST1(OP_INT64, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid128_llround, *(long long int *)&result_i64, a);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_isSigned") == 0) {
  GETTEST1(OP_INT32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND_NOSTAT(bid32_isSigned, i2, a32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_isSigned") == 0) {
  GETTEST1(OP_INT32, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND_NOSTAT(bid64_isSigned, i2, a64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_isSigned") == 0) {
  GETTEST1(OP_INT32, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND_NOSTAT(bid128_isSigned, i2, a);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_isNormal") == 0) {
  GETTEST1(OP_INT32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND_NOSTAT(bid32_isNormal, i2, a32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_isNormal") == 0) {
  GETTEST1(OP_INT32, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND_NOSTAT(bid64_isNormal, i2, a64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_isNormal") == 0) {
  GETTEST1(OP_INT32, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND_NOSTAT(bid128_isNormal, i2, a);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_isSubnormal") == 0) {
  GETTEST1(OP_INT32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND_NOSTAT(bid32_isSubnormal, i2, a32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_isSubnormal") == 0) {
  GETTEST1(OP_INT32, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND_NOSTAT(bid64_isSubnormal, i2, a64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_isSubnormal") == 0) {
  GETTEST1(OP_INT32, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND_NOSTAT(bid128_isSubnormal, i2, a);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_isFinite") == 0) {
  GETTEST1(OP_INT32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND_NOSTAT(bid32_isFinite, i2, a32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_isFinite") == 0) {
  GETTEST1(OP_INT32, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND_NOSTAT(bid64_isFinite, i2, a64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_isFinite") == 0) {
  GETTEST1(OP_INT32, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND_NOSTAT(bid128_isFinite, i2, a);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_isZero") == 0) {
  GETTEST1(OP_INT32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND_NOSTAT(bid32_isZero, i2, a32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_isZero") == 0) {
  GETTEST1(OP_INT32, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND_NOSTAT(bid64_isZero, i2, a64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_isZero") == 0) {
  GETTEST1(OP_INT32, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND_NOSTAT(bid128_isZero, i2, a);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_isInf") == 0) {
  GETTEST1(OP_INT32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND_NOSTAT(bid32_isInf, i2, a32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_isInf") == 0) {
  GETTEST1(OP_INT32, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND_NOSTAT(bid64_isInf, i2, a64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_isInf") == 0) {
  GETTEST1(OP_INT32, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND_NOSTAT(bid128_isInf, i2, a);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_isSignaling") == 0) {
  GETTEST1(OP_INT32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND_NOSTAT(bid32_isSignaling, i2, a32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_isSignaling") == 0) {
  GETTEST1(OP_INT32, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND_NOSTAT(bid64_isSignaling, i2, a64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_isSignaling") == 0) {
  GETTEST1(OP_INT32, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND_NOSTAT(bid128_isSignaling, i2, a);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_isCanonical") == 0) {
  GETTEST1(OP_INT32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND_NOSTAT(bid32_isCanonical, i2, a32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_isCanonical") == 0) {
  GETTEST1(OP_INT32, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND_NOSTAT(bid64_isCanonical, i2, a64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_isCanonical") == 0) {
  GETTEST1(OP_INT32, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND_NOSTAT(bid128_isCanonical, i2, a);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_isNaN") == 0) {
  GETTEST1(OP_INT32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND_NOSTAT(bid32_isNaN, i2, a32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_isNaN") == 0) {
  GETTEST1(OP_INT32, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND_NOSTAT(bid64_isNaN, i2, a64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_isNaN") == 0) {
  GETTEST1(OP_INT32, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND_NOSTAT(bid128_isNaN, i2, a);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_sameQuantum") == 0) {
  GETTEST2(OP_INT32, OP_DEC32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND_NOSTAT(bid32_sameQuantum, i2, a32, b32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_sameQuantum") == 0) {
  GETTEST2(OP_INT32, OP_DEC64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND_NOSTAT(bid64_sameQuantum, i2, a64, b64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_sameQuantum") == 0) {
  GETTEST2(OP_INT32, OP_DEC128, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND_NOSTAT(bid128_sameQuantum, i2, a, b);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_totalOrder") == 0) {
  GETTEST2(OP_INT32, OP_DEC32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND_NOSTAT(bid32_totalOrder, i2, a32, b32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_totalOrderMag") == 0) {
  GETTEST2(OP_INT32, OP_DEC32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND_NOSTAT(bid32_totalOrderMag, i2, a32, b32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_totalOrder") == 0) {
  GETTEST2(OP_INT32, OP_DEC64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND_NOSTAT(bid64_totalOrder, i2, a64, b64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_totalOrderMag") == 0) {
  GETTEST2(OP_INT32, OP_DEC64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND_NOSTAT(bid64_totalOrderMag, i2, a64, b64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_totalOrder") == 0) {
  GETTEST2(OP_INT32, OP_DEC128, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND_NOSTAT(bid128_totalOrder, i2, a, b);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_totalOrderMag") == 0) {
  GETTEST2(OP_INT32, OP_DEC128, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND_NOSTAT(bid128_totalOrderMag, i2, a, b);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_to_bid128") == 0) {
  GETTEST1(OP_DEC128, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid32_to_bid128, q, a32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_to_bid64") == 0) {
  GETTEST1(OP_DEC64, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid32_to_bid64, q64, a32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_to_bid32") == 0) {
  GETTEST1(OP_DEC32, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid64_to_bid32, q32, a64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_to_bid128") == 0) {
  GETTEST1(OP_DEC128, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid64_to_bid128, q, a64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_to_bid32") == 0) {
  GETTEST1(OP_DEC32, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid128_to_bid32, q32, a);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_to_bid64") == 0) {
  GETTEST1(OP_DEC64, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid128_to_bid64, q64, a);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_to_binary128") == 0) {
  GETTEST1(OP_BIN128, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid128_to_binary128, rquad, a);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_to_binary128") == 0) {
  GETTEST1(OP_BIN128, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid64_to_binary128, rquad, a64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_to_binary128") == 0) {
  GETTEST1(OP_BIN128, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid32_to_binary128, rquad, a32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
#if defined(__ENABLE_BINARY80__) && __ENABLE_BINARY80__
if(strcmp(func, "bid128_to_binary80") == 0) {
  GETTEST1(OP_BIN80, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid128_to_binary80, Rldbl, A);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_to_binary80") == 0) {
  GETTEST1(OP_BIN80, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid64_to_binary80, Rldbl, A64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_to_binary80") == 0) {
  GETTEST1(OP_BIN80, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid32_to_binary80, Rldbl, A32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
#endif
if(strcmp(func, "bid128_to_binary64") == 0) {
  GETTEST1(OP_BIN64, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid128_to_binary64, rdbl, a);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_to_binary64") == 0) {
  GETTEST1(OP_BIN64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid64_to_binary64, rdbl, a64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_to_binary64") == 0) {
  GETTEST1(OP_BIN64, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid32_to_binary64, rdbl, a32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_to_binary32") == 0) {
  GETTEST1(OP_BIN32, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid128_to_binary32, rflt, a);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_to_binary32") == 0) {
  GETTEST1(OP_BIN32, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid64_to_binary32, rflt, a64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_to_binary32") == 0) {
  GETTEST1(OP_BIN32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid32_to_binary32, rflt, a32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "binary64_to_bid128") == 0) {
  GETTEST1(OP_DEC128, OP_BIN64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(binary64_to_bid128, q, adbl);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "binary64_to_bid64") == 0) {
  GETTEST1(OP_DEC64, OP_BIN64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(binary64_to_bid64, q64, adbl);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "binary64_to_bid32") == 0) {
  GETTEST1(OP_DEC32, OP_BIN64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(binary64_to_bid32, q32, adbl);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "binary32_to_bid128") == 0) {
  GETTEST1(OP_DEC128, OP_BIN32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(binary32_to_bid128, q, aflt);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "binary32_to_bid64") == 0) {
  GETTEST1(OP_DEC64, OP_BIN32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(binary32_to_bid64, q64, aflt);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "binary32_to_bid32") == 0) {
  GETTEST1(OP_DEC32, OP_BIN32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(binary32_to_bid32, q32, aflt);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
#if defined(__ENABLE_BINARY80__) && __ENABLE_BINARY80__
if(strcmp(func, "binary80_to_bid128") == 0) {
  GETTEST1(OP_DEC128, OP_BIN80);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(binary80_to_bid128, Q, Aldbl);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "binary80_to_bid64") == 0) {
  GETTEST1(OP_DEC64, OP_BIN80);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(binary80_to_bid64, Q64, Aldbl);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "binary80_to_bid32") == 0) {
  GETTEST1(OP_DEC32, OP_BIN80);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(binary80_to_bid32, Q32, Aldbl);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
#endif
if(strcmp(func, "binary128_to_bid128") == 0) {
  GETTEST1(OP_DEC128, OP_BIN128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(binary128_to_bid128, q, aquad);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "binary128_to_bid64") == 0) {
  GETTEST1(OP_DEC64, OP_BIN128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(binary128_to_bid64, q64, aquad);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "binary128_to_bid32") == 0) {
  GETTEST1(OP_DEC32, OP_BIN128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(binary128_to_bid32, q32, aquad);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid_testFlags") == 0) {
  GETTEST2(OP_BID_UINT32, OP_BID_UINT32, OP_BID_UINT32);
  {
    *pfpsf = bu_i32 & BID_FLAG_MASK;
    save_binary_status();
    BIDECIMAL_CALL1_NORND_NOMASK_NOINFO(bid_testFlags,
                                        *(_IDEC_flags *)&i2, au_i32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid_lowerFlags") == 0) {
  GETTEST2(OP_BID_UINT32, OP_BID_UINT32, OP_BID_UINT32);
  {
    *pfpsf = bu_i32 & BID_FLAG_MASK;
    save_binary_status();
    i1 = i2 = 0;
    BIDECIMAL_CALL1_NORND_NOMASK_NOINFO_RESVOID(bid_lowerFlags, au_i32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid_signalException") == 0) {
  GETTEST2(OP_BID_UINT32, OP_BID_UINT32, OP_BID_UINT32);
  {
    *pfpsf = bu_i32 & BID_FLAG_MASK;
    save_binary_status();
    i1 = i2 = 0;
    BIDECIMAL_CALL1_NORND_NOMASK_NOINFO_RESVOID(bid_signalException,
                                                au_i32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid_saveFlags") == 0) {
  GETTEST2(OP_BID_UINT32, OP_BID_UINT32, OP_BID_UINT32);
  {
    *pfpsf = bu_i32 & BID_FLAG_MASK;
    save_binary_status();
    BIDECIMAL_CALL1_NORND_NOMASK_NOINFO(bid_saveFlags,
                                        *(_IDEC_flags *)&i2, au_i32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid_restoreFlags") == 0) {
  GETTEST3(OP_BID_UINT32, OP_BID_UINT32, OP_BID_UINT32, OP_BID_UINT32);
  {
    *pfpsf = cu_i32 & BID_FLAG_MASK;
    save_binary_status();
    i1 = i2 = 0;
    BIDECIMAL_CALL2_NORND_NOMASK_NOINFO_RESVOID(bid_restoreFlags, au_i32,
                                                bu_i32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid_testSavedFlags") == 0) {
  GETTEST2(OP_BID_UINT32, OP_BID_UINT32, OP_BID_UINT32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND_NOFLAGS_NOMASK_NOINFO(bid_testSavedFlags,
                                                *(_IDEC_flags *)&i2,
                                                bu_i32, au_i32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid_getDecimalRoundingDirection") == 0) {
  GETTEST1(OP_BID_UINT32, OP_BID_UINT32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALLV_NOFLAGS_NOMASK_NOINFO(bid_getDecimalRoundingDirection,
                                          *(_IDEC_flags *)&i2);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid_setDecimalRoundingDirection") == 0) {
  GETTEST1(OP_BID_UINT32, OP_BID_UINT32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NOFLAGS_NOMASK_NOINFO(bid_setDecimalRoundingDirection,
                                          *(_IDEC_flags *)&i2,
                                          au_i32);
#if DECIMAL_GLOBAL_ROUNDING || DECIMAL_CALL_BY_REFERENCE
    i2 = rnd_mode;
#endif
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_radix") == 0) {
  GETTEST1(OP_INT32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND_NOSTAT(bid32_radix, i2, a32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_radix") == 0) {
  GETTEST1(OP_INT32, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND_NOSTAT(bid64_radix, i2, a64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_radix") == 0) {
  GETTEST1(OP_INT32, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND_NOSTAT(bid128_radix, i2, a);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid_is754") == 0) {
  GETTEST1(OP_INT32, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALLV_EMPTY(bid_is754, i2);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid_is754R") == 0) {
  GETTEST1(OP_INT32, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALLV_EMPTY(bid_is754R, i2);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_add") == 0) {
  GETTEST2(OP_DEC32, OP_DEC32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2(bid32_add, q32, a32, b32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_sub") == 0) {
  GETTEST2(OP_DEC32, OP_DEC32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2(bid32_sub, q32, a32, b32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_mul") == 0) {
  GETTEST2(OP_DEC32, OP_DEC32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2(bid32_mul, q32, a32, b32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_div") == 0) {
  GETTEST2(OP_DEC32, OP_DEC32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2(bid32_div, q32, a32, b32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_fma") == 0) {
  GETTEST3(OP_DEC32, OP_DEC32, OP_DEC32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL3(bid32_fma, q32, a32, b32, c32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_sqrt") == 0) {
  GETTEST1(OP_DEC32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid32_sqrt, q32, a32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_rem") == 0) {
  GETTEST2(OP_DEC32, OP_DEC32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND(bid32_rem, q32, a32, b32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_fmod") == 0) {
  GETTEST2(OP_DEC32, OP_DEC32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND(bid32_fmod, q32, a32, b32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_scalbn") == 0) {
  GETTEST2(OP_DEC32, OP_DEC32, OP_INT32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2(bid32_scalbn, q32, a32, b_i32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_ilogb") == 0) {
  GETTEST1(OP_INT32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid32_ilogb, i2, a32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_logb") == 0) {
  GETTEST1(OP_DEC32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid32_logb, q32, a32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_quantize") == 0) {
  GETTEST2(OP_DEC32, OP_DEC32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2(bid32_quantize, q32, a32, b32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_to_string") == 0) {
  GETTEST1(OP_DEC32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND_RESREF(bid32_to_string, convstr, a32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_from_string") == 0) {
  GETTEST1(OP_DEC32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_RESARG(bid32_from_string, q32, istr1);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_quiet_not_equal") == 0) {
  GETTEST2(OP_INT32, OP_DEC32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND(bid32_quiet_not_equal, i2, a32, b32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_quiet_ordered") == 0) {
  GETTEST2(OP_INT32, OP_DEC32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND(bid32_quiet_ordered, i2, a32, b32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_quiet_unordered") == 0) {
  GETTEST2(OP_INT32, OP_DEC32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND(bid32_quiet_unordered, i2, a32, b32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_quiet_greater_unordered") == 0) {
  GETTEST2(OP_INT32, OP_DEC32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND(bid32_quiet_greater_unordered, i2, a32, b32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_quiet_less_unordered") == 0) {
  GETTEST2(OP_INT32, OP_DEC32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND(bid32_quiet_less_unordered, i2, a32, b32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_quiet_greater_equal") == 0) {
  GETTEST2(OP_INT32, OP_DEC32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND(bid32_quiet_greater_equal, i2, a32, b32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_quiet_not_less") == 0) {
  GETTEST2(OP_INT32, OP_DEC32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND(bid32_quiet_not_less, i2, a32, b32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_quiet_less") == 0) {
  GETTEST2(OP_INT32, OP_DEC32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND(bid32_quiet_less, i2, a32, b32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_quiet_less_equal") == 0) {
  GETTEST2(OP_INT32, OP_DEC32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND(bid32_quiet_less_equal, i2, a32, b32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_quiet_not_greater") == 0) {
  GETTEST2(OP_INT32, OP_DEC32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND(bid32_quiet_not_greater, i2, a32, b32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_quiet_greater") == 0) {
  GETTEST2(OP_INT32, OP_DEC32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND(bid32_quiet_greater, i2, a32, b32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_quiet_equal") == 0) {
  GETTEST2(OP_INT32, OP_DEC32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND(bid32_quiet_equal, i2, a32, b32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_signaling_greater_unordered") == 0) {
  GETTEST2(OP_INT32, OP_DEC32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND(bid32_signaling_greater_unordered, i2, a32, b32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_signaling_less_unordered") == 0) {
  GETTEST2(OP_INT32, OP_DEC32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND(bid32_signaling_less_unordered, i2, a32, b32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_signaling_greater_equal") == 0) {
  GETTEST2(OP_INT32, OP_DEC32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND(bid32_signaling_greater_equal, i2, a32, b32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_signaling_not_less") == 0) {
  GETTEST2(OP_INT32, OP_DEC32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND(bid32_signaling_not_less, i2, a32, b32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_signaling_less") == 0) {
  GETTEST2(OP_INT32, OP_DEC32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND(bid32_signaling_less, i2, a32, b32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_signaling_less_equal") == 0) {
  GETTEST2(OP_INT32, OP_DEC32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND(bid32_signaling_less_equal, i2, a32, b32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_signaling_not_greater") == 0) {
  GETTEST2(OP_INT32, OP_DEC32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND(bid32_signaling_not_greater, i2, a32, b32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_signaling_greater") == 0) {
  GETTEST2(OP_INT32, OP_DEC32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND(bid32_signaling_greater, i2, a32, b32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_exp") == 0) {
  GETTEST1(OP_DEC32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid32_exp, q32, a32);
    fpsf_0 = 0;
    check_results(CMP_RELATIVEERR);
  }
}
if(strcmp(func, "bid32_log") == 0) {
  GETTEST1(OP_DEC32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid32_log, q32, a32);
    fpsf_0 = 0;
    check_results(CMP_RELATIVEERR);
  }
}
if(strcmp(func, "bid32_pow") == 0) {
  GETTEST2(OP_DEC32, OP_DEC32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2(bid32_pow, q32, a32, b32);
    fpsf_0 = 0;
    check_results(CMP_RELATIVEERR);
  }
}
if(strcmp(func, "bid64_log") == 0) {
  GETTEST1(OP_DEC64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid64_log, q64, a64);
    fpsf_0 = 0;
    check_results(CMP_RELATIVEERR);
  }
}
if(strcmp(func, "bid64_pow") == 0) {
  GETTEST2(OP_DEC64, OP_DEC64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2(bid64_pow, q64, a64, b64);
    fpsf_0 = 0;
    check_results(CMP_RELATIVEERR);
  }
}
if(strcmp(func, "bid64_exp") == 0) {
  GETTEST1(OP_DEC64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid64_exp, q64, a64);
    fpsf_0 = 0;
    check_results(CMP_RELATIVEERR);
  }
}
if(strcmp(func, "bid128_log") == 0) {
  GETTEST1(OP_DEC128, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid128_log, q, a);
    fpsf_0 = 0;
    check_results(CMP_RELATIVEERR);
  }
}
if(strcmp(func, "bid128_pow") == 0) {
  GETTEST2(OP_DEC128, OP_DEC128, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2(bid128_pow, q, a, b);
    fpsf_0 = 0;
    check_results(CMP_RELATIVEERR);
  }
}
if(strcmp(func, "bid128_exp") == 0) {
  GETTEST1(OP_DEC128, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid128_exp, q, a);
    fpsf_0 = 0;
    check_results(CMP_RELATIVEERR);
  }
}
if(strcmp(func, "bid32_sin") == 0) {
  GETTEST1(OP_DEC32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid32_sin, q32, a32);
    fpsf_0 = 0;
    check_results(CMP_RELATIVEERR);
  }
}
if(strcmp(func, "bid32_cos") == 0) {
  GETTEST1(OP_DEC32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid32_cos, q32, a32);
    fpsf_0 = 0;
    check_results(CMP_RELATIVEERR);
  }
}
if(strcmp(func, "bid32_tan") == 0) {
  GETTEST1(OP_DEC32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid32_tan, q32, a32);
    fpsf_0 = 0;
    check_results(CMP_RELATIVEERR);
  }
}
if(strcmp(func, "bid32_asin") == 0) {
  GETTEST1(OP_DEC32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid32_asin, q32, a32);
    fpsf_0 = 0;
    check_results(CMP_RELATIVEERR);
  }
}
if(strcmp(func, "bid32_acos") == 0) {
  GETTEST1(OP_DEC32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid32_acos, q32, a32);
    fpsf_0 = 0;
    check_results(CMP_RELATIVEERR);
  }
}
if(strcmp(func, "bid32_atan") == 0) {
  GETTEST1(OP_DEC32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid32_atan, q32, a32);
    fpsf_0 = 0;
    check_results(CMP_RELATIVEERR);
  }
}
if(strcmp(func, "bid32_sinh") == 0) {
  GETTEST1(OP_DEC32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid32_sinh, q32, a32);
    fpsf_0 = 0;
    check_results(CMP_RELATIVEERR);
  }
}
if(strcmp(func, "bid32_cosh") == 0) {
  GETTEST1(OP_DEC32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid32_cosh, q32, a32);
    fpsf_0 = 0;
    check_results(CMP_RELATIVEERR);
  }
}
if(strcmp(func, "bid32_tanh") == 0) {
  GETTEST1(OP_DEC32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid32_tanh, q32, a32);
    fpsf_0 = 0;
    check_results(CMP_RELATIVEERR);
  }
}
if(strcmp(func, "bid32_asinh") == 0) {
  GETTEST1(OP_DEC32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid32_asinh, q32, a32);
    fpsf_0 = 0;
    check_results(CMP_RELATIVEERR);
  }
}
if(strcmp(func, "bid32_acosh") == 0) {
  mre_max[0] = 0.55 * 2;
  mre_max[1] = 1.05 * 2;
  mre_max[2] = 1.05 * 2;
  mre_max[3] = 1.05 * 2;
  mre_max[4] = 0.55 * 2;
  GETTEST1(OP_DEC32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid32_acosh, q32, a32);
    fpsf_0 = 0;
    check_results(CMP_RELATIVEERR);
  }
}
if(strcmp(func, "bid32_atanh") == 0) {
  GETTEST1(OP_DEC32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid32_atanh, q32, a32);
    fpsf_0 = 0;
    check_results(CMP_RELATIVEERR);
  }
}
if(strcmp(func, "bid32_atan2") == 0) {
  GETTEST2(OP_DEC32, OP_DEC32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2(bid32_atan2, q32, a32, b32);
    fpsf_0 = 0;
    check_results(CMP_RELATIVEERR);
  }
}
if(strcmp(func, "bid32_fmod") == 0) {
  GETTEST2(OP_DEC32, OP_DEC32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND(bid32_fmod, q32, a32, b32);
    fpsf_0 = 0;
    check_results(CMP_RELATIVEERR);
  }
}
if(strcmp(func, "bid32_hypot") == 0) {
  GETTEST2(OP_DEC32, OP_DEC32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2(bid32_hypot, q32, a32, b32);
    fpsf_0 = 0;
    check_results(CMP_RELATIVEERR);
  }
}
if(strcmp(func, "bid32_cbrt") == 0) {
  GETTEST1(OP_DEC32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid32_cbrt, q32, a32);
    fpsf_0 = 0;
    check_results(CMP_RELATIVEERR);
  }
}
if(strcmp(func, "bid32_expm1") == 0) {
  GETTEST1(OP_DEC32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid32_expm1, q32, a32);
    fpsf_0 = 0;
    check_results(CMP_RELATIVEERR);
  }
}
if(strcmp(func, "bid32_log1p") == 0) {
  GETTEST1(OP_DEC32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid32_log1p, q32, a32);
    fpsf_0 = 0;
    check_results(CMP_RELATIVEERR);
  }
}
if(strcmp(func, "bid32_log10") == 0) {
  GETTEST1(OP_DEC32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid32_log10, q32, a32);
    fpsf_0 = 0;
    check_results(CMP_RELATIVEERR);
  }
}
if(strcmp(func, "bid32_exp2") == 0) {
  GETTEST1(OP_DEC32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid32_exp2, q32, a32);
    fpsf_0 = 0;
    check_results(CMP_RELATIVEERR);
  }
}
if(strcmp(func, "bid32_exp10") == 0) {
  GETTEST1(OP_DEC32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid32_exp10, q32, a32);
    fpsf_0 = 0;
    check_results(CMP_RELATIVEERR);
  }
}
if(strcmp(func, "bid32_log2") == 0) {
  GETTEST1(OP_DEC32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid32_log2, q32, a32);
    fpsf_0 = 0;
    check_results(CMP_RELATIVEERR);
  }
}
if(strcmp(func, "bid32_erf") == 0) {
  GETTEST1(OP_DEC32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid32_erf, q32, a32);
    fpsf_0 = 0;
    check_results(CMP_RELATIVEERR);
  }
}
if(strcmp(func, "bid32_erfc") == 0) {
  GETTEST1(OP_DEC32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid32_erfc, q32, a32);
    fpsf_0 = 0;
    check_results(CMP_RELATIVEERR);
  }
}
if(strcmp(func, "bid32_tgamma") == 0) {
  mre_max[0] = 0.55e+4;
  mre_max[1] = 1.05e+4;
  mre_max[2] = 1.05e+4;
  mre_max[3] = 1.05e+4;
  mre_max[4] = 0.55e+4;
  GETTEST1(OP_DEC32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid32_tgamma, q32, a32);
    fpsf_0 = 0;
    check_results(CMP_RELATIVEERR);
  }
}
if(strcmp(func, "bid32_lgamma") == 0) {
  mre_max[0] = 0.55e+4;
  mre_max[1] = 1.05e+4;
  mre_max[2] = 1.05e+4;
  mre_max[3] = 1.05e+4;
  mre_max[4] = 0.55e+4;
  GETTEST1(OP_DEC32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid32_lgamma, q32, a32);
    fpsf_0 = 0;
    check_results(CMP_RELATIVEERR);
  }
}
if(strcmp(func, "bid32_modf") == 0) {
  GETTEST2(OP_DEC32, OP_DEC32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_YPTR_NORND(bid32_modf, q32, a32, b32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_sin") == 0) {
  GETTEST1(OP_DEC64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid64_sin, q64, a64);
    fpsf_0 = 0;
    check_results(CMP_RELATIVEERR);
  }
}
if(strcmp(func, "bid64_cos") == 0) {
  GETTEST1(OP_DEC64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid64_cos, q64, a64);
    fpsf_0 = 0;
    check_results(CMP_RELATIVEERR);
  }
}
if(strcmp(func, "bid64_tan") == 0) {
  GETTEST1(OP_DEC64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid64_tan, q64, a64);
    fpsf_0 = 0;
    check_results(CMP_RELATIVEERR);
  }
}
if(strcmp(func, "bid64_asin") == 0) {
  GETTEST1(OP_DEC64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid64_asin, q64, a64);
    fpsf_0 = 0;
    check_results(CMP_RELATIVEERR);
  }
}
if(strcmp(func, "bid64_acos") == 0) {
  GETTEST1(OP_DEC64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid64_acos, q64, a64);
    fpsf_0 = 0;
    check_results(CMP_RELATIVEERR);
  }
}
if(strcmp(func, "bid64_atan") == 0) {
  GETTEST1(OP_DEC64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid64_atan, q64, a64);
    fpsf_0 = 0;
    check_results(CMP_RELATIVEERR);
  }
}
if(strcmp(func, "bid64_sinh") == 0) {
  GETTEST1(OP_DEC64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid64_sinh, q64, a64);
    fpsf_0 = 0;
    check_results(CMP_RELATIVEERR);
  }
}
if(strcmp(func, "bid64_cosh") == 0) {
  GETTEST1(OP_DEC64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid64_cosh, q64, a64);
    fpsf_0 = 0;
    check_results(CMP_RELATIVEERR);
  }
}
if(strcmp(func, "bid64_tanh") == 0) {
  GETTEST1(OP_DEC64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid64_tanh, q64, a64);
    fpsf_0 = 0;
    check_results(CMP_RELATIVEERR);
  }
}
if(strcmp(func, "bid64_asinh") == 0) {
  GETTEST1(OP_DEC64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid64_asinh, q64, a64);
    fpsf_0 = 0;
    check_results(CMP_RELATIVEERR);
  }
}
if(strcmp(func, "bid64_acosh") == 0) {
  mre_max[0] = 0.55 * 2;
  mre_max[1] = 1.05 * 2;
  mre_max[2] = 1.05 * 2;
  mre_max[3] = 1.05 * 2;
  mre_max[4] = 0.55 * 2;
  GETTEST1(OP_DEC64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid64_acosh, q64, a64);
    fpsf_0 = 0;
    check_results(CMP_RELATIVEERR);
  }
}
if(strcmp(func, "bid64_atanh") == 0) {
  GETTEST1(OP_DEC64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid64_atanh, q64, a64);
    fpsf_0 = 0;
    check_results(CMP_RELATIVEERR);
  }
}
if(strcmp(func, "bid64_atan2") == 0) {
  GETTEST2(OP_DEC64, OP_DEC64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2(bid64_atan2, q64, a64, b64);
    fpsf_0 = 0;
    check_results(CMP_RELATIVEERR);
  }
}
if(strcmp(func, "bid64_fmod") == 0) {
  GETTEST2(OP_DEC64, OP_DEC64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND(bid64_fmod, q64, a64, b64);
    fpsf_0 = 0;
    check_results(CMP_RELATIVEERR);
  }
}
if(strcmp(func, "bid64_hypot") == 0) {
  GETTEST2(OP_DEC64, OP_DEC64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2(bid64_hypot, q64, a64, b64);
    fpsf_0 = 0;
    check_results(CMP_RELATIVEERR);
  }
}
if(strcmp(func, "bid64_expm1") == 0) {
  GETTEST1(OP_DEC64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid64_expm1, q64, a64);
    fpsf_0 = 0;
    check_results(CMP_RELATIVEERR);
  }
}
if(strcmp(func, "bid64_cbrt") == 0) {
  GETTEST1(OP_DEC64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid64_cbrt, q64, a64);
    fpsf_0 = 0;
    check_results(CMP_RELATIVEERR);
  }
}
if(strcmp(func, "bid64_log1p") == 0) {
  GETTEST1(OP_DEC64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid64_log1p, q64, a64);
    fpsf_0 = 0;
    check_results(CMP_RELATIVEERR);
  }
}
if(strcmp(func, "bid64_log10") == 0) {
  GETTEST1(OP_DEC64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid64_log10, q64, a64);
    fpsf_0 = 0;
    check_results(CMP_RELATIVEERR);
  }
}
if(strcmp(func, "bid64_exp2") == 0) {
  GETTEST1(OP_DEC64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid64_exp2, q64, a64);
    fpsf_0 = 0;
    check_results(CMP_RELATIVEERR);
  }
}
if(strcmp(func, "bid64_exp10") == 0) {
  GETTEST1(OP_DEC64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid64_exp10, q64, a64);
    fpsf_0 = 0;
    check_results(CMP_RELATIVEERR);
  }
}
if(strcmp(func, "bid64_log2") == 0) {
  GETTEST1(OP_DEC64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid64_log2, q64, a64);
    fpsf_0 = 0;
    check_results(CMP_RELATIVEERR);
  }
}
if(strcmp(func, "bid64_erf") == 0) {
  GETTEST1(OP_DEC64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid64_erf, q64, a64);
    fpsf_0 = 0;
    check_results(CMP_RELATIVEERR);
  }
}
if(strcmp(func, "bid64_erfc") == 0) {
  GETTEST1(OP_DEC64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid64_erfc, q64, a64);
    fpsf_0 = 0;
    check_results(CMP_RELATIVEERR);
  }
}
if(strcmp(func, "bid64_tgamma") == 0) {
  mre_max[0] = 0.55e+13;
  mre_max[1] = 1.05e+13;
  mre_max[2] = 1.05e+13;
  mre_max[3] = 1.05e+13;
  mre_max[4] = 0.55e+13;
  GETTEST1(OP_DEC64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid64_tgamma, q64, a64);
    fpsf_0 = 0;
    check_results(CMP_RELATIVEERR);
  }
}
if(strcmp(func, "bid64_lgamma") == 0) {
  mre_max[0] = 0.55e+13;
  mre_max[1] = 1.05e+13;
  mre_max[2] = 1.05e+13;
  mre_max[3] = 1.05e+13;
  mre_max[4] = 0.55e+13;
  GETTEST1(OP_DEC64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid64_lgamma, q64, a64);
    fpsf_0 = 0;
    check_results(CMP_RELATIVEERR);
  }
}
if(strcmp(func, "bid64_modf") == 0) {
  GETTEST2(OP_DEC64, OP_DEC64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_YPTR_NORND(bid64_modf, q64, a64, b64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_sin") == 0) {
  GETTEST1(OP_DEC128, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid128_sin, q, a);
    fpsf_0 = 0;
    check_results(CMP_RELATIVEERR);
  }
}
if(strcmp(func, "bid128_cos") == 0) {
  GETTEST1(OP_DEC128, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid128_cos, q, a);
    fpsf_0 = 0;
    check_results(CMP_RELATIVEERR);
  }
}
if(strcmp(func, "bid128_tan") == 0) {
  GETTEST1(OP_DEC128, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid128_tan, q, a);
    fpsf_0 = 0;
    check_results(CMP_RELATIVEERR);
  }
}
if(strcmp(func, "bid128_asin") == 0) {
  GETTEST1(OP_DEC128, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid128_asin, q, a);
    fpsf_0 = 0;
    check_results(CMP_RELATIVEERR);
  }
}
if(strcmp(func, "bid128_acos") == 0) {
  GETTEST1(OP_DEC128, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid128_acos, q, a);
    fpsf_0 = 0;
    check_results(CMP_RELATIVEERR);
  }
}
if(strcmp(func, "bid128_atan") == 0) {
  GETTEST1(OP_DEC128, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid128_atan, q, a);
    fpsf_0 = 0;
    check_results(CMP_RELATIVEERR);
  }
}
if(strcmp(func, "bid128_sinh") == 0) {
  GETTEST1(OP_DEC128, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid128_sinh, q, a);
    fpsf_0 = 0;
    check_results(CMP_RELATIVEERR);
  }
}
if(strcmp(func, "bid128_cosh") == 0) {
  GETTEST1(OP_DEC128, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid128_cosh, q, a);
    fpsf_0 = 0;
    check_results(CMP_RELATIVEERR);
  }
}
if(strcmp(func, "bid128_tanh") == 0) {
  GETTEST1(OP_DEC128, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid128_tanh, q, a);
    fpsf_0 = 0;
    check_results(CMP_RELATIVEERR);
  }
}
if(strcmp(func, "bid128_asinh") == 0) {
  GETTEST1(OP_DEC128, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid128_asinh, q, a);
    fpsf_0 = 0;
    check_results(CMP_RELATIVEERR);
  }
}
if(strcmp(func, "bid128_acosh") == 0) {
  GETTEST1(OP_DEC128, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid128_acosh, q, a);
    fpsf_0 = 0;
    check_results(CMP_RELATIVEERR);
  }
}
if(strcmp(func, "bid128_atanh") == 0) {
  GETTEST1(OP_DEC128, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid128_atanh, q, a);
    fpsf_0 = 0;
    check_results(CMP_RELATIVEERR);
  }
}
if(strcmp(func, "bid128_atan2") == 0) {
  GETTEST2(OP_DEC128, OP_DEC128, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2(bid128_atan2, q, a, b);
    fpsf_0 = 0;
    check_results(CMP_RELATIVEERR);
  }
}
if(strcmp(func, "bid128_fmod") == 0) {
  GETTEST2(OP_DEC128, OP_DEC128, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND(bid128_fmod, q, a, b);
    fpsf_0 = 0;
    check_results(CMP_RELATIVEERR);
  }
}
if(strcmp(func, "bid128_hypot") == 0) {
  GETTEST2(OP_DEC128, OP_DEC128, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2(bid128_hypot, q, a, b);
    fpsf_0 = 0;
    check_results(CMP_RELATIVEERR);
  }
}
if(strcmp(func, "bid128_cbrt") == 0) {
  GETTEST1(OP_DEC128, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid128_cbrt, q, a);
    fpsf_0 = 0;
    check_results(CMP_RELATIVEERR);
  }
}
if(strcmp(func, "bid128_expm1") == 0) {
  GETTEST1(OP_DEC128, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid128_expm1, q, a);
    fpsf_0 = 0;
    check_results(CMP_RELATIVEERR);
  }
}
if(strcmp(func, "bid128_log1p") == 0) {
  GETTEST1(OP_DEC128, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid128_log1p, q, a);
    fpsf_0 = 0;
    check_results(CMP_RELATIVEERR);
  }
}
if(strcmp(func, "bid128_log10") == 0) {
  GETTEST1(OP_DEC128, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid128_log10, q, a);
    fpsf_0 = 0;
    check_results(CMP_RELATIVEERR);
  }
}
if(strcmp(func, "bid128_exp2") == 0) {
  GETTEST1(OP_DEC128, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid128_exp2, q, a);
    fpsf_0 = 0;
    check_results(CMP_RELATIVEERR);
  }
}
if(strcmp(func, "bid128_exp10") == 0) {
  GETTEST1(OP_DEC128, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid128_exp10, q, a);
    fpsf_0 = 0;
    check_results(CMP_RELATIVEERR);
  }
}
if(strcmp(func, "bid128_log2") == 0) {
  GETTEST1(OP_DEC128, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid128_log2, q, a);
    fpsf_0 = 0;
    check_results(CMP_RELATIVEERR);
  }
}
if(strcmp(func, "bid128_erf") == 0) {
  GETTEST1(OP_DEC128, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid128_erf, q, a);
    fpsf_0 = 0;
    check_results(CMP_RELATIVEERR);
  }
}
if(strcmp(func, "bid128_erfc") == 0) {
  GETTEST1(OP_DEC128, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid128_erfc, q, a);
    fpsf_0 = 0;
    check_results(CMP_RELATIVEERR);
  }
}
if(strcmp(func, "bid128_tgamma") == 0) {
  mre_max[0] = 0.55e+31;
  mre_max[1] = 1.05e+31;
  mre_max[2] = 1.05e+31;
  mre_max[3] = 1.05e+31;
  mre_max[4] = 0.55e+31;
  GETTEST1(OP_DEC128, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid128_tgamma, q, a);
    fpsf_0 = 0;
    check_results(CMP_RELATIVEERR);
  }
}
if(strcmp(func, "bid128_lgamma") == 0) {
  mre_max[0] = 0.55e+13;
  mre_max[1] = 1.05e+13;
  mre_max[2] = 1.05e+13;
  mre_max[3] = 1.05e+13;
  mre_max[4] = 0.55e+13;
  GETTEST1(OP_DEC128, OP_DEC128);
  {
    int t3;
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1(bid128_lgamma, q, a);

    // deal with overflow flag (8) for inaccurate lgamma
    if((expected_status ^ (*pfpsf)) & 8) {
      BIDECIMAL_CALL1_NORND_NOSTAT(bid128_isInf, t3, q);
      if((expected_status & 8) && (!t3)) {
        expected_status ^= 8;
      } else if((!(expected_status & 8)) && (t3)) {
        expected_status ^= 8;
      }
    }

    fpsf_0 = 0;
    check_results(CMP_RELATIVEERR);
  }
}
if(strcmp(func, "bid128_modf") == 0) {
  GETTEST2(OP_DEC128, OP_DEC128, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_YPTR_NORND(bid128_modf, q, a, b);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_fdim") == 0) {
  GETTEST2(OP_DEC32, OP_DEC32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2(bid32_fdim, q32, a32, b32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_fdim") == 0) {
  GETTEST2(OP_DEC64, OP_DEC64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2(bid64_fdim, q64, a64, b64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_fdim") == 0) {
  GETTEST2(OP_DEC128, OP_DEC128, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2(bid128_fdim, q, a, b);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_quantexp") == 0) {
  GETTEST1(OP_INT32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid32_quantexp, i2, a32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_quantexp") == 0) {
  GETTEST1(OP_INT32, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid64_quantexp, i2, a64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_quantexp") == 0) {
  GETTEST1(OP_INT32, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid128_quantexp, i2, a);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_llquantexp") == 0) {
  GETTEST1(OP_INT64, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid32_llquantexp, *(long long int *)&result_i64, a32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_llquantexp") == 0) {
  GETTEST1(OP_INT64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid64_llquantexp, *(long long int *)&result_i64, a64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_llquantexp") == 0) {
  GETTEST1(OP_INT64, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND(bid128_llquantexp, *(long long int *)&result_i64, a);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_quantum") == 0) {
  GETTEST1(OP_DEC32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND_NOSTAT(bid32_quantum, q32, a32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_quantum") == 0) {
  GETTEST1(OP_DEC64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND_NOSTAT(bid64_quantum, q64, a64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_quantum") == 0) {
  GETTEST1(OP_DEC128, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL1_NORND_NOSTAT(bid128_quantum, q, a);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_nan") == 0) {
  GETTEST1(OP_DEC32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    if(!strcmp("NULL", istr1)) {
      BIDECIMAL_CALL1_NORND_NOFLAGS_NOMASK_NOINFO_ARGREF(bid32_nan, q32, NULL);
    } else {
      BIDECIMAL_CALL1_NORND_NOFLAGS_NOMASK_NOINFO_ARGREF(bid32_nan, q32, (const char *)istr1);
    }
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_nan") == 0) {
  GETTEST1(OP_DEC64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    if(!strcmp("NULL", istr1)) {
      BIDECIMAL_CALL1_NORND_NOFLAGS_NOMASK_NOINFO_ARGREF(bid64_nan, q64, NULL);
    } else {
      BIDECIMAL_CALL1_NORND_NOFLAGS_NOMASK_NOINFO_ARGREF(bid64_nan, q64, (const char *)istr1);
    }
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_nan") == 0) {
  GETTEST1(OP_DEC128, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    if(!strcmp("NULL", istr1)) {
      BIDECIMAL_CALL1_NORND_NOFLAGS_NOMASK_NOINFO_ARGREF(bid128_nan, q, NULL);
    } else {
      BIDECIMAL_CALL1_NORND_NOFLAGS_NOMASK_NOINFO_ARGREF(bid128_nan, q, (const char *)istr1);
    }
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_frexp") == 0) {
  GETTEST2(OP_DEC32, OP_DEC32, OP_INT32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND_NOFLAGS_NOMASK_NOINFO_ARG2REF(bid32_frexp, q32, a32, &i2);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_frexp") == 0) {
  GETTEST2(OP_DEC64, OP_DEC64, OP_INT32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND_NOFLAGS_NOMASK_NOINFO_ARG2REF(bid64_frexp, q64, a64, &i2);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_frexp") == 0) {
  GETTEST2(OP_DEC128, OP_DEC128, OP_INT32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2_NORND_NOFLAGS_NOMASK_NOINFO_ARG2REF(bid128_frexp, q, a, &i2);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_ldexp") == 0) {
  GETTEST2(OP_DEC32, OP_DEC32, OP_INT32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2(bid32_ldexp, q32, a32, b_i32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_ldexp") == 0) {
  GETTEST2(OP_DEC64, OP_DEC64, OP_INT32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2(bid64_ldexp, q64, a64, b_i32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_ldexp") == 0) {
  GETTEST2(OP_DEC128, OP_DEC128, OP_INT32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2(bid128_ldexp, q, a, b_i32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_inf") == 0) {
  GETTEST1(OP_DEC32, OP_INT32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALLV_EMPTY(bid32_inf, q32);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_inf") == 0) {
  GETTEST1(OP_DEC64, OP_INT32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALLV_EMPTY(bid64_inf, q64);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_inf") == 0) {
  GETTEST1(OP_DEC128, OP_INT32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALLV_EMPTY(bid128_inf, q);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid32_scalbln") == 0) {
  GETTEST2(OP_DEC32, OP_DEC32, OP_LINT);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2(bid32_scalbln, q32, a32, bli);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid64_scalbln") == 0) {
  GETTEST2(OP_DEC64, OP_DEC64, OP_LINT);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2(bid64_scalbln, q64, a64, bli);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid128_scalbln") == 0) {
  GETTEST2(OP_DEC128, OP_DEC128, OP_LINT);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    BIDECIMAL_CALL2(bid128_scalbln, q, a, bli);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid_strtod32") == 0) {
  GETTEST1(OP_DEC32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    if(!strcmp("NULL", istr1)) {
      q32 = bid_strtod32(NULL, &endptr);
    } else if(!strcmp("EMPTY", istr1)) {
      q32 = bid_strtod32("", &endptr);
    } else if(str_prefix[0] != 0) {
      char strtmp[STRMAX];
      strcpy(strtmp, str_prefix);
      strcat(strtmp, istr1);
      strcpy(istr1, strtmp);
      q32 = bid_strtod32(istr1, &endptr);
    } else {
      q32 = bid_strtod32(istr1, &endptr);
    }
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid_strtod64") == 0) {
  GETTEST1(OP_DEC64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    if(!strcmp("NULL", istr1)) {
      q64 = bid_strtod64(NULL, &endptr);
    } else if(!strcmp("EMPTY", istr1)) {
      q64 = bid_strtod64("", &endptr);
    } else if(str_prefix[0] != 0) {
      char strtmp[STRMAX];
      strcpy(strtmp, str_prefix);
      strcat(strtmp, istr1);
      strcpy(istr1, strtmp);
      q64 = bid_strtod64(istr1, &endptr);
    } else {
      q64 = bid_strtod64(istr1, &endptr);
    }
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid_strtod128") == 0) {
  GETTEST1(OP_DEC128, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    if(!strcmp("NULL", istr1)) {
      q = bid_strtod128(NULL, &endptr);
    } else if(!strcmp("EMPTY", istr1)) {
      q = bid_strtod128("", &endptr);
    } else if(str_prefix[0] != 0) {
      char strtmp[STRMAX];
      strcpy(strtmp, str_prefix);
      strcat(strtmp, istr1);
      strcpy(istr1, strtmp);
      q = bid_strtod128(istr1, &endptr);
    } else {
      q = bid_strtod128(istr1, &endptr);
    }
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid_wcstod32") == 0) {
  GETTEST1(OP_DEC32, OP_DEC32);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    copy_str_to_wstr();
    if(!strcmp("NULL", istr1)) {
      q32 = bid_wcstod32(NULL, &wendptr);
    } else if(!strcmp("EMPTY", istr1)) {
      wistr1[0] = 0;
      q32 = bid_wcstod32(wistr1, &wendptr);
    } else if(str_prefix[0] != 0) {
      char strtmp[STRMAX];
      strcpy(strtmp, str_prefix);
      strcat(strtmp, istr1);
      strcpy(istr1, strtmp);
      copy_str_to_wstr();
      q32 = bid_wcstod32(wistr1, &wendptr);
    } else {
      q32 = bid_wcstod32(wistr1, &wendptr);
    }
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid_wcstod64") == 0) {
  GETTEST1(OP_DEC64, OP_DEC64);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    copy_str_to_wstr();
    if(!strcmp("NULL", istr1)) {
      q64 = bid_wcstod64(NULL, &wendptr);
    } else if(!strcmp("EMPTY", istr1)) {
      wistr1[0] = 0;
      q64 = bid_wcstod64(wistr1, &wendptr);
    } else if(str_prefix[0] != 0) {
      char strtmp[STRMAX];
      strcpy(strtmp, str_prefix);
      strcat(strtmp, istr1);
      strcpy(istr1, strtmp);
      copy_str_to_wstr();
      q64 = bid_wcstod64(wistr1, &wendptr);
    } else {
      q64 = bid_wcstod64(wistr1, &wendptr);
    }
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid_wcstod128") == 0) {
  GETTEST1(OP_DEC128, OP_DEC128);
  {
    *pfpsf = fpsf_0;
    save_binary_status();
    copy_str_to_wstr();
    if(!strcmp("NULL", istr1)) {
      q = bid_wcstod128(NULL, &wendptr);
    } else if(!strcmp("EMPTY", istr1)) {
      wistr1[0] = 0;
      q = bid_wcstod128(wistr1, &wendptr);
    } else if(str_prefix[0] != 0) {
      char strtmp[STRMAX];
      strcpy(strtmp, str_prefix);
      strcat(strtmp, istr1);
      strcpy(istr1, strtmp);
      copy_str_to_wstr();
      q = bid_wcstod128(wistr1, &wendptr);
    } else {
      q = bid_wcstod128(wistr1, &wendptr);
    }
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid_feclearexcept") == 0) {
  GETTEST2(OP_BID_UINT32, OP_BID_UINT32, OP_BID_UINT32);
  {
    *pfpsf = bu_i32 & BID_FLAG_MASK;
    save_binary_status();
    i1 = i2 = 0;
    bid_feclearexcept((int)au_i32 _EXC_FLAGS_ARG);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid_fegetexceptflag") == 0) {
  GETTEST2(OP_BID_UINT32, OP_BID_UINT32, OP_BID_UINT32);
  {
    *pfpsf = bu_i32 & BID_FLAG_MASK;
    save_binary_status();
    fp_fl = (fexcept_t)i2;
    bid_fegetexceptflag(&fp_fl, (int)au_i32 _EXC_FLAGS_ARG);
    i2 = (int)fp_fl;
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid_feraiseexcept") == 0) {
  GETTEST2(OP_BID_UINT32, OP_BID_UINT32, OP_BID_UINT32);
  {
    *pfpsf = bu_i32 & BID_FLAG_MASK;
    save_binary_status();
    i1 = i2 = 0;
    bid_feraiseexcept((int)au_i32 _EXC_FLAGS_ARG);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid_fesetexceptflag") == 0) {
  GETTEST2(OP_BID_UINT32, OP_BID_UINT32, OP_BID_UINT32);
  {
    *pfpsf = bu_i32 & BID_FLAG_MASK;
    save_binary_status();
    i2 = i1;
    fp_fl = (fexcept_t)i1;
    bid_fesetexceptflag(&fp_fl, (int)au_i32 _EXC_FLAGS_ARG);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
if(strcmp(func, "bid_fetestexcept") == 0) {
  GETTEST2(OP_BID_UINT32, OP_BID_UINT32, OP_BID_UINT32);
  {
    *pfpsf = bu_i32 & BID_FLAG_MASK;
    save_binary_status();
    i2 = bid_fetestexcept((int)au_i32 _EXC_FLAGS_ARG);
    fpsf_0 = 0;
    check_results(CMP_FUZZYSTATUS);
  }
}
