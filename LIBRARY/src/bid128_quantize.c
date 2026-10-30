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

#define BID_FUNCTION_SETS_BINARY_FLAGS
#define BID_128RES
#include "bid_internal.h"

BID128_FUNCTION_ARG2(bid128_quantize, x, y)

BID_UINT256 ct;
BID_UINT128 cx, cy, t, c_x2, cr, stemp, res, rem_h, c2_n;
BID_UINT64 sign_x, sign_y, remainder_h, carry, c_y64, valid_x;
int_float tempx;
int exponent_x, exponent_y, digits_x, extra_digits, amount;
int expon_diff, total_digits, bin_expon_cx, status;
unsigned int rmode;

BID_OPT_SAVE_BINARY_FLAGS()

valid_x = unpack_BID128_value(&sign_x, &exponent_x, &cx, x);

// unpack arguments, check for NaN or Infinity
if(!unpack_BID128_value(&sign_y, &exponent_y, &cy, y)) {
  // y is Inf. or NaN
#ifdef BID_SET_STATUS_FLAGS
  if((x.w[1U] & SNAN_MASK64) == SNAN_MASK64) // y is sNaN
    __set_status_flags(pfpsf, BID_INVALID_EXCEPTION);
#endif

  // test if y is NaN
  if((y.w[1U] & 0x7c00000000000000ull) == 0x7c00000000000000ull) {
#ifdef BID_SET_STATUS_FLAGS
    if((y.w[1U] & 0x7e00000000000000ull) == 0x7e00000000000000ull) {
      // set status flags
      __set_status_flags(pfpsf, BID_INVALID_EXCEPTION);
    }
#endif
    if((x.w[1U] & 0x7c00000000000000ull) != 0x7c00000000000000ull) {
      res.w[1U] = cy.w[1U] & QUIET_MASK64;
      res.w[0U] = cy.w[0U];
    } else {
      res.w[1U] = cx.w[1U] & QUIET_MASK64;
      res.w[0U] = cx.w[0U];
    }
    BID_RETURN(res);
  }
  // y is Infinity?
  if((y.w[1U] & 0x7800000000000000ull) == 0x7800000000000000ull) {
    // check if x is not Inf.
    if(((x.w[1U] & 0x7c00000000000000ull) < 0x7800000000000000ull)) {
      // return NaN
#ifdef BID_SET_STATUS_FLAGS
      // set status flags
      __set_status_flags(pfpsf, BID_INVALID_EXCEPTION);
#endif
      res.w[1U] = 0x7c00000000000000ull;
      res.w[0U] = 0;
      BID_RETURN(res);
    } else if(((x.w[1U] & 0x7c00000000000000ull) <= 0x7800000000000000ull)) {
      res.w[1U] = cx.w[1U] & QUIET_MASK64;
      res.w[0U] = cx.w[0U];
      BID_RETURN(res);
    }
  }
}

if(!valid_x) {
  // test if x is NaN or Inf
  if((x.w[1U] & 0x7c00000000000000ull) == 0x7800000000000000ull) {
#ifdef BID_SET_STATUS_FLAGS
    // set status flags
    __set_status_flags(pfpsf, BID_INVALID_EXCEPTION);
#endif
    res.w[1U] = 0x7c00000000000000ull;
    res.w[0U] = 0;
    BID_RETURN(res);
  } else if((x.w[1U] & 0x7c00000000000000ull) == 0x7c00000000000000ull) {
    if((x.w[1U] & 0x7e00000000000000ull) == 0x7e00000000000000ull) {
#ifdef BID_SET_STATUS_FLAGS
      // set status flags
      __set_status_flags(pfpsf, BID_INVALID_EXCEPTION);
#endif
    }
    res.w[1U] = cx.w[1U] & QUIET_MASK64;
    res.w[0U] = cx.w[0U];
    BID_RETURN(res);
  }
  if(!cx.w[1U] && !cx.w[0U]) {
    bid_get_BID128_very_fast(&res, sign_x, exponent_y, cx);
    BID_RETURN(res);
  }
}
// get number of decimal digits in coefficient_x
if(cx.w[1U]) {
  tempx.d = (float)cx.w[1U];
  bin_expon_cx = ((tempx.i >> 23) & 0xffU) - 0x7fU + 64;
} else {
  tempx.d = (float)cx.w[0U];
  bin_expon_cx = ((tempx.i >> 23) & 0xffU) - 0x7fU;
}

digits_x = bid_estimate_decimal_digits[bin_expon_cx];
if(cx.w[1U] > bid_power10_table_128[digits_x].w[1U] || (cx.w[1U] == bid_power10_table_128[digits_x].w[1U] && cx.w[0U] >= bid_power10_table_128[digits_x].w[0U]))
  digits_x++;

expon_diff = exponent_x - exponent_y;
total_digits = digits_x + expon_diff;

if((BID_UINT32)total_digits <= 34) {
  if(expon_diff >= 0) {
    t = bid_power10_table_128[expon_diff];
    __mul_128x128_low(c_x2, t, cx);
    bid_get_BID128_very_fast(&res, sign_x, exponent_y, c_x2);
    BID_RETURN(res);
  }
#ifndef IEEE_ROUND_NEAREST_TIES_AWAY
#ifndef IEEE_ROUND_NEAREST
  rmode = (unsigned int)rnd_mode;
  if(sign_x && (unsigned)(rmode - 1) < 2)
    rmode = 3 - rmode;
#else
  rmode = 0;
#endif
#else
  rmode = 0;
#endif
  // must round off -expon_diff digits
  extra_digits = -expon_diff;
  __add_128_128(cx, cx, bid_round_const_table_128[rmode][extra_digits]);

  // get P*(2^M[extra_digits])/10^extra_digits
  __mul_128x128_to_256(ct, cx, bid_reciprocals10_128[extra_digits]);

  // now get P/10^extra_digits: shift C64 right by M[extra_digits]-128
  amount = bid_recip_scale[extra_digits];
  c_x2.w[0U] = ct.w[2U];
  c_x2.w[1U] = ct.w[3U];
  if(amount >= 64) {
    cr.w[1U] = 0;
    cr.w[0U] = c_x2.w[1U] >> (amount - 64);
  } else {
    __shr_128(cr, c_x2, amount);
  }

#ifndef IEEE_ROUND_NEAREST_TIES_AWAY
#ifndef IEEE_ROUND_NEAREST
  if(rnd_mode == 0)
#endif
    if(cr.w[0U] & 1) {
      // check whether fractional part of initial_P/10^extra_digits is
      // exactly .5 this is the same as fractional part of
      // (initial_P + 0.5*10^extra_digits)/10^extra_digits is exactly zero

      // get remainder
      if(amount >= 64) {
        remainder_h = c_x2.w[0U] | (c_x2.w[1U] << (128 - amount));
      } else
        remainder_h = c_x2.w[0U] << (64 - amount);

      // test whether fractional part is 0
      if(!remainder_h && (ct.w[1U] < bid_reciprocals10_128[extra_digits].w[1U] || (ct.w[1U] == bid_reciprocals10_128[extra_digits].w[1U] && ct.w[0U] < bid_reciprocals10_128[extra_digits].w[0U]))) {
        cr.w[0U]--;
      }
    }
#endif

#ifdef BID_SET_STATUS_FLAGS
  status = BID_INEXACT_EXCEPTION;

  // get remainder
  if(amount >= 64) {
    rem_h.w[1U] = (c_x2.w[1U] << (128 - amount));
    rem_h.w[0U] = c_x2.w[0U];
  } else {
    rem_h.w[1U] = c_x2.w[0U] << (64 - amount);
    rem_h.w[0U] = 0;
  }

  switch(rmode) {
  case BID_ROUNDING_TO_NEAREST:
  case BID_ROUNDING_TIES_AWAY:
    // test whether fractional part is 0
    if(rem_h.w[1U] == 0x8000000000000000ull && !rem_h.w[0U] && (ct.w[1U] < bid_reciprocals10_128[extra_digits].w[1U] || (ct.w[1U] == bid_reciprocals10_128[extra_digits].w[1U] && ct.w[0U] < bid_reciprocals10_128[extra_digits].w[0U])))
      status = BID_EXACT_STATUS;
    break;
  case BID_ROUNDING_DOWN:
  case BID_ROUNDING_TO_ZERO:
    if(!(rem_h.w[1U] | rem_h.w[0U]) && (ct.w[1U] < bid_reciprocals10_128[extra_digits].w[1U] || (ct.w[1U] == bid_reciprocals10_128[extra_digits].w[1U] && ct.w[0U] < bid_reciprocals10_128[extra_digits].w[0U])))
      status = BID_EXACT_STATUS;
    break;
  default:
    // round up
    __add_carry_out(stemp.w[0U], c_y64, ct.w[0U],
                    bid_reciprocals10_128[extra_digits].w[0U]);
    __add_carry_in_out(stemp.w[1U], carry, ct.w[1U],
                       bid_reciprocals10_128[extra_digits].w[1U], c_y64);
    if(amount < 64) {
      c2_n.w[1U] = 0;
      c2_n.w[0U] = ((BID_UINT64)1) << amount;
      rem_h.w[0U] = rem_h.w[1U] >> (64 - amount);
      rem_h.w[1U] = 0;
    } else {
      c2_n.w[1U] = ((BID_UINT64)1) << (amount - 64);
      c2_n.w[0U] = 0;
      rem_h.w[1U] >>= (128 - amount);
    }
    rem_h.w[0U] += carry;
    if(rem_h.w[0U] < carry)
      rem_h.w[1U]++;
    if(__unsigned_compare_ge_128(rem_h, c2_n))
      status = BID_EXACT_STATUS;
  }

  __set_status_flags(pfpsf, status);

#endif
  bid_get_BID128_very_fast(&res, sign_x, exponent_y, cr);
  BID_RETURN(res);
}
if(total_digits < 0) {
  cr.w[1U] = cr.w[0U] = 0;
#ifndef IEEE_ROUND_NEAREST_TIES_AWAY
#ifndef IEEE_ROUND_NEAREST
  rmode = (unsigned int)rnd_mode;
  if(sign_x && (unsigned)(rmode - 1) < 2)
    rmode = 3 - rmode;
  if(rmode == BID_ROUNDING_UP)
    cr.w[0U] = 1;
#endif
#endif
#ifdef BID_SET_STATUS_FLAGS
  __set_status_flags(pfpsf, BID_INEXACT_EXCEPTION);
#endif
  bid_get_BID128_very_fast(&res, sign_x, exponent_y, cr);
  BID_RETURN(res);
}
// else  more than 34 digits in coefficient
#ifdef BID_SET_STATUS_FLAGS
__set_status_flags(pfpsf, BID_INVALID_EXCEPTION);
#endif
res.w[1U] = 0x7c00000000000000ull;
res.w[0U] = 0;
BID_RETURN(res);
}
