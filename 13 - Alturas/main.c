#include <stdio.h>
#include <stdlib.h>



int main()
{
    int N, contadorAlt, contadorIda;
    double soma, mediaAltura, mediaIda;

    printf("Quantas pessoas serao digitadas? ");
    scanf("%d", &N);

    int idade[N];
    double altura[N];
    char nome[N][50];

    for(int i = 0; i < N; i++){
        printf("Dados da %da pessoa:\n",i+1);

        printf("Nome: ");
        fseek(stdin, 0, SEEK_END);
        gets(nome[i]);

        printf("Idade: ");
        scanf("%d", &idade[i]);

        printf("Altura: ");
        scanf("%lf", &altura[i]);
    }

    soma = 0;

    //calcula a media da altura das pessoas
    for(int i = 0; i < N; i++){
        soma = soma + altura[i];

    }

    mediaAltura = soma / N;
    printf("\nAltura media: %.2lf\n", mediaAltura);

    // calcula a media da idade
    contadorIda = 0;
    for(int i = 0; i < N; i++){

        if(idade[i]< 16){
          contadorIda = contadorIda + 1;

        }
    }

    mediaIda = contadorIda * 100.0 / N;
    printf("Pessoas com menos de 16 anos: %.1lf %%\n", mediaIda);

    //imprime os nome com menos de 16 anos na tela
    for(int i = 0; i < N; i++){

        if(idade[i] < 16){
           printf("%s\n", nome[i]);

        }
    }

    return 0;
}
