#include <stdio.h>
#include <stdlib.h>
#include <math.h>

main()
{
    float first_coef, second_coef, third_coef;
    float discriminant;
    float first_root, second_root;

    scanf("%f %f %f", &first_coef, &second_coef, &third_coef);

    discriminant =  pow(second_coef, 2) - 4 * first_coef * third_coef;

    if(discriminant < 0)
    {
        printf("корней нет\n");
    }
    else
    {
        first_root =  ((- second_coef) + sqrtf(discriminant)) / (2 * first_coef);
        second_root = ((- second_coef) - sqrtf(discriminant)) / (2 * first_coef);
        printf("первый корень: %f\nвторой корень: %f\n", first_root, second_root);
    }
}
