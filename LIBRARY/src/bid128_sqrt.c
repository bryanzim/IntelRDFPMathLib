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

#define BID_128RES
#define BID_FUNCTION_SETS_BINARY_FLAGS
#include "bid_internal.h"
#include "bid_sqrt_macros.h"
#include <fenv.h>

BID128_FUNCTION_ARG1(bid128_sqrt, x)

BID_UINT256 m256, c256, c4, c8;
BID_UINT128 cx, c_x1, c_x2, a10, s2, t128, t_p128, cs, csm, res;
BID_UINT64 sign_x, carry;
BID_SINT64 d;
int_float fx, f64;
int exponent_x, bin_expon_cx;
int digits, scale, exponent_q;
int old_rm, rm_changed = 0;

BID_OPT_SAVE_BINARY_FLAGS()

// Set it to round-to-nearest (if different)
if((old_rm = fegetround()) != FE_TONEAREST) {
  rm_changed = 1;
  fesetround(FE_TONEAREST);
}

// unpack arguments, check for NaN or Infinity
if(!unpack_BID128_value(&sign_x, &exponent_x, &cx, x)) {
  res.w[1U] = cx.w[1U];
  res.w[0U] = cx.w[0U];
  // NaN ?
  if((x.w[1U] & 0x7c00000000000000ull) == 0x7c00000000000000ull) {
#ifdef BID_SET_STATUS_FLAGS
    if((x.w[1U] & 0x7e00000000000000ull) == 0x7e00000000000000ull) // sNaN
      __set_status_flags(pfpsf, BID_INVALID_EXCEPTION);
#endif
    res.w[1U] = cx.w[1U] & QUIET_MASK64;
    // restore the rounding mode back if it has been changed
    if(rm_changed)
      fesetround(old_rm);
    BID_RETURN(res);
  }
  // x is Infinity?
  if((x.w[1U] & 0x7800000000000000ull) == 0x7800000000000000ull) {
    res.w[1U] = cx.w[1U];
    if(sign_x) {
      // -Inf, return NaN
      res.w[1U] = 0x7c00000000000000ull;
#ifdef BID_SET_STATUS_FLAGS
      __set_status_flags(pfpsf, BID_INVALID_EXCEPTION);
#endif
    }
    // restore the rounding mode back if it has been changed
    if(rm_changed)
      fesetround(old_rm);
    BID_RETURN(res);
  }
  // x is 0 otherwise

  res.w[1U] =
      sign_x |
      ((((BID_UINT64)(exponent_x + DECIMAL_EXPONENT_BIAS_128)) >> 1) << 49);
  res.w[0U] = 0;
  // restore the rounding mode back if it has been changed
  if(rm_changed)
    fesetround(old_rm);
  BID_RETURN(res);
}
if(sign_x) {
  res.w[1U] = 0x7c00000000000000ull;
  res.w[0U] = 0;
#ifdef BID_SET_STATUS_FLAGS
  __set_status_flags(pfpsf, BID_INVALID_EXCEPTION);
#endif
  // restore the rounding mode back if it has been changed
  if(rm_changed)
    fesetround(old_rm);
  BID_RETURN(res);
}
#ifdef UNCHANGED_BINARY_STATUS_FLAGS
// (void) fegetexceptflag (&binaryflags, BID_FE_ALL_FLAGS);
#endif
// 2^64
f64.i = 0x5f800000U;

// fx ~ CX
fx.d = (float)cx.w[1U] * f64.d + (float)cx.w[0U];
bin_expon_cx = ((fx.i >> 23) & 0xffU) - 0x7fU;
digits = bid_estimate_decimal_digits[bin_expon_cx];

a10 = cx;
if(exponent_x & 1) {
  a10.w[1U] = (cx.w[1U] << 3) | (cx.w[0U] >> 61);
  a10.w[0U] = cx.w[0U] << 3;
  c_x2.w[1U] = (cx.w[1U] << 1) | (cx.w[0U] >> 63);
  c_x2.w[0U] = cx.w[0U] << 1;
  __add_128_128(a10, a10, c_x2);
}

cs.w[0U] = short_sqrt128(a10);
cs.w[1U] = 0;
// check for exact result
if(cs.w[0U] * cs.w[0U] == a10.w[0U]) {
  __mul_64x64_to_128_fast(s2, cs.w[0U], cs.w[0U]);
  if(s2.w[1U] == a10.w[1U]) // && S2.w[0]==A10.w[0])
  {
    bid_get_BID128_very_fast(&res, 0,
                             (exponent_x +
                              DECIMAL_EXPONENT_BIAS_128) >>
                                 1,
                             cs);
#ifdef UNCHANGED_BINARY_STATUS_FLAGS
    // (void) fesetexceptflag (&binaryflags, BID_FE_ALL_FLAGS);
#endif
    // restore the rounding mode back if it has been changed
    if(rm_changed)
      fesetround(old_rm);
    BID_RETURN(res);
  }
}
// get number of digits in CX
d = (BID_SINT64)cx.w[1U] - (BID_SINT64)bid_power10_index_binexp_128[bin_expon_cx].w[1U];
if(d > 0 || (!d && cx.w[0U] >= bid_power10_index_binexp_128[bin_expon_cx].w[0U]))
  digits++;

// if exponent is odd, scale coefficient by 10
scale = 67 - digits;
exponent_q = exponent_x - scale;
scale += (exponent_q & 1); // exp. bias is even

if(scale > 38) {
  t128 = bid_power10_table_128[scale - 37];
  __mul_128x128_low(c_x1, cx, t128);

  t_p128 = bid_power10_table_128[37U];
  __mul_128x128_to_256(c256, c_x1, t_p128);
} else {
  t128 = bid_power10_table_128[scale];
  __mul_128x128_to_256(c256, cx, t128);
}

// 4*C256
c4.w[3U] = (c256.w[3U] << 2) | (c256.w[2U] >> 62);
c4.w[2U] = (c256.w[2U] << 2) | (c256.w[1U] >> 62);
c4.w[1U] = (c256.w[1U] << 2) | (c256.w[0U] >> 62);
c4.w[0U] = c256.w[0U] << 2;

bid_long_sqrt128(&cs, c256);
// printf("C256=%016I64x %016I64x %016I64x %016I64x, CS=%016I64x %016I64x \n",C256.w[3],C256.w[2],C256.w[1],C256.w[0],CS.w[1],CS.w[0]);

#ifndef IEEE_ROUND_NEAREST
#ifndef IEEE_ROUND_NEAREST_TIES_AWAY
if(!((rnd_mode) & 3)) {
#endif
#endif
  // compare to midpoints
  csm.w[1U] = (cs.w[1U] << 1) | (cs.w[0U] >> 63);
  csm.w[0U] = (cs.w[0U] + cs.w[0U]) | 1;
  // CSM^2
  //__mul_128x128_to_256(M256, CSM, CSM);
  __sqr128_to_256(m256, csm);

  if(c4.w[3U] > m256.w[3U] || (c4.w[3U] == m256.w[3U] && (c4.w[2U] > m256.w[2U] || (c4.w[2U] == m256.w[2U] && (c4.w[1U] > m256.w[1U] || (c4.w[1U] == m256.w[1U] && c4.w[0U] > m256.w[0U])))))) {
    // round up
    cs.w[0U]++;
    if(!cs.w[0U])
      cs.w[1U]++;
  } else {
    c8.w[1U] = (cs.w[1U] << 3) | (cs.w[0U] >> 61);
    c8.w[0U] = cs.w[0U] << 3;
    // M256 - 8*CSM
    __sub_borrow_out(m256.w[0U], carry, m256.w[0U], c8.w[0U]);
    __sub_borrow_in_out(m256.w[1U], carry, m256.w[1U], c8.w[1U], carry);
    __sub_borrow_in_out(m256.w[2U], carry, m256.w[2U], 0, carry);
    m256.w[3U] = m256.w[3U] - carry;

    // if CSM' > C256, round up
    if(m256.w[3U] > c4.w[3U] || (m256.w[3U] == c4.w[3U] && (m256.w[2U] > c4.w[2U] || (m256.w[2U] == c4.w[2U] && (m256.w[1U] > c4.w[1U] || (m256.w[1U] == c4.w[1U] && m256.w[0U] > c4.w[0U])))))) {
      // round down
      if(!cs.w[0U])
        cs.w[1U]--;
      cs.w[0U]--;
    }
  }
#ifndef IEEE_ROUND_NEAREST
#ifndef IEEE_ROUND_NEAREST_TIES_AWAY
} else {
  __sqr128_to_256(m256, cs);
  c8.w[1U] = (cs.w[1U] << 1) | (cs.w[0U] >> 63);
  c8.w[0U] = cs.w[0U] << 1;
  if(m256.w[3U] > c256.w[3U] || (m256.w[3U] == c256.w[3U] && (m256.w[2U] > c256.w[2U] || (m256.w[2U] == c256.w[2U] && (m256.w[1U] > c256.w[1U] || (m256.w[1U] == c256.w[1U] && m256.w[0U] > c256.w[0U])))))) {
    __sub_borrow_out(m256.w[0U], carry, m256.w[0U], c8.w[0U]);
    __sub_borrow_in_out(m256.w[1U], carry, m256.w[1U], c8.w[1U], carry);
    __sub_borrow_in_out(m256.w[2U], carry, m256.w[2U], 0, carry);
    m256.w[3U] = m256.w[3U] - carry;
    m256.w[0U]++;
    if(!m256.w[0U]) {
      m256.w[1U]++;
      if(!m256.w[1U]) {
        m256.w[2U]++;
        if(!m256.w[2U])
          m256.w[3U]++;
      }
    }

    if(!cs.w[0U])
      cs.w[1U]--;
    cs.w[0U]--;

    if(m256.w[3U] > c256.w[3U] || (m256.w[3U] == c256.w[3U] && (m256.w[2U] > c256.w[2U] || (m256.w[2U] == c256.w[2U] && (m256.w[1U] > c256.w[1U] || (m256.w[1U] == c256.w[1U] && m256.w[0U] > c256.w[0U])))))) {

      if(!cs.w[0U])
        cs.w[1U]--;
      cs.w[0U]--;
    }
  }

  else {
    __add_carry_out(m256.w[0U], carry, m256.w[0U], c8.w[0U]);
    __add_carry_in_out(m256.w[1U], carry, m256.w[1U], c8.w[1U], carry);
    __add_carry_in_out(m256.w[2U], carry, m256.w[2U], 0, carry);
    m256.w[3U] = m256.w[3U] + carry;
    m256.w[0U]++;
    if(!m256.w[0U]) {
      m256.w[1U]++;
      if(!m256.w[1U]) {
        m256.w[2U]++;
        if(!m256.w[2U])
          m256.w[3U]++;
      }
    }
    if(m256.w[3U] < c256.w[3U] || (m256.w[3U] == c256.w[3U] && (m256.w[2U] < c256.w[2U] || (m256.w[2U] == c256.w[2U] && (m256.w[1U] < c256.w[1U] || (m256.w[1U] == c256.w[1U] && m256.w[0U] <= c256.w[0U])))))) {

      cs.w[0U]++;
      if(!cs.w[0U])
        cs.w[1U]++;
    }
  }
  // RU?
  if((rnd_mode) == BID_ROUNDING_UP) {
    cs.w[0U]++;
    if(!cs.w[0U])
      cs.w[1U]++;
  }
}
#endif
#endif

#ifdef BID_SET_STATUS_FLAGS
__set_status_flags(pfpsf, BID_INEXACT_EXCEPTION);
#endif
bid_get_BID128_fast(&res, 0,
                    (exponent_q + DECIMAL_EXPONENT_BIAS_128) >> 1, cs);
#ifdef UNCHANGED_BINARY_STATUS_FLAGS
// (void) fesetexceptflag (&binaryflags, BID_FE_ALL_FLAGS);
#endif
// restore the rounding mode back if it has been changed
if(rm_changed)
  fesetround(old_rm);
BID_RETURN(res);
}

BID128_FUNCTION_ARGTYPE1(bid128d_sqrt, BID_UINT64, x)

BID_UINT256 m256, c256, c4, c8;
BID_UINT128 cx, c_x1, c_x2, a10, s2, t128, t_p128, cs, csm, res;
BID_UINT64 sign_x, carry;
BID_SINT64 d;
int_float fx, f64;
int exponent_x, bin_expon_cx;
int digits, scale, exponent_q;
int old_rm, rm_changed = 0;

BID_OPT_SAVE_BINARY_FLAGS()

// Set it to round-to-nearest (if different)
if((old_rm = fegetround()) != FE_TONEAREST) {
  rm_changed = 1;
  fesetround(FE_TONEAREST);
}

// unpack arguments, check for NaN or Infinity
// unpack arguments, check for NaN or Infinity
cx.w[1U] = 0;
if(!unpack_BID64(&sign_x, &exponent_x, &cx.w[0U], x)) {
  res.w[1U] = cx.w[0U];
  res.w[0U] = 0;
  // NaN ?
  if((x & 0x7c00000000000000ull) == 0x7c00000000000000ull) {
#ifdef BID_SET_STATUS_FLAGS
    if((x & SNAN_MASK64) == SNAN_MASK64) // sNaN
      __set_status_flags(pfpsf, BID_INVALID_EXCEPTION);
#endif
    res.w[0U] = (cx.w[0U] & 0x0003ffffffffffffull);
    __mul_64x64_to_128(res, res.w[0U], bid_power10_table_128[18U].w[0U]);
    res.w[1U] |= ((cx.w[0U]) & 0xfc00000000000000ull);
    // restore the rounding mode back if it has been changed
    if(rm_changed)
      fesetround(old_rm);
    BID_RETURN(res);
  }
  // x is Infinity?
  if((x & 0x7800000000000000ull) == 0x7800000000000000ull) {
    if(sign_x) {
      // -Inf, return NaN
      res.w[1U] = 0x7c00000000000000ull;
#ifdef BID_SET_STATUS_FLAGS
      __set_status_flags(pfpsf, BID_INVALID_EXCEPTION);
#endif
    }
    // restore the rounding mode back if it has been changed
    if(rm_changed)
      fesetround(old_rm);
    BID_RETURN(res);
  }
  // x is 0 otherwise

  exponent_x =
      exponent_x - DECIMAL_EXPONENT_BIAS + DECIMAL_EXPONENT_BIAS_128;
  res.w[1U] =
      sign_x | ((((BID_UINT64)(exponent_x + DECIMAL_EXPONENT_BIAS_128)) >> 1)
                << 49);
  res.w[0U] = 0;
  // restore the rounding mode back if it has been changed
  if(rm_changed)
    fesetround(old_rm);
  BID_RETURN(res);
}
if(sign_x) {
  res.w[1U] = 0x7c00000000000000ull;
  res.w[0U] = 0;
#ifdef BID_SET_STATUS_FLAGS
  __set_status_flags(pfpsf, BID_INVALID_EXCEPTION);
#endif
  // restore the rounding mode back if it has been changed
  if(rm_changed)
    fesetround(old_rm);
  BID_RETURN(res);
}
#ifdef UNCHANGED_BINARY_STATUS_FLAGS
// (void) fegetexceptflag (&binaryflags, BID_FE_ALL_FLAGS);
#endif
exponent_x =
    exponent_x - DECIMAL_EXPONENT_BIAS + DECIMAL_EXPONENT_BIAS_128;

// 2^64
f64.i = 0x5f800000U;

// fx ~ CX
fx.d = (float)cx.w[1U] * f64.d + (float)cx.w[0U];
bin_expon_cx = ((fx.i >> 23) & 0xffU) - 0x7fU;
digits = bid_estimate_decimal_digits[bin_expon_cx];

a10 = cx;
if(exponent_x & 1) {
  a10.w[1U] = (cx.w[1U] << 3) | (cx.w[0U] >> 61);
  a10.w[0U] = cx.w[0U] << 3;
  c_x2.w[1U] = (cx.w[1U] << 1) | (cx.w[0U] >> 63);
  c_x2.w[0U] = cx.w[0U] << 1;
  __add_128_128(a10, a10, c_x2);
}

cs.w[0U] = short_sqrt128(a10);
cs.w[1U] = 0;
// check for exact result
if(cs.w[0U] * cs.w[0U] == a10.w[0U]) {
  __mul_64x64_to_128_fast(s2, cs.w[0U], cs.w[0U]);
  if(s2.w[1U] == a10.w[1U]) {
    bid_get_BID128_very_fast(&res, 0,
                             (exponent_x + DECIMAL_EXPONENT_BIAS_128) >> 1,
                             cs);
#ifdef UNCHANGED_BINARY_STATUS_FLAGS
    // (void) fesetexceptflag (&binaryflags, BID_FE_ALL_FLAGS);
#endif
    // restore the rounding mode back if it has been changed
    if(rm_changed)
      fesetround(old_rm);
    BID_RETURN(res);
  }
}
// get number of digits in CX
d = (BID_SINT64)cx.w[1U] - (BID_SINT64)bid_power10_index_binexp_128[bin_expon_cx].w[1U];
if(d > 0 || (!d && cx.w[0U] >= bid_power10_index_binexp_128[bin_expon_cx].w[0U]))
  digits++;

// if exponent is odd, scale coefficient by 10
scale = 67 - digits;
exponent_q = exponent_x - scale;
scale += (exponent_q & 1); // exp. bias is even

if(scale > 38) {
  t128 = bid_power10_table_128[scale - 37];
  __mul_128x128_low(c_x1, cx, t128);

  t_p128 = bid_power10_table_128[37U];
  __mul_128x128_to_256(c256, c_x1, t_p128);
} else {
  t128 = bid_power10_table_128[scale];
  __mul_128x128_to_256(c256, cx, t128);
}

// 4*C256
c4.w[3U] = (c256.w[3U] << 2) | (c256.w[2U] >> 62);
c4.w[2U] = (c256.w[2U] << 2) | (c256.w[1U] >> 62);
c4.w[1U] = (c256.w[1U] << 2) | (c256.w[0U] >> 62);
c4.w[0U] = c256.w[0U] << 2;

bid_long_sqrt128(&cs, c256);

#ifndef IEEE_ROUND_NEAREST
#ifndef IEEE_ROUND_NEAREST_TIES_AWAY
if(!((rnd_mode) & 3)) {
#endif
#endif
  // compare to midpoints
  csm.w[1U] = (cs.w[1U] << 1) | (cs.w[0U] >> 63);
  csm.w[0U] = (cs.w[0U] + cs.w[0U]) | 1;
  // CSM^2
  //__mul_128x128_to_256(M256, CSM, CSM);
  __sqr128_to_256(m256, csm);

  if(c4.w[3U] > m256.w[3U] || (c4.w[3U] == m256.w[3U] && (c4.w[2U] > m256.w[2U] || (c4.w[2U] == m256.w[2U] && (c4.w[1U] > m256.w[1U] || (c4.w[1U] == m256.w[1U] && c4.w[0U] > m256.w[0U])))))) {
    // round up
    cs.w[0U]++;
    if(!cs.w[0U])
      cs.w[1U]++;
  } else {
    c8.w[1U] = (cs.w[1U] << 3) | (cs.w[0U] >> 61);
    c8.w[0U] = cs.w[0U] << 3;
    // M256 - 8*CSM
    __sub_borrow_out(m256.w[0U], carry, m256.w[0U], c8.w[0U]);
    __sub_borrow_in_out(m256.w[1U], carry, m256.w[1U], c8.w[1U], carry);
    __sub_borrow_in_out(m256.w[2U], carry, m256.w[2U], 0, carry);
    m256.w[3U] = m256.w[3U] - carry;

    // if CSM' > C256, round up
    if(m256.w[3U] > c4.w[3U] || (m256.w[3U] == c4.w[3U] && (m256.w[2U] > c4.w[2U] || (m256.w[2U] == c4.w[2U] && (m256.w[1U] > c4.w[1U] || (m256.w[1U] == c4.w[1U] && m256.w[0U] > c4.w[0U])))))) {
      // round down
      if(!cs.w[0U])
        cs.w[1U]--;
      cs.w[0U]--;
    }
  }
#ifndef IEEE_ROUND_NEAREST
#ifndef IEEE_ROUND_NEAREST_TIES_AWAY
} else {
  __sqr128_to_256(m256, cs);
  c8.w[1U] = (cs.w[1U] << 1) | (cs.w[0U] >> 63);
  c8.w[0U] = cs.w[0U] << 1;
  if(m256.w[3U] > c256.w[3U] || (m256.w[3U] == c256.w[3U] && (m256.w[2U] > c256.w[2U] || (m256.w[2U] == c256.w[2U] && (m256.w[1U] > c256.w[1U] || (m256.w[1U] == c256.w[1U] && m256.w[0U] > c256.w[0U])))))) {
    __sub_borrow_out(m256.w[0U], carry, m256.w[0U], c8.w[0U]);
    __sub_borrow_in_out(m256.w[1U], carry, m256.w[1U], c8.w[1U], carry);
    __sub_borrow_in_out(m256.w[2U], carry, m256.w[2U], 0, carry);
    m256.w[3U] = m256.w[3U] - carry;
    m256.w[0U]++;
    if(!m256.w[0U]) {
      m256.w[1U]++;
      if(!m256.w[1U]) {
        m256.w[2U]++;
        if(!m256.w[2U])
          m256.w[3U]++;
      }
    }

    if(!cs.w[0U])
      cs.w[1U]--;
    cs.w[0U]--;

    if(m256.w[3U] > c256.w[3U] || (m256.w[3U] == c256.w[3U] && (m256.w[2U] > c256.w[2U] || (m256.w[2U] == c256.w[2U] && (m256.w[1U] > c256.w[1U] || (m256.w[1U] == c256.w[1U] && m256.w[0U] > c256.w[0U])))))) {

      if(!cs.w[0U])
        cs.w[1U]--;
      cs.w[0U]--;
    }
  }

  else {
    __add_carry_out(m256.w[0U], carry, m256.w[0U], c8.w[0U]);
    __add_carry_in_out(m256.w[1U], carry, m256.w[1U], c8.w[1U], carry);
    __add_carry_in_out(m256.w[2U], carry, m256.w[2U], 0, carry);
    m256.w[3U] = m256.w[3U] + carry;
    m256.w[0U]++;
    if(!m256.w[0U]) {
      m256.w[1U]++;
      if(!m256.w[1U]) {
        m256.w[2U]++;
        if(!m256.w[2U])
          m256.w[3U]++;
      }
    }
    if(m256.w[3U] < c256.w[3U] || (m256.w[3U] == c256.w[3U] && (m256.w[2U] < c256.w[2U] || (m256.w[2U] == c256.w[2U] && (m256.w[1U] < c256.w[1U] || (m256.w[1U] == c256.w[1U] && m256.w[0U] <= c256.w[0U])))))) {

      cs.w[0U]++;
      if(!cs.w[0U])
        cs.w[1U]++;
    }
  }
  // RU?
  if((rnd_mode) == BID_ROUNDING_UP) {
    cs.w[0U]++;
    if(!cs.w[0U])
      cs.w[1U]++;
  }
}
#endif
#endif

#ifdef BID_SET_STATUS_FLAGS
__set_status_flags(pfpsf, BID_INEXACT_EXCEPTION);
#endif
bid_get_BID128_fast(&res, 0, (exponent_q + DECIMAL_EXPONENT_BIAS_128) >> 1,
                    cs);
#ifdef UNCHANGED_BINARY_STATUS_FLAGS
// (void) fesetexceptflag (&binaryflags, BID_FE_ALL_FLAGS);
#endif
// restore the rounding mode back if it has been changed
if(rm_changed)
  fesetround(old_rm);
BID_RETURN(res);
}
