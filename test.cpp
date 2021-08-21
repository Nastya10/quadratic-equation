#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "floats.h"
#include "test.h"
#include "solving_equations.h"

int test_solve_square(void)
{
    float root1 = 0;
    float root2 = 0;
    int n_failed_tests = 0;

    n_failed_tests += test_solve_square_roots_quantity(0, 0, 0, INF_ROOTS);
    n_failed_tests += test_solve_square_roots(0, 0, 0, 0, 0);

    n_failed_tests += test_solve_square_roots_quantity(0, 0, 5, 0);
    n_failed_tests += test_solve_square_roots(0, 0, 5, 0, 0);

    n_failed_tests += test_solve_square_roots_quantity(0, 3, 15, 1);
    n_failed_tests += test_solve_square_roots(0, 3, 15, -5, -5);

    n_failed_tests += test_solve_square_roots_quantity(1, -4, 4, 1);
    n_failed_tests += test_solve_square_roots(1, -4, 4, 2, 2);

    n_failed_tests += test_solve_square_roots_quantity(2, 4, 3, 0);
    n_failed_tests += test_solve_square_roots(2, 4, 3, 0, 0);

    n_failed_tests += test_solve_square_roots_quantity(1, 2, -15, 2);
    n_failed_tests += test_solve_square_roots(1, 2, -15, 3, -5);

    return n_failed_tests;
}

int test_solve_square_roots_quantity(float a, float b, float c, int correct_n_roots)
{
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));
    assert(correct_n_roots >= 0 && correct_n_roots <= 2);
    assert(correct_n_roots == INF_ROOTS);

    float unused1 = 0, unused2 = 0;

    int n_observed_roots = solve_square(a, b, c, &unused1, &unused2);
    if(n_observed_roots != correct_n_roots)
    {
        printf("TEST FAILD: when entering a = %g; b = %g; c = %g\n"
               "Expected number of roots: %g\n"
               "The resulting number of roots: %g", a, b, c, correct_n_roots, n_observed_roots);
        return 1;
    }
    else
        return 0;
}

int test_solve_square_roots(float a, float b, float c, float root1_expected, float root2_expected)
{
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));
    assert(isfinite(root1_expected));
    assert(isfinite(root2_expected));

    float root1_observed = 0, root2_observed = 0;

    solve_square(a, b, c, &root1_observed, &root2_observed);

    if(root1_observed != root1_expected && root2_observed != root2_expected)
    {
        printf("TEST FAILD: when entering a = %g; b = %g; c = %g\n"
               "Roots were expected: root1 = %g, root2 = %g\n"
               "The resulting roots: root1 = %g, root2 = %g\n",
               a, b, c, root1_expected, root2_expected, root1_observed, root2_observed);
        return 1;
    }
    else
        return 0;
}
