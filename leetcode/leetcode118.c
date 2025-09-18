#include <stdio.h>
#include <stdlib.h>

int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    //alocação com malloc para a resposta -> como se fosse matriz
    int**triangle;
    triangle = (int**)malloc(numRows * sizeof(int*));
    //tamanho da colunas
    *returnColumnSizes = (int*)malloc(numRows * sizeof(int));

    //o tamanho vai ser um ponteiro do número de linhas
    *returnSize = numRows;

    // criar cada linha do triângulo
    for (int i = 0; i < numRows; i++) {
        triangle[i] = (int*)malloc((i + 1) * sizeof(int));
        (*returnColumnSizes)[i] = i + 1; //guardar o tamanho dessa linha

        /* primeiro e último elementos da linha são sempre 1 -> como 
        mostra na foto */
        triangle[i][0] = 1;
        triangle[i][i] = 1;

        // Preenche os elementos do meio
        for (int j = 1; j < i; j++) {
            // Regra de Pascal: soma dos dois elementos acima
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
    }

    // Retorna o triângulo gerado
    return triangle;
}