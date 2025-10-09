#include <stdio.h>
#include <limits.h>

#define MAX 100

typedef struct Lista {
    int array[MAX];
    int n; // número de elementos
} Lista;

// Inicializar
void iniciar(Lista* l) {
    l->n = 0;
}

// Inserir no fim
void inserir(Lista* l, int x) {
    if (l->n >= MAX) {
        printf("Erro: lista cheia!\n");
        return;
    }
    l->array[l->n++] = x;
}

// Remover no início
int remover(Lista* l) {
    if (l->n == 0) {
        printf("Erro: lista vazia!\n");
        return INT_MIN;
    }
    int elemento = l->array[0];
    for (int i = 0; i < l->n - 1; i++)
        l->array[i] = l->array[i + 1];
    l->n--;
    return elemento;
}

// Mostrar
void mostrar(Lista* l) {
    printf("[ ");
    for (int i = 0; i < l->n; i++)
        printf("%d ", l->array[i]);
    printf("]\n");
}

// Tamanho
int tamanho(Lista* l) {
    return l->n;
}

// Maior elemento
int maior(Lista* l) {
    if (l->n == 0) {
        printf("Lista vazia!\n");
        return INT_MIN;
    }
    int max = l->array[0];
    for (int i = 1; i < l->n; i++)
        if (l->array[i] > max)
            max = l->array[i];
    return max;
}

// Teste
int main() {
    Lista l;
    iniciar(&l);

    inserir(&l, 5);
    inserir(&l, 2);
    inserir(&l, 8);
    inserir(&l, 1);

    printf("Lista atual: ");
    mostrar(&l);
    printf("Tamanho: %d\n", tamanho(&l));
    printf("Maior: %d\n", maior(&l));

    printf("Removendo: %d\n", remover(&l));
    mostrar(&l);

    return 0;
}
