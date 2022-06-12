#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "floats.h"
#include "solver.h"

static float calculate_discriminant(float a, float b, float c);

enum roots_num solve_quadratic(const float a, const float b, const float c, float *root1, float *root2)
{
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));

    assert(root1 != NULL);
    assert(root2 != NULL);
    assert(root1 != root2);

    if (compare_floats(a, 0) == EQUAL)
    {
        enum roots_num n_roots = solve_linear(b, c, root1);
        if (n_roots == 1)
            *root2 = *root1;
        return n_roots;
    }
    else
    {
        float d =  calculate_discriminant(a, b, c);
        float parab_vert = -b / (2 * a);

        if (compare_floats(d, 0) == LESS)
        {
            return NO_ROOTS;
        }
        else if (floats_are_equal(d, 0))
        {
            *root1 = *root2 = parab_vert;
            return ONE_ROOT;
        }
        else
        {
            float d_sqrt = sqrt(d);

            *root1 = parab_vert + d_sqrt / (2 * a);
            *root2 = parab_vert - d_sqrt / (2 * a);
            return TWO_ROOTS;
        }
    }
}

enum roots_num solve_linear(float b, float c, float *root)
{
    assert(isfinite(b));
    assert(isfinite(c));

    assert(root != NULL);

    if (floats_are_equal(b, 0))
    {
        if (floats_are_equal(c, 0))
        {
            return INF_ROOTS;
        }
        else
        {
            return NO_ROOTS;
        }
    }
    else
    {
        *root = -c / b;
        return ONE_ROOT;
    }
}

static float calculate_discriminant(float a, float b, float c)
{
    return b * b - 4 * a * c;
}
