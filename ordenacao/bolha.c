#include <stdio.h>

void bubbleSort(int array[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (array[j] > array[j + 1]) {
                int tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
            }
}

void mostrar(int array[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");
}

int main() {
    int array[] = {5, 2, 9, 1, 7};
    int n = 5;

    printf("Antes: ");
    mostrar(array, n);
    bubbleSort(array, n);
    printf("Depois: ");
    mostrar(array, n);

    return 0;
}
