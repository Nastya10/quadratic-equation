#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "functions_fo_floats.h"
#include "test.h"
#include "solving_squares.h"

int test_solve_square(void)
{
    float root1 = 0;
    float root2 = 0;
    int n_errors = 0;

    n_errors += test_solve_square_roots_quantity(0, 0, 0, INF_ROOTS);
    test_solve_square_roots(0, 0, 0, 0, 0);

    n_errors += test_solve_square_roots_quantity(0, 0, 5, 0);
    test_solve_square_roots(0, 0, 5, 0, 0);

    n_errors += test_solve_square_roots_quantity(0, 3, 15, 1);
    test_solve_square_roots(0, 3, 15, -5, -5);

    n_errors += test_solve_square_roots_quantity(1, -4, 4, 1);
    test_solve_square_roots(1, -4, 4, 2, 2);

    n_errors += test_solve_square_roots_quantity(2, 4, 3, 0);
    test_solve_square_roots(2, 4, 3, 0, 0);

    n_errors += test_solve_square_roots_quantity(1, 2, -15, 2);
    test_solve_square_roots(1, 2, -15, 3, -5);

    return n_errors;
}

int test_solve_square_roots_quantity(float a, float b, float c, int correct_n_roots)
{
    float root1_observed = 0, root2_observed = 0;

    if(solve_square(a, b, c, &root1_observed, &root2_observed) != correct_n_roots)
        return 1;
    else
        return 0;
}

void test_solve_square_roots(float a, float b, float c, float root1_expected, float root2_expected)
{
    float root1_observed = 0, root2_observed = 0;

    solve_square(a, b, c, &root1_observed, &root2_observed);

    if(root1_observed != root1_expected && root2_observed != root2_expected)
    {
        printf("ERROR when entering a = %g; b = %g; c = %g\n", a, b, c);
    }
}
