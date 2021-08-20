#define NDEBUG

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int solve_square(float a, float b, float c, float* root1, float* root2);
int solve_linear(float coef1, float coef2, float* root);

bool floats_are_equal(float num1, float num2);

const int INF_SOLUTIONS = 3;
const float EPSILON = pow(10, -7);

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
            printf("The quadratic equation has one root: %lg\n", root1);
            break;
        case 2:
            printf("The quadratic equation has two roots\nFirst: %lg\nSecond: %lg\n", root1, root2);
            break;
        case INF_SOLUTIONS:
            printf("The equation has an infinite number of solutions\n");
            break;
        default:
            printf("INTERNAL ERROR: solve_square returned a unexpected number of roots: %lg\n", n_roots);
            return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

/*
 * Solves a square equation ax^2 + bx + c = 0
 *
 * @param [in]  a   a - coefficient
 * @param [in]  b   b - coefficient
 * @param [in]  c   c - coefficient
 * @param [out]  root1   root1 - pointer to the first root
 * @param [out]  root2   root2 - pointer to the second root
 *
 * @return Number of roots
 *
 * @note In the case of an infinite number of roots returns INF_SOLUTIONS
 * @note Use functions solve_linear and floats_are_equal
 *
 */

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

/*
 * Solves a square equation bx + c = 0
 *
 * @param [in]  b   b - coefficient
 * @param [in]  c   c - coefficient
 * @param [out]  root   root - pointer to the root
 *
 * @return Number of roots
 *
 * @note In the case of an infinite number of roots returns INF_SOLUTIONS
 * @note Use function floats_are_equal
 *
 */

int solve_linear(float b, float c, float* root)
{
    assert(isfinite(b));
    assert(isfinite(c));

    assert(root != NULL);

    if(floats_are_equal(b, 0))
    {
        if(floats_are_equal(c, 0))
        {
            return INF_SOLUTIONS;
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

/*
 * Checks the equality of two float numbers
 *
 * @param [in]  num1   num1 - the first float number
 * @param [in]  num2   num2 - the second float number
 *
 * @return Is it true that the numbers are equal
 *
 * @note Epsilon is a constant that determines the maximum
 *       difference between the modules of numbers
 *
 */

bool floats_are_equal(float num1, float num2)
{
        return fabsf(fabsf(num1) - fabsf(num2)) <= EPSILON;
}
