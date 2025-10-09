#include <stdio.h>
#include <stdlib.h>

void merge(int array[], int esq, int meio, int dir) {
    int n1 = meio - esq + 1;
    int n2 = dir - meio;
    int* L = (int*) malloc(n1 * sizeof(int));
    int* R = (int*) malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++)
        L[i] = array[esq + i];
    for (int j = 0; j < n2; j++)
        R[j] = array[meio + 1 + j];

    int i = 0, j = 0, k = esq;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) array[k++] = L[i++];
        else array[k++] = R[j++];
    }

    while (i < n1) array[k++] = L[i++];
    while (j < n2) array[k++] = R[j++];

    free(L);
    free(R);
}

void mergesort(int array[], int esq, int dir) {
    if (esq < dir) {
        int meio = esq + (dir - esq) / 2;
        mergesort(array, esq, meio);
        mergesort(array, meio + 1, dir);
        merge(array, esq, meio, dir);
    }
}

void mostrar(int array[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");
}

int main() {
    int array[] = {9, 7, 5, 11, 12, 2, 14, 3, 10, 6};
    int n = 10;

    printf("Antes: ");
    mostrar(array, n);
    mergesort(array, 0, n - 1);
    printf("Depois: ");
    mostrar(array, n);

    return 0;
}
