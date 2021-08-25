/**
 * @file
 * @brief Functions of solutions of quadratic and linear equations
 * @date i do not know when this is gonna end :D
 */

#ifndef SOLVER_H_INCLUDED
#define SOLVER_H_INCLUDED

/**
 * This enumeration contains all possible returned root counts
 */
enum roots_num {
    INF_ROOTS = -1, /**< denotes an infinite number of roots*/
    NO_ROOTS  =  0, /**< denotes no roots*/
    ONE_ROOT  =  1, /**< denotes one root*/
    TWO_ROOTS =  2  /**< denotes two roots*/
};

/**
 * Solves a quadratic equation ax^2 + bx + c = 0
 *
 * @param[in] a quadratic coefficient
 * @param[in] b linear coefficient
 * @param[in] c free member
 *
 * @param[out] root1 the larger root of the equation is placed
 * @param[out] root2 the smaller root of the equation is placed
 *
 * @return Number of roots
 *
 * @retval NO_ROOTS
 * @retval ONE_ROOT
 * @retval TWO_ROOTS
 * @retval INF_ROOTS in case of infinite number of roots
 */
enum roots_num solve_quadratic(
    const float a, const float b, const float c,
    float *root1, float *root2
);

/**
 * Solves a quadratic equation bx + c = 0
 *
 * @param[in] b linear coefficient
 * @param[in] c free member
 *
 * @param[out] root
 *
 * @return Number of roots
 *
 * @retval NO_ROOTS
 * @retval ONE_ROOT
 * @retval INF_ROOTS in case of infinite number of roots
 */
enum roots_num solve_linear(float b, float c, float *root);

#endif // SOLVING_SQUARES_H_INCLUDED
