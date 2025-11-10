#include <stdio.h>
#include <stdlib.h>

// ---------- ESTRUTURA DO NÓ ----------
typedef struct No {
    int elemento;
    struct No *esq;
    struct No *dir;
} No;

// ---------- FUNÇÃO PARA CRIAR NÓ ----------
No* novoNo(int x) {
    No *no = (No*) malloc(sizeof(No));
    no->elemento = x;
    no->esq = no->dir = NULL;
    return no;
}

// ---------- INSERIR ----------
No* inserir(No *raiz, int x) {
    if (raiz == NULL) {
        raiz = novoNo(x);
    } else if (x < raiz->elemento) {
        raiz->esq = inserir(raiz->esq, x);
    } else if (x > raiz->elemento) {
        raiz->dir = inserir(raiz->dir, x);
    }
    // se for igual, não faz nada (evita duplicados)
    return raiz;
}

// ---------- PESQUISAR ----------
int pesquisar(No *raiz, int x) {
    if (raiz == NULL) return 0;
    if (raiz->elemento == x) return 1;
    if (x < raiz->elemento) return pesquisar(raiz->esq, x);
    else return pesquisar(raiz->dir, x);
}

// ---------- ENCONTRAR O MENOR NÓ (AUXILIAR PARA REMOVER) ----------
No* menorNo(No *no) {
    while (no->esq != NULL)
        no = no->esq;
    return no;
}

// ---------- REMOVER ----------
No* remover(No *raiz, int x) {
    if (raiz == NULL) return NULL;

    if (x < raiz->elemento) {
        raiz->esq = remover(raiz->esq, x);
    } else if (x > raiz->elemento) {
        raiz->dir = remover(raiz->dir, x);
    } else {
        // caso 1: sem filhos
        if (raiz->esq == NULL && raiz->dir == NULL) {
            free(raiz);
            return NULL;
        }
        // caso 2: um filho
        else if (raiz->esq == NULL) {
            No *temp = raiz->dir;
            free(raiz);
            return temp;
        }
        else if (raiz->dir == NULL) {
            No *temp = raiz->esq;
            free(raiz);
            return temp;
        }
        // caso 3: dois filhos
        else {
            No *sucessor = menorNo(raiz->dir);
            raiz->elemento = sucessor->elemento;
            raiz->dir = remover(raiz->dir, sucessor->elemento);
        }
    }
    return raiz;
}

// ---------- PERCURSOS ----------
void preOrdem(No *raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->elemento);
        preOrdem(raiz->esq);
        preOrdem(raiz->dir);
    }
}

void inOrdem(No *raiz) {
    if (raiz != NULL) {
        inOrdem(raiz->esq);
        printf("%d ", raiz->elemento);
        inOrdem(raiz->dir);
    }
}

void posOrdem(No *raiz) {
    if (raiz != NULL) {
        posOrdem(raiz->esq);
        posOrdem(raiz->dir);
        printf("%d ", raiz->elemento);
    }
}

// ---------- PROGRAMA PRINCIPAL ----------
int main() {
    No *raiz = NULL;

    // Inserção de exemplo
    raiz = inserir(raiz, 8);
    raiz = inserir(raiz, 3);
    raiz = inserir(raiz, 10);
    raiz = inserir(raiz, 1);
    raiz = inserir(raiz, 6);
    raiz = inserir(raiz, 14);
    raiz = inserir(raiz, 4);
    raiz = inserir(raiz, 7);
    raiz = inserir(raiz, 13);

    printf("Pré-ordem: ");
    preOrdem(raiz);
    printf("\n");

    printf("Em ordem: ");
    inOrdem(raiz);
    printf("\n");

    printf("Pós-ordem: ");
    posOrdem(raiz);
    printf("\n");

    // Exemplo de busca
    int x = 6;
    if (pesquisar(raiz, x))
        printf("%d encontrado!\n", x);
    else
        printf("%d não encontrado!\n", x);

    // Exemplo de remoção
    raiz = remover(raiz, 3);
    printf("Após remover 3, em ordem: ");
    inOrdem(raiz);
    printf("\n");

    return 0;
}
