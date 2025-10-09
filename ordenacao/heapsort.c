#include <stdio.h>

void heapify(int array[], int n, int i) {
    int maior = i;
    int esq = 2 * i + 1;
    int dir = 2 * i + 2;

    if (esq < n && array[esq] > array[maior])
        maior = esq;
    if (dir < n && array[dir] > array[maior])
        maior = dir;

    if (maior != i) {
        int tmp = array[i];
        array[i] = array[maior];
        array[maior] = tmp;
        heapify(array, n, maior);
    }
}

void heapsort(int array[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(array, n, i);

    for (int i = n - 1; i > 0; i--) {
        int tmp = array[0];
        array[0] = array[i];
        array[i] = tmp;
        heapify(array, i, 0);
    }
}

void mostrar(int array[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");
}

int main() {
    int array[] = {4, 10, 3, 5, 1};
    int n = 5;

    printf("Antes: ");
    mostrar(array, n);
    heapsort(array, n);
    printf("Depois: ");
    mostrar(array, n);

    return 0;
}
