#include <stdio.h>
#include <stdlib.h>

// ---------- ESTRUTURA DA CÉLULA ----------
typedef struct Celula {
    int elemento;
    struct Celula *ant;
    struct Celula *prox;
} Celula;

// ---------- CRIAR NOVA CÉLULA ----------
Celula* novaCelula(int x) {
    Celula *tmp = (Celula*) malloc(sizeof(Celula));
    tmp->elemento = x;
    tmp->ant = tmp->prox = NULL;
    return tmp;
}

// ---------- INSERIR NO INÍCIO ----------
Celula* inserirInicio(Celula *inicio, int x) {
    Celula *tmp = novaCelula(x);
    if (inicio == NULL) {
        inicio = tmp;
    } else {
        tmp->prox = inicio;
        inicio->ant = tmp;
        inicio = tmp;
    }
    return inicio;
}

// ---------- INSERIR NO FIM ----------
Celula* inserirFim(Celula *inicio, int x) {
    Celula *tmp = novaCelula(x);
    if (inicio == NULL) {
        inicio = tmp;
    } else {
        Celula *i = inicio;
        while (i->prox != NULL) i = i->prox;
        i->prox = tmp;
        tmp->ant = i;
    }
    return inicio;
}

// ---------- REMOVER DO INÍCIO ----------
Celula* removerInicio(Celula *inicio) {
    if (inicio == NULL) {
        printf("Lista vazia!\n");
        return NULL;
    }
    Celula *tmp = inicio;
    inicio = inicio->prox;
    if (inicio != NULL)
        inicio->ant = NULL;
    free(tmp);
    return inicio;
}

// ---------- REMOVER DO FIM ----------
Celula* removerFim(Celula *inicio) {
    if (inicio == NULL) {
        printf("Lista vazia!\n");
        return NULL;
    }
    if (inicio->prox == NULL) { // só um elemento
        free(inicio);
        return NULL;
    }
    Celula *i = inicio;
    while (i->prox != NULL) i = i->prox;
    i->ant->prox = NULL;
    free(i);
    return inicio;
}

// ---------- IMPRIMIR DO INÍCIO AO FIM ----------
void mostrarFrente(Celula *inicio) {
    Celula *i;
    for (i = inicio; i != NULL; i = i->prox)
        printf("%d ", i->elemento);
    printf("\n");
}

// ---------- IMPRIMIR DO FIM AO INÍCIO ----------
void mostrarTras(Celula *inicio) {
    if (inicio == NULL) return;

    // vai pro último
    Celula *i = inicio;
    while (i->prox != NULL) i = i->prox;

    // volta imprimindo
    for (; i != NULL; i = i->ant)
        printf("%d ", i->elemento);
    printf("\n");
}

// ---------- MAIN PARA TESTAR ----------
int main() {
    Celula *lista = NULL;

    lista = inserirFim(lista, 10);
    lista = inserirFim(lista, 20);
    lista = inserirFim(lista, 30);
    lista = inserirInicio(lista, 5);

    printf("Lista (frente): ");
    mostrarFrente(lista);

    printf("Lista (trás): ");
    mostrarTras(lista);

    lista = removerInicio(lista);
    printf("Após remover início: ");
    mostrarFrente(lista);

    lista = removerFim(lista);
    printf("Após remover fim: ");
    mostrarFrente(lista);

    return 0;
}
