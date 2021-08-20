#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "various_functions.h"
#include "test.h"

int test_solve_square(float* root1, float* root2)
{
    int n_errors = 0;

    n_errors += test_quantity_roots(solve_square(0, 0, 0, root1, root2), INF_ROOTS);
    if(*root1 != *root2 && *root1 != 0)
        printf("ERROR when entering a = 0; b = 0; c = 0");

    n_errors += test_quantity_roots(solve_square(0, 0, 5, root1, root2), 0);
    if(*root1 != *root2 && *root1 != 0)
        printf("ERROR when entering a = 0; b = 0; c = 5");

    n_errors += test_quantity_roots(solve_square(0, 3, 15, root1, root2), 1);
    if(*root1 != *root2 && *root1 != 5)
        printf("ERROR when entering a = 0; b = 3; c = 15");

    n_errors += test_quantity_roots(solve_square(1, -4, 4, root1, root2), 1);
    if(*root1 != *root2 && *root1 != 2)
        printf("ERROR when entering a = 1; b = -4; c = 4");

    n_errors += test_quantity_roots(solve_square(2, 4, 3, root1, root2), 0);
    if(*root1 != *root2 && *root1 != 0)
        printf("ERROR when entering a = 2; b = 4; c = 3");

    n_errors += test_quantity_roots(solve_square(1, 2, -15, root1, root2), 2);
    if(*root1 != 3 && *root2 != -5)
        printf("ERROR when entering a = 1; b = 2; c = -15");

    return n_errors;
}

int test_quantity_roots(int function_result, int correct_result)
{
    if(function_result != correct_result)
        return 1;
    else
        return 0;
}
