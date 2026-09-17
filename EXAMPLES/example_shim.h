#ifndef EXAMPLE_SHIM_H
#define EXAMPLE_SHIM_H

#include "decimal.h"

Decimal128 example_bid128_mul (Decimal128 x, Decimal128 y,
                               _IDEC_round rnd_mode, _IDEC_flags *fpsf);

#endif
