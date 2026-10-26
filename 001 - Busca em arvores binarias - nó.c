
#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *esquerda;
    struct No *direita;
} No;

// Prototipos das funcoes
No *incluir(No *raiz, int valor);
No *remover(No *raiz, int valor);
No *menorNo(No *raiz);
No *buscar(No *raiz, int valor);
void preOrdem(No *raiz);
void emOrdem(No *raiz);
void posOrdem(No *raiz);
void exibirArvore(No *raiz, int nivel);
void liberarArvore(No *raiz);
void limparTela(void);
void limparEntrada(void);
void aguardarEnter(void);

// Limpa a tela no Windows
void limparTela(void) {
    system("cls");
}

// Descarta caracteres que ficaram na entrada
void limparEntrada(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
}

// Aguarda o usuario pressionar ENTER
void aguardarEnter(void) {
    printf("\nPressione ENTER para continuar...");
    getchar();
}

// Inclui um valor respeitando as regras da arvore binaria
No *incluir(No *raiz, int valor) {
    if (raiz == NULL) {
        No *novo = malloc(sizeof(No));

        if (novo == NULL) {
            printf("Erro: nao foi possivel alocar memoria!\n");
            return NULL;
        }

        novo->valor = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;

        return novo;
    }

    if (valor < raiz->valor) {
        raiz->esquerda = incluir(raiz->esquerda, valor);
    } else if (valor > raiz->valor) {
        raiz->direita = incluir(raiz->direita, valor);
    }

    return raiz;
}

// Encontra o menor valor de uma subarvore
No *menorNo(No *raiz) {
    while (raiz != NULL && raiz->esquerda != NULL) {
        raiz = raiz->esquerda;
    }

    return raiz;
}

// Remove um valor da arvore
No *remover(No *raiz, int valor) {
    if (raiz == NULL) {
        return NULL;
    }

    if (valor < raiz->valor) {
        raiz->esquerda = remover(raiz->esquerda, valor);
    } else if (valor > raiz->valor) {
        raiz->direita = remover(raiz->direita, valor);
    } else {
        // No sem filho esquerdo
        if (raiz->esquerda == NULL) {
            No *temporario = raiz->direita;
            free(raiz);
            return temporario;
        }

        // No sem filho direito
        if (raiz->direita == NULL) {
            No *temporario = raiz->esquerda;
            free(raiz);
            return temporario;
        }

        // No com dois filhos: usa o menor da subarvore direita
        No *temporario = menorNo(raiz->direita);
        raiz->valor = temporario->valor;
        raiz->direita = remover(raiz->direita, temporario->valor);
    }

    return raiz;
}

// Pesquisa um valor na arvore
No *buscar(No *raiz, int valor) {
    while (raiz != NULL) {
        if (valor == raiz->valor) {
            return raiz;
        }

        if (valor < raiz->valor) {
            raiz = raiz->esquerda;
        } else {
            raiz = raiz->direita;
        }
    }

    return NULL;
}

// Percurso: raiz, esquerda, direita
void preOrdem(No *raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->valor);
        preOrdem(raiz->esquerda);
        preOrdem(raiz->direita);
    }
}

// Percurso: esquerda, raiz, direita
void emOrdem(No *raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->esquerda);
        printf("%d ", raiz->valor);
        emOrdem(raiz->direita);
    }
}

// Percurso: esquerda, direita, raiz
void posOrdem(No *raiz) {
    if (raiz != NULL) {
        posOrdem(raiz->esquerda);
        posOrdem(raiz->direita);
        printf("%d ", raiz->valor);
    }
}



// Libera a memoria de todos os nos
void liberarArvore(No *raiz) {
    if (raiz != NULL) {
        liberarArvore(raiz->esquerda);
        liberarArvore(raiz->direita);
        free(raiz);
    }
}

int main(void) {
    No *raiz = NULL;
    int opcao, valor;

    do {
        printf("\n===== ARVORE BINARIA DE BUSCA =====\n");
        printf("1. Incluir no\n");
        printf("2. Remover no\n");
        printf("3. Buscar pre-ordem\n");
        printf("4. Buscar em ordem\n");
        printf("5. Buscar pos-ordem\n");
        printf("6. Pesquisar um valor\n");
        printf("0. Encerrar\n");
        printf("Escolha uma opcao: ");

        if (scanf("%d", &opcao) != 1) {
            printf("Opcao invalida! Digite um numero.\n");
            limparEntrada();
            aguardarEnter();
            limparTela();
            continue;
        }

        limparEntrada();

        switch (opcao) {
            case 1: {
                printf("Digite o valor do no: ");

                if (scanf("%d", &valor) != 1) {
                    printf("Valor invalido!\n");
                    limparEntrada();
                    break;
                }

                limparEntrada();

                if (buscar(raiz, valor) != NULL) {
                    printf("Esse valor ja existe na arvore!\n");
                } else {
                    No *novaRaiz = incluir(raiz, valor);

                    // Atualiza a raiz apos a inclusao
                    if (novaRaiz != NULL || raiz == NULL) {
                        raiz = novaRaiz;
                        if (buscar(raiz, valor) != NULL) {
                            printf("No incluido com sucesso!\n");
                        }
                    }
                }
                break;
            }

            case 2: {
                if (raiz == NULL) {
                    printf("A arvore esta vazia!\n");
                    break;
                }

                printf("\n===== NOS DA ARVORE =====\n");
                printf("Valores disponiveis: ");
                emOrdem(raiz);
                printf("\n");

                printf("Digite o valor que deseja remover: ");

                if (scanf("%d", &valor) != 1) {
                    printf("Valor invalido!\n");
                    limparEntrada();
                    break;
                }

                limparEntrada();

                if (buscar(raiz, valor) == NULL) {
                    printf("Valor nao encontrado na arvore!\n");
                } else {
                    raiz = remover(raiz, valor);
                    printf("No removido com sucesso!\n");
                }
                break;
            }

            case 3:
                if (raiz == NULL) {
                    printf("A arvore esta vazia!\n");
                } else {
                    printf("Percurso pre-ordem: ");
                    preOrdem(raiz);
                    printf("\n");
                }
                break;

            case 4:
                if (raiz == NULL) {
                    printf("A arvore esta vazia!\n");
                } else {
                    printf("Percurso em ordem: ");
                    emOrdem(raiz);
                    printf("\n");
                }
                break;

            case 5:
                if (raiz == NULL) {
                    printf("A arvore esta vazia!\n");
                } else {
                    printf("Percurso pos-ordem: ");
                    posOrdem(raiz);
                    printf("\n");
                }
                break;



            case 6:
                if (raiz == NULL) {
                    printf("A arvore esta vazia!\n");
                    break;
                }

                printf("Digite o valor que deseja pesquisar: ");

                if (scanf("%d", &valor) != 1) {
                    printf("Valor invalido!\n");
                    limparEntrada();
                    break;
                }

                limparEntrada();

                if (buscar(raiz, valor) != NULL) {
                    printf("Valor %d encontrado na arvore!\n", valor);
                } else {
                    printf("Valor %d nao encontrado na arvore!\n", valor);
                }
                break;

            case 0:
                printf("Encerrando o programa...\n");
                break;

            default:
                printf("Opcao inexistente! Escolha uma opcao do menu.\n");
        }

        if (opcao != 0) {
            aguardarEnter();
            limparTela();
        }

    } while (opcao != 0);

    liberarArvore(raiz);

    return 0;
}
