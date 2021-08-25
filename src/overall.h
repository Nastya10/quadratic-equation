/**
 * @file
 * @brief В этом файле находятся функции для main
 * @date
 */

#ifndef OVERALL_H_INCLUDED
#define OVERALL_H_INCLUDED

#include "solver.h"

/**
 * Тестирует программу
 */
void test(void);

/**
 * Вводит три коэффицента квадратного уравнения
 *
 * @param[in] a quadratic coefficient
 * @param[in] b linear coefficient
 * @param[in] c free member
 *
 * @param[out] Возвращает код ошибки
 */
int input(float *a, float *b, float *c);

/**
 * Выводит количество корней и их значения
 *
 * @param[in] b linear coefficient
 * @param[in] c free member
 *
 * @param[out] Возвращает код ошибки
 */
int print(
    enum roots_num n_roots,
    const float root1, const float root2
);

#endif // OVERALL_H_INCLUDED
