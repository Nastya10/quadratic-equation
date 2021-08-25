/**
 * @file
 * @brief � ���� ����� ��������� ������� ��� main
 * @date
 */

#ifndef OVERALL_H_INCLUDED
#define OVERALL_H_INCLUDED

#include "solver.h"

/**
 * ��������� ���������
 */
void test(void);

/**
 * ������ ��� ����������� ����������� ���������
 *
 * @param[in] a quadratic coefficient
 * @param[in] b linear coefficient
 * @param[in] c free member
 *
 * @param[out] ���������� ��� ������
 */
int input(float *a, float *b, float *c);

/**
 * ������� ���������� ������ � �� ��������
 *
 * @param[in] b linear coefficient
 * @param[in] c free member
 *
 * @param[out] ���������� ��� ������
 */
int print(
    enum roots_num n_roots,
    const float root1, const float root2
);

#endif // OVERALL_H_INCLUDED
