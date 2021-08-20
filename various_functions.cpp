#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "various_functions.h"

int INF_ROOTS = 3;
float EPSILON = 10E-8;

int solve_square(float a, float b, float c, float* root1, float* root2)
{
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));

    assert(root1 != NULL);
    assert(root2 != NULL);
    assert(root1 != root2);

    if(floats_are_equal(a, 0))
    {
        int n_roots = solve_linear(b, c, root1);
        if(n_roots == 1)
            *root2 = *root1;
        return n_roots;
    }
    else
    {
        float d =  pow(b, 2) - 4 * a * c;
        float parab_vert = -b / (2 * a);

        if(d < 0)
        {
            return 0;
        }
        else if(floats_are_equal(d, 0))
        {
            *root1 = *root2 = parab_vert;
            return 1;
        }
        else
        {
            float d_sqrt = sqrt(d);

            *root1 = parab_vert + d_sqrt / (2 * a);
            *root2 = parab_vert - d_sqrt / (2 * a);
            return 2;
        }
    }
}

int solve_linear(float b, float c, float* root)
{
    assert(isfinite(b));
    assert(isfinite(c));

    assert(root != NULL);

    if(floats_are_equal(b, 0))
    {
        if(floats_are_equal(c, 0))
        {
            return INF_ROOTS;
        }
        else
        {
            return 0;
        }

    }
    else
    {
        *root = -c / b;
        return 1;
    }
}

bool floats_are_equal(float float1, float float2)
{
        return fabsf(float1 - float2) <= EPSILON;
}
