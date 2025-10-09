#include <stdio.h>

void selectionSort(int array[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++)
            if (array[j] < array[min])
                min = j;
        int tmp = array[i];
        array[i] = array[min];
        array[min] = tmp;
    }
}

void mostrar(int array[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");
}

int main() {
    int array[] = {8, 4, 6, 2, 9, 1};
    int n = 6;

    printf("Antes: ");
    mostrar(array, n);
    selectionSort(array, n);
    printf("Depois: ");
    mostrar(array, n);

    return 0;
}
