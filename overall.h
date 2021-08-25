/**
 * @file
 * @brief Functions for main
 * @date i do not know when this is gonna end :D
 */

#ifndef OVERALL_H_INCLUDED
#define OVERALL_H_INCLUDED

#include "solver.h"

/**
 * Tests the program
 */
void test(void);

/**
 * Input of three coefficients
 *
 * @param[in] a quadratic coefficient
 * @param[in] b linear coefficient
 * @param[in] c free member
 *
 * @param[out] Returns error code
 */
int input(float *a, float *b, float *c);

/**
 * Displays the number of roots and their values
 *
 * @param[in] b linear coefficient
 * @param[in] c free member
 *
 * @param[out] Returns error code
 */
int print(
    enum roots_num n_roots,
    const float root1, const float root2
);

#endif // OVERALL_H_INCLUDED
