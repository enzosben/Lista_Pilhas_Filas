#include <stdio.h>
#include <stdlib.h>

#define MAX 32  /* int de 32 bits: no maximo 31 digitos binarios para valores >= 0 */

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

int main() {
    Pilha p;
    iniciarPilha(&p);
    int numero, n, bit;

    printf("Digite um inteiro nao negativo: ");
    if (scanf("%d", &numero) != 1) {
        printf("Entrada invalida!\n");
        return 1;
    }
    if (numero < 0) {
        printf("[ERRO] Numeros negativos nao sao aceitos.\n");
        return 1;
    }

    n = numero;
    if (n == 0) {
        empilhar(&p, 0);  /* caso especial: 0 em binario e 0 */
    }
    while (n > 0) {
        empilhar(&p, n % 2);
        n /= 2;
    }

    printf("%d em binario: ", numero);
    while (desempilhar(&p, &bit)) {
        printf("%d", bit);
    }
    printf("\n");
    return 0;
}
