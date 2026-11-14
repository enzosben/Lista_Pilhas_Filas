#include <stdio.h>
#include <stdlib.h>

#define MAX 5  /* tamanho maximo do historico */

typedef struct {
    int itens[MAX];
    int topo;
} Pilha;

void iniciarPilha(Pilha *p) {
    p->topo = -1;
}

int empilhar(Pilha *p, int valor) {
    if (p->topo == MAX - 1) return 0;
    p->itens[++p->topo] = valor;
    return 1;
}

int desempilhar(Pilha *p, int *valor) {
    if (p->topo == -1) return 0;
    *valor = p->itens[p->topo--];
    return 1;
}

void alterarValor(Pilha *hist, int *atual, int novo) {
    if (!empilhar(hist, *atual)) {
        printf("\n[ERRO] Historico cheio! Alteracao rejeitada. Valor atual continua %d.\n", *atual);
        return;
    }
    printf("\n[OK] Valor alterado de %d para %d.\n", *atual, novo);
    *atual = novo;
}

void desfazer(Pilha *hist, int *atual) {
    int anterior;
    if (!desempilhar(hist, &anterior)) {
        printf("\n[ERRO] Nao ha historico: nao e possivel desfazer.\n");
        return;
    }
    printf("\n[OK] Desfeito: valor voltou de %d para %d.\n", *atual, anterior);
    *atual = anterior;
}

void consultar(const Pilha *hist, int atual) {
    printf("\nValor atual: %d\n", atual);
    if (hist->topo == -1) {
        printf("Historico: vazio\n");
    } else {
        printf("Historico (mais recente -> mais antigo): ");
        for (int i = hist->topo; i >= 0; i--) {
            printf("%d%s", hist->itens[i], i > 0 ? ", " : "");
        }
        printf("\n");
    }
}

int main() {
    Pilha historico;
    iniciarPilha(&historico);
    int atual = 0, opcao, novo;

    do {
        printf("\n=== VALOR COM DESFAZER ===\n");
        printf("1. Alterar valor\n");
        printf("2. Desfazer\n");
        printf("3. Consultar valor e historico\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        if (scanf("%d", &opcao) != 1) {
            int c; while ((c = getchar()) != '\n' && c != EOF);
            if (c == EOF) break;
            opcao = -1;
        }

        switch (opcao) {
            case 1:
                printf("Novo valor: ");
                if (scanf("%d", &novo) == 1) alterarValor(&historico, &atual, novo);
                else { int c; while ((c = getchar()) != '\n' && c != EOF); printf("Valor invalido!\n"); }
                break;
            case 2: desfazer(&historico, &atual); break;
            case 3: consultar(&historico, atual); break;
            case 0: printf("Saindo...\n"); break;
            default: printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}
