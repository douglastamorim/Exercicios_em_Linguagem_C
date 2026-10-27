#include <stdio.h>
#include <stdlib.h>
#include<math.h>

int main()
{
    double Base, Altura, Area, Perimetro, Diagonal;

    printf("Base do retangulo: ");
    scanf("%lf",&Base);

    printf("Altura do retangulo: ");
    scanf("%lf",&Altura);

    Area = Base * Altura;
    Perimetro = (Base + Altura) * 2;
//  Diagonal = sqrt(Base * Base + Altura * Altura);
    Diagonal = sqrt(pow (Base, 2.0) + pow (Altura, 2.0));

    printf("Area = %.4lf\n",Area);
    printf("Perimetro = %.4lf\n",Perimetro);
    printf("Diagonal = %.4lf\n",Diagonal);



    return 0;
}
