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

BID128_FUNCTION_ARG1 (bid128_sqrt, x)

     BID_UINT256 M256, C256, C4, C8;
     BID_UINT128 CX, CX1, CX2, A10, S2, T128, TP128, CS, CSM, res;
     BID_UINT64 sign_x, Carry;
     BID_SINT64 D;
     int_float fx, f64;
     int exponent_x, bin_expon_cx;
     int digits, scale, exponent_q;
     int old_rm, rm_changed=0;

  BID_OPT_SAVE_BINARY_FLAGS()

  // Set it to round-to-nearest (if different)
  if ((old_rm=fegetround()) != FE_TONEAREST) {
    rm_changed=1;
    fesetround(FE_TONEAREST);
  }

  // unpack arguments, check for NaN or Infinity
if (!unpack_BID128_value (&sign_x, &exponent_x, &CX, x)) {
res.w[1U] = CX.w[1U];
res.w[0U] = CX.w[0U];
    // NaN ?
if ((x.w[1U] & 0x7c00000000000000ull) == 0x7c00000000000000ull) {
#ifdef BID_SET_STATUS_FLAGS
  if ((x.w[1U] & 0x7e00000000000000ull) == 0x7e00000000000000ull)	// sNaN
    __set_status_flags (pfpsf, BID_INVALID_EXCEPTION);
#endif
  res.w[1U] = CX.w[1U] & QUIET_MASK64;
  // restore the rounding mode back if it has been changed
  if (rm_changed) fesetround(old_rm);
  BID_RETURN (res);
}
    // x is Infinity?
if ((x.w[1U] & 0x7800000000000000ull) == 0x7800000000000000ull) {
  res.w[1U] = CX.w[1U];
  if (sign_x) {
    // -Inf, return NaN
    res.w[1U] = 0x7c00000000000000ull;
#ifdef BID_SET_STATUS_FLAGS
    __set_status_flags (pfpsf, BID_INVALID_EXCEPTION);
#endif
  }
  // restore the rounding mode back if it has been changed
  if (rm_changed) fesetround(old_rm);
  BID_RETURN (res);
}
    // x is 0 otherwise

res.w[1U] =
  sign_x |
  ((((BID_UINT64) (exponent_x + DECIMAL_EXPONENT_BIAS_128)) >> 1) << 49);
res.w[0U] = 0;
// restore the rounding mode back if it has been changed
if (rm_changed) fesetround(old_rm);
BID_RETURN (res);
}
if (sign_x) {
  res.w[1U] = 0x7c00000000000000ull;
  res.w[0U] = 0;
#ifdef BID_SET_STATUS_FLAGS
  __set_status_flags (pfpsf, BID_INVALID_EXCEPTION);
#endif
  // restore the rounding mode back if it has been changed
  if (rm_changed) fesetround(old_rm);
  BID_RETURN (res);
}
#ifdef UNCHANGED_BINARY_STATUS_FLAGS
// (void) fegetexceptflag (&binaryflags, BID_FE_ALL_FLAGS);
#endif
  // 2^64
f64.i = 0x5f800000U;

  // fx ~ CX
fx.d = (float) CX.w[1U] * f64.d + (float) CX.w[0U];
bin_expon_cx = ((fx.i >> 23) & 0xffU) - 0x7fU;
digits = bid_estimate_decimal_digits[bin_expon_cx];

A10 = CX;
if (exponent_x & 1) {
  A10.w[1U] = (CX.w[1U] << 3) | (CX.w[0U] >> 61);
  A10.w[0U] = CX.w[0U] << 3;
  CX2.w[1U] = (CX.w[1U] << 1) | (CX.w[0U] >> 63);
  CX2.w[0U] = CX.w[0U] << 1;
  __add_128_128 (A10, A10, CX2);
}

CS.w[0U] = short_sqrt128 (A10);
CS.w[1U] = 0;
  // check for exact result
if (CS.w[0U] * CS.w[0U] == A10.w[0U]) {
  __mul_64x64_to_128_fast (S2, CS.w[0U], CS.w[0U]);
  if (S2.w[1U] == A10.w[1U])	// && S2.w[0]==A10.w[0])
  {
    bid_get_BID128_very_fast (&res, 0,
			  (exponent_x +
			   DECIMAL_EXPONENT_BIAS_128) >> 1, CS);
#ifdef UNCHANGED_BINARY_STATUS_FLAGS
    // (void) fesetexceptflag (&binaryflags, BID_FE_ALL_FLAGS);
#endif
    // restore the rounding mode back if it has been changed
    if (rm_changed) fesetround(old_rm);
    BID_RETURN (res);
  }
}
  // get number of digits in CX
D = (BID_SINT64)CX.w[1U] - (BID_SINT64)bid_power10_index_binexp_128[bin_expon_cx].w[1U];
if (D > 0
    || (!D && CX.w[0U] >= bid_power10_index_binexp_128[bin_expon_cx].w[0U]))
  digits++;

  // if exponent is odd, scale coefficient by 10
scale = 67 - digits;
exponent_q = exponent_x - scale;
scale += (exponent_q & 1);	// exp. bias is even

if (scale > 38) {
  T128 = bid_power10_table_128[scale - 37];
  __mul_128x128_low (CX1, CX, T128);

  TP128 = bid_power10_table_128[37U];
  __mul_128x128_to_256 (C256, CX1, TP128);
} else {
  T128 = bid_power10_table_128[scale];
  __mul_128x128_to_256 (C256, CX, T128);
}


  // 4*C256
C4.w[3U] = (C256.w[3U] << 2) | (C256.w[2U] >> 62);
C4.w[2U] = (C256.w[2U] << 2) | (C256.w[1U] >> 62);
C4.w[1U] = (C256.w[1U] << 2) | (C256.w[0U] >> 62);
C4.w[0U] = C256.w[0U] << 2;

bid_long_sqrt128 (&CS, C256);
   //printf("C256=%016I64x %016I64x %016I64x %016I64x, CS=%016I64x %016I64x \n",C256.w[3],C256.w[2],C256.w[1],C256.w[0],CS.w[1],CS.w[0]);

#ifndef IEEE_ROUND_NEAREST
#ifndef IEEE_ROUND_NEAREST_TIES_AWAY
if (!((rnd_mode) & 3)) {
#endif
#endif
  // compare to midpoints
  CSM.w[1U] = (CS.w[1U] << 1) | (CS.w[0U] >> 63);
  CSM.w[0U] = (CS.w[0U] + CS.w[0U]) | 1;
  // CSM^2
  //__mul_128x128_to_256(M256, CSM, CSM);
  __sqr128_to_256 (M256, CSM);

  if (C4.w[3U] > M256.w[3U]
      || (C4.w[3U] == M256.w[3U]
	  && (C4.w[2U] > M256.w[2U]
	      || (C4.w[2U] == M256.w[2U]
		  && (C4.w[1U] > M256.w[1U]
		      || (C4.w[1U] == M256.w[1U]
			  && C4.w[0U] > M256.w[0U])))))) {
    // round up
    CS.w[0U]++;
    if (!CS.w[0U])
      CS.w[1U]++;
  } else {
    C8.w[1U] = (CS.w[1U] << 3) | (CS.w[0U] >> 61);
    C8.w[0U] = CS.w[0U] << 3;
    // M256 - 8*CSM
    __sub_borrow_out (M256.w[0U], Carry, M256.w[0U], C8.w[0U]);
    __sub_borrow_in_out (M256.w[1U], Carry, M256.w[1U], C8.w[1U], Carry);
    __sub_borrow_in_out (M256.w[2U], Carry, M256.w[2U], 0, Carry);
    M256.w[3U] = M256.w[3U] - Carry;

    // if CSM' > C256, round up
    if (M256.w[3U] > C4.w[3U]
	|| (M256.w[3U] == C4.w[3U]
	    && (M256.w[2U] > C4.w[2U]
		|| (M256.w[2U] == C4.w[2U]
		    && (M256.w[1U] > C4.w[1U]
			|| (M256.w[1U] == C4.w[1U]
			    && M256.w[0U] > C4.w[0U])))))) {
      // round down
      if (!CS.w[0U])
	CS.w[1U]--;
      CS.w[0U]--;
    }
  }
#ifndef IEEE_ROUND_NEAREST
#ifndef IEEE_ROUND_NEAREST_TIES_AWAY
} else {
  __sqr128_to_256 (M256, CS);
  C8.w[1U] = (CS.w[1U] << 1) | (CS.w[0U] >> 63);
  C8.w[0U] = CS.w[0U] << 1;
  if (M256.w[3U] > C256.w[3U]
      || (M256.w[3U] == C256.w[3U]
	  && (M256.w[2U] > C256.w[2U]
	      || (M256.w[2U] == C256.w[2U]
		  && (M256.w[1U] > C256.w[1U]
		      || (M256.w[1U] == C256.w[1U]
			  && M256.w[0U] > C256.w[0U])))))) {
    __sub_borrow_out (M256.w[0U], Carry, M256.w[0U], C8.w[0U]);
    __sub_borrow_in_out (M256.w[1U], Carry, M256.w[1U], C8.w[1U], Carry);
    __sub_borrow_in_out (M256.w[2U], Carry, M256.w[2U], 0, Carry);
    M256.w[3U] = M256.w[3U] - Carry;
    M256.w[0U]++;
    if (!M256.w[0U]) {
      M256.w[1U]++;
      if (!M256.w[1U]) {
	M256.w[2U]++;
	if (!M256.w[2U])
	  M256.w[3U]++;
      }
    }

    if (!CS.w[0U])
      CS.w[1U]--;
    CS.w[0U]--;

    if (M256.w[3U] > C256.w[3U]
	|| (M256.w[3U] == C256.w[3U]
	    && (M256.w[2U] > C256.w[2U]
		|| (M256.w[2U] == C256.w[2U]
		    && (M256.w[1U] > C256.w[1U]
			|| (M256.w[1U] == C256.w[1U]
			    && M256.w[0U] > C256.w[0U])))))) {

      if (!CS.w[0U])
	CS.w[1U]--;
      CS.w[0U]--;
    }
  }

  else {
    __add_carry_out (M256.w[0U], Carry, M256.w[0U], C8.w[0U]);
    __add_carry_in_out (M256.w[1U], Carry, M256.w[1U], C8.w[1U], Carry);
    __add_carry_in_out (M256.w[2U], Carry, M256.w[2U], 0, Carry);
    M256.w[3U] = M256.w[3U] + Carry;
    M256.w[0U]++;
    if (!M256.w[0U]) {
      M256.w[1U]++;
      if (!M256.w[1U]) {
	M256.w[2U]++;
	if (!M256.w[2U])
	  M256.w[3U]++;
      }
    }
    if (M256.w[3U] < C256.w[3U]
	|| (M256.w[3U] == C256.w[3U]
	    && (M256.w[2U] < C256.w[2U]
		|| (M256.w[2U] == C256.w[2U]
		    && (M256.w[1U] < C256.w[1U]
			|| (M256.w[1U] == C256.w[1U]
			    && M256.w[0U] <= C256.w[0U])))))) {

      CS.w[0U]++;
      if (!CS.w[0U])
	CS.w[1U]++;
    }
  }
  // RU?
  if ((rnd_mode) == BID_ROUNDING_UP) {
    CS.w[0U]++;
    if (!CS.w[0U])
      CS.w[1U]++;
  }

}
#endif
#endif

#ifdef BID_SET_STATUS_FLAGS
__set_status_flags (pfpsf, BID_INEXACT_EXCEPTION);
#endif
bid_get_BID128_fast (&res, 0,
		 (exponent_q + DECIMAL_EXPONENT_BIAS_128) >> 1, CS);
#ifdef UNCHANGED_BINARY_STATUS_FLAGS
// (void) fesetexceptflag (&binaryflags, BID_FE_ALL_FLAGS);
#endif
// restore the rounding mode back if it has been changed
if (rm_changed) fesetround(old_rm);
BID_RETURN (res);
}



BID128_FUNCTION_ARGTYPE1 (bid128d_sqrt, BID_UINT64, x)

     BID_UINT256 M256, C256, C4, C8;
     BID_UINT128 CX, CX1, CX2, A10, S2, T128, TP128, CS, CSM, res;
     BID_UINT64 sign_x, Carry;
     BID_SINT64 D;
     int_float fx, f64;
     int exponent_x, bin_expon_cx;
     int digits, scale, exponent_q;
     int old_rm, rm_changed=0;

  BID_OPT_SAVE_BINARY_FLAGS()

  // Set it to round-to-nearest (if different)
  if ((old_rm=fegetround()) != FE_TONEAREST) {
    rm_changed=1;
    fesetround(FE_TONEAREST);
  }

	// unpack arguments, check for NaN or Infinity
   // unpack arguments, check for NaN or Infinity
CX.w[1U] = 0;
if (!unpack_BID64 (&sign_x, &exponent_x, &CX.w[0U], x)) {
res.w[1U] = CX.w[0U];
res.w[0U] = 0;
	   // NaN ?
if ((x & 0x7c00000000000000ull) == 0x7c00000000000000ull) {
#ifdef BID_SET_STATUS_FLAGS
  if ((x & SNAN_MASK64) == SNAN_MASK64)	// sNaN
    __set_status_flags (pfpsf, BID_INVALID_EXCEPTION);
#endif
  res.w[0U] = (CX.w[0U] & 0x0003ffffffffffffull);
  __mul_64x64_to_128 (res, res.w[0U], bid_power10_table_128[18U].w[0U]);
  res.w[1U] |= ((CX.w[0U]) & 0xfc00000000000000ull);
  // restore the rounding mode back if it has been changed
  if (rm_changed) fesetround(old_rm);
  BID_RETURN (res);
}
	   // x is Infinity?
if ((x & 0x7800000000000000ull) == 0x7800000000000000ull) {
  if (sign_x) {
    // -Inf, return NaN
    res.w[1U] = 0x7c00000000000000ull;
#ifdef BID_SET_STATUS_FLAGS
    __set_status_flags (pfpsf, BID_INVALID_EXCEPTION);
#endif
  }
  // restore the rounding mode back if it has been changed
  if (rm_changed) fesetround(old_rm);
  BID_RETURN (res);
}
	   // x is 0 otherwise

exponent_x =
  exponent_x - DECIMAL_EXPONENT_BIAS + DECIMAL_EXPONENT_BIAS_128;
res.w[1U] =
  sign_x | ((((BID_UINT64) (exponent_x + DECIMAL_EXPONENT_BIAS_128)) >> 1)
	    << 49);
res.w[0U] = 0;
// restore the rounding mode back if it has been changed
if (rm_changed) fesetround(old_rm);
BID_RETURN (res);
}
if (sign_x) {
  res.w[1U] = 0x7c00000000000000ull;
  res.w[0U] = 0;
#ifdef BID_SET_STATUS_FLAGS
  __set_status_flags (pfpsf, BID_INVALID_EXCEPTION);
#endif
  // restore the rounding mode back if it has been changed
  if (rm_changed) fesetround(old_rm);
  BID_RETURN (res);
}
#ifdef UNCHANGED_BINARY_STATUS_FLAGS
// (void) fegetexceptflag (&binaryflags, BID_FE_ALL_FLAGS);
#endif
exponent_x =
  exponent_x - DECIMAL_EXPONENT_BIAS + DECIMAL_EXPONENT_BIAS_128;

	   // 2^64
f64.i = 0x5f800000U;

	   // fx ~ CX
fx.d = (float) CX.w[1U] * f64.d + (float) CX.w[0U];
bin_expon_cx = ((fx.i >> 23) & 0xffU) - 0x7fU;
digits = bid_estimate_decimal_digits[bin_expon_cx];

A10 = CX;
if (exponent_x & 1) {
  A10.w[1U] = (CX.w[1U] << 3) | (CX.w[0U] >> 61);
  A10.w[0U] = CX.w[0U] << 3;
  CX2.w[1U] = (CX.w[1U] << 1) | (CX.w[0U] >> 63);
  CX2.w[0U] = CX.w[0U] << 1;
  __add_128_128 (A10, A10, CX2);
}

CS.w[0U] = short_sqrt128 (A10);
CS.w[1U] = 0;
	   // check for exact result
if (CS.w[0U] * CS.w[0U] == A10.w[0U]) {
  __mul_64x64_to_128_fast (S2, CS.w[0U], CS.w[0U]);
  if (S2.w[1U] == A10.w[1U]) {
    bid_get_BID128_very_fast (&res, 0,
			  (exponent_x + DECIMAL_EXPONENT_BIAS_128) >> 1,
			  CS);
#ifdef UNCHANGED_BINARY_STATUS_FLAGS
    // (void) fesetexceptflag (&binaryflags, BID_FE_ALL_FLAGS);
#endif
    // restore the rounding mode back if it has been changed
    if (rm_changed) fesetround(old_rm);
    BID_RETURN (res);
  }
}
	   // get number of digits in CX
D = (BID_SINT64)CX.w[1U] - (BID_SINT64)bid_power10_index_binexp_128[bin_expon_cx].w[1U];
if (D > 0
    || (!D && CX.w[0U] >= bid_power10_index_binexp_128[bin_expon_cx].w[0U]))
  digits++;

		// if exponent is odd, scale coefficient by 10
scale = 67 - digits;
exponent_q = exponent_x - scale;
scale += (exponent_q & 1);	// exp. bias is even

if (scale > 38) {
  T128 = bid_power10_table_128[scale - 37];
  __mul_128x128_low (CX1, CX, T128);

  TP128 = bid_power10_table_128[37U];
  __mul_128x128_to_256 (C256, CX1, TP128);
} else {
  T128 = bid_power10_table_128[scale];
  __mul_128x128_to_256 (C256, CX, T128);
}


	   // 4*C256
C4.w[3U] = (C256.w[3U] << 2) | (C256.w[2U] >> 62);
C4.w[2U] = (C256.w[2U] << 2) | (C256.w[1U] >> 62);
C4.w[1U] = (C256.w[1U] << 2) | (C256.w[0U] >> 62);
C4.w[0U] = C256.w[0U] << 2;

bid_long_sqrt128 (&CS, C256);

#ifndef IEEE_ROUND_NEAREST
#ifndef IEEE_ROUND_NEAREST_TIES_AWAY
if (!((rnd_mode) & 3)) {
#endif
#endif
  // compare to midpoints
  CSM.w[1U] = (CS.w[1U] << 1) | (CS.w[0U] >> 63);
  CSM.w[0U] = (CS.w[0U] + CS.w[0U]) | 1;
  // CSM^2
  //__mul_128x128_to_256(M256, CSM, CSM);
  __sqr128_to_256 (M256, CSM);

  if (C4.w[3U] > M256.w[3U]
      || (C4.w[3U] == M256.w[3U]
	  && (C4.w[2U] > M256.w[2U]
	      || (C4.w[2U] == M256.w[2U]
		  && (C4.w[1U] > M256.w[1U]
		      || (C4.w[1U] == M256.w[1U]
			  && C4.w[0U] > M256.w[0U])))))) {
    // round up
    CS.w[0U]++;
    if (!CS.w[0U])
      CS.w[1U]++;
  } else {
    C8.w[1U] = (CS.w[1U] << 3) | (CS.w[0U] >> 61);
    C8.w[0U] = CS.w[0U] << 3;
    // M256 - 8*CSM
    __sub_borrow_out (M256.w[0U], Carry, M256.w[0U], C8.w[0U]);
    __sub_borrow_in_out (M256.w[1U], Carry, M256.w[1U], C8.w[1U], Carry);
    __sub_borrow_in_out (M256.w[2U], Carry, M256.w[2U], 0, Carry);
    M256.w[3U] = M256.w[3U] - Carry;

    // if CSM' > C256, round up
    if (M256.w[3U] > C4.w[3U]
	|| (M256.w[3U] == C4.w[3U]
	    && (M256.w[2U] > C4.w[2U]
		|| (M256.w[2U] == C4.w[2U]
		    && (M256.w[1U] > C4.w[1U]
			|| (M256.w[1U] == C4.w[1U]
			    && M256.w[0U] > C4.w[0U])))))) {
      // round down
      if (!CS.w[0U])
	CS.w[1U]--;
      CS.w[0U]--;
    }
  }
#ifndef IEEE_ROUND_NEAREST
#ifndef IEEE_ROUND_NEAREST_TIES_AWAY
} else {
  __sqr128_to_256 (M256, CS);
  C8.w[1U] = (CS.w[1U] << 1) | (CS.w[0U] >> 63);
  C8.w[0U] = CS.w[0U] << 1;
  if (M256.w[3U] > C256.w[3U]
      || (M256.w[3U] == C256.w[3U]
	  && (M256.w[2U] > C256.w[2U]
	      || (M256.w[2U] == C256.w[2U]
		  && (M256.w[1U] > C256.w[1U]
		      || (M256.w[1U] == C256.w[1U]
			  && M256.w[0U] > C256.w[0U])))))) {
    __sub_borrow_out (M256.w[0U], Carry, M256.w[0U], C8.w[0U]);
    __sub_borrow_in_out (M256.w[1U], Carry, M256.w[1U], C8.w[1U], Carry);
    __sub_borrow_in_out (M256.w[2U], Carry, M256.w[2U], 0, Carry);
    M256.w[3U] = M256.w[3U] - Carry;
    M256.w[0U]++;
    if (!M256.w[0U]) {
      M256.w[1U]++;
      if (!M256.w[1U]) {
	M256.w[2U]++;
	if (!M256.w[2U])
	  M256.w[3U]++;
      }
    }

    if (!CS.w[0U])
      CS.w[1U]--;
    CS.w[0U]--;

    if (M256.w[3U] > C256.w[3U]
	|| (M256.w[3U] == C256.w[3U]
	    && (M256.w[2U] > C256.w[2U]
		|| (M256.w[2U] == C256.w[2U]
		    && (M256.w[1U] > C256.w[1U]
			|| (M256.w[1U] == C256.w[1U]
			    && M256.w[0U] > C256.w[0U])))))) {

      if (!CS.w[0U])
	CS.w[1U]--;
      CS.w[0U]--;
    }
  }

  else {
    __add_carry_out (M256.w[0U], Carry, M256.w[0U], C8.w[0U]);
    __add_carry_in_out (M256.w[1U], Carry, M256.w[1U], C8.w[1U], Carry);
    __add_carry_in_out (M256.w[2U], Carry, M256.w[2U], 0, Carry);
    M256.w[3U] = M256.w[3U] + Carry;
    M256.w[0U]++;
    if (!M256.w[0U]) {
      M256.w[1U]++;
      if (!M256.w[1U]) {
	M256.w[2U]++;
	if (!M256.w[2U])
	  M256.w[3U]++;
      }
    }
    if (M256.w[3U] < C256.w[3U]
	|| (M256.w[3U] == C256.w[3U]
	    && (M256.w[2U] < C256.w[2U]
		|| (M256.w[2U] == C256.w[2U]
		    && (M256.w[1U] < C256.w[1U]
			|| (M256.w[1U] == C256.w[1U]
			    && M256.w[0U] <= C256.w[0U])))))) {

      CS.w[0U]++;
      if (!CS.w[0U])
	CS.w[1U]++;
    }
  }
  // RU?
  if ((rnd_mode) == BID_ROUNDING_UP) {
    CS.w[0U]++;
    if (!CS.w[0U])
      CS.w[1U]++;
  }

}
#endif
#endif

#ifdef BID_SET_STATUS_FLAGS
__set_status_flags (pfpsf, BID_INEXACT_EXCEPTION);
#endif
bid_get_BID128_fast (&res, 0, (exponent_q + DECIMAL_EXPONENT_BIAS_128) >> 1,
		 CS);
#ifdef UNCHANGED_BINARY_STATUS_FLAGS
// (void) fesetexceptflag (&binaryflags, BID_FE_ALL_FLAGS);
#endif
// restore the rounding mode back if it has been changed
if (rm_changed) fesetround(old_rm);
BID_RETURN (res);


}
