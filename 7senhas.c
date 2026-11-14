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

int filaCheia(const Fila *f) { return f->fim == MAX; }
int filaVazia(const Fila *f) { return f->inicio == f->fim; }

int enfileirar(Fila *f, int valor) {
    if (filaCheia(f)) return 0;
    f->itens[f->fim++] = valor;
    return 1;
}

int desenfileirar(Fila *f, int *valor) {
    if (filaVazia(f)) return 0;
    *valor = f->itens[f->inicio++];
    return 1;
}

int main() {
    Fila fila;
    iniciarFila(&fila);
    int proximaSenha = 1;  /* so avanca quando a insercao e possivel */
    int opcao, senha;

    do {
        printf("\n=== SECRETARIA - ATENDIMENTO POR SENHAS ===\n");
        printf("1. Gerar senha\n");
        printf("2. Chamar proxima senha\n");
        printf("3. Consultar proxima senha\n");
        printf("4. Mostrar senhas aguardando\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        if (scanf("%d", &opcao) != 1) {
            int c; while ((c = getchar()) != '\n' && c != EOF);
            if (c == EOF) break;
            opcao = -1;
        }

        switch (opcao) {
            case 1:
                if (filaCheia(&fila)) {
                    printf("\n[ERRO] Fila cheia! Nenhuma senha foi gerada.\n");
                } else {
                    enfileirar(&fila, proximaSenha);
                    printf("\n[OK] Senha gerada: %d\n", proximaSenha);
                    proximaSenha++;
                }
                break;
            case 2:
                if (desenfileirar(&fila, &senha))
                    printf("\n[OK] Chamando a senha %d!\n", senha);
                else
                    printf("\n[ERRO] Nao ha senhas aguardando atendimento.\n");
                break;
            case 3:
                if (filaVazia(&fila))
                    printf("\nNao ha senhas aguardando.\n");
                else
                    printf("\nProxima senha: %d\n", fila.itens[fila.inicio]);
                break;
            case 4:
                if (filaVazia(&fila)) {
                    printf("\nNenhuma senha aguardando.\n");
                } else {
                    printf("\nSenhas aguardando: ");
                    for (int i = fila.inicio; i < fila.fim; i++) printf("[%d] ", fila.itens[i]);
                    printf("\n");
                }
                break;
            case 0: printf("Encerrando atendimento...\n"); break;
            default: printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}
