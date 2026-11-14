#include <stdio.h>
#include <stdlib.h>

#define MAX 5

/* inicio permanece sempre 0; fim indica a quantidade de elementos */
typedef struct {
    int itens[MAX];
    int inicio;
    int fim;
} Fila;

void iniciarFila(Fila *f) {
    f->inicio = 0;
    f->fim = 0;
}

void enfileirar(Fila *f, int valor) {
    if (f->fim == MAX) {
        printf("\n[ERRO] A fila esta cheia!\n");
    } else {
        f->itens[f->fim] = valor;
        f->fim++;
        printf("\n[SUCESSO] %d entrou no final da fila!\n", valor);
    }
}

void desenfileirar(Fila *f) {
    if (f->inicio == f->fim) {
        printf("\n[ERRO] A fila esta vazia!\n");
    } else {
        printf("\n[SUCESSO] %d saiu da fila!\n", f->itens[f->inicio]);
        /* desloca os restantes uma posicao para a esquerda */
        for (int i = 0; i < f->fim - 1; i++) {
            f->itens[i] = f->itens[i + 1];
        }
        f->fim--;
    }
}

void mostrarFila(const Fila *f) {
    if (f->inicio == f->fim) {
        printf("\nA fila esta vazia.\n");
    } else {
        printf("\nInicio -> ");
        for (int i = f->inicio; i < f->fim; i++) printf("[%d] ", f->itens[i]);
        printf("<- Fim\n");
    }
}

int main() {
    Fila fila;
    iniciarFila(&fila);
    int opcao, valor;

    do {
        printf("\n=== MENU FILA COM REAPROVEITAMENTO ===\n");
        printf("1. Enfileirar\n");
        printf("2. Desenfileirar\n");
        printf("3. Mostrar Fila\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        if (scanf("%d", &opcao) != 1) {
            int c; while ((c = getchar()) != '\n' && c != EOF);
            if (c == EOF) break;
            opcao = -1;
        }

        switch (opcao) {
            case 1:
                printf("Digite o valor: ");
                if (scanf("%d", &valor) == 1) enfileirar(&fila, valor);
                else { int c; while ((c = getchar()) != '\n' && c != EOF); printf("Valor invalido!\n"); }
                break;
            case 2: desenfileirar(&fila); break;
            case 3: mostrarFila(&fila); break;
            case 0: printf("Saindo...\n"); break;
            default: printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}
