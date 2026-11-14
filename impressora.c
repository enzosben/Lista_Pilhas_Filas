#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct {
    int itens[MAX];
    int inicio;
    int fim;
} Fila;

void iniciarFila(Fila *f) {
    f->inicio = 0;
    f->fim = 0;
}

int filaVazia(const Fila *f) { return f->inicio == f->fim; }

int enfileirar(Fila *f, int valor) {
    if (f->fim == MAX) return 0;
    f->itens[f->fim++] = valor;
    return 1;
}

int desenfileirar(Fila *f, int *valor) {
    if (filaVazia(f)) return 0;
    *valor = f->itens[f->inicio++];
    return 1;
}

void imprimirProximo(Fila *f) {
    int id;
    if (desenfileirar(f, &id))
        printf("\n[IMPRESSO] Trabalho %d\n", id);
    else
        printf("\n[ERRO] Nao ha trabalhos pendentes.\n");
}

void listarPendentes(const Fila *f) {
    if (filaVazia(f)) {
        printf("\nNenhum trabalho pendente.\n");
    } else {
        printf("\nPendentes (ordem de impressao): ");
        for (int i = f->inicio; i < f->fim; i++) printf("[%d] ", f->itens[i]);
        printf("\n");
    }
}

/* Remove e apresenta cada trabalho, um a um */
void imprimirTodos(Fila *f) {
    int id;
    if (filaVazia(f)) {
        printf("\nNao ha trabalhos para imprimir.\n");
        return;
    }
    printf("\n--- Imprimindo todos os trabalhos ---\n");
    while (desenfileirar(f, &id)) {
        printf("[IMPRESSO] Trabalho %d\n", id);
    }
    printf("--- Fila de impressao vazia ---\n");
}

int main() {
    Fila fila;
    iniciarFila(&fila);
    int opcao, id;

    do {
        printf("\n=== FILA DE IMPRESSAO ===\n");
        printf("1. Adicionar trabalho\n");
        printf("2. Imprimir proximo\n");
        printf("3. Listar pendentes\n");
        printf("4. Imprimir todos\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        if (scanf("%d", &opcao) != 1) {
            int c; while ((c = getchar()) != '\n' && c != EOF);
            if (c == EOF) break;
            opcao = -1;
        }

        switch (opcao) {
            case 1:
                printf("Identificador do trabalho: ");
                if (scanf("%d", &id) == 1) {
                    if (enfileirar(&fila, id)) printf("\n[OK] Trabalho %d adicionado.\n", id);
                    else printf("\n[ERRO] Fila de impressao cheia!\n");
                } else {
                    int c; while ((c = getchar()) != '\n' && c != EOF);
                    printf("Valor invalido!\n");
                }
                break;
            case 2: imprimirProximo(&fila); break;
            case 3: listarPendentes(&fila); break;
            case 4: imprimirTodos(&fila); break;
            case 0: printf("Saindo...\n"); break;
            default: printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}
