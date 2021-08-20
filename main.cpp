/**
 * @file main.cpp
 * @brief Solving Quadratic Equations
 * @date не знаю когда это закончится :D
 */

#define NDEBUG

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * Denotes an infinite number of roots
 */
const int INF_ROOTS = 3;

/**
 * Epsilon is a constant that determines the maximum
 * difference between two floats to consider them equal
 */
const float EPSILON = 10E-8;

/**
 * Solves a square equation ax^2 + bx + c = 0
 *
 * @param[in]   a quadratic coefficient
 * @param[in]   b linear coefficient
 * @param[in]   c free member
 * @param[out]  root1 the larger root of the equation is placed
 * @param[out]  root2 the smaller root of the equation is placed
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
 * @param[in]   b linear coefficient
 * @param[in]   c coefficient
 * @param[out]  free member
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
 * @param[in]  float1
 * @param[in]  float2
 *
 * @return Is it true that the floats are equal
 */
bool floats_are_equal(float float1, float float2);

int main(void)
{
    float a = 0, b = 0, c = 0;
    float root1 = 0, root2 = 0;

    printf("The program solves quadratic equations\n");
    printf("Enter the coefficients a, b and c:");

    if(scanf("%f %f %f", &a, &b, &c) != 3)
    {
        printf("INPUT ERROR: incorrect number of values\n");
        return EXIT_SUCCESS;
    }

    int n_roots = solve_square(a, b, c, &root1, &root2);
    switch(n_roots)
    {
        case 0:
            printf("The quadratic equation has no roots\n");
            break;
        case 1:
            printf("The quadratic equation has one root: %g\n", root1);
            break;
        case 2:
            printf("The quadratic equation has two roots\nFirst: %g\nSecond: %g\n", root1, root2);
            break;
        case INF_ROOTS:
            printf("The equation has an infinite number of solutions\n");
            break;
        default:
            printf("INTERNAL ERROR: solve_square returned a unexpected number of roots: %g\n", n_roots);
            return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

int solve_square(float a, float b, float c, float* root1, float* root2)
{
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));

    assert(root1 != NULL);
    assert(root2 != NULL);
    assert(root1 != root2);

    if(floats_are_equal(a, 0))
    {
        int n_roots = solve_linear(b, c, root1);
        if(n_roots == 1)
            *root2 = *root1;
        return n_roots;
    }
    else
    {
        float d =  pow(b, 2) - 4 * a * c;
        float parab_vert = -b / (2 * a);

        if(d < 0)
        {
            return 0;
        }
        else if(floats_are_equal(d, 0))
        {
            *root1 = *root2 = parab_vert;
            return 1;
        }
        else
        {
            float d_sqrt = sqrt(d);

            *root1 = parab_vert + d_sqrt / (2 * a);
            *root2 = parab_vert - d_sqrt / (2 * a);
            return 2;
        }
    }
}

int solve_linear(float b, float c, float* root)
{
    assert(isfinite(b));
    assert(isfinite(c));

    assert(root != NULL);

    if(floats_are_equal(b, 0))
    {
        if(floats_are_equal(c, 0))
        {
            return INF_ROOTS;
        }
        else
        {
            return 0;
        }

    }
    else
    {
        *root = -c / b;
        return 1;
    }
}

bool floats_are_equal(float float1, float float2)
{
        return fabsf(float1 - float2) <= EPSILON;
}
