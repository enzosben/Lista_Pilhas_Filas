#include <stdio.h>
#include <stdlib.h>

#define MAX 5

/* inicio permanece sempre 0 (fila com reaproveitamento de posicoes) */
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

/* Retorna 1 e devolve o id em *valor; 0 se vazia */
int desenfileirar(Fila *f, int *valor) {
    if (filaVazia(f)) return 0;
    *valor = f->itens[f->inicio];
    for (int i = 0; i < f->fim - 1; i++) {
        f->itens[i] = f->itens[i + 1];
    }
    f->fim--;
    return 1;
}

void mostrarFila(const Fila *f) {
    if (filaVazia(f)) {
        printf("\nNenhuma tarefa na fila.\n");
    } else {
        printf("\nInicio -> ");
        for (int i = f->inicio; i < f->fim; i++) printf("[%d] ", f->itens[i]);
        printf("<- Fim\n");
    }
}

void executarRodada(Fila *f) {
    int id, resp;
    if (!desenfileirar(f, &id)) {
        printf("\n[ERRO] Nao ha tarefas para executar.\n");
        return;
    }
    printf("\nExecutando a tarefa %d.\n", id);
    do {
        printf("A tarefa %d foi concluida? (1 = sim, 0 = nao): ", id);
        if (scanf("%d", &resp) != 1) {
            int c; while ((c = getchar()) != '\n' && c != EOF);
            if (c == EOF) resp = 1; else resp = -1;
        }
    } while (resp != 0 && resp != 1);

    if (resp == 1) {
        printf("[OK] Tarefa %d concluida e removida da fila.\n", id);
    } else {
        enfileirar(f, id);  /* sempre cabe: acabamos de liberar uma posicao */
        printf("[OK] Tarefa %d voltou para o final da fila.\n", id);
    }
}

int main() {
    Fila fila;
    iniciarFila(&fila);
    int opcao, id;

    do {
        printf("\n=== RODIZIO DE TAREFAS ===\n");
        printf("1. Adicionar tarefa\n");
        printf("2. Executar uma rodada\n");
        printf("3. Mostrar fila\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        if (scanf("%d", &opcao) != 1) {
            int c; while ((c = getchar()) != '\n' && c != EOF);
            if (c == EOF) break;
            opcao = -1;
        }

        switch (opcao) {
            case 1:
                printf("Identificador da tarefa: ");
                if (scanf("%d", &id) == 1) {
                    if (enfileirar(&fila, id)) printf("\n[OK] Tarefa %d adicionada.\n", id);
                    else printf("\n[ERRO] Fila cheia!\n");
                } else {
                    int c; while ((c = getchar()) != '\n' && c != EOF);
                    printf("Valor invalido!\n");
                }
                break;
            case 2: executarRodada(&fila); break;
            case 3: mostrarFila(&fila); break;
            case 0: printf("Saindo...\n"); break;
            default: printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}
