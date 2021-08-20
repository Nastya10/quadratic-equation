/**
 * @file main.cpp
 * @brief Solving Quadratic Equations
 * @date не знаю когда это закончится :D
 */

#define NDEBUG

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "various_functions.h"
#include "test.h"

int main(void)
{
    /*float a = 0, b = 0, c = 0;
    float root1 = 0, root2 = 0;

    printf("The program solves quadratic equations\n");
    printf("Enter the coefficients a, b and c:");

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
            printf("The quadratic equation has two roots\nFirst: %g\nSecond: %g\n", root1, root2);
            break;
        case INF_ROOTS:
            printf("The equation has an infinite number of solutions\n");
            break;
        default:
            printf("INTERNAL ERROR: solve_square returned a unexpected number of roots: %g\n", n_roots);
            return EXIT_FAILURE;
    }*/

    float root1 = 0;
    float root2 = 0;

    int n_errors = test_solve_square(&root1, &root2);
    if(n_errors != 0)
        printf("TESTS FAILED, number of errors: %d\n", n_errors);
    else
        printf("TESTS PASSED\n");

    return EXIT_SUCCESS;
}
