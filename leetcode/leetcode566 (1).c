/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** matrixReshape(int** mat, int matSize, int* matColSize, int r, int c, int* returnSize, int** returnColumnSizes) {
    //total será as linhas multiplicadas pelo tamanho da coluna
    int total;
    total = matSize*(*matColSize);

    //se o total pedido for difernte do total original, não é possível
    // retornar a matriz original
    if (total != r * c) {
        *returnSize = matSize;
        //faz alocação dinâmica
        *returnColumnSizes =  malloc(matSize*sizeof(int));
        for (int i=0; i<matSize; i++)
            (*returnColumnSizes)[i] = matColSize[i];
        return mat; //devolve a matriz
    }

    //caso passe do return acima, é possível
    //cria espaço para a nova matriz organizada
    int** res = malloc(r*sizeof(int*)); //faz as rows = linhas
    *returnColumnSizes = malloc(r * sizeof(int));
    for (int i= 0; i< r; i++) {
        res[i] = malloc(c * sizeof(int)); //fazer as columns = colunas
        (*returnColumnSizes)[i] = c;
    }

    //com a matriz criada, organizar
    *returnSize = r;
    for (int i = 0; i < total; i++)
        res[i / c][i % c] = 
        mat[i / (*matColSize)][i % (*matColSize)];

    return res;
}