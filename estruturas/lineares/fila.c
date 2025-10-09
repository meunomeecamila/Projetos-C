#include <stdio.h>
#include <limits.h>

#define MAX 100

typedef struct Fila {
    int array[MAX];
    int primeiro;
    int ultimo;
} Fila;

// Inicializar
void iniciar(Fila* f) {
    f->primeiro = 0;
    f->ultimo = 0;
}

// Inserir (enqueue)
void inserir(Fila* f, int x) {
    if ((f->ultimo + 1) % MAX == f->primeiro) {
        printf("Erro: fila cheia!\n");
        return;
    }
    f->array[f->ultimo] = x;
    f->ultimo = (f->ultimo + 1) % MAX;
}

// Remover (dequeue)
int remover(Fila* f) {
    if (f->primeiro == f->ultimo) {
        printf("Erro: fila vazia!\n");
        return INT_MIN;
    }
    int elemento = f->array[f->primeiro];
    f->primeiro = (f->primeiro + 1) % MAX;
    return elemento;
}

// Mostrar
void mostrar(Fila* f) {
    printf("[ ");
    for (int i = f->primeiro; i != f->ultimo; i = (i + 1) % MAX)
        printf("%d ", f->array[i]);
    printf("]\n");
}

// Tamanho
int tamanho(Fila* f) {
    return (f->ultimo - f->primeiro + MAX) % MAX;
}

// Maior
int maior(Fila* f) {
    if (f->primeiro == f->ultimo) {
        printf("Fila vazia!\n");
        return INT_MIN;
    }

    int max = f->array[f->primeiro];
    for (int i = (f->primeiro + 1) % MAX; i != f->ultimo; i = (i + 1) % MAX)
        if (f->array[i] > max)
            max = f->array[i];
    return max;
}

// Teste
int main() {
    Fila f;
    iniciar(&f);

    inserir(&f, 4);
    inserir(&f, 1);
    inserir(&f, 7);
    inserir(&f, 2);

    printf("Fila atual: ");
    mostrar(&f);
    printf("Tamanho: %d\n", tamanho(&f));
    printf("Maior: %d\n", maior(&f));

    printf("Removendo: %d\n", remover(&f));
    mostrar(&f);

    return 0;
}
