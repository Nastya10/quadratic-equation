/**
 * @file main.cpp
 * @brief Tests that verify functions for solutions of quadratic and linear equations
 * @date i don’t know when this is gonna end :D
 */

#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED

int test_solve_square(void);
int test_solve_square_roots_quantity(float a, float b, float c, int correct_n_roots);
int test_solve_square_roots(float a, float b, float c, float root1_expected, float root2_expected);

int test_solve_linear(void);
int test_solve_linear_roots_quantity(float b, float c, int correct_n_roots);
int test_solve_linear_root(float b, float c, float root_expected);

#endif // TEST_H_INCLUDED
