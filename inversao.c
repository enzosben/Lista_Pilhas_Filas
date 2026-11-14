#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct {
    int itens[MAX];
    int topo;
} Pilha;

void iniciarPilha(Pilha *p) {
    p->topo = -1;
}

/* Retorna 1 se empilhou, 0 se cheia */
int empilhar(Pilha *p, int valor) {
    if (p->topo == MAX - 1) return 0;
    p->itens[++p->topo] = valor;
    return 1;
}

/* Retorna 1 se desempilhou (valor em *valor), 0 se vazia */
int desempilhar(Pilha *p, int *valor) {
    if (p->topo == -1) return 0;
    *valor = p->itens[p->topo--];
    return 1;
}

int main() {
    Pilha p;
    iniciarPilha(&p);
    int n, v;

    do {
        printf("Quantos numeros deseja inverter (1 a %d)? ", MAX);
        if (scanf("%d", &n) != 1) {
            int c; while ((c = getchar()) != '\n' && c != EOF);
            if (c == EOF) return 1;
            n = 0;
        }
        if (n < 1 || n > MAX) printf("Quantidade invalida!\n");
    } while (n < 1 || n > MAX);

    for (int i = 0; i < n; i++) {
        printf("Numero %d: ", i + 1);
        if (scanf("%d", &v) != 1) return 1;
        empilhar(&p, v);
    }

    printf("Sequencia invertida: ");
    int primeiro = 1;
    while (desempilhar(&p, &v)) {
        printf(primeiro ? "%d" : ", %d", v);
        primeiro = 0;
    }
    printf("\n");

    printf("Pilha vazia ao final? %s\n", p.topo == -1 ? "Sim" : "Nao");
    return 0;
}
