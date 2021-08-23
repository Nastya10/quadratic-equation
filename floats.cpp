#include <assert.h>
#include <float.h>
#include <math.h>
#include <stdio.h>

#include "floats.h"

bool floats_are_equal(float float1, float float2)
{
        assert(isfinite(float1));
        assert(isfinite(float2));

        return fabsf(float1 - float2) <= FLT_EPSILON;
}
