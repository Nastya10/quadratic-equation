#ifndef VARIOUS_FUNCTIONS_H_INCLUDED
#define VARIOUS_FUNCTIONS_H_INCLUDED

/**
 * Denotes an infinite number of roots
 */
extern int INF_ROOTS;

/**
 * Epsilon is a constant that determines the maximum
 * difference between two floats to consider them equal
 */
extern float EPSILON;

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
int solve_square(float a, float b, float c, float* root1, float* root2);
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
int solve_linear(float float1, float float2, float* root);

/**
 * Checks the equality of two floats
 *
 * @param[in] float1
 * @param[in] float2
 *
 * @return Is it true that the floats are equal
 */
bool floats_are_equal(float float1, float float2);

#endif // VARIOUS_FUNCTIONS_H_INCLUDED
