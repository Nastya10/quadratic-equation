/**
 * @file
 * @brief ������� � ���� ����� ������ ���������� � �������� ���������
 * @date
 */

#ifndef SOLVER_H_INCLUDED
#define SOLVER_H_INCLUDED

/**
 * ����� ����������� ��� ��������� �������� ���������� ������
 */
enum roots_num {
    INF_ROOTS = -1, /**< �������� ����������� ���������� ������*/
    NO_ROOTS  =  0, /**< �������� ���������� ������*/
    ONE_ROOT  =  1, /**< �������� ���� ������*/
    TWO_ROOTS =  2  /**< �������� ��� �����*/
};

/**
 * ������ ���������� ��������� ax^2 + bx + c = 0
 *
 * @param[in] a ������������ ����������
 * @param[in] b �������� ����������
 * @param[in] c ��������� ����
 *
 * @param[out] root1 �������� ������� ������ ���������
 * @param[out] root2 �������� ������� ������ ���������
 *
 * @return ���������� ������ ���������
 *
 * @retval NO_ROOTS
 * @retval ONE_ROOT
 * @retval TWO_ROOTS
 * @retval INF_ROOTS ������������ � ������ ������������ ���������� ������
 */
enum roots_num solve_quadratic(
    const float a, const float b, const float c,
    float *root1, float *root2
);

/**
 * ������ �������� ��������� bx + c = 0
 *
 * @param[in] b �������� ����������
 * @param[in] c ��������� ����
 *
 * @param[out] root
 *
 * @return ���������� ������ ���������
 *
 * @retval NO_ROOTS
 * @retval ONE_ROOT
 * @retval INF_ROOTS ������������ � ������ ������������ ���������� ������
 */
enum roots_num solve_linear(float b, float c, float *root);

#endif // SOLVING_SQUARES_H_INCLUDED
