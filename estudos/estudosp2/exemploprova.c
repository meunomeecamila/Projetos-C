/*
QUESTÃO 01 – Matriz dos Pães de Queijo

Você deve escrever um programa que recebe uma matriz de tamanho N x M contendo apenas 0 e 1.
Cada posição da matriz representa um local onde:
- 1 indica a presença de um pão de queijo;
- 0 indica um local vazio.

O programa deve:
1. Ler dois inteiros N e M, representando o número de linhas e colunas da matriz.
2. Ler os valores da matriz.
3. Substituir todos os valores 1 por 9.
4. Para cada posição que contém 0, calcular quantos pães de queijo (valor 9)
   existem nas posições adjacentes (cima, baixo, esquerda e direita) e
   armazenar essa contagem nessa posição.
5. Ao final, imprimir a matriz resultante.

Exemplo de entrada:
4
5
0 0 1 0 0
0 0 0 0 0
0 1 0 1 0
0 0 0 0 0

Saída esperada:
00100
01210
19191
01110
*/

#include <stdio.h>

int main(){
    int n; //linhas
    scanf("%d", &n);
    
    int m; //colunas 
    scanf("%d", &m);

    //criar a matriz
    int matriz[n][m];

    //percorrer e pegar os valores
    //obs: se o valor for 1, já trocar por 9
    for(int i=0; i<n; i++){ //linhas
        for(int j=0; j<m; j++){ //colunas
            scanf("%d", &matriz[i][j]);

            if(matriz[i][j] == 1) matriz[i][j] = 9;
            //printf("%d",matriz[i][j]);
        }
    }

    //agora, temos uma matriz com vários 9 e vários 0
    //percorrer e contar os adjacentes
    int cont;
    for(int i=0; i<n; i++){ //linhas
        for(int j=0; j<m; j++){ //colunas
            cont = 0; //zerar o contador de adjacentes

            //só coloca os adjacentes se não tiver pão de queijo
            if(matriz[i][j] != 9){
                //conferir o de cima
                if(i != 0 && matriz[i-1][j] == 9) cont++;
                //conferir o de baixo
                if(i != n-1 && matriz[i+1][j] == 9) cont++;
                //conferir o da esquerda
                if(j != 0 && matriz[i][j-1] == 9) cont++;
                //conferir o da direita
                if(j != m-1 && matriz[i][j+1] == 9) cont++;

                matriz[i][j] = cont;
            }
        }
    }

    //no final, imprimir
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            printf("%d",matriz[i][j]);
        }

        printf("\n");
    }

    

    return 0;
}