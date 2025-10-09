#include <stdio.h>
#include <limits.h>

#define MAX 100

typedef struct Pilha {
    int array[MAX];
    int topo;
} Pilha;

// Inicializar pilha
void iniciar(Pilha* p) {
    p->topo = 0;
}

// Inserir (push)
void inserir(Pilha* p, int x) {
    if (p->topo >= MAX) {
        printf("Erro: pilha cheia!\n");
        return;
    }
    p->array[p->topo++] = x;
}

// Remover (pop)
int remover(Pilha* p) {
    if (p->topo == 0) {
        printf("Erro: pilha vazia!\n");
        return INT_MIN;
    }
    return p->array[--p->topo];
}

// Mostrar elementos
void mostrar(Pilha* p) {
    printf("[ ");
    for (int i = p->topo - 1; i >= 0; i--)
        printf("%d ", p->array[i]);
    printf("]\n");
}

// Tamanho
int tamanho(Pilha* p) {
    return p->topo;
}

// Maior elemento
int maior(Pilha* p) {
    if (p->topo == 0) {
        printf("Pilha vazia!\n");
        return INT_MIN;
    }
    int max = p->array[0];
    for (int i = 1; i < p->topo; i++)
        if (p->array[i] > max)
            max = p->array[i];
    return max;
}

// Teste
int main() {
    Pilha p;
    iniciar(&p);

    inserir(&p, 3);
    inserir(&p, 8);
    inserir(&p, 1);

    printf("Pilha atual: ");
    mostrar(&p);
    printf("Tamanho: %d\n", tamanho(&p));
    printf("Maior: %d\n", maior(&p));

    printf("Removendo: %d\n", remover(&p));
    mostrar(&p);

    return 0;
}
