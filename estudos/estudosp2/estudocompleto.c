#include <stdio.h>
#include <stdlib.h>

// * Esse documento conterá as matérias para a prova 2 de AED. 

// TODO - Caso deseje utilizar algum dos códigos, execute na main

// ! Matérias:
// ? (Códigos de ordenação) 
/*
- Selection - ok
- Bubble - ok
- Insertion - ok
- Heap - ok
- Quick - ok
- Merge - ok
- Shell - ok
- Counting - ok
*/

// ? (Estruturas de dados flexíveis)
/*
- Pilha flex - ok
- Fila flex - ok
- lista simples flex - ok
- Lista dupla flex - ok
- Matriz flex 
- Árvore 
*/

// ? (Extras)
/*
- Coleta de lixo 
- Ordenações parciais 
*/

//* Algoritmos de ordenação ========================
// ! Selection sort 
/* Complexidade no melhor caso: n²
   Complexidade no pior caso: n²
   Utilização: Bom para achar o menor item ou para ordenação parcial. 
*/

void selection(int n, int* vetor){
    for(int i=0; i<n-1; i++){
        int menor = i;
        for(int j=i+1; j<n; j++){
            if(vetor[j] < vetor[menor]){
                menor = j;
            }
        }
        swap(vetor,menor,i);
    }
}

// ! Insertion sort 
/* Complexidade no melhor caso: n
   Complexidade no pior caso: n²
   Utilização: Bom para inserir elementos em um conjunto já ou parcialmente ordenado
*/

void insertion(int n, int*vetor){
    for(int i=1; i<n; i++){
        int tmp = vetor[i];
        int j = i-1;

        while(j>=0 && vetor[j] > tmp){
            vetor[j+1] = vetor[j]; //arredar
            j--;
        }

        vetor[j+1] = tmp;
    }
}

// ! Bubble sort
/* Complexidade no melhor caso: n
   Complexidade no pior caso: n²
   Utilização: Fácil de implementar e eficiente em casos pequenos
*/

void bubble(int n, int * vetor){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-1-i; j++){
            if(vetor[j] > vetor[j+1]){
                swap(vetor,j,j+1);
            }
        }
    }
}

// ! Quicksort
/* Complexidade no melhor caso: n x lg n
   Complexidade no pior caso: n²
   Utilização: Muito rápido e usa pouca memória
*/
void auxiliarQuick(int *vetor){
    int tam = 10; //exemplo
    quicksort(0,tam-1, vetor);
}
void quicksort(int esq, int dir, int * vetor){
    int i = esq; int j = dir;
    int n = getTam(vetor);
    int pivo = vetor[n/2];
    while(i<=j){
        while(vetor[i]<pivo) i++;
        while(vetor[j]>pivo) j--;

        if(i<=j){
            swap(vetor,i,j);
            i++; j--;
        }

        if (esq < j) quicksort(esq, j, vetor);  // Recursão na parte esquerda
        if (i < dir) quicksort(i, dir, vetor);  // Recursão na parte direita
    }
}

// ! Shellsort 
/* Complexidade no melhor caso: n x log² n
   Complexidade no pior caso: n²
   Utilização: Melhoria do insertion, desloca menos quando está longe
*/

//obs: funciona como o shellsort mas com o gap
void shellsort(int *vetor, int n){
    for(int gap=n/2; gap > 0; gap/=2){
        for(int i=gap; i<n; i++){
            int tmp = vetor[i];
            int j=i;

            while(j>=gap && vetor[j-gap] > tmp){
                vetor[j] = vetor[j-gap];
                j-= gap;
            }

            vetor[j] = tmp;
        }
    }
}

// ! Mergesort
/* Complexidade no melhor caso: n x log n
   Complexidade no pior caso: n x log n
   Utilização: Sempre a mesma complexidade, ordenações externas
*/

void mergeSort(int * vetor, int esq, int dir){
    if(esq < dir){
        int meio = (esq+dir)/2;

        //ordenar as duas metades
        mergeSort(vetor,esq,meio); //metade 1
        mergeSort(vetor,meio+1,dir); //metade 2

        //intercalar
        merge(vetor, esq, meio, dir);
    }
}

//função de intercalar
void merge(int * vetor, int esq, int meio, int dir){
    //obs: em caso de vetor de tamanho impar, esq fica com 1 a mais
    int n1 = meio-esq+1; //tamanho do primeiro vetor
    int n2 = dir-meio; //tamanho do segundo vetor

    int * esquerda = (int *)malloc(n1 * sizeof(int)); //criou o primeiro vetor
    int * direita = (int *)malloc(n2 * sizeof(int)); //criou o segundo vetor

    for(int i=0; i<n1; i++) esquerda[i] = vetor[esq+i]; //colocou os valores da esq
    for(int i=0; i<n2; i++) direita[i] = vetor[meio+1+i]; //colocou os valores da dir

    int i=0; //incrementador (cursor) da esquerda
    int j=0; //incrementador (cursor) da direita
    int k = esq; //incrementador (cursor) do vetor original

    while(i<n1 && j<n2){
        //intercalar propriamente dito
        if(esquerda[i] <= direita[j]) vetor[k++] = esquerda[i++];
        else vetor[k++] = direita[j++];
    }

    //se sobrou algo, copia o restante
    while(i < n1) vetor[k++] = esquerda[i++];
    while(j < n2) vetor[k++] = direita[j++];

    free(esquerda);
    free(direita);

}

// ! Heap
/* Complexidade no melhor caso: n x log n
   Complexidade no pior caso: n x log n
   Utilização: Sempre a mesma complexidade, precisa de pouca memória 
*/

void heap(int * vetor, int n){
    //transformar vetor em um heap
    for(int i=(n/2 - 1); i>=0; i--) heapify(vetor,n,i);

    //extrair item por item do heap
    for(int i=n-1; i>0; i--){
        //funcao de swap
        swap(vetor, i,0);
        heapify(vetor,i,0);
    }
}

void heapify(int * vetor, int tam, int i){
    int maior = i;
    int esquerda = 2*i + 1; //filho 1
    int direita = 2*i + 2; //filho 2

    if(esquerda < tam && vetor[esquerda] > vetor[maior]) maior = esquerda;
    if(direita > tam && vetor[direita] > vetor[maior]) maior = direita;

    if(maior != i){
        swap(vetor, i, maior);
        heapify(vetor, tam, maior);
    }
}

// ! Counting
/* Complexidade no melhor caso: (n+k) sendo k o maior num do vetor
   Complexidade no pior caso: (n+k) sendo k o maior num do vetor
   Utilização: Rápido para inteiros pequenos
*/

void counting(int * vetor, int n){
    int max = vetor[0];
    for(int i=1; i<n; i++){
        if(vetor[i] > max) max = vetor[i];
    }

    int * contagem = (int *)malloc((max+1)*sizeof(int));

    //contar quantas vezes cada um aparece
    for(int i=0; i<n; i++) contagem[vetor[i]]++;

    //reconstrução
    int index = 0;
    for(int i=0; i<=max; i++){
        while(contagem[i]>0){
            vetor[index++] = i;
            contagem[i]--;
        }
    }

    free(contagem);
}

//* Estruturas de dados flexíveis ========================
//? Obs: Sem contar com a matriz, as células das estruturas flexíveis seguem o
//? mesmo modelo, que é: 

//? Podemos considerar com ou sem o nó cabeça, isso deve ser explicito na pergunta 
//? ou até no comentário do código

//? Em C, usaremos o método START para inicializar nossas estruturas

typedef struct Celula {
    int elemento; 
    struct Celula *prox;
} Celula;

//construtor
Celula *nova(int x){
    Celula *c = (Celula*)malloc(sizeof(Celula));
    c->elemento = x;
    c->prox = NULL;
    return c;
}

// ! Pilha flexível (sem nó cabeça)
// O primeiro a entrar é o último a sair, são empilhados (LIFO)

typedef struct PilhaFlex{
    Celula *topo;
} PilhaFlex; 

//inicializar a pilha
PilhaFlex *start(){
    PilhaFlex *p = (PilhaFlex*)malloc(sizeof(PilhaFlex));
    p->topo = NULL;
    return p;
}

void inserir(PilhaFlex *p, int x){
    Celula *tmp = (Celula*)malloc(sizeof(Celula));
    tmp->elemento = x;

    tmp->prox = p->topo;
    p->topo = tmp;
    tmp = NULL;
}

int remover(PilhaFlex *p){
    if(p->topo != NULL){
        //celula auxiliar
        Celula *i = p->topo;
        p->topo = p->topo->prox; //anda com topo

        int ele = i->elemento; //retorna oq removeu
        i->prox = NULL;
        free(i); 
        //obs: por mais que nessa função não demos malloc, demos na hora de inserir
        i = NULL;
        return ele;
    }
    else return -1;
}

void mostrar(PilhaFlex *p){
    for(Celula *i = p->topo; i != NULL; i=i->prox){
        printf("%d", i->elemento);
    }
    printf("\n");
}

// ! Fila flexível (com nó cabeça)
//O primeiro a entrar é o primeiro a sair (FIFO)

typedef struct FilaFlex {
    Celula *primeiro;
    Celula *ultimo;
} FilaFlex;

//função que cria a fila vazia
FilaFlex *start(){
    FilaFlex *f = (FilaFlex*)malloc(sizeof(FilaFlex));
    f->primeiro = (Celula*)malloc(sizeof(Celula)); //nó cabeça
    f->primeiro->prox = NULL;
    f->ultimo = f->primeiro;
    return f;
}

//inserir considerando a existencia de um nó cabeça
void inserir(FilaFlex *f, int x){
    f->ultimo->prox = (Celula*)malloc(sizeof(Celula)); //cria a nova celula
    f->ultimo->prox->elemento = x; //coloca o valor
    f->ultimo = f->ultimo->prox; //anda com o ponteiro
    f->ultimo->prox = NULL; //próximo vale null
}

//remover considerando a existencia de um nó cabeça
//obs: primeiro numero valido é o primeiro->prox
int remover(FilaFlex *f){
    if(f->primeiro != f->ultimo){
        Celula *i = f->primeiro;
        int ele = i->prox->elemento;
        f->primeiro = f->primeiro->prox;
        i->prox = NULL;
        free(i);
        i = NULL;
        return ele;
    } else return -1;
}

void mostrar(FilaFlex *f){
    for(Celula*i = f->primeiro->prox; i != NULL; i = i->prox){
        printf("%d",i->elemento);
    }
    printf("\n");
}

// ! Lista flexivel simples (com nó cabeça)
//Pode-se inserir e remover de qualquer lugar

typedef struct ListaFlex{
    Celula *primeiro;
    Celula *ultimo;
} ListaFlex;

ListaFlex *start(){
    ListaFlex *l = (ListaFlex*)malloc(sizeof(ListaFlex));
    //inicializar a lista com nó cabeça
    l->primeiro = (Celula*)malloc(sizeof(Celula));
    l->primeiro->prox = NULL;
    l->ultimo = l->primeiro;
    return l;
}

void inserir_inicio(ListaFlex *l, int x){
    Celula *tmp = (Celula*)malloc(sizeof(Celula));
    tmp->elemento = x;

    //considerando a existencia do nó cabeça, inserimos depois dele
    tmp->prox = l->primeiro->prox;
    l->primeiro->prox = tmp;
    tmp = NULL;

    if(l->ultimo == l->primeiro) l->ultimo = l->primeiro->prox;
}

void inserir_fim(ListaFlex *l, int x){
    l->ultimo->prox = (Celula*)malloc(sizeof(Celula));
    l->ultimo->prox->elemento = x;
    l->ultimo = l->ultimo->prox;
    l->ultimo->prox = NULL;
}

void inserir_meio(ListaFlex *l, int x, int pos){
    int tam = getTam(l);
    if(pos < 0 || pos > tam+1) printf("Posição inválida\n");
    else if(pos == 0) inserir_inicio(l,x);
    else if(pos == tam) inserir_fim(l,x);
    else {
        //andar até onde quer inserir
        Celula *i = l->primeiro; int j;
        for(j=0; j<pos; j++) i=i->prox;

        Celula *j = i->prox;
        i->prox = (Celula*)malloc(sizeof(Celula));
        i->prox->elemento = x;

        i->prox->prox = j;
    }
}

int remover_inicio(ListaFlex *l){
    //considerando o nó cabeça, remover o nó e fazer o primeiro->prox ser o nó
    if(l->primeiro != l->ultimo){
        int ele = l->primeiro->prox->elemento; //guardar o valor
        Celula *j = l->primeiro; //ponteiro auxiliar
        l->primeiro = l->primeiro->prox; //andar com o primeiro

        //liberar o antigo nó cabeça
        j->prox = NULL;
        free(j);
        j = NULL;
        return ele;
    }
}

int remover_fim(ListaFlex *l){
    if(l->primeiro != l->ultimo){
        Celula *i; //ponteiro auxiliar
        for(i = l->primeiro; i->prox != l->ultimo; i=i->prox); //anda até antes do ultimo
        int ele = i->prox->elemento; //pega o elemento

        free(i->prox);
        i->prox = NULL;
        l->ultimo = i;
        i = NULL;

        return ele;
    }
}

int remover_meio(ListaFlex *l, int pos){
    //verificações 
    int tam = getTam(l);
    if(pos < 0 || pos > tam) printf("Posição inválida\n");
    else if(pos == 0) return remover_inicio(l);
    else if(pos == tam-1) return remover_fim(l);
    else {
        Celula *i = l->primeiro;
        int k;
        for(k=0; k<pos-1; k++) i = i->prox; //andar

        //chegou antes da posição, remover
        int ele = i->prox->elemento;
        
        Celula *j = i->prox;
        i->prox = j->prox;
        j->prox = NULL;
        free(j);
        j = NULL;
        return ele;
    }
}

// ! Lista flexivel dupla (com nó cabeça)
//Pode-se inserir e remover de qualquer lugar
//obs: a parte boa da lista dupla é que podemos andar pros dois lados

//para isso, teríamos que usar a celula dupla
typedef struct CelulaDupla {
    int elemento;
    struct CelulaDupla *ant;
    struct CelulaDupla *prox;
} CelulaDupla;

typedef struct ListaFlexDupla {
    CelulaDupla *primeiro;
    CelulaDupla *ultimo;
} ListaFlexDupla;

//função para inicializar com o nó cabeça
ListaFlexDupla* start(){
    //criar uma lista
    ListaFlexDupla *ld = (ListaFlexDupla*)malloc(sizeof(ListaFlexDupla));

    //criar o nó cabeça
    ld->primeiro = (CelulaDupla*)malloc(sizeof(CelulaDupla));
    ld->primeiro->prox = NULL;
    ld->primeiro->ant = NULL;
    ld->ultimo = ld->primeiro;

    return ld;
}

//funções normais
void inserir_inicio(ListaFlexDupla *ld, int x){
    CelulaDupla *tmp = (CelulaDupla*)malloc(sizeof(CelulaDupla));
    tmp->elemento = x;

    tmp->prox = ld->primeiro->prox;
    tmp->ant = ld->primeiro;
    ld->primeiro->prox = tmp;

    if(tmp->prox != NULL){ //ja existia alguem depois do no cabeca
        tmp->prox->ant = tmp;
    }

    else { //existia apenas o no cabeca 
        ld->ultimo = ld->ultimo->prox;
    }
}

void inserir_fim(ListaFlexDupla *ld, int x){
    ld->ultimo->prox = (CelulaDupla*)malloc(sizeof(CelulaDupla));
    ld->ultimo->prox->elemento = x;
    ld->ultimo->prox->prox = NULL;

    ld->ultimo->prox->ant = ld->ultimo;
    ld->ultimo = ld->ultimo->prox;
}

void inserir_meio(ListaFlexDupla *ld, int x, int pos){
    int tam = getTam(ld);

    //verificações
    if(pos < 0 || pos > tam) printf("Posição inválida\n");
    else if(pos == 0) inserir_inicio(ld, x);
    else if(pos == tam) inserir_fim(ld,x);

    else {
        //criar a célula
        CelulaDupla *tmp = (CelulaDupla*)malloc(sizeof(CelulaDupla));
        tmp->elemento = x;
        tmp->prox = NULL;

        //anda até antes de inserir
        CelulaDupla *i = ld->primeiro; int j; 
        for(j=0; j<pos-1; j++) i = i->prox;

        tmp->prox = i->prox;
        tmp->ant = i;

        i->prox = tmp;
        tmp->prox->ant = tmp;
    }
}

//métodos de remover
//obs: como fizemos malloc nos de inserir, fazemos free nos de remover

int remover_inicio(ListaFlexDupla *ld){
    if(ld->primeiro != ld->ultimo){
        //remover o nó cabeça e fazer o próximo ser o nó cabeça
        int ele = ld->primeiro->prox->elemento;
        CelulaDupla *tmp = ld->primeiro; //apontar pro primeiro
        ld->primeiro = ld->primeiro->prox; //andar com o primeiro

        //desconectar
        tmp->prox = NULL;
        ld->primeiro->ant = NULL;

        free(tmp);
        tmp = NULL;

        return ele;
    }
    else return -1;
}

int remover_fim(ListaFlexDupla *ld){
    if(ld->primeiro != ld->ultimo){
        CelulaDupla *i = ld->ultimo;
        int ele = i->elemento;
        ld->ultimo = ld->ultimo->ant; //andei com o ultimo

        ld->ultimo->prox = NULL;
        i->ant = NULL;

        free(i);
        i = NULL;

        return ele;
    }
    else return -1;
}

int remover_meio(ListaFlexDupla *ld, int pos){
    int tam = getTam(ld);
    if(pos < 0 || pos > tam-1) {printf("Posição inválida"); return -1; }
    else if(pos == 0) return remover_inicio(ld);
    else if(pos == tam-1) return remover_fim(ld);
    else {
        //andar até antes da remoção
        int j; CelulaDupla *i = ld->primeiro;
        for(j=0; j<pos; j++) i=i->prox;

        CelulaDupla *k = i->prox;
        int ele = k->elemento;

        i->prox = k->prox;
        k->prox->ant = i;

        k->ant = NULL;
        k->prox = NULL;
        free(k);
        k = NULL;

        return ele;
    }
}

void mostrar(ListaFlexDupla *ld){
    for(CelulaDupla *i = ld->primeiro; i != NULL; i = i->prox){
        printf("%d", i->elemento);
    }
    printf("\n");
}

// ! Matriz flexível ========================
//Conta com um ponteiro de início que aponta para a célula (0,0)
//tem ant, prox, sub e inf

typedef struct CelulaMatriz {
    int elemento;
    struct CelulaMatriz *sub; //ponteiro de cima
    struct CelulaMatriz *inf; //ponteiro de baixo
    struct CelulaMatriz *prox; //ponteiro da direita
    struct CelulaMatriz *ant; //ponteiro da esquerda

} CelulaMatriz;

typedef struct MatrizFlex {
    CelulaMatriz *inicio;
} MatrizFlex;

MatrizFlex *start(int l, int c){
    //alocar a estrutura principal da matriz
    MatrizFlex *m = (MatrizFlex*)malloc(sizeof(MatrizFlex));

    //criar o nó cabeça no inicio
    m->inicio = (CelulaMatriz*)malloc(sizeof(CelulaMatriz));
    m->inicio->elemento = 0;
    m->inicio->sub = NULL;
    m->inicio->inf = NULL;
    m->inicio->prox = NULL;
    m->inicio->ant = NULL;

    //criar a primeira linha
    CelulaMatriz *i = m->inicio; //i é a linha atual
    for(int var=1; var<c; var++){
        CelulaMatriz *nova = (CelulaMatriz*)malloc(sizeof(CelulaMatriz));
        nova->prox = NULL;
        nova->sub = NULL;
        nova->inf = NULL;

        nova->ant = i; //conecta com a última
        i->prox = nova;

        //incrementa o i
        i = i->prox;
    }

    //cria as demais linhas
    CelulaMatriz *linhaAcima = m->inicio; //a linha de cima começa em inicio
    for(int var=1; var<l; var++){
        //cria o primeiro elemento da nova linha (1,0)
        CelulaMatriz *nova = (CelulaMatriz*)malloc(sizeof(CelulaMatriz));
        nova->ant = NULL;
        nova->prox = NULL;
        nova->inf = NULL;

        nova->sub = linhaAcima; //conecta com a linha de cima
        linhaAcima->inf = nova;

        //ponteiros pra percorrer a coluna da próxima linha nova
        //cel acima começa um elemento para a direita porque o inicio ja foi criado
        CelulaMatriz *celAcima = linhaAcima->prox;
        CelulaMatriz *celAtual = linhaAcima;

        //percorrer as colunas
        for(int var=1; var<c; var++){
            //cria mais uma célula
            CelulaMatriz *nova = (CelulaMatriz*)malloc(sizeof(CelulaMatriz));
            nova->inf = NULL;
            nova->prox = NULL;

            //fazer as conexões
            nova->sub = celAcima;
            nova->ant = celAtual;

            celAcima->inf = nova;
            celAtual->prox = nova;

            //mover os ponteiros
            celAcima = celAcima->prox;
            celAtual = celAtual->prox;
        }

        //desce pra próxima linha
        linhaAcima = linhaAcima->inf;
    }

    //no final, retorna
    return m;
}

void imprimir_main_diag(MatrizFlex *m, int l, int c){
    if(l == c){
        CelulaMatriz *i = m->inicio;
        while(i != NULL){
            printf("%d", i->elemento);

            if((i->prox != NULL && i->prox->inf != NULL))
            i = i->prox->inf;

            else break;
        }
        printf("\n");
    }
    else printf("Matriz inválida \n");
}

bool acharNUM(MatrizFlex *m, int l, int c, int num){
    CelulaMatriz *linha = m->inicio;

    for(int i=0; i<l; i++){
        CelulaMatriz *coluna = linha;
        for(int j=0; j<c; j++){
            if(coluna->elemento == num) return true;
            else coluna = coluna->prox;
        }
        linha = linha->inf;
    }

    return false;
}

void fazerBuraco(MatrizFlex *m, int l, int c){
    //nesse caso, dão o elemento da l linha e c coluna 
    //esse é o elemento que temos que "remover"

    CelulaMatriz *aux = m->inicio;
    for(int i=0; i<l; i++) aux = aux->inf; //linhas
    for(int j=0; j<c; j++) aux = aux->prox; //colunas

    //agora, estamos no lugar que queremos remover

    //direita (ant)
    if(aux->ant != NULL) {
        aux->ant->prox = NULL;
    }

    //esquerda (prox)
    if(aux->prox != NULL){
        aux->prox->ant = NULL;
    }

    //parte superior
    if(aux->sub != NULL){
        aux->sub->inf = NULL;
    }

    //parte inferior
    if(aux->inf != NULL){
        aux->inf->sub = NULL;
    }

    aux->inf = aux->sub = aux->prox = aux->ant = NULL;

    free(aux);
    aux = NULL;

}

void destruirMatriz(MatrizFlex *m){
    if(m == NULL || m->inicio == NULL) return; 

    CelulaMatriz *linha = m->inicio;
    while(linha != NULL){
        CelulaMatriz *coluna = linha;
        CelulaMatriz *proximaLinha = linha->inf; // guarda antes de liberar a linha atual

        while(coluna != NULL){
            CelulaMatriz *tmp = coluna; 
            coluna = coluna->prox; //anda antes de desconectar
            free(tmp);
        }

        linha = proximaLinha;
    }

    m->inicio = NULL;
    m = NULL;
}



//* Coleta de lixo ========================
/* A coleta de lixo é um método que facilita a vida de quem mexe com Java. 
Itens que perdem a referência, ou seja, não tem nenhum ponteiro apontado para eles, 
são coletados pelo Garbage Collector quando é necessária a utilização de espaço. 
Porém, em C, não temos essa coleta. E por isso é tão importante darmos os free 
quando damos malloc, calloc, etc; 
*/

//* Ordenações parciais ========================
/*As ordenações parciais são formas de implementar algoritmos de ordenação para que eles
só ordenem k elementos, ao invés de n elementos, sendo k um número de escolha, muitas
vezes do usuário. O algoritmo que eu acho mais fácil de implementar a busca parcial
é o Seleção, no qual mudamos apenas o FOR, como no exemplo a seguir
*/







//TODO - Funções auxiliares 
//TODO - SWAP
void swap(int* vetor, int i, int j){
    int tmp = vetor[i];
    vetor[i] = vetor[j];
    vetor[j] = tmp;
}

//TODO - Pegar o tamanho de alguma coisa flexivel
int getTam(ListaFlex *l) {
    int tam = 0;
    // começa no primeiro elemento real (depois do nó cabeça)
    for (Celula *i = l->primeiro->prox; i != NULL; i = i->prox) tam++;
    return tam;
}
