/**
 * @file solver.cpp
 * @brief Functions of solutions of quadratic and linear equations
 * @date i don’t know when this is gonna end :D
 */

#ifndef SOLVER_H_INCLUDED
#define SOLVER_H_INCLUDED

/**
 * INF_ROOTS denotes an infinite number of roots
 */
enum Number_of_roots {INF_ROOTS = -1, NO_ROOTS, ONE_ROOT, TWO_ROOTS};

/**
 * Solves a square equation ax^2 + bx + c = 0
 *
 * @param[in] a quadratic coefficient
 * @param[in] b linear coefficient
 * @param[in] c free member
 * @param[out] root1 the larger root of the equation is placed
 * @param[out] root2 the smaller root of the equation is placed
 *
 * @return Number of roots
 *
 * @retval 0
 * @retval 1
 * @retval 2
 * @retval INF_ROOTS in case of infinite number of roots
 */
int solve_square(float a, float b, float c, float *root1, float *root2);

/**
 * Solves a square equation bx + c = 0
 *
 * @param[in] b linear coefficient
 * @param[in] c coefficient
 * @param[out] free member
 *
 * @return Number of roots
 *
 * @retval 0
 * @retval 1
 * @retval INF_ROOTS in case of infinite number of roots
 */
int solve_linear(float float1, float float2, float *root);

#endif // SOLVING_SQUARES_H_INCLUDED
