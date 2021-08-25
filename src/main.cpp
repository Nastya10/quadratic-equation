/**
 * @file main.cpp
 * @brief Решение квадратных уравнений
 * @date
 * ---------------------------------------------------------------
 * При запуске программа решает квадратные уравнения
 * если не используется макрос TEST
 * И этот файл запускает юнит-тесты
 * при использования макроса TEST
 *
 * @mainpage
 */

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "floats.h"
#include "overall.h"
#include "test.h"
#include "solver.h"

//#define TEST

int main(void)
{
#ifdef TEST
    test();
#else

    float a = 0, b = 0, c = 0;
    float root1 = 0, root2 = 0;

    printf("The program solves quadratic equations\n"
           "Enter the coefficients a, b and c: ");

    int status_input = input(&a, &b, &c);
    if (status_input == EXIT_FAILURE) {
        return EXIT_FAILURE;
    }

    enum roots_num n_roots = solve_quadratic(a, b, c, &root1, &root2);

    int status_print = print(n_roots, root1, root2);
    if (status_print == EXIT_FAILURE) {
        return EXIT_FAILURE;
    }

#endif

    return EXIT_SUCCESS;
}
