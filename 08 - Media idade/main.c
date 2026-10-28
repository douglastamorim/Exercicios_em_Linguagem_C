#include <stdio.h>
#include <stdlib.h>

int main()
{
    int idade, soma, contador;
    double media;

    soma = 0;
    contador = 0;

    printf("Digite as idades:\n");
    scanf("%d", &idade);

    while(idade >= 0){

        soma = soma + idade;
        contador = contador + 1;

        scanf("%d", &idade);

    }

    if(contador == 0 ){
        printf("Impossivel Calcular!\n");
    }
    else{
        media = (double)soma / contador;
        printf("Media = %.2lf\n", media);

    }

    return 0;
}
