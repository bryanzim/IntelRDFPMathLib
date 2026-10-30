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

/*****************************************************************************
 *    BID64 remainder
 *****************************************************************************
 *
 *  Algorithm description:
 *
 *  if(exponent_x < exponent_y)
 *    scale coefficient_y so exponents are aligned
 *    perform coefficient divide (64-bit integer divide), unless
 *            coefficient_y is longer than 64 bits (clearly larger
 *                                               than coefficient_x)
 *  else  // exponent_x > exponent_y
 *     use a loop to scale coefficient_x to 18_digits, divide by
 *         coefficient_y (64-bit integer divide), calculate remainder
 *         as new_coefficient_x and repeat until final remainder is obtained
 *         (when new_exponent_x < exponent_y)
 *
 ****************************************************************************/

#define BID_FUNCTION_SETS_BINARY_FLAGS

#include "bid_internal.h"

BID_TYPE0_FUNCTION_ARGTYPE1_ARGTYPE2_NORND(BID_UINT32, bid32_fmod, BID_UINT32, x, BID_UINT32, y)

BID_UINT64 cx, q64, cyl;
BID_UINT32 cy, sign_x, sign_y, coefficient_x, coefficient_y, res;
BID_UINT32 q, r, t, valid_y, valid_x;
int_float tempx;
int exponent_x, exponent_y, bin_expon, e_scale;
int digits_x, diff_expon;

BID_OPT_SAVE_BINARY_FLAGS()

valid_y = unpack_BID32(&sign_y, &exponent_y, &coefficient_y, y);
valid_x = unpack_BID32(&sign_x, &exponent_x, &coefficient_x, x);

// unpack arguments, check for NaN or Infinity
if(!valid_x) {
  // x is Inf. or NaN or 0
#ifdef BID_SET_STATUS_FLAGS
  if((y & SNAN_MASK32) == SNAN_MASK32) // y is sNaN
    __set_status_flags(pfpsf, BID_INVALID_EXCEPTION);
#endif

  // test if x is NaN
  if((x & 0x7c000000U) == 0x7c000000U) {
#ifdef BID_SET_STATUS_FLAGS
    if(((x & SNAN_MASK32) == SNAN_MASK32))
      __set_status_flags(pfpsf, BID_INVALID_EXCEPTION);
#endif
    res = coefficient_x & QUIET_MASK32;
    ;
    BID_RETURN(res);
  }
  // x is Infinity?
  if((x & 0x78000000U) == 0x78000000U) {
    if(((y & NAN_MASK32) != NAN_MASK32)) {
#ifdef BID_SET_STATUS_FLAGS
      __set_status_flags(pfpsf, BID_INVALID_EXCEPTION);
#endif
      // return NaN
      res = 0x7c000000U;
      BID_RETURN(res);
    }
  }
  // x is 0
  // return x if y != 0
  if(((y & 0x78000000U) < 0x78000000U) &&
     coefficient_y) {
    if((y & 0x60000000U) == 0x60000000U)
      exponent_y = (y >> 21) & 0xffU;
    else
      exponent_y = (y >> 23) & 0xffU;

    if(exponent_y < exponent_x)
      exponent_x = exponent_y;

    res = sign_x | (((BID_UINT32)exponent_x) << 23U);
    BID_RETURN(res);
  }
}
if(!valid_y) {
  // y is Inf. or NaN

  // test if y is NaN
  if((y & 0x7c000000U) == 0x7c000000U) {
#ifdef BID_SET_STATUS_FLAGS
    if(((y & SNAN_MASK32) == SNAN_MASK32))
      __set_status_flags(pfpsf, BID_INVALID_EXCEPTION);
#endif
    res = coefficient_y & QUIET_MASK32;
    ;
    BID_RETURN(res);
  }
  // y is Infinity?
  if((y & 0x78000000U) == 0x78000000U) {
    res = very_fast_get_BID32(sign_x, exponent_x, coefficient_x);
    BID_RETURN(res);
  }
  // y is 0, return NaN
  {
#ifdef BID_SET_STATUS_FLAGS
    __set_status_flags(pfpsf, BID_INVALID_EXCEPTION);
#endif
    res = 0x7c000000U;
    BID_RETURN(res);
  }
}

diff_expon = exponent_x - exponent_y;
if(diff_expon <= 0) {
  diff_expon = -diff_expon;

  if(diff_expon > 7) {
    // |x|<|y| in this case
    res = x;
    BID_RETURN(res);
  }
  // set exponent of y to exponent_x, scale coefficient_y
  t = (BID_UINT32)(bid_power10_table_128[diff_expon].w[0U]);
  cyl = ((BID_UINT64)coefficient_y) * t;
  if(cyl > (BID_UINT64)(coefficient_x)) {
    res = x;
    BID_RETURN(res);
  }

  cy = (BID_UINT32)cyl;
  q = coefficient_x / cy;
  r = coefficient_x - q * cy;

  res = very_fast_get_BID32(sign_x, exponent_x, r);
  BID_RETURN(res);
}

cx = coefficient_x;
while(diff_expon > 0) {
  // get number of digits in coeff_x
  tempx.d = (float)cx;
  bin_expon = ((tempx.i >> 23) & 0xffU) - 0x7fU;
  digits_x = bid_estimate_decimal_digits[bin_expon];
  // will not use this test, dividend will have 18 or 19 digits
  // if(CX >= bid_power10_table_128[digits_x].w[0])
  //      digits_x++;

  e_scale = 18 - digits_x;
  if(diff_expon >= e_scale) {
    diff_expon -= e_scale;
  } else {
    e_scale = diff_expon;
    diff_expon = 0;
  }

  // scale dividend to 18 or 19 digits
  cx *= bid_power10_table_128[e_scale].w[0U];

  // quotient
  q64 = cx / coefficient_y;
  // remainder
  cx -= q64 * (BID_UINT64)coefficient_y;

  // check for remainder == 0
  if(!cx) {
    res = very_fast_get_BID32(sign_x, exponent_y, 0);
    BID_RETURN(res);
  }
}

coefficient_x = (BID_UINT32)cx;

res = very_fast_get_BID32(sign_x, exponent_y, coefficient_x);
BID_RETURN(res);
}
