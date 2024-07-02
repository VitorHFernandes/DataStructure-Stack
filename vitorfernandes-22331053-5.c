#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX_SIZE 100

struct Pilha {
    char itens[MAX_SIZE][MAX_SIZE];
    int topo;
};

void inicializar(struct Pilha *p) {
    p->topo = -1;
}

int vazia(struct Pilha *p) {
    return p->topo == -1;
}

int cheia(struct Pilha *p) {
    return p->topo == MAX_SIZE - 1;
}

void push(struct Pilha *p, const char *item) {
    if (cheia(p)) {
        printf("\nErro: Pilha cheia, não é possível adicionar a palavra '%s'.\n", item);
    } else {
        strcpy(p->itens[++(p->topo)], item);
    }
}

char* pop(struct Pilha *p) {
    if (vazia(p)) {
        printf("\nErro: Pilha vazia, não é possível remover uma palavra.\n");
        return NULL;
    } else {
        return p->itens[(p->topo)--];
    }
}

char* topo(struct Pilha *p) {
    if (vazia(p)) {
        return NULL;
    } else {
        return p->itens[p->topo];
    }
}

void limpar(struct Pilha *p) {
    p->topo = -1;
}

void inverte(char *palavra) {
    struct Pilha p;
    inicializar(&p);
    int len = strlen(palavra);

    for (int i = 0; i < len; i++) {
        push(&p, &palavra[i]);
    }

    for (int i = 0; i < len; i++) {
        palavra[i] = *pop(&p);
    }
}

int main() {
    system("cmd /c CHCP 65001"); // Altera a página de código do console ativo para UTF-8.
    setlocale(LC_ALL, "Portuguese_Brasil"); // Define todas as categorias, retornando apenas a cadeia de caracteres.

    struct Pilha p;
    inicializar(&p);

    while (1) {
        printf("\nDigite 1 para adicionar uma palavra à pilha\n");
        printf("Digite 2 para desempilhar a palavra\n");
        printf("Digite 3 para limpar a pilha\n");
        printf("Digite 4 para exibir o topo da pilha\n");
        printf("Digite 5 para inverter uma palavra\n");
        printf("Digite 0 para sair\n");

        int opcao;
        printf("\nEscolha uma opção: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1: {
                char palavra[MAX_SIZE];
                printf("\nDigite a palavra a ser adicionada: ");
                fgets(palavra, MAX_SIZE, stdin);
                palavra[strcspn(palavra, "\n")] = '\0';
                push(&p, palavra);
                printf("\nPalavra '%s' adicionada à pilha.\n", palavra);
                break;
            }
            case 2: {
                char* palavra = pop(&p);
                if (palavra != NULL) {
                    printf("\nPalavra desempilhada: '%s'\n", palavra);
                } else {
                    printf("\nPilha vazia. Nenhum elemento para mostrar.\n");
                }
                break;
            }
            case 3: {
                limpar(&p);
                printf("\nPilha limpa.\n");
                break;
            }
            case 4: {
                char* top = topo(&p);
                if (top == NULL) {
                    printf("\nPilha vazia. Nenhum elemento para mostrar.\n");
                } else {
                    printf("\nElemento no topo da pilha: %s\n", top);
                }
                break;
            }
            case 5: {
                char palavra[MAX_SIZE];
                printf("\nDigite a palavra a ser invertida: ");
                fgets(palavra, MAX_SIZE, stdin);
                palavra[strcspn(palavra, "\n")] = '\0';
                inverte(palavra);
                printf("\nPalavra invertida: '%s'\n", palavra);
                break;
            }
            case 0: {
                return 0;
            }
            default: {
                printf("\nOpção inválida. Digite 1, 2, 3, 4, 5 ou 0.\n");
            }
        }
    }

    return 0;
}