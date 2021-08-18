#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "TXLib.h"

int main(void)
{
    float a = 0, b = 0, c = 0;
    float d = 0;
    float root1 = 0, root2 = 0;

    printf("The program solves quadratic equations\n");
    printf("Enter the coefficients:");
    scanf("%f %f %f", &a, &b, &c);

    if(a == 0)
    {
        if(b == 0 || c == 0)
        {
                printf("The quadratic equation has one root: %f\n", 0);
        }
        else
        {
            printf("The quadratic equation has one root: %f\n", (c / b));
        }
    }
    else
    {
        d =  pow(b, 2) - 4 * a * c;

        if(d < 0)
        {
            printf("The quadratic equation has no roots\n");
        }
        else
        {
            root1 =  ((- b) + sqrtf(d)) / (2 * a);
            root2 = ((- b) - sqrtf(d)) / (2 * a);
            if(root1 == root2)
            {
                printf("The quadratic equation has one root: %f\n", root1);
            }
            else
            {
                printf("The quadratic equation has two roots\nFirst: %f\nSecond: %f\n", root1, root2);
            }
        }
    }
    return EXIT_SUCCESS;
}
