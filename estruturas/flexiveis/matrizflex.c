#include <stdio.h>
#include <stdlib.h>

// ---------- ESTRUTURA DA CÉLULA ----------
typedef struct Celula {
    int elemento;
    struct Celula *ant, *prox, *sup, *inf;
} Celula;

// ---------- CRIAR NOVA CÉLULA ----------
Celula* novaCelula(int x) {
    Celula *tmp = (Celula*) malloc(sizeof(Celula));
    tmp->elemento = x;
    tmp->ant = tmp->prox = tmp->sup = tmp->inf = NULL;
    return tmp;
}

// ---------- CONSTRUIR MATRIZ FLEXÍVEL ----------
Celula* construirMatriz(int linhas, int colunas) {
    if (linhas <= 0 || colunas <= 0) return NULL;

    // cria a célula inicial (canto superior esquerdo)
    Celula *inicio = novaCelula(0);

    // ----- cria a primeira linha -----
    Celula *j = inicio;
    for (int c = 1; c < colunas; c++) {
        j->prox = novaCelula(0);
        j->prox->ant = j;
        j = j->prox;
    }

    // ----- cria as demais linhas -----
    Celula *cima = inicio;
    for (int l = 1; l < linhas; l++) {
        // primeira célula da nova linha
        Celula *baixo = novaCelula(0);
        baixo->sup = cima;
        cima->inf = baixo;

        // conecta horizontalmente
        Celula *a = baixo;
        Celula *b = cima->prox;

        for (int c = 1; c < colunas; c++) {
            a->prox = novaCelula(0);
            a->prox->ant = a;
            a = a->prox;

            a->sup = b;
            b->inf = a;

            b = b->prox;
        }

        // move o "cima" pra próxima linha
        cima = cima->inf;
    }

    return inicio;
}

// ---------- PREENCHER MATRIZ COM VALORES ----------
void preencherMatriz(Celula *inicio, int linhas, int colunas) {
    Celula *i = inicio;
    for (int l = 0; l < linhas; l++) {
        Celula *j = i;
        for (int c = 0; c < colunas; c++) {
            printf("Elemento [%d][%d]: ", l, c);
            scanf("%d", &j->elemento);
            j = j->prox;
        }
        i = i->inf;
    }
}

// ---------- IMPRIMIR MATRIZ ----------
void mostrarMatriz(Celula *inicio, int linhas, int colunas) {
    Celula *i = inicio;
    for (int l = 0; l < linhas; l++) {
        Celula *j = i;
        for (int c = 0; c < colunas; c++) {
            printf("%d ", j->elemento);
            j = j->prox;
        }
        printf("\n");
        i = i->inf;
    }
}

// ---------- LIBERAR MATRIZ ----------
void liberarMatriz(Celula *inicio, int linhas, int colunas) {
    Celula *i = inicio;
    for (int l = 0; l < linhas; l++) {
        Celula *j = i;
        Celula *proxLinha = i->inf;
        for (int c = 0; c < colunas; c++) {
            Celula *tmp = j;
            j = j->prox;
            free(tmp);
        }
        i = proxLinha;
    }
}

// ---------- MAIN PARA TESTAR ----------
int main() {
    int linhas, colunas;
    printf("Digite o número de linhas e colunas: ");
    scanf("%d %d", &linhas, &colunas);

    Celula *matriz = construirMatriz(linhas, colunas);

    printf("Preencha a matriz:\n");
    preencherMatriz(matriz, linhas, colunas);

    printf("\nMatriz:\n");
    mostrarMatriz(matriz, linhas, colunas);

    liberarMatriz(matriz, linhas, colunas);

    return 0;
}
