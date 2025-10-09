#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Celula {
    int elemento;
    struct Celula* prox;
} Celula;


typedef struct Fila {
    Celula* primeiro; // nó cabeça
    Celula* ultimo;
} Fila;


// Inicializar fila
void iniciar(Fila* f) {
    f->primeiro = (Celula*) malloc(sizeof(Celula));
    f->primeiro->prox = NULL;
    f->ultimo = f->primeiro;
}

// Inserir (enqueue)
void inserir(Fila* f, int x) {
    f->ultimo->prox = (Celula*) malloc(sizeof(Celula));
    f->ultimo = f->ultimo->prox;
    f->ultimo->elemento = x;
    f->ultimo->prox = NULL;
}

// Remover (dequeue)
int remover(Fila* f) {
    if (f->primeiro == f->ultimo) {
        printf("Erro: fila vazia!\n");
        return INT_MIN;
    }

    Celula* tmp = f->primeiro->prox;
    int elemento = tmp->elemento;

    f->primeiro->prox = tmp->prox;
    if (f->ultimo == tmp)
        f->ultimo = f->primeiro;

    free(tmp);
    return elemento;
}

// Mostrar elementos
void mostrar(Fila* f) {
    printf("[ ");
    for (Celula* i = f->primeiro->prox; i != NULL; i = i->prox) {
        printf("%d ", i->elemento);
    }
    printf("]\n");
}

// Retornar tamanho da fila
int tamanho(Fila* f) {
    int cont = 0;
    for (Celula* i = f->primeiro->prox; i != NULL; i = i->prox)
        cont++;
    return cont;
}

// Achar o maior elemento da fila
int maior(Fila* f) {
    if (f->primeiro == f->ultimo) {
        printf("Fila vazia!\n");
        return INT_MIN;
    }

    int max = f->primeiro->prox->elemento;
    for (Celula* i = f->primeiro->prox->prox; i != NULL; i = i->prox)
        if (i->elemento > max)
            max = i->elemento;
    return max;
}

// ===============================
// Teste
// ===============================
int main() {
    Fila f;
    iniciar(&f);

    inserir(&f, 5);
    inserir(&f, 1);
    inserir(&f, 9);
    inserir(&f, 3);

    printf("Fila atual: ");
    mostrar(&f);
    printf("Tamanho: %d\n", tamanho(&f));
    printf("Maior: %d\n", maior(&f));

    printf("Removendo: %d\n", remover(&f));
    printf("Fila apos remocao: ");
    mostrar(&f);

    return 0;
}
