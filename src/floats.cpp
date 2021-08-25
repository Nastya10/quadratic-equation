#include <assert.h>
#include <float.h>
#include <math.h>
#include <stdio.h>

#include "floats.h"

//FLT_EPSILON is about 2^(-23)

int compare_floats(const float float1, const float float2)
{
    if (floats_are_equal(float1, float2))
        return EQUAL;
    else if (float_is_less(float1, float2))
        return LESS;
    else
        return MORE;
}

bool floats_are_equal(const float float1, const float float2)
{
        assert(isfinite(float1));
        assert(isfinite(float2));

        return fabsf(float1 - float2) <= FLT_EPSILON;
}

bool float_is_less(const float float_min, const float float_max)
{
    assert(isfinite(float_min));
    assert(isfinite(float_max));

    return float_max - float_min > FLT_EPSILON;
}
