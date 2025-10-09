#include <stdio.h>

void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void quicksort(int array[], int esq, int dir) {
    int i = esq, j = dir;
    int pivo = array[(esq + dir) / 2];

    while (i <= j) {
        while (array[i] < pivo) i++;
        while (array[j] > pivo) j--;
        if (i <= j) {
            swap(&array[i], &array[j]);
            i++;
            j--;
        }
    }
    if (esq < j) quicksort(array, esq, j);
    if (i < dir) quicksort(array, i, dir);
}

void mostrar(int array[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");
}

int main() {
    int array[] = {9, 3, 7, 1, 5, 8, 2};
    int n = 7;

    printf("Antes: ");
    mostrar(array, n);
    quicksort(array, 0, n - 1);
    printf("Depois: ");
    mostrar(array, n);

    return 0;
}
