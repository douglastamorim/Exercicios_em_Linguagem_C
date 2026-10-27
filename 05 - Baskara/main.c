#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{

    double A, B, C, X1, X2, delta;

    printf("Coeeficiente a: ");
    scanf("%lf",&A);

    printf("Coeeficiente b: ");
    scanf("%lf",&B);

    printf("Coeeficiente c: ");
    scanf("%lf",&C);

    delta = (B * B)- 4 * A * C;

    if (A == 0 || delta < 0){
      printf("Esta equacao nao possui raizes reais\n");
    }
    else{
      X1 = (-B + sqrt(delta)) / (2*A);
      X2 = (-B - sqrt(delta)) / (2*A);
      printf("X1 %.4lf\n", X1);
      printf("X2 %.4lf\n", X2);
    }




    return 0;
}
