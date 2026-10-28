#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, N, resultado;

    printf("Deseja a tabuada para qual valor? ");
    scanf("%d",&N);

    for(i = 1; i<=10; i++){
        resultado = N * i;
        printf("%d x %d = %d\n",N, i, resultado);
    }

    return 0;
}
