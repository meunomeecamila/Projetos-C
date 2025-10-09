#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Celula {
    int elemento;
    struct Celula* prox;
} Celula;

typedef struct Lista {
    Celula* primeiro; // nó cabeça
    Celula* ultimo;
} Lista;

// Inicializar lista
void iniciar(Lista* l) {
    l->primeiro = (Celula*) malloc(sizeof(Celula));
    l->primeiro->prox = NULL;
    l->ultimo = l->primeiro;
}

// Inserir no fim
void inserirFim(Lista* l, int x) {
    Celula* nova = (Celula*) malloc(sizeof(Celula));
    nova->elemento = x;
    nova->prox = NULL;
    l->ultimo->prox = nova;
    l->ultimo = nova;
}

// Remover no início
int removerInicio(Lista* l) {
    if (l->primeiro == l->ultimo) {
        printf("Erro: lista vazia!\n");
        return INT_MIN;
    }

    Celula* tmp = l->primeiro->prox;
    int elemento = tmp->elemento;

    l->primeiro->prox = tmp->prox;
    if (tmp == l->ultimo)
        l->ultimo = l->primeiro;

    free(tmp);
    return elemento;
}

// Mostrar elementos
void mostrar(Lista* l) {
    printf("[ ");
    for (Celula* i = l->primeiro->prox; i != NULL; i = i->prox) {
        printf("%d ", i->elemento);
    }
    printf("]\n");
}

// Retornar tamanho
int tamanho(Lista* l) {
    int cont = 0;
    for (Celula* i = l->primeiro->prox; i != NULL; i = i->prox)
        cont++;
    return cont;
}

// Retornar o maior elemento
int maior(Lista* l) {
    if (l->primeiro == l->ultimo) {
        printf("Lista vazia!\n");
        return INT_MIN;
    }

    int max = l->primeiro->prox->elemento;
    for (Celula* i = l->primeiro->prox->prox; i != NULL; i = i->prox)
        if (i->elemento > max)
            max = i->elemento;
    return max;
}

// ===============================
// Teste
// ===============================
int main() {
    Lista l;
    iniciar(&l);

    inserirFim(&l, 4);
    inserirFim(&l, 8);
    inserirFim(&l, 2);
    inserirFim(&l, 10);

    printf("Lista atual: ");
    mostrar(&l);
    printf("Tamanho: %d\n", tamanho(&l));
    printf("Maior: %d\n", maior(&l));

    printf("Removendo: %d\n", removerInicio(&l));
    mostrar(&l);

    return 0;
}
