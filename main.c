#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    float a, b, c;
    float discriminant;
    float first_root, second_root;

    scanf("%f %f %f", &a, &b, &c);

    discriminant =  pow(b, 2) - 4 * a * c;

    if(discriminant < 0)
    {
        printf("there are no roots\n");
    }
    else
    {
        first_root =  ((- b) + sqrtf(discriminant)) / (2 * a);
        second_root = ((- b) - sqrtf(discriminant)) / (2 * a);
        
        if(first_root == second_root)
        {
            printf("one root: %f\n", first_root);
        }
        else
        {
            printf("the first root: %f\nthe second root: %f\n", first_root, second_root);
        }
    }

    return EXIT_SUCCESS;
}

