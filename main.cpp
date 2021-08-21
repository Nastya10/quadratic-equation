/**
 * @file main.cpp
 * @brief Solving Quadratic Equations
 * @date i don’t know when this is gonna end :D
 */

#define NDEBUG

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "functions_fo_floats.h"
#include "test.h"
#include "solving_squares.h"


//#define TEST

int main(void)
{
    #if defined TEST
        int n_errors = test_solve_square();
        if(n_errors != 0)
            printf("TESTS FAILED: number of failed tests: %d\n", n_errors);
        else
            printf("TESTS PASSED\n");
    #else
        float a = 0, b = 0, c = 0;
        float root1 = 0, root2 = 0;
        printf("The program solves quadratic equations\n"
               "Enter the coefficients a, b and c:");
        if(scanf("%f %f %f", &a, &b, &c) != 3)
        {
            printf("INPUT ERROR: incorrect number of values\n");
            return EXIT_SUCCESS;
        }
        int n_roots = solve_square(a, b, c, &root1, &root2);
        switch(n_roots)
        {
            case 0:
                printf("The quadratic equation has no roots\n");
                break;
            case 1:
                printf("The quadratic equation has one root: %g\n", root1);
                break;
            case 2:
                printf("The quadratic equation has two roots\n"
                       "First: %g\n"
                       "Second: %g\n", root1, root2);
                break;
            case INF_ROOTS:
                printf("The equation has an infinite number of solutions\n");
                break;
            default:
                printf("INTERNAL ERROR: solve_square returned a unexpected number of roots: %g\n", n_roots);
                return EXIT_FAILURE;
        }

    #endif

    return EXIT_SUCCESS;
}
