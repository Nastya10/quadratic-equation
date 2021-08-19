#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "TXLib.h"

int solve_linear(float coef1, float coef2, float* root);
int solve_square(float a, float b, float c, float* root1, float* root2);

const int INF_SOLUTIONS = 3;

int main(void)
{
    float a = 0, b = 0, c = 0;
    float root1 = 0, root2 = 0;

    printf("The program solves quadratic equations\n");
    printf("Enter the coefficients a, b and c:");

    if(scanf("%f %f %f", &a, &b, &c) != 3)
    {
        printf("ERROR: Incorrect number of numbers entered\n");
        return EXIT_FAILURE;
    }

    int n_roots = solve_square(a, b, c, &root1, &root2);
    switch(n_roots)
    {
        case 0:
            printf("The quadratic equation has no roots\n");
            break;
        case 1:
            printf("The quadratic equation has one root: %f\n", root1);
            break;
        case 2:
            printf("The quadratic equation has two roots\nFirst: %f\nSecond: %f\n", root1, root2);
            break;
        case INF_SOLUTIONS:
            printf("The equation has an infinite number of solutions\n");
            break;
        default:
            printf("ERROR; solve_square returned a strange number of roots: %d\n", n_roots);
            return EXIT_FAILURE;

    }

    return EXIT_SUCCESS;
}

int solve_square(float a, float b, float c, float* root1, float* root2)
{
    float d = 0;
    float parab_vert = 0;

    if(a == 0)
    {
        int n_roots = solve_linear(b, c, root1);
        if(n_roots == 1)
            *root2 = *root1;
        return n_roots;
    }
    else
    {
        d =  pow(b, 2) - 4 * a * c;
        parab_vert = -b / (2 * a);

        if(d < 0)
        {
            return 0;
        }
        if(d == 0)
        {
            *root1 = *root2 = parab_vert;
            return 1;
        }
        if(d > 0)
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
    if(b == 0)
    {
        if(c == 0)
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
