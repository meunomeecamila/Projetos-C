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
- Pilha flex 
- Fila flex 
- lista simples flex 
- Lista dupla flex 
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








//TODO - Funções auxiliares 
//TODO - SWAP
void swap(int* vetor, int i, int j){
    int tmp = vetor[i];
    vetor[i] = vetor[j];
    vetor[j] = tmp;
}