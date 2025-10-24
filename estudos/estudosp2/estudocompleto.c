// * Esse documento conterá as matérias para a prova 2 de AED. 

// TODO - Caso deseje utilizar algum dos códigos, execute na main

// ! Matérias:
// ? (Códigos de ordenação) 
/*
- Selection - ok
- Bubble - ok
- Insertion - ok
- Heap
- Quick 
- Merge 
- Shell 
- Counting 
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

void quicksort(int esq, int dir, int * vetor, int n){
    int i = esq; int j = dir;
    int pivo = vetor[n/2];
    while(i<=j){
        while(vetor[i]<pivo) i++;
        while(vetor[j]>pivo) j--;

        if(i<=j){
            swap(vetor,i,j);
            i++; j--;
        }

        if (esq < j) quicksort(esq, j, vetor, n);  // Recursão na parte esquerda
        if (i < dir) quicksort(i, dir, vetor,n);  // Recursão na parte direita
    }
}





//TODO - Funções auxiliares 
//TODO - SWAP
void swap(int* vetor, int i, int j){
    int tmp = vetor[i];
    vetor[i] = vetor[j];
    vetor[j] = tmp;
}