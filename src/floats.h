/**
 * @file
 * @brief ¬ этом файле наход€тс€ функции дл€ сравнени€ двух чисел типа float
 * @date
 */

#ifndef FLOATS_H_INCLUDED
#define FLOATS_H_INCLUDED

/**
 * «десь перечислены все возможные
 * результаты при сравнении двух чисел типа float
 */
enum compare_floats_result {
    MORE  = 0, /**< ќзначает, что первое число больше второго*/
    LESS  = 1, /**< ќзначает, что первое число меньше второго*/
    EQUAL = 2  /**< ќзначает, что два числа равны*/
};

/**
 * ѕровер€ет равны ли два числа
 *
 * @param[in] float1
 * @param[in] float2
 *
 * @return явл€ютс€ ли числа равными
 */
bool floats_are_equal(const float float1, const float float2);

/**
 * ѕровер€ет меньше ли первое передаваемое число
 *
 * @param[in] float_min
 * @param[in] float_max
 *
 * @return явл€етс€ ли первое число меньше
 */
bool float_is_less(const float float_min, const float float_max);

/**
 * —равнивает два числа
 *
 * @param[in] float_min
 * @param[in] float_max
 *
 * @return –езультат сравнени€
 */
enum compare_floats_result compare_floats(const float float1, const float float2);

#endif // FUNCTIONS_FO_FLOATS_H_INCLUDED
