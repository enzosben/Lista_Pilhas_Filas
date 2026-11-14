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
        printf("\n[ERRO] A fila esta vazia! Ninguem para atender.\n");
    } else {
        printf("\n[SUCESSO] %d foi atendido e saiu da fila!\n", f->itens[f->inicio]);
        f->inicio++;
    }
}

void mostrarFila(const Fila *f) {
    if (f->inicio == f->fim) {
        printf("\nA fila esta vazia.\n");
    } else {
        printf("\n--- ESTADO ATUAL DA FILA ---\n");
        printf("Inicio -> ");
        for (int i = f->inicio; i < f->fim; i++) {
            printf("[%d] ", f->itens[i]);
        }
        printf("<- Fim\n");
    }
}

/* Consulta o primeiro elemento sem remove-lo */
void consultarProximo(const Fila *f) {
    if (f->inicio == f->fim) {
        printf("\nA fila esta vazia: nao ha proximo elemento.\n");
    } else {
        printf("\nProximo elemento: %d\n", f->itens[f->inicio]);
    }
}

/* Quantidade calculada com inicio e fim (sem contador extra) */
void mostrarQuantidade(const Fila *f) {
    printf("\nElementos aguardando: %d\n", f->fim - f->inicio);
}

int main() {
    Fila minhaFila;
    iniciarFila(&minhaFila);
    int opcao, valor;

    do {
        printf("\n=== MENU FILA (FIFO) ===\n");
        printf("1. Enfileirar (Entrar na fila)\n");
        printf("2. Desenfileirar (Atender)\n");
        printf("3. Mostrar Fila\n");
        printf("4. Consultar proximo elemento\n");
        printf("5. Mostrar quantidade de elementos\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        if (scanf("%d", &opcao) != 1) {
            int c; while ((c = getchar()) != '\n' && c != EOF);
            if (c == EOF) break;
            opcao = -1;
        }

        switch (opcao) {
            case 1:
                printf("Digite o valor para entrar na fila: ");
                if (scanf("%d", &valor) == 1) enfileirar(&minhaFila, valor);
                else { int c; while ((c = getchar()) != '\n' && c != EOF); printf("Valor invalido!\n"); }
                break;
            case 2: desenfileirar(&minhaFila); break;
            case 3: mostrarFila(&minhaFila); break;
            case 4: consultarProximo(&minhaFila); break;
            case 5: mostrarQuantidade(&minhaFila); break;
            case 0: printf("Saindo...\n"); break;
            default: printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}
