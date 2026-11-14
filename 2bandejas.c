#include <stdio.h>
#include <stdlib.h>

#define MAX 5  /* capacidade maxima: 5 bandejas */

typedef struct {
    int itens[MAX];
    int topo;
} Pilha;

void iniciarPilha(Pilha *p) {
    p->topo = -1;
}

void adicionarBandeja(Pilha *p, int numero) {
    if (p->topo == MAX - 1) {
        printf("\n[ERRO] A pilha de bandejas esta cheia! Nao cabe a bandeja %d.\n", numero);
    } else {
        p->itens[++p->topo] = numero;
        printf("\n[OK] Bandeja %d colocada no topo da pilha.\n", numero);
    }
}

void retirarBandeja(Pilha *p) {
    if (p->topo == -1) {
        printf("\n[ERRO] Nao ha bandejas para retirar!\n");
    } else {
        printf("\n[OK] Bandeja %d retirada do topo.\n", p->itens[p->topo]);
        p->topo--;
    }
}

void consultarProxima(const Pilha *p) {
    if (p->topo == -1) {
        printf("\nNao ha bandejas disponiveis.\n");
    } else {
        printf("\nProxima bandeja disponivel: %d\n", p->itens[p->topo]);
    }
}

void mostrarBandejas(const Pilha *p) {
    if (p->topo == -1) {
        printf("\nNenhuma bandeja na pilha.\n");
    } else {
        printf("\n--- BANDEJAS (topo -> base) ---\n");
        for (int i = p->topo; i >= 0; i--) {
            printf("| Bandeja %4d |%s\n", p->itens[i], i == p->topo ? "  <- topo" : "");
        }
        printf("-------------------------------\n");
    }
}

int main() {
    Pilha bandejas;
    iniciarPilha(&bandejas);
    int opcao, numero;

    do {
        printf("\n=== LANCHONETE - PILHA DE BANDEJAS ===\n");
        printf("1. Adicionar bandeja\n");
        printf("2. Retirar bandeja do topo\n");
        printf("3. Consultar proxima bandeja disponivel\n");
        printf("4. Mostrar bandejas (topo -> base)\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        if (scanf("%d", &opcao) != 1) {
            int c; while ((c = getchar()) != '\n' && c != EOF);
            if (c == EOF) break;
            opcao = -1;
        }

        switch (opcao) {
            case 1:
                printf("Numero de identificacao da bandeja: ");
                if (scanf("%d", &numero) == 1) adicionarBandeja(&bandejas, numero);
                else { int c; while ((c = getchar()) != '\n' && c != EOF); printf("Numero invalido!\n"); }
                break;
            case 2: retirarBandeja(&bandejas); break;
            case 3: consultarProxima(&bandejas); break;
            case 4: mostrarBandejas(&bandejas); break;
            case 0: printf("Encerrando o controle de bandejas...\n"); break;
            default: printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}
