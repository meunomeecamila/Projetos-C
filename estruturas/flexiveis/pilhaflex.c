#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // para usar INT_MIN

typedef struct Celula {
    int elemento;
    struct Celula* prox;
} Celula;


typedef struct Pilha {
    Celula* topo;
} Pilha;

//Inicializar a pilha
void iniciar(Pilha* p) {
    p->topo = NULL;
}

// Inserir elemento (push)
void inserir(Pilha* p, int x) {
    Celula* nova = (Celula*) malloc(sizeof(Celula));
    nova->elemento = x;
    nova->prox = p->topo;
    p->topo = nova;
}

// Remover elemento (pop)
int remover(Pilha* p) {
    if (p->topo == NULL) {
        printf("Erro: pilha vazia!\n");
        return INT_MIN;
    }

    Celula* tmp = p->topo;
    int elemento = tmp->elemento;
    p->topo = tmp->prox;
    free(tmp);
    return elemento;
}

// Mostrar elementos
void mostrar(Pilha* p) {
    printf("[ ");
    for (Celula* i = p->topo; i != NULL; i = i->prox) {
        printf("%d ", i->elemento);
    }
    printf("]\n");
}

// Retornar tamanho da pilha
int tamanho(Pilha* p) {
    int cont = 0;
    for (Celula* i = p->topo; i != NULL; i = i->prox) {
        cont++;
    }
    return cont;
}

// Achar o maior elemento
int maior(Pilha* p) {
    if (p->topo == NULL) {
        printf("Pilha vazia!\n");
        return INT_MIN;
    }

    int max = p->topo->elemento;
    for (Celula* i = p->topo->prox; i != NULL; i = i->prox) {
        if (i->elemento > max)
            max = i->elemento;
    }
    return max;
}

// ===============================
// Função principal para testes
// ===============================
int main() {
    Pilha p;
    iniciar(&p);

    inserir(&p, 5);
    inserir(&p, 2);
    inserir(&p, 9);
    inserir(&p, 3);

    printf("Pilha atual: ");
    mostrar(&p);

    printf("Tamanho: %d\n", tamanho(&p));
    printf("Maior elemento: %d\n", maior(&p));

    printf("Removendo: %d\n", remover(&p));
    printf("Pilha apos remocao: ");
    mostrar(&p);

    return 0;
}
