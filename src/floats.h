/**
 * @file
 * @brief � ���� ����� ��������� ������� ��� ��������� ���� ����� ���� float
 * @date
 */

#ifndef FLOATS_H_INCLUDED
#define FLOATS_H_INCLUDED

/**
 * ����� ����������� ��� ���������
 * ���������� ��� ��������� ���� ����� ���� float
 */
enum compare_floats_result {
    MORE  = 0, /**< ��������, ��� ������ ����� ������ �������*/
    LESS  = 1, /**< ��������, ��� ������ ����� ������ �������*/
    EQUAL = 2  /**< ��������, ��� ��� ����� �����*/
};

/**
 * ��������� ����� �� ��� �����
 *
 * @param[in] float1
 * @param[in] float2
 *
 * @return �������� �� ����� �������
 */
bool floats_are_equal(const float float1, const float float2);

/**
 * ��������� ������ �� ������ ������������ �����
 *
 * @param[in] float_min
 * @param[in] float_max
 *
 * @return �������� �� ������ ����� ������
 */
bool float_is_less(const float float_min, const float float_max);

/**
 * ���������� ��� �����
 *
 * @param[in] float_min
 * @param[in] float_max
 *
 * @return ��������� ���������
 */
enum compare_floats_result compare_floats(const float float1, const float float2);

#endif // FUNCTIONS_FO_FLOATS_H_INCLUDED
