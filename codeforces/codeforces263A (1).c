/*CODEFORCES - 263A
Autor: Camila Cardoso de Menezes
O código abaixo cadastra a matriz pedida usando alocação dinâmica. Depois de pegar os valores, confere também a posição do 1, 
guardando em duas variáveis separadas: uma para linha e outra para coluna.
Depois disso, faz o cálculo de quantas linhas estão distantes do 2 e a mesma coisa com colunas. 
Por último, imprime esse resultado. 
*/


#include <stdio.h>
#include <stdlib.h>
int main(){
    //Encontrar onde o número 1 está na matriz
    //Para isso, temos que cadastrar a matriz
    //Lugar no meio -> 2,2
    int **matriz;
    int n = 5;
    matriz = (int **)malloc(n*sizeof(int*)); //criar o espaço
    for(int i=0; i<n; i++){
        matriz[i] = (int *)malloc(n*sizeof(int));
    }

    //Agora que já foi criado, pegar os itens
    int l=0; //linha do 1
    int c=0; //coluna do 1
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d",&matriz[i][j]);
            //encontrar onde está o item 1
            if(matriz[i][j] == 1){
                l = i;
                c = j; 
            }
        }
    }

    /* agora que sabemos onde está o item 1, calcular 
    quantos movimentos precisamos fazer, olhando as colunas e linhas separadamente */
    // LINHAS
    int movimentos;
    movimentos = 0;
    if(l < 2){
        //não está na linha correta, para menos
        movimentos += 2 - l;
    }
    else if(l > 2){
        //não está na linha correta, para mais
        movimentos += l - 2;
    }

    // COLUNAS
    if(c < 2){
        //não está na coluna correta, para menos
        movimentos += 2 - c;
    }
    else if(c > 2){
        //não está na coluna correta, para mais
        movimentos += c - 2;
    }

    //printar os movimentos
    printf("%d\n",movimentos);

    //liberar memória
    for(int i=0; i<5; i++){
        free(matriz[i]);
    }
    free(matriz);
    return 0;
}