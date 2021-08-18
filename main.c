#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "TXLib.h"

int main(void)
{
    float a = 0, b = 0, c = 0;
    float d = 0;
    float root1 = 0, root2 = 0;

    printf("Программа решает квадратные уравнения\n");
    printf("Введите коэффиценты:");
    scanf("%f %f %f", &a, &b, &c);

    d =  pow(b, 2) - 4 * a * c;

    if(d < 0)
    {
        printf("Квадратное уравнение не имеет корней\n");
    }
    else
    {
        root1 =  ((- b) + sqrtf(d)) / (2 * a);
        root2 = ((- b) - sqrtf(d)) / (2 * a);
        if(root1 == root2)
        {
            printf("У квадратного уравнения есть один корень: %f\n", root1);
        }
        else
        {
            printf("У квадратного уравнения есть два корня\nПервый: %f\nВторой: %f\n", root1, root2);
        }
    }

    return EXIT_SUCCESS;
}

