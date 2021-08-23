#include <assert.h>
#include <float.h>
#include <math.h>
#include <stdio.h>

#include "floats.h"

//FLT_EPSILON is about 2^(-23)

bool floats_are_equal(float float1, float float2)
{
        assert(isfinite(float1));
        assert(isfinite(float2));

        return fabsf(float1 - float2) <= FLT_EPSILON;
}

bool float_is_less(float float_num, int int_num)
{
    assert(isfinite(float_num));

    return int_num - float_num > FLT_EPSILON;
}
