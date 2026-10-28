#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N;
    double soma, media;

    printf("Quantos numeros vai digitar? ");
    scanf("%d", &N);

    double vet[N];

//  for para armazenar o vetor
    for(int i = 0; i < N; i++ ){

        printf("Digite um numero: ");
        scanf("%lf", &vet[i]);

    }

// for para ler e imprimir as posições do vetor
    printf("\nValores = ");
    for(int i=0; i< N; i++ ){

        printf("%.1lf ", vet[i]);
    }
    printf("\n");

//   for para soma de todas as posições do vetor
     for(int i=0; i< N; i++ ){

        soma = soma + vet[i];
    }
    printf("\nsoma = %.2lf\n", soma);

//  media dos valores do vetor
    media = soma / N;
    printf("media = %.2lf\n", media);

    return 0;
}
