#include <stdio.h>
#include <stdlib.h>

// ---------- ESTRUTURA DO NÓ ----------
typedef struct No {
    int elemento;
    struct No *esq;
    struct No *dir;
    int altura;
} No;

// ---------- FUNÇÕES AUXILIARES ----------
int altura(No *n) {
    return (n == NULL) ? 0 : n->altura;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

// ---------- CRIAR NOVO NÓ ----------
No* novoNo(int x) {
    No *no = (No*) malloc(sizeof(No));
    no->elemento = x;
    no->esq = no->dir = NULL;
    no->altura = 1; // altura inicial do novo nó
    return no;
}

// ---------- FATOR DE BALANCEAMENTO ----------
int getBalance(No *n) {
    if (n == NULL) return 0;
    return altura(n->esq) - altura(n->dir);
}

// ---------- ROTAÇÕES ----------

// 1️⃣ Rotação simples à direita (LL)
No* rotacaoDireita(No *y) {
    No *x = y->esq;
    No *T2 = x->dir;

    // Rotaciona
    x->dir = y;
    y->esq = T2;

    // Atualiza alturas
    y->altura = 1 + max(altura(y->esq), altura(y->dir));
    x->altura = 1 + max(altura(x->esq), altura(x->dir));

    return x; // nova raiz
}

// 2️⃣ Rotação simples à esquerda (RR)
No* rotacaoEsquerda(No *x) {
    No *y = x->dir;
    No *T2 = y->esq;

    // Rotaciona
    y->esq = x;
    x->dir = T2;

    // Atualiza alturas
    x->altura = 1 + max(altura(x->esq), altura(x->dir));
    y->altura = 1 + max(altura(y->esq), altura(y->dir));

    return y; // nova raiz
}

// 3️⃣ Rotação dupla à direita (LR)
No* rotacaoDuplaDireita(No *no) {
    no->esq = rotacaoEsquerda(no->esq);
    return rotacaoDireita(no);
}

// 4️⃣ Rotação dupla à esquerda (RL)
No* rotacaoDuplaEsquerda(No *no) {
    no->dir = rotacaoDireita(no->dir);
    return rotacaoEsquerda(no);
}

// ---------- INSERIR COM BALANCEAMENTO ----------
No* inserir(No *no, int x) {
    // Inserção normal de ABB
    if (no == NULL)
        return novoNo(x);

    if (x < no->elemento)
        no->esq = inserir(no->esq, x);
    else if (x > no->elemento)
        no->dir = inserir(no->dir, x);
    else
        return no; // valores duplicados não são inseridos

    // Atualiza altura
    no->altura = 1 + max(altura(no->esq), altura(no->dir));

    // Calcula fator de balanceamento
    int balance = getBalance(no);

    // 1️⃣ Caso LL - Totalmente pra esquerda
    if (balance > 1 && x < no->esq->elemento)
        return rotacaoDireita(no);

    // 2️⃣ Caso RR - Totalmente pra direita
    if (balance < -1 && x > no->dir->elemento)
        return rotacaoEsquerda(no);

    // 3️⃣ Caso LR - V pra esquerda
    if (balance > 1 && x > no->esq->elemento)
        return rotacaoDuplaDireita(no);

    // 4️⃣ Caso RL - V pra direita
    if (balance < -1 && x < no->dir->elemento)
        return rotacaoDuplaEsquerda(no);

    // Retorna o nó (sem rotação necessária)
    return no;
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

// ---------- MAIN PARA TESTE ----------
int main() {
    No *raiz = NULL;

    // Teste com inserções que forçam todos os tipos de rotação
    raiz = inserir(raiz, 30);
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 10); // causa LL
    raiz = inserir(raiz, 25); // causa LR
    raiz = inserir(raiz, 40);
    raiz = inserir(raiz, 50); // causa RR
    raiz = inserir(raiz, 45); // causa RL

    printf("Pré-ordem da árvore balanceada: ");
    preOrdem(raiz);
    printf("\n");

    printf("Em ordem (ordenada): ");
    inOrdem(raiz);
    printf("\n");

    return 0;
}
