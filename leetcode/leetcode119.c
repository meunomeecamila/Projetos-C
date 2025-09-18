#include <stdlib.h>
int* getRow(int rowIndex, int* returnSize) {
    *returnSize = rowIndex + 1;

    //faz alocação de memória com malloc
     int*row = (int*)malloc(sizeof(int)*(*returnSize));

    //igualar todos os itens do vetor a zero
    for (int i=0; i<=rowIndex; i++) {
        row[i] = 0;
    }

    // igualar o primeiro elemento a 1
    row[0] = 1;

    //construção de linhas
    for (int i=1; i<= rowIndex; i++) {
        // De trás pra frente para evitar sobrescrever os valores ainda necessários
        for (int j=i; j>0; j--) {
            row[j] = row[j] + row[j - 1];
        }
    }

    return row;
}
