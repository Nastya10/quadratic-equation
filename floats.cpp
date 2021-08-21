#include <assert.h>
#include <math.h>
#include <stdio.h>

#include "functions_fo_floats.h"
#include "solving_squares.h"

/**
 * Epsilon is a constant that determines the maximum
 * difference between two floats to consider them equal
 */
const float EPSILON = 10E-8;

bool floats_are_equal(float float1, float float2)
{
        assert(isfinite(float1));
        assert(isfinite(float2));

        return fabsf(float1 - float2) <= EPSILON;
}
