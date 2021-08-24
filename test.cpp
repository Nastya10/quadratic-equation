#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "floats.h"
#include "test.h"
#include "solver.h"

int test_solve_quadratic(void)
{
    int n_failed_tests_quadratic = 0;

    n_failed_tests_quadratic += test_solve_quadratic_roots_quantity(0, 0, 0, INF_ROOTS);
    n_failed_tests_quadratic += test_solve_quadratic_roots(0, 0, 0, 0, 0);

    n_failed_tests_quadratic += test_solve_quadratic_roots_quantity(0, 0, 5, NO_ROOTS);
    n_failed_tests_quadratic += test_solve_quadratic_roots(0, 0, 5, 0, 0);

    n_failed_tests_quadratic += test_solve_quadratic_roots_quantity(2, 4, 3, NO_ROOTS);
    n_failed_tests_quadratic += test_solve_quadratic_roots(2, 4, 3, 0, 0);

    n_failed_tests_quadratic += test_solve_quadratic_roots_quantity(0, 3, 15, ONE_ROOT);
    n_failed_tests_quadratic += test_solve_quadratic_roots(0, 3, 15, -5, -5);

    n_failed_tests_quadratic += test_solve_quadratic_roots_quantity(1, -4, 4, ONE_ROOT);
    n_failed_tests_quadratic += test_solve_quadratic_roots(1, -4, 4, 2, 2);

    n_failed_tests_quadratic += test_solve_quadratic_roots_quantity(1, 2, -15, TWO_ROOTS);
    n_failed_tests_quadratic += test_solve_quadratic_roots(1, 2, -15, 3, -5);

    return n_failed_tests_quadratic;
}

int test_solve_quadratic_roots_quantity(float a, float b, float c, enum roots_num correct_n_roots)
{
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));
    assert((correct_n_roots >= 0 && correct_n_roots <= 2) || correct_n_roots == INF_ROOTS);

    float unused1 = 0, unused2 = 0;

    enum roots_num n_observed_roots = solve_quadratic(a, b, c, &unused1, &unused2);
    if (n_observed_roots != correct_n_roots)
    {
        printf("TEST FAILED: with parameters a = %g, b = %g, c = %g\n"
               "Expected number of roots: %g\n"
               "Observed number of roots: %g", a, b, c, correct_n_roots, n_observed_roots);
        return 1;
    }
    else
        return 0;
}

int test_solve_quadratic_roots(float a, float b, float c, float root1_expected, float root2_expected)
{
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));
    assert(isfinite(root1_expected));
    assert(isfinite(root2_expected));

    float root1_observed = 0, root2_observed = 0;

    solve_quadratic(a, b, c, &root1_observed, &root2_observed);

    if (root1_observed != root1_expected && root2_observed != root2_expected)
    {
        printf("TEST FAILED: with parameters a = %g, b = %g, c = %g\n"
               "Roots expected: root1 = %g, root2 = %g\n"
               "Observed roots: root1 = %g, root2 = %g\n",
               a, b, c, root1_expected, root2_expected, root1_observed, root2_observed);
        return 1;
    }
    else
        return 0;
}

int test_solve_linear(void)
{
    int n_failed_tests_linear = 0;

    n_failed_tests_linear += test_solve_linear_roots_quantity(0, 0, INF_ROOTS);
    n_failed_tests_linear += test_solve_linear_root(0, 0, 0);

    n_failed_tests_linear += test_solve_linear_roots_quantity(0, 5, NO_ROOTS);
    n_failed_tests_linear += test_solve_linear_root(0, 5, 0);

    n_failed_tests_linear += test_solve_linear_roots_quantity(3, -15, ONE_ROOT);
    n_failed_tests_linear += test_solve_linear_root(3, -15, 5);

    return n_failed_tests_linear;
}

int test_solve_linear_roots_quantity(float b, float c, enum roots_num correct_n_roots)
{
    assert(isfinite(b));
    assert(isfinite(c));
    assert((correct_n_roots >= 0 && correct_n_roots <= 1) || correct_n_roots == INF_ROOTS);

    float unused = 0;

    enum roots_num n_observed_roots = solve_linear(b, c, &unused);
    if (n_observed_roots != correct_n_roots)
    {
        printf("TEST FAILED: with parameters b = %g, c = %g\n"
               "Expected number of roots: %g\n"
               "Observed number of roots: %g", b, c, correct_n_roots, n_observed_roots);
        return 1;
    }
    else
        return 0;
}

int test_solve_linear_root(float b, float c, float root_expected)
{
    assert(isfinite(b));
    assert(isfinite(c));
    assert(isfinite(root_expected));

    float root_observed = 0;

    solve_linear(b, c, &root_observed);

    if (root_observed != root_expected)
    {
        printf("TEST FAILED: with parameters b = %g, c = %g\n"
               "Root expected: root = %g\n"
               "Observed root: root = %g\n",
               b, c, root_expected, root_observed);
        return 1;
    }
    else
        return 0;
}
