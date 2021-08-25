/**
 * @file
 * @brief Функции в этом файле решают квадратные и линейные уравнения
 * @date
 */

#ifndef SOLVER_H_INCLUDED
#define SOLVER_H_INCLUDED

/**
 * Здесь перечислены все возможные варианты количества корней
 */
enum roots_num {
    INF_ROOTS = -1, /**< Означает бесконечное количество корней*/
    NO_ROOTS  =  0, /**< Означает отсутствие корней*/
    ONE_ROOT  =  1, /**< Означает один корень*/
    TWO_ROOTS =  2  /**< Означает два корня*/
};

/**
 * Решает квадратное уравнение ax^2 + bx + c = 0
 *
 * @param[in] a квадратичный коэффицент
 * @param[in] b линейный коэффицент
 * @param[in] c свободный член
 *
 * @param[out] root1 является большем корнем уравнения
 * @param[out] root2 является меньшим корнем уравнения
 *
 * @return Количество корней уравнения
 *
 * @retval NO_ROOTS
 * @retval ONE_ROOT
 * @retval TWO_ROOTS
 * @retval INF_ROOTS возвращается в случае бесконечного количества корней
 */
enum roots_num solve_quadratic(
    const float a, const float b, const float c,
    float *root1, float *root2
);

/**
 * Решает линейное уравнение bx + c = 0
 *
 * @param[in] b линейный коэффицент
 * @param[in] c свободный член
 *
 * @param[out] root
 *
 * @return Количество корней уравнения
 *
 * @retval NO_ROOTS
 * @retval ONE_ROOT
 * @retval INF_ROOTS возвращается в случае бесконечного количества корней
 */
enum roots_num solve_linear(float b, float c, float *root);

#endif // SOLVING_SQUARES_H_INCLUDED
