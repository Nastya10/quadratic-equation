/**
 * @file main.cpp
 * @brief Solving Quadratic Equations
 * @date i do not know when this is gonna end :D
 * ---------------------------------------------------------------
 * This file is an application for quadratic square equations if
 * Release mode (without flag TEST)
 * And this file implements square equation solver unit tests if
 * building in Debug mode (with flag TEST)
 */

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "floats.h"
#include "overall.h"
#include "test.h"
#include "solver.h"

#define TEST

int main(void)
{
#ifdef TEST
    test();
#else

    float a = 0, b = 0, c = 0;
    float root1 = NAN, root2 = NAN;

    printf("The program solves quadratic equations\n"
           "Enter the coefficients a, b and c: ");

    input(&a, &b, &c);

    if (__isnanf(root1) != 0 || __isnanf(root2) != 0)
        return EXIT_SUCCESS;

    enum roots_num  n_roots = solve_quadratic(a, b, c, &root1, &root2);
    print(n_roots, root1, root2);

#endif

    return EXIT_SUCCESS;
}
