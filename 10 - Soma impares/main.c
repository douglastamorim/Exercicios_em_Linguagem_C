#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, x, y, soma, troca;

    soma = 0;

    printf("Digite dois numeros:\n");
    scanf("%d", &x);
    scanf("%d", &y);

    if (x > y){
       troca = x;
       x = y;
       y = troca;
    }

    for (i = x +1; i < y; i++){
        if(i % 2 != 0){
            soma = soma + i;
        }
    }

    printf("Soma dos impares = %d\n", soma);
   
    return 0;
}
