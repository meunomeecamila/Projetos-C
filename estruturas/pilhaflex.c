#include <stdio.h>

typedef Struct Celula{
    int elemento;
    struct Celula* prox;
} Celula;

Celula *topo;

void start(){
    topo = NULL;
}

void inserir(int x){
    Celula *tmp = new Celula(x);
    tmp->prox = topo;
    topo = tmp;
    tmp = NULL;
}

int remover(){
    //remover no topo
    int resp = topo->elemento
    Celula tmp = topo;
    topo = topo->prox;
    tmp->prox = NULL;
    free(tmp);
    tmp = NULL;
    return resp;
}

void mostrar(){
    for(Celula *i = topo; i!= NULL; i=i->prox){
        printf("%d", topo->elemento);
    }
    printf("\n");
}