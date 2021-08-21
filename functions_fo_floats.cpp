#include <assert.h>
#include <math.h>
#include <stdio.h>

bool floats_are_equal(float float1, float float2)
{
        return fabsf(float1 - float2) <= EPSILON;
}
