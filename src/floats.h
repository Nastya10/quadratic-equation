/**
 * @file
 * @brief Function for checking the equality of two floats
 * @date i do not know when this is gonna end :D
 */

#ifndef FLOATS_H_INCLUDED
#define FLOATS_H_INCLUDED

/**
 * This enumeration contains all possible results of
 * two float-point numbers comparison
 */
enum compare_floats_result {
    MORE  = 0, /**< denotes that the first float is greater than the second*/
    LESS  = 1, /**< denotes that the first float is less than the second*/
    EQUAL = 2  /**< denotes that numbers are equal*/
};

/**
 * Checks the equality of two floats
 *
 * @param[in] float1
 * @param[in] float2
 *
 * @return Is it true that the floats are equal
 */
bool floats_are_equal(const float float1, const float float2);

/**
 * Checks which float is less
 *
 * @param[in] float_min
 * @param[in] float_max
 *
 * @return First floats is less ore not
 */
bool float_is_less(const float float_min, const float float_max);

/**
 * Ñomparison floats
 *
 * @param[in] float_min
 * @param[in] float_max
 *
 * @return Result of comparison
 */
int compare_floats(const float float1, const float float2);

#endif // FUNCTIONS_FO_FLOATS_H_INCLUDED
