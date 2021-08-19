#define NDEBUG
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include "TXLib.h"

int solve_square(float a, float b, float c, float* root1, float* root2);
int solve_linear(float coef1, float coef2, float* root);
bool equality_fractions(float num1, float num2);

const int INF_SOLUTIONS = 3;

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

int solve_square(float a, float b, float c, float* root1, float* root2)
{
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));

    assert(root1 != NULL);
    assert(root2 != NULL);
    assert(root1 != root2);

    if(equality_fractions(a, 0))
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
        else if(equality_fractions(d, 0))
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

    if(equality_fractions(b, 0))
    {
        if(equality_fractions(c, 0))
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

bool equality_fractions(float num1, float num2)
{
        float epsilon = pow(10, -7);
        return fabsf(fabsf(num1) - fabsf(num2)) <= epsilon;
}
