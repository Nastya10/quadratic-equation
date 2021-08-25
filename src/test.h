/**
 * @file
 * @brief Tests that verify functions for solutions of quadratic and linear equations
 * @date i do not know when this is gonna end :D
 */

#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED

#include "solver.h"

int test_solve_quadratic(void);
int test_solve_quadratic_roots_quantity(
    const float a, const float b, const float c,
    enum roots_num correct_n_roots
);
int test_solve_quadratic_roots(
    const float a, const float b, const float c,
    float root1_expected, float root2_expected
);

int test_solve_linear(void);
int test_solve_linear_roots_quantity(
    const float b, const float c,
    enum roots_num correct_n_roots
);
int test_solve_linear_root(const float b, const float c, float root_expected);

#endif // TEST_H_INCLUDED
