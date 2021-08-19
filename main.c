#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "TXLib.h"

int solution_linear(float coef1, float coef2, float* root);
int solution_square(float a, float b, float c, float* root1, float* root2);

const int INFINITY_SOLUTIONS = 3;

int main(void)
{
    float a = 0, b = 0, c = 0;
    float d = 0;
    float root1 = 0, root2 = 0;

    printf("The program solves quadratic equations\n");
    printf("Enter the coefficients:");
    scanf("%f %f %f", &a, &b, &c);

    int n_roots = solution_square(a, b, c, &root1, &root2);
    printf("%d, %f", n_roots, root1);

    return EXIT_SUCCESS;
}

int solution_square(float a, float b, float c, float* root1, float* root2)
{
    float d = 0;

    if(a == 0)
    {
        return solution_linear(b, c, *root1);
    }
    else
    {
        d =  pow(b, 2) - 4 * a * c;

        if(d < 0)
        {
            return 0;
        }
        else
        {
            *root1 =  ((- b) + sqrtf(d)) / (2 * a);
            *root2 = ((- b) - sqrtf(d)) / (2 * a);
            if(*root1 == *root2)
            {
                return 1;
            }
            else
            {
                return 2;
            }
        }
    }
}

int solution_linear(float coef1, float coef2, float* root)
{
    if(coef1 == 0)
    {
        if(coef2 == 0)
        {
            return INFINITY_SOLUTIONS;
        }
        else
        {
            return 0;
        }

    }
    else
    {
        *root = (-coef2)/coef1;
        return 1;
    }
}
