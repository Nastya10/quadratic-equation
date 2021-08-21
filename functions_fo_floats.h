#ifndef FUNCTIONS_FO_FLOATS_H_INCLUDED
#define FUNCTIONS_FO_FLOATS_H_INCLUDED

/**
 * Epsilon is a constant that determines the maximum
 * difference between two floats to consider them equal
 */
const float EPSILON = 10E-8;

/**
 * Checks the equality of two floats
 *
 * @param[in] float1
 * @param[in] float2
 *
 * @return Is it true that the floats are equal
 */
bool floats_are_equal(float float1, float float2);

#endif // FUNCTIONS_FO_FLOATS_H_INCLUDED
