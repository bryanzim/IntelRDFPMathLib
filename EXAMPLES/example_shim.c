#include "bid_conf.h"
#include "bid_functions.h"
#include "decimal.h"
#include "example_shim.h"

Decimal128
example_bid128_mul (Decimal128 x, Decimal128 y,
                    _IDEC_round rnd_mode, _IDEC_flags *fpsf)
{
  BID_UINT128 bx, by, bz;
  bx.w[BID_HIGH_128W] = x.w[HIGH_128W];
  bx.w[BID_LOW_128W] = x.w[LOW_128W];
  by.w[BID_HIGH_128W] = y.w[HIGH_128W];
  by.w[BID_LOW_128W] = y.w[LOW_128W];
  bz = bid128_mul (bx, by, rnd_mode, fpsf);
  x.w[HIGH_128W] = bz.w[BID_HIGH_128W];
  x.w[LOW_128W] = bz.w[BID_LOW_128W];
  return x;
}
