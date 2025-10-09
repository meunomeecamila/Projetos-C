#include <stdio.h>

void insertionSort(int array[], int n) {
    for (int i = 1; i < n; i++) {
        int tmp = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > tmp) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = tmp;
    }
}

void mostrar(int array[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");
}

int main() {
    int array[] = {9, 3, 7, 1, 5};
    int n = 5;

    printf("Antes: ");
    mostrar(array, n);
    insertionSort(array, n);
    printf("Depois: ");
    mostrar(array, n);

    return 0;
}
