#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N;

    printf("Quantos numeros vai digitar? ");
    scanf("%d", &N);

    int vet[N];

    for (int i = 0; i < N ; i++){
        printf("Digite um numero: ");
        scanf("%d", &vet[i]);
    }

    printf("\nNumeros negativos:\n");
    for (int i = 0; i < N ; i++){

        if (vet[i] < 0){
         printf("%d\n", vet[i]);
        }
    }

    return 0;
}
