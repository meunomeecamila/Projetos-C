#include <stdio.h>
#include <stdlib.h>

typedef struct Celula {
    int elemento; 
    struct Celula *prox;
} Celula;

typedef struct Pilha {
    struct Celula *topo;
} Pilha;

//função de inicializar a pilha
Pilha* novaPilha(){
    Pilha *nova = (Pilha*)malloc(sizeof(Pilha));
    nova->topo = NULL;
    return nova;
}

Celula* novaCelula(int x){
    Celula *nova = (Celula*)malloc(sizeof(Celula));
    nova->elemento = x;
    nova->prox = NULL;
    return nova;
}

//função de inserir na pilha
void inserir(int x, Pilha *p){
    Celula *aux = novaCelula(x);
    aux->prox = p->topo;
    p->topo = aux;
}

void remover(Pilha *p){
    if(p->topo == NULL){
        printf("EMPTY\n");
        return;
    }

    //remover o no topo
    Celula *j = p->topo;
    p->topo = p->topo->prox;
    free(j);
}

void minimo(Pilha *p){
    if(p->topo == NULL){
        printf("EMPTY\n");
        return;
    }
    int menor = 100;
    for(Celula *j = p->topo; j != NULL; j=j->prox){
        if(j->elemento < menor) menor = j->elemento;
    }
    printf("%d\n",menor);
}


int main(){
    Pilha *p = novaPilha();
    int n; 
    scanf("%d",&n); //número de operações

    char ops[10];
    
    for(int i=0; i<n; i++){
        scanf("%s",ops);
        if(ops[1] == 'U'){
            //PUSH
            int num; 
            scanf("%d", &num);
            inserir(num, p);
        }

        else if(ops[1] == 'O'){
            //POP
            remover(p);
        }

        else if(ops[0] == 'M'){
            //MIN
            minimo(p);
        }
    }
    
    return 0;
}