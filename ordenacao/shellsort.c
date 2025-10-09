#include <stdio.h>

void shellsort(int array[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int tmp = array[i];
            int j;
            for (j = i; j >= gap && array[j - gap] > tmp; j -= gap)
                array[j] = array[j - gap];
            array[j] = tmp;
        }
    }
}

void mostrar(int array[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");
}

int main() {
    int array[] = {12, 34, 54, 2, 3};
    int n = 5;

    printf("Antes: ");
    mostrar(array, n);
    shellsort(array, n);
    printf("Depois: ");
    mostrar(array, n);

    return 0;
}
