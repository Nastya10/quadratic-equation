/**
 * @file main.cpp
 * @brief Solving Quadratic Equations
 * @date i don’t know when this is gonna end :D
 * ---------------------------------------------------------------
 * This file is an application for solving quadratic equations if
 * Release mode (with flag NDEBUG)
 * And this file implements square equation solver unit tests if
 * building in Debug mode (without flag NDEBUG)
 */

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "floats.h"
#include "test.h"
#include "solver.h"


//#define TEST

int main(void)
{
    #if defined TEST
        int n_failed_tests_square = test_solve_square();
        if (n_failed_tests_square != 0)
            printf("TESTS FAILED (function solve_square): "
                   "number of failed tests: %d\n", n_failed_tests_square);
        else
            printf("TESTS PASSED (function solve_square)\n");

        int n_failed_tests_square_linear = test_solve_linear();
        if (n_failed_tests_square_linear != 0)
            printf("TESTS FAILED (function solve_linear): "
                   "number of failed tests: %d\n", n_failed_tests_square_linear);
        else
            printf("TESTS PASSED (function solve_linear)\n");
    #else

        float a = 0, b = 0, c = 0;
        float root1 = 0, root2 = 0;

        printf("The program solves quadratic equations\n"
               "Enter the coefficients a, b and c: ");

        if (scanf("%f %f %f", &a, &b, &c) != 3)
        {
            printf("INPUT ERROR: incorrect number of values\n");
            return EXIT_SUCCESS;
        }

        int n_roots = solve_square(a, b, c, &root1, &root2);
        switch (n_roots)
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
