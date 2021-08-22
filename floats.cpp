/**
 * @file main.cpp
 * @brief Function for checking the equality of two floats
 * @date i don’t know when this is gonna end :D
 */

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <float.h>

#include "floats.h"

bool floats_are_equal(float float1, float float2)
{
        assert(isfinite(float1));
        assert(isfinite(float2));

        return fabsf(float1 - float2) <= FLT_EPSILON;
}
