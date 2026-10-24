
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Limpa a tela do console no Windows
void limparTela(void) {
    system("cls");
}

// Estrutura que representa cada elemento (no) da lista
typedef struct No {
    int codigo;
    char nome[100];
    int quantidade;
    struct No *proximo; // Ponteiro para o proximo no
} No;

// Prototipos das funcoes
void listar(No *inicio);
No *remover(No *inicio);

// Funcao para limpar caracteres restantes do teclado
void limparEntrada(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
}

// Funcao para ler o nome do produto
void lerNome(char nome[], int tamanho) {
    fgets(nome, tamanho, stdin);

    // Remove a quebra de linha do final do texto
    nome[strcspn(nome, "\n")] = '\0';
}

// Funcao para localizar um produto pelo codigo
No *buscar(No *inicio, int codigo) {
    No *atual = inicio;

    // Percorre a lista ate encontrar o codigo ou chegar ao final
    while (atual != NULL) {
        if (atual->codigo == codigo) {
            return atual; // Retorna o no encontrado
        }

        atual = atual->proximo;
    }

    return NULL; // Retorna NULL se nao encontrar
}

// OPERACAO 1: INCLUSAO DE PRODUTO
No *incluir(No *inicio) {
    int codigo, quantidade;
    char nome[100];

    printf("Codigo do produto: ");
    if (scanf("%d", &codigo) != 1) {
        printf("Codigo invalido!\n");
        limparEntrada();
        return inicio;
    }
    limparEntrada();

    // Impede o cadastro de codigos repetidos
    if (buscar(inicio, codigo) != NULL) {
        printf("Ja existe um produto com esse codigo!\n");
        return inicio;
    }

    printf("Nome do produto: ");
    lerNome(nome, sizeof(nome));

    printf("Quantidade em estoque: ");
    if (scanf("%d", &quantidade) != 1 || quantidade < 0) {
        printf("Quantidade invalida!\n");
        limparEntrada();
        return inicio;
    }
    limparEntrada();

    // Reserva memoria dinamicamente para um novo no
    No *novo = malloc(sizeof(No));

    if (novo == NULL) {
        printf("Erro ao alocar memoria!\n");
        return inicio;
    }

    // Preenche os dados do novo no
    novo->codigo = codigo;
    strcpy(novo->nome, nome);
    novo->quantidade = quantidade;
    novo->proximo = NULL;

    // Se a lista estiver vazia, o novo no sera o primeiro
    if (inicio == NULL) {
        inicio = novo;
    } else {
        // Percorre a lista ate encontrar o ultimo no
        No *atual = inicio;

        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }

        // Conecta o ultimo no ao novo no
        atual->proximo = novo;
    }

    printf("Produto cadastrado com sucesso!\n");

    // Retorna o inicio atualizado da lista
    return inicio;
}

// OPERACAO 2: CONSULTA DE PRODUTO
void consultar(No *inicio) {
    int codigo;

    printf("Digite o codigo do produto: ");
    if (scanf("%d", &codigo) != 1) {
        printf("Codigo invalido!\n");
        limparEntrada();
        return;
    }
    limparEntrada();

    // Procura o produto na lista
    No *produto = buscar(inicio, codigo);

    if (produto == NULL) {
        printf("Produto nao encontrado!\n");
    } else {
        printf("\nCodigo: %d\n", produto->codigo);
        printf("Nome: %s\n", produto->nome);
        printf("Quantidade: %d\n", produto->quantidade);
    }
}


 // OPERACAO 3: ALTERACAO DE PRODUTO
void alterar(No *inicio) {
    int codigo, quantidade;
    char nome[100];

    printf("Digite o codigo do produto que deseja alterar: ");

    if (scanf("%d", &codigo) != 1) {
        printf("Codigo invalido!\n");
        limparEntrada();
        return;
    }

    limparEntrada();

    // Busca o produto pelo codigo informado
    No *produto = buscar(inicio, codigo);

    // Verifica se o produto existe
    if (produto == NULL) {
        printf("\nProduto nao encontrado!\n");
        return;
    }

    // Exibe os dados atuais para confirmar o produto
    printf("\n===== PRODUTO SELECIONADO =====\n");
    printf("Codigo atual: %d\n", produto->codigo);
    printf("Nome atual: %s\n", produto->nome);
    printf("Quantidade atual: %d\n", produto->quantidade);

    // Solicita os novos dados logo abaixo
    printf("\n===== ALTERAR DADOS =====\n");

    printf("Novo nome: ");
    lerNome(nome, sizeof(nome));

    printf("Nova quantidade: ");

    if (scanf("%d", &quantidade) != 1 || quantidade < 0) {
        printf("Quantidade invalida! Alteracao cancelada.\n");
        limparEntrada();
        return;
    }

    limparEntrada();

    // Atualiza os dados do produto encontrado
    strcpy(produto->nome, nome);
    produto->quantidade = quantidade;

    // Confirma a alteracao e mostra os dados atualizados
    printf("\nProduto alterado com sucesso!\n");
    printf("\n===== DADOS ATUALIZADOS =====\n");
    printf("Codigo: %d\n", produto->codigo);
    printf("Nome: %s\n", produto->nome);
    printf("Quantidade: %d\n", produto->quantidade);
}



// OPERACAO 4: REMOCAO DE PRODUTO
No *remover(No *inicio) {
    int codigo;

    // Exibe todos os produtos antes de solicitar a remocao
    printf("\n===== PRODUTOS CADASTRADOS =====\n");
    listar(inicio);

    // Se a lista estiver vazia, nao ha o que remover
    if (inicio == NULL) {
        return inicio;
    }

    // Solicita o codigo do produto que sera removido
    printf("\nDigite o codigo do produto que deseja remover: ");

    if (scanf("%d", &codigo) != 1) {
        printf("Codigo invalido!\n");
        limparEntrada();
        return inicio;
    }

    limparEntrada();

    No *atual = inicio;
    No *anterior = NULL;

    // Procura o produto pelo codigo informado
    while (atual != NULL && atual->codigo != codigo) {
        anterior = atual;
        atual = atual->proximo;
    }

    // Verifica se o codigo existe na lista
    if (atual == NULL) {
        printf("\nProduto nao encontrado!\n");
        return inicio;
    }

    // Mostra qual produto sera removido
    printf("\nProduto selecionado para remocao:\n");
    printf("Codigo: %d\n", atual->codigo);
    printf("Nome: %s\n", atual->nome);
    printf("Quantidade: %d\n", atual->quantidade);

    // Se o produto for o primeiro da lista,
    // atualiza o inicio para o proximo no
    if (anterior == NULL) {
        inicio = atual->proximo;
    } else {
        // Liga o no anterior ao proximo do no removido
        anterior->proximo = atual->proximo;
    }

    // Libera a memoria do no removido
    free(atual);

    printf("\nProduto removido com sucesso!\n");

    return inicio;
}


// OPERACAO 5: LISTAGEM DE TODOS OS PRODUTOS
void listar(No *inicio) {
    No *atual = inicio;

    if (atual == NULL) {
        printf("A lista esta vazia!\n");
        return;
    }

    printf("\n===== PRODUTOS CADASTRADOS =====\n");

    // Percorre e exibe todos os nos da lista
    while (atual != NULL) {
        printf("Codigo: %d | Nome: %s | Quantidade: %d\n",
               atual->codigo,
               atual->nome,
               atual->quantidade);

        atual = atual->proximo;
    }
}

// Libera a memoria de todos os nos ao encerrar o programa
void liberarLista(No *inicio) {
    while (inicio != NULL) {
        No *temporario = inicio;
        inicio = inicio->proximo;
        free(temporario);
    }
}


int main(void) {
    // Inicialmente, a lista esta vazia
    No *lista = NULL;
    int opcao;

    do {
        // Exibe o menu principal
        printf("\n===== SISTEMA DE LISTA ENCADEADA =====\n");
        printf("1 - Incluir produto\n");
        printf("2 - Consultar produto\n");
        printf("3 - Alterar produto\n");
        printf("4 - Remover produto\n");
        printf("5 - Listar todos os produtos\n");
        printf("0 - Sair\n");
        printf("\n");
        printf("Escolha uma opcao: ");

        if (scanf("%d", &opcao) != 1) {
            printf("Opcao invalida!\n");
            limparEntrada();

            printf("\nPressione ENTER para continuar...");
            getchar();

            limparTela();
            continue;
        }

        limparEntrada();

        // Executa a operacao escolhida
        switch (opcao) {
            case 1:
                lista = incluir(lista);
                break;

            case 2:
                consultar(lista);
                break;

            case 3:
                alterar(lista);
                break;

            case 4:
                lista = remover(lista);
                break;

            case 5:
                listar(lista);
                break;

            case 0:
                printf("Encerrando o programa...\n");
                break;

            default:
                printf("Opcao inexistente!\n");
        }

        // Aguarda o usuario ler o resultado
        if (opcao != 0) {
            printf("\nPressione ENTER para voltar ao menu...");
            getchar();

            // Limpa a tela antes de mostrar o menu novamente
            limparTela();
        }

    } while (opcao != 0);

    // Libera a memoria de todos os nos
    liberarLista(lista);

    return 0;
}

