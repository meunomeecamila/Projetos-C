// * Esse documento conterá as matérias para a prova 2 de AED. 

// TODO - Caso deseje utilizar algum dos códigos, execute na main

// ! Matérias:
// ? (Códigos de ordenação) 
/*
- Selection 
- Bubble 
- Insertion 
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





//TODO - Funções auxiliares 
//TODO - SWAP
void swap(int* vetor, int i, int j){
    int tmp = vetor[i];
    vetor[i] = vetor[j];
    vetor[j] = tmp;
}